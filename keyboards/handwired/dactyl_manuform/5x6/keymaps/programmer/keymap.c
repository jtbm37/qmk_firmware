
/* A Dvorak layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ALT 3
#define _DEV 4

#define RAISE MO(_RAISE)
#define RAISE_D LT(_RAISE,KC_D)
#define RAISE_K LT(_RAISE,KC_K)
#define ALTL LM(_ALT, MOD_LALT)
#define DEV MO(_DEV)

#define PRINT_SCREEN LGUI(KC_PSCREEN)
#define CTL_ESC LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_5x6(
     KC_EQL , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
     KC_ESC , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSLASH,
     KC_LSFT, KC_A  , KC_S  , RAISE_D , KC_F  , KC_G  ,                         KC_H  , KC_J  , RAISE_K  , KC_L  ,KC_SCLN,KC_QUOT,
				DEV, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_DEL,
                      KC_NUBS,KC_GRV,                                                       KC_LBRC,KC_RBRC, 
																				ALTL,CTL_ESC,                        KC_LSFT, KC_SPC,
																				PRINT_SCREEN,KC_BSPC,                   KC_LGUI, _______,  
																				KC_TAB, KC_ENT,                         KC_HOME,KC_END
  ),
  [_RAISE] = LAYOUT_5x6(
     KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                         KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
     _______,_______,KC_HOME,KC_UP,KC_END,KC_PGUP,                         _______,_______,_______,_______,_______,_______,
		_______,_______,KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,                         KC_TAB,KC_BSPC,KC_ENT,_______,_______,_______,
     RESET,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
																		_______,_______,                         KC_INS,_______,
                                     _______,_______,                         _______,_______,
                                     _______,_______,                         _______,_______,
                                     _______,_______,                         _______,_______
  ),

  [_ALT] = LAYOUT_5x6(
												_______,_______,_______,_______,_______,_______,                         _______, _______, _______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
		_______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
                                     _______,_______,                         KC_TAB,KC_ENT,
                                     _______,_______,                         _______,_______,
                                     _______,_______,                         _______,_______,
                                     _______,_______,                         _______,_______
  ),
  [_DEV] = LAYOUT_5x6(
												_______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
		_______,_______,_______,_______,_______,_______,                         KC_F9,KC_F10,KC_F11,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                         KC_F5,_______,_______,_______,_______,_______,
                                     _______,_______,                         _______,_______,
                                     _______,_______,                         _______,_______,
                                     _______,_______,                         _______,_______,
                                     _______,_______,                         _______,_______
  ),
  };
