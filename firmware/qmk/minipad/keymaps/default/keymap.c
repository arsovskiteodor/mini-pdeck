#include QMK_KEYBOARD_H
#include <hal.h>

// ============================================================================
// Keys: K1-K4 type a, b, c, d. Order follows the "layout" list in keyboard.json.
// ============================================================================
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_A, KC_B,
        KC_C, KC_D
    )
};

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
// OLED: title, last key pressed and a press counter.
// ============================================================================
static char     last_key = '-';
static uint16_t presses  = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed && keycode >= KC_A && keycode <= KC_Z) {
        last_key = 'A' + (keycode - KC_A);
        presses++;
    }
    return true; // true = let QMK send the key to the computer as usual
}

bool oled_task_user(void) {
    oled_write_ln_P(PSTR("minipad Rev A"), false);
    oled_write_ln_P(PSTR("-------------"), false);
    oled_write_P(PSTR("Last key: "), false);
    oled_write_char(last_key, false);
    oled_advance_page(true); // rest of the line cleared, move to the next one
    oled_write_P(PSTR("Presses: "), false);
    oled_write_ln(get_u16_str(presses, ' '), false);
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
