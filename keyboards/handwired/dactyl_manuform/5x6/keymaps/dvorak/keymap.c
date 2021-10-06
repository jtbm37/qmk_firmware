
/* A Dvorak layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _DVORAK 0
#define _GAMING 1
#define _RAISE 2
#define _OSX 3
#define _DEV 4
#define _TEST 5

#define OSX MO(_OSX)
#define DEV MO(_DEV)
#define DVK DF(_DVORAK)
#define GIG DF(_GAMING)
#define SHIFTED MO(_TEST)

#define RAISE_E LT(_RAISE,KC_E)
#define RAISE_T LT(_RAISE,KC_T)
#define RAISE_SPC LT(_RAISE,KC_SPC)

#define PRINT_SCREEN LGUI(KC_PSCREEN)
#define CTL_ESC LCTL_T(KC_ESC)
#define ALT_BSPC LALT_T(KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_5x6(
												 /*KC_DLR , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_EXLM,*/ 
		KC_DLR, KC_PLUS  , KC_LBRC  , KC_LCBR  , KC_LPRN  , KC_AMPR  ,             KC_EQL  , KC_RPRN  , KC_RCBR  , KC_RBRC  , KC_ASTR  ,KC_EXLM,
		KC_TAB , KC_SCLN  , KC_COMM  , KC_DOT  , KC_P  , KC_Y  ,                  KC_F  , KC_G  , KC_C  , KC_R  , KC_L  ,KC_SLASH,
    KC_LSFT, KC_A  , KC_O  , RAISE_E  , KC_U  , KC_I  ,                         KC_D  , KC_H  , KC_T  , KC_N  ,KC_S, KC_MINS,
    DEV, KC_QUOTE  , KC_Q  , KC_J  , KC_K  , KC_X  ,                         KC_B  , KC_M  ,KC_W,KC_V ,KC_Z,KC_DEL,
														KC_NUBS,KC_GRV,                                                       KC_NUHS, S(KC_QUOT),
																				ALT_BSPC,CTL_ESC,                        SHIFTED, RAISE_SPC,
																				PRINT_SCREEN,OSX,                   KC_LGUI, OSX,  
																				KC_TAB, KC_ENT,                         KC_HOME,KC_END
  ),
  [_GAMING] = LAYOUT_5x6(
		KC_ESC,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,KC_E,_______,_______,                        _______,_______,_______,_______,_______,_______,
     DVK,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
                                             _______,_______,            _______,_______,
                                             KC_LSFT,KC_LCTL,            _______,_______,
                                             _______,KC_SPC,            _______,_______,
                                             _______,KC_ENT,            _______,_______
),
  [_RAISE] = LAYOUT_5x6(
     KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                         KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
     XXXXXXX,XXXXXXX,KC_HOME,KC_UP,KC_END,XXXXXXX,                         XXXXXXX,XXXXXXX,KC_BSPC,XXXXXXX,XXXXXXX,XXXXXXX,
		XXXXXXX,XXXXXXX,KC_LEFT,KC_DOWN,KC_RGHT,XXXXXXX,                         KC_TAB,XXXXXXX,KC_ENT,XXXXXXX,XXXXXXX,XXXXXXX,
     RESET,XXXXXXX,KC_PGUP,KC_ENT,KC_PGDN,XXXXXXX,                         XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
																		_______,_______,                         KC_INS,_______,
                                     _______,_______,                         _______,_______,
                                     _______,_______,                         _______,_______,
                                     _______,_______,                         _______,_______
  ),

  [_OSX] = LAYOUT_5x6(
		_______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
		_______,_______,_______,S(KC_UP),_______,_______,                         _______,_______,_______,_______,_______,_______,
		_______,_______,S(KC_LEFT),S(KC_DOWN),S(KC_RIGHT),_______,                         _______,S(G(KC_3)),C(S(G(KC_4))),S(G(KC_4)),_______,_______,
     _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
                                     _______,_______,                         _______,_______,
                                     _______,_______,                         _______,_______,
                                     _______,_______,                         _______,_______,
                                     _______,_______,                         _______,_______
  ),
/*   [_SYMS] = LAYOUT_5x6( */
/* 		S(KC_NUHS) , KC_PLUS  , KC_LBRC  , KC_LCBR  , KC_LPRN  , KC_AMPR  ,             KC_EQL  , KC_RPRN  , KC_RCBR  , KC_RBRC  , KC_ASTR  ,KC_PERC, */
/*      _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______, */
/*      _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______, */
/*      _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______, */
/*                                              _______,_______,            _______,_______, */
/*                                              _______,_______,            _______,_______, */
/*                                              _______,_______,            _______,_______, */
/*                                              _______,_______,            _______,_______ */
/* ), */
  [_DEV] = LAYOUT_5x6(
		GIG,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
		_______,_______,_______,_______,_______,_______,                         KC_F9,KC_F10,KC_F11,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                         KC_F5,_______,_______,_______,_______,_______,
                                     _______,_______,                         _______,_______,
                                     _______,_______,                         _______,_______,
                                     _______,_______,                         _______,_______,
                                     _______,_______,                         _______,_______
  ),
  [_TEST] = LAYOUT_5x6(
		S(KC_NUHS) , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_PERC,
		S(KC_TAB), S(KC_SCLN)  , S(KC_COMM)  , S(KC_DOT)  , S(KC_P)  , S(KC_Y)  ,          S(KC_F)  , S(KC_G)  , S(KC_C)  , S(KC_R)  , S(KC_L)  ,S(KC_SLASH),
    _______, S(KC_A)  , S(KC_O)  , S(KC_E)  , S(KC_U)  , S(KC_I)  ,              S(KC_D)  , S(KC_H)  , S(KC_T)  , S(KC_N)  ,S(KC_S), S(KC_MINS),
    _______, S(KC_2)  , S(KC_Q)  , S(KC_J)  , S(KC_K)  , S(KC_X)  ,             S(KC_B)  , S(KC_M)  ,S(KC_W),S(KC_V) ,S(KC_Z) ,_______,
		S(KC_NUBS),S(KC_GRV),                                                       KC_NUHS, S(KC_QUOT),
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______
),
  };
