/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

// clang-format off

enum layers {
    BASE,
    FUNC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_numpad_6x5(
        KC_MPLY,  MO(FUNC),  KC_MPRV,  KC_MNXT,  KC_MPLY,
        KC_BSPC,  KC_NUM,    KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_PSCR,  KC_P7,     KC_P8,    KC_P9,    KC_PPLS,
        KC_F13,   KC_P4,     KC_P5,    KC_P6,
        KC_F14,   KC_P1,     KC_P2,    KC_P3,    KC_PENT,
        KC_F15,   KC_P0,               KC_PDOT),

    [FUNC] = LAYOUT_numpad_6x5(
        KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,    RM_TOGG,
        KC_NO,  QK_BOOT,        EE_CLR)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [FUNC] = { ENCODER_CCW_CW(KC_NO, KC_NO) },
};
#endif // ENCODER_MAP_ENABLE

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case FUNC:
                rgb_matrix_set_color(22, RGB_YELLOW); // RM_TOGG
                rgb_matrix_set_color(24, RGB_YELLOW); // QK_BOOT
                rgb_matrix_set_color(25, RGB_YELLOW); // EE_CLR
                break;
            default:
                rgb_matrix_set_color(i, RGB_OFF);
                break;
        }
    }
    if (host_keyboard_led_state().num_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LOCK_LED_INDEX, 255, 255, 255); // assuming num lock is at led #NUM_LOCK_LED_INDEX
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LOCK_LED_INDEX, 0, 0, 0);
    }
    return false;
}
