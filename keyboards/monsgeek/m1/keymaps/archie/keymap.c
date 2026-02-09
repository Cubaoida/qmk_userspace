/* Copyright (C) 2023 jonylee@hfd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum unicode_names {
    KC_LAE,
    KC_LOE,
    KC_LUE,
    KC_SS,
    KC_UAE,
    KC_UOE,
    KC_UUE
};

const uint32_t PROGMEM unicode_map[] = {
    [KC_LAE]  = 0x00E4,  // ä
    [KC_LOE]  = 0x00F6,  // ö
    [KC_LUE]  = 0x00FC,  // ü
    [KC_SS]   = 0x00DF,  // ß
    [KC_UAE]  = 0x00C4,  // Ä
    [KC_UOE]  = 0x00D6,  // Ö
    [KC_UUE]  = 0x00DC,  // Ü
};

enum __layers {
    BASE,
    FUNC
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_all( /* Base */
        KC_ESC,   KC_F1,    KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,    KC_F10,    KC_F11,   KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,     KC_0,      KC_MINS,  KC_EQL,   KC_BSPC,            KC_HOME,
        KC_TAB,   KC_Q,     KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,     KC_P,      KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
        KC_CAPS,  KC_A,     KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,     KC_SCLN,   KC_QUOT,  KC_NUHS,  KC_ENT,             KC_PGDN,
        KC_LSFT,  KC_NUBS,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT,    KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
        KC_LCTL,  KC_LGUI,  KC_LALT,                KC_SPC,                         KC_RALT,  MO(FUNC),  KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [FUNC] = LAYOUT_all( /* FN */
        QK_BOOT,  RM_TOGG,             KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,               KC_NO,  KC_NO,               KC_NO,  KC_NO,  EE_CLR,  KC_NO,          KC_NO,
        KC_NO,    KC_R,                KC_E,       KC_I,   KC_S,   KC_U,   KC_B,   KC_NO,               KC_NO,  KC_NO,               KC_NO,  KC_NO,  KC_NO,   KC_NO,          KC_NO,
        KC_NO,    KC_NO,               KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  UP(KC_LUE, KC_UUE),  KC_NO,  UP(KC_LOE, KC_UOE),  KC_NO,  KC_NO,  KC_NO,   KC_NO,          KC_NO,
        KC_NO,    UP(KC_LAE, KC_UAE),  UM(KC_SS),  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,               KC_NO,  KC_NO,               KC_NO,  KC_NO,  KC_NO,   KC_NO,          KC_NO,
        KC_LSFT,  KC_NO,               KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,               KC_NO,  KC_NO,               KC_NO,  KC_NO,           KC_NO,  KC_NO,  KC_NO,
        KC_NO,    KC_NO,               KC_NO,                      KC_NO,                                       KC_RALT,             KC_NO,  KC_PSCR,         KC_NO,  KC_NO,  KC_NO)
};


// clang-format off
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [FUNC] = { ENCODER_CCW_CW(KC_NO, KC_NO) }
};
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case FUNC:
                rgb_matrix_set_color(0, RGB_YELLOW); // QK_BOOT
                rgb_matrix_set_color(1, RGB_YELLOW); // RM_TOGG
                rgb_matrix_set_color(12, RGB_YELLOW); // EE_CLR
                rgb_matrix_set_color(15, RGB_RED); // KC_R
                rgb_matrix_set_color(16, RGB_RED); // KC_E
                rgb_matrix_set_color(17, RGB_RED); // KC_I
                rgb_matrix_set_color(18, RGB_RED); // KC_S
                rgb_matrix_set_color(19, RGB_RED); // KC_U
                rgb_matrix_set_color(20, RGB_RED); // KC_B
                rgb_matrix_set_color(36, RGB_GREEN); // UP(KC_LUE, KC_UUE)
                rgb_matrix_set_color(38, RGB_GREEN); // UP(KC_LOE, KC_UOE)
                rgb_matrix_set_color(45, RGB_GREEN); // UP(KC_LAE, KC_UAE)
                rgb_matrix_set_color(46, RGB_GREEN); // UM(KC_SS)
                rgb_matrix_set_color(59, RGB_GREEN); // KC_LSFT
                rgb_matrix_set_color(78, RGB_RED); // KC_RALT)
                rgb_matrix_set_color(80, RGB_RED); // KC_PSCR)
                break;
            default:
                rgb_matrix_set_color(i, RGB_OFF);
                break;
        }
    }
    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(44, 255, 255, 255); // assuming caps lock is at led #44
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(44, 0, 0, 0);
    }
    return false;
}

