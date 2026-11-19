// Copyright 2026 Teodor Arsovski
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <hal.h>

// ============================================================================
// Keys: K1-K4 type a, b, c, d; ENC1 push = mute, ENC2 push = Enter.
// Order follows the "layout" list in keyboard.json.
// ============================================================================
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_A,    KC_B,
        KC_C,    KC_D,
        KC_MUTE, KC_ENT // ENC1 push, ENC2 push
    )
};

// ============================================================================
// Encoders: ENC1 = volume, ENC2 = left/right arrow (one cursor step per detent,
// easy to count in a text editor). QMK calls this once per detent (resolution 4
// in keyboard.json). If a direction is reversed, swap pin_a and pin_b there.
// ============================================================================
static int16_t enc_pos[2] = {0, 0}; // detents counted since power-up, CW = +1

static const char *last_action = "-";

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index > 1) return false;
    enc_pos[index] += clockwise ? 1 : -1;
    if (index == 0) {
        tap_code(clockwise ? KC_VOLU : KC_VOLD);
        last_action = clockwise ? "Vol +" : "Vol -";
    } else {
        tap_code(clockwise ? KC_RGHT : KC_LEFT);
        last_action = clockwise ? "Right" : "Left";
    }
    return false; // false = we handled it; skip QMK's default (volume on every encoder)
}

// ============================================================================
// Key LEDs D1-D4: all four breathe together.
//
// Why not QMK's backlight feature: its "pwm" driver drives one pin only, the "timer" driver
// needs a ChibiOS GPT timer that the RP2040 port doesn't have, and the "software" driver
// can't breathe (docs/features/backlight.md). So we drive the RP2040's PWM hardware directly.
// Each PWM slice has two channels, A and B (mcuconf.h has the pin -> slice mapping).
// ============================================================================
#define LED_PWM_FREQUENCY 1000000 // PWM counter clock: 1 MHz (same as QMK's RP2040 backlight)
#define LED_PWM_PERIOD 1024       // ticks per PWM cycle: 1 MHz / 1024 = about 977 Hz, no flicker
#define BREATH_PERIOD_MS 2000     // one breath: dark -> bright -> dark
#define BREATH_UPDATE_MS 10       // how often the brightness changes (100 times a second)

typedef struct {
    pin_t        pin;
    PWMDriver   *driver;  // PWMDn = slice n
    pwmchannel_t channel; // 0 = A, 1 = B
} key_led_t;

static const key_led_t key_leds[] = {
    {GP9, &PWMD4, 1},  // D1 under K1: slice 4 B
    {GP10, &PWMD5, 0}, // D2 under K2: slice 5 A
    {GP11, &PWMD5, 1}, // D3 under K3: slice 5 B
    {GP12, &PWMD6, 0}, // D4 under K4: slice 6 A
};

// One config for all three slices: both channels active-high (bigger number = brighter).
static const PWMConfig led_pwm_config = {
    .frequency = LED_PWM_FREQUENCY,
    .period    = LED_PWM_PERIOD,
    .callback  = NULL,
    .channels  = {
        {.mode = PWM_OUTPUT_ACTIVE_HIGH, .callback = NULL},
        {.mode = PWM_OUTPUT_ACTIVE_HIGH, .callback = NULL},
    },
};

static void key_leds_init(void) {
    for (uint8_t i = 0; i < ARRAY_SIZE(key_leds); i++) {
        // Connect the pin to the PWM block instead of plain GPIO. Same pin mode QMK's backlight
        // used on GP9 in the 2026-11-11 bench test (platforms/chibios/chibios_config.h).
        palSetLineMode(key_leds[i].pin, PAL_MODE_ALTERNATE_PWM | PAL_RP_PAD_DRIVE12 | PAL_RP_GPIO_OE);
    }
    pwmStart(&PWMD4, &led_pwm_config);
    pwmStart(&PWMD5, &led_pwm_config);
    pwmStart(&PWMD6, &led_pwm_config);
}

// Brightness 0..65025 for a moment in time. A triangle wave (up, then down), squared:
// our eyes notice changes at low brightness much more than at high brightness, so a
// straight line looks like it jumps on quickly and then sits at full for a long time.
static uint32_t breath_level(uint32_t now_ms) {
    uint32_t t    = now_ms % BREATH_PERIOD_MS;
    uint32_t half = BREATH_PERIOD_MS / 2;
    uint32_t ramp = (t < half) ? t : (BREATH_PERIOD_MS - t); // 0 -> half -> 0
    uint32_t lin  = ramp * 255 / half;                       // 0..255
    return lin * lin;                                        // 0..65025
}

static void key_leds_set(uint32_t level) {
    uint32_t width = level * LED_PWM_PERIOD / 65025; // ticks the pin stays high per cycle
    for (uint8_t i = 0; i < ARRAY_SIZE(key_leds); i++) {
        pwmEnableChannel(key_leds[i].driver, key_leds[i].channel, (pwmcnt_t)width);
    }
}

// ============================================================================
// OLED: title, last action, press counter and both encoder positions.
// ============================================================================
static uint16_t presses = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        static const char *const letters[] = {"A", "B", "C", "D"};
        if (keycode >= KC_A && keycode <= KC_D) last_action = letters[keycode - KC_A];
        else if (keycode == KC_MUTE)            last_action = "Mute";
        else if (keycode == KC_ENT)             last_action = "Enter";
        presses++;
    }
    return true; // true = let QMK send the key to the computer as usual
}

// Writes e.g. "ENC1:  -12": sign first, because get_u16_str only does unsigned numbers.
static void oled_write_enc(const char *name, int16_t pos) {
    oled_write(name, false);
    oled_write_char(pos < 0 ? '-' : ' ', false);
    oled_write_ln(get_u16_str(pos < 0 ? -pos : pos, ' '), false);
}

bool oled_task_user(void) {
    oled_write_ln_P(PSTR("minipad Rev A"), false);
    oled_write_ln_P(PSTR("-------------"), false);
    oled_write_P(PSTR("Last: "), false);
    oled_write(last_action, false);
    oled_advance_page(true); // rest of the line cleared, move to the next one
    oled_write_P(PSTR("Presses: "), false);
    oled_write_ln(get_u16_str(presses, ' '), false);
    oled_write_enc("ENC1:", enc_pos[0]);
    oled_write_enc("ENC2:", enc_pos[1]);
    return false;
}

// ============================================================================
// QMK hooks
// ============================================================================
void keyboard_post_init_user(void) {
    key_leds_init();
}

// Runs on every pass of QMK's main loop, between matrix scans.
void housekeeping_task_user(void) {
    static uint32_t last_update = 0;
    if (timer_elapsed32(last_update) >= BREATH_UPDATE_MS) {
        last_update = timer_read32();
        key_leds_set(breath_level(last_update));
    }
}
