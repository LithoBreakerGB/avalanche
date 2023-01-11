#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _LOWER,
    _RAISE,
};

#define MT_LALT LALT_T(KC_ESC)
#define MT_RALT RALT_T(KC_ENT)
#define MT_SPC LT(_RAISE, KC_SPC)
#define MT_LSFT LSFT_T(KC_EQL)
#define MT_RSFT RSFT_T(KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
                    KC_1, KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                                           KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,     KC_EQL,
                  KC_TAB, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                                           KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_CAPS,
        XXXXXXX, KC_BSLS, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                                           KC_H,    KC_N,    KC_E,    KC_I,       KC_O,    KC_QUOT, KC_ENT,
                 KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,  KC_INS,  KC_PSCR,  KC_RBRC,   KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_BSLS,
                                            KC_LCTL,KC_LGUI, KC_ENT, TO(2),  KC_LALT, KC_RALT,  TO(1),KC_SPC, KC_LGUI, KC_RCTL
    ),
    [_LOWER] = LAYOUT(
                    KC_1,    KC_2,       KC_3,      KC_4,      KC_5,       KC_6,                                         KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,     KC_EQL,
                    KC_1,    KC_2,       KC_3,      KC_4,      KC_5,       KC_6,                                         KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,     KC_EQL,
        XXXXXXX, KC_BSLS, KC_LCTL,    KC_LALT,    KC_ESC,    KC_DEL,    XXXXXXX,                                        KC_UP,  KC_GRV,  KC_LBRC, KC_RBRC,   KC_SCLN,    KC_QUOT, XXXXXXX,
                 KC_LSFT,    KC_Z,       KC_X,      KC_C,      KC_V,    KC_LEFT,    _______, _______, _______, _______, KC_DOWN, KC_RGHT,  KC_COMM,  KC_DOT, KC_SLSH,    KC_BSLS,
                                            KC_LCTL,KC_LGUI, KC_ENT, TO(0),  KC_LALT, KC_RALT,  TO(2),KC_SPC, KC_LGUI, KC_RCTL
    [_RAISE] = LAYOUT(
                 KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,                                     KC_AMPR, KC_ASTR, KC_MINS, KC_UNDS, KC_PLUS, KC_EQL,
                 KC_BSLS, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,                                     XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_BSLS, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_DEL,                                      KC_BSPC, KC_DLR,  KC_PERC, KC_CIRC, XXXXXXX, XXXXXXX, XXXXXXX,
                  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    XXXXXXX, _______, _______, _______, _______, XXXXXXX, KC_AMPR, KC_ASTR, KC_PCMM, XXXXXXX, _______,
                                            KC_LCTL,KC_LGUI, KC_ENT, TO(0),  KC_LALT, KC_RALT,  TO(0),KC_SPC, KC_LGUI, KC_RCTL
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC__VOLUP);
        } else {
            tap_code(KC__VOLDOWN);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_MS_WH_UP);
        } else {
            tap_code(KC_PGDOWN);
        }
    }
    return true;
}

#void dip_switch_update_user(uint8_t index, bool active) 
#{ 
# switch (index) {
#        case 0:		//ENC0_SW
#        if(active) //ENC0 pressed3
#		{ 
#			tap_code(KC_MUTE);
#		} 
#	else //ENC0 released
#               {
#			//do nothing
#		}

# switch (index) {
#        case 1:		//ENC1_SW
#        if(active) //ENC1 pressed3
#		{ 
#			tap_code(KC_MUTE);
#		} 
#	else //ENC0 released
#               {
#			//do nothing
#		}
#            break;
