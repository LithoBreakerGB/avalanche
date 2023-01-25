// Copyright 2022 Viatly Volkov (@vlkv)
// SPDX-License-Identifier: GPL-2.0-or-later

/*
qmk compile -kb avalanche/v4 -km default
qmk flash -kb avalanche/v4 -km default
*/

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define MT_LALT LALT_T(KC_ESC)
#define MT_RALT RALT_T(KC_ENT)
#define MT_SPC LT(_RAISE, KC_SPC)
#define MT_LSFT LSFT_T(KC_EQL)
#define MT_RSFT RSFT_T(KC_MINS) 

    
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
                KC_1,    KC_2,    KC_3,   KC_4,   KC_5,    KC_6,                                         KC_7,    KC_8,     KC_9,    KC_0, KC_MINS,  KC_EQL,
              KC_TAB,    KC_Q,    KC_W,   KC_F,   KC_P,    KC_G,                                         KC_J,    KC_L,     KC_U,    KC_Y, KC_SCLN, KC_CAPS,
    KC_LEFT_CTRL, KC_BSPC,    KC_A,    KC_R,   KC_S,   KC_T,    KC_D,                                         KC_H,    KC_N,     KC_E,    KC_I,    KC_O, KC_QUOT, KC_ENT,
             KC_LSFT,    KC_Z,    KC_X,   KC_C,   KC_V,    KC_B,    KC_COPY, KC_INS, KC_PSCR, KC_PASTE,    KC_K,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
                                             KC_LCTL, KC_LGUI, KC_ENT, TO(2), KC_LALT, KC_RALT, TO(1), LT(1,KC_SPACE), KC_LGUI, KC_RCTL
    ),
    [_LOWER] = LAYOUT(
                KC_1,    KC_2,    KC_3,   KC_4,   KC_5,    KC_6,                                          KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL,
                KC_1,    KC_2,    KC_3,   KC_4,   KC_5,    KC_6,                                          KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL,
    KC_LEFT_CTRL, KC_BSPC, KC_LCTL, KC_LALT, KC_ESC, KC_DEL, XXXXXXX,                                         KC_UP,  KC_GRV, KC_LBRC, KC_RBRC, KC_SCLN, KC_QUOT, XXXXXXX,
             KC_LSFT,    KC_Z,    KC_X,   KC_C,   KC_V, KC_LEFT,   KC_COPY, KC_INS, KC_PSCR, KC_PASTE,   KC_DOWN, KC_RGHT, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
                                             KC_LCTL,KC_LGUI, KC_ENT, TO(0),  KC_LALT, KC_RALT,  TO(2),KC_SPACE, KC_LGUI, KC_RCTL
    ),
    [_RAISE] = LAYOUT(
                KC_1,    KC_2,    KC_3,   KC_4,   KC_5,    KC_6,                                          KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL,
                KC_1,    KC_2,    KC_3,   KC_4,   KC_5,    KC_6,                                          KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL,
    KC_LEFT_CTRL, KC_BSPC, KC_LCTL, KC_LALT, KC_ESC, KC_DEL, XXXXXXX,                                         KC_UP, XXXXXXX, XXXXXXX, KC_PGUP, KC_HOME,  KC_DEL, XXXXXXX,
             KC_LSFT,    KC_Z,    KC_X,   KC_C,   KC_V, KC_LEFT,   KC_COPY, KC_INS, KC_PSCR, KC_PASTE,   KC_DOWN, KC_RGHT, XXXXXXX, KC_PGDN,  KC_END, XXXXXXX,
                                            KC_LCTL,KC_LGUI, KC_ENT, TO(0),  KC_LALT, KC_RALT,  TO(3),KC_SPACE, KC_LGUI, KC_RCTL
    ),    
    [_ADJUST] = LAYOUT(
               KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,   KC_F6,                                         KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
               KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,   KC_F6,                                         KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
    KC_LEFT_CTRL, KC_BSPC, KC_LCTL, KC_LALT, KC_ESC, KC_DEL, XXXXXXX,                                         KC_UP, XXXXXXX, XXXXXXX, KC_PGUP, KC_HOME,  KC_DEL, XXXXXXX,
             KC_LSFT,    KC_Z,    KC_X,   KC_C,   KC_V, KC_LEFT,   KC_COPY, KC_INS, KC_PSCR, KC_PASTE,   KC_DOWN, KC_RGHT, XXXXXXX, KC_PGDN,  KC_END, XXXXXXX,
                                            KC_LCTL,KC_LGUI, KC_ENT, TO(0),  KC_LALT, KC_RALT,  TO(0),KC_SPACE, KC_LGUI, KC_RCTL             
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_MS_WH_UP);
        } else {
            tap_code(KC_MS_WH_DOWN);
        }
    }
    return true;
}

void dip_switch_update_user(uint8_t index, bool active) 
{ 
 switch (index) {
        case 0:		//ENC0_SW
        if(active) //ENC0 pressed3
			{ 
			tap_code(KC_COPY);
			} 
	else //ENC0 released
               		{
			//do nothing
			}
		}

 switch (index) {
       case 1:		//ENC1_SW
       if(active) //ENC1 pressed3
			{ 
			tap_code(KC_PASTE);
			} 
	else //ENC1 released
             		{
			//do nothing
			}
		}
}
	
	
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("COLEMAK\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("SYMBOLS\nNUMBERS"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("FUNCTION\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("LAYER 4\n"), false);
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}
#endif
	
