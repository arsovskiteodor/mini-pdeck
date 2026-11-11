#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_A)
};

// QMK starts the PWM backlight (backlight_init_ports, keyboard.c) before it loads the saved
// settings (backlight_init), so a saved "breathing on" never starts the breathing timer at
// power-up. Start it here, after both have run.
void keyboard_post_init_user(void) {
    if (is_backlight_enabled() && is_backlight_breathing() && !is_breathing()) {
        breathing_enable();
    }
}