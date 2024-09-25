
/* A Dvorak layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _DVORAK 0
#define _SHIFTED 1
#define _RAISE 2
#define _OSX 3
#define _DEV 4
#define _GAMING1 5
#define _GAMING2 6
#define _GAMING3 7
#define _MOUSE 8

#define OSX MO(_OSX)
#define DEV MO(_DEV)
#define DVK DF(_DVORAK)
#define SHIFTED MO(_SHIFTED)
#define MOUSE_L TG(_MOUSE)

#define GIG DF(_GAMING1)
#define GIG2 MO(_GAMING2)
#define GIG3_SPC LT(_GAMING3,KC_SPC)

/* #define RAISE_E LT(_RAISE,KC_E) */
/* #define RAISE_T LT(_RAISE,KC_T) */

#define GUI_R LGUI_T(KC_R)
#define GUI_COMM LGUI_T(KC_COMM)
#define RAISE_SPC LT(_RAISE,KC_SPC)
#define RAISE_O LT(_MOUSE,KC_O)

#define PRINT_SCREEN LGUI(KC_PSCR)
#define CTL_ESC LCTL_T(KC_ESC)
#define ALT_BSPC LALT_T(KC_BSPC)

// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    SLASH_LAYR, // Our custom tap dance key; add any other tap dance keys to this enum 
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(tap_dance_state_t *state, void *user_data);
void ql_reset(tap_dance_state_t *state, void *user_data);



enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

bool set_scrolling = false;

// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 100.0
#define SCROLL_DIVISOR_V 100.0

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Check if drag scrolling is active
    if (set_scrolling) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        //scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        //mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        /* scroll_accumulated_h -= (int8_t)scroll_accumulated_h; */
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

// Function to handle key events and enable/disable drag scrolling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRAG_SCROLL:
            // Toggle set_scrolling when DRAG_SCROLL key is pressed or released
            set_scrolling = record->event.pressed;
            break;
        default:
            break;
    }
    return true;
}

// Function to handle layer changes and disable drag scrolling when not in AUTO_MOUSE_DEFAULT_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    // Disable set_scrolling if the current layer is not the AUTO_MOUSE_DEFAULT_LAYER
    if (get_highest_layer(state) != _MOUSE) {
        set_scrolling = false;
    }
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_5x6(
												 /*KC_DLR , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_EXLM,*/ 
		KC_DLR, KC_PLUS  , KC_LBRC  , KC_LCBR  , KC_LPRN  , KC_AMPR  ,             KC_EQL  , KC_RPRN  , KC_RCBR  , KC_RBRC  , KC_ASTR  ,KC_EXLM,
		KC_TAB , KC_SCLN  , GUI_COMM  , KC_DOT  , KC_P  , KC_Y  ,                  KC_F  , KC_G  , KC_C  , GUI_R  , KC_L  ,TD(SLASH_LAYR),
    KC_LSFT, KC_A  , RAISE_O  , KC_E  , KC_U  , KC_I  ,                         KC_D  , KC_H  , KC_T  , KC_N  ,KC_S, KC_MINS,
    DEV, KC_QUOTE  , KC_Q  , KC_J  , KC_K  , KC_X  ,                         KC_B  , KC_M  ,KC_W,KC_V ,KC_Z,KC_DEL,
														KC_NUBS,KC_GRV,                                                       KC_NUHS, S(KC_QUOT),
																				ALT_BSPC,RAISE_SPC,                        SHIFTED, XXXXXXX,
																				MOUSE_L,/*OSX*/CTL_ESC,                   XXXXXXX, KC_END,  
																				KC_TAB, KC_ESC,                         KC_LGUI,KC_HOME
  ),
  [_SHIFTED] = LAYOUT_5x6(
		S(KC_NUHS) , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_PERC,
		S(KC_TAB), S(KC_SCLN)  , S(KC_COMM)  , S(KC_DOT)  , S(KC_P)  , S(KC_Y)  ,          S(KC_F)  , S(KC_G)  , S(KC_C)  , S(KC_R)  , S(KC_L)  ,S(KC_SLASH),
    _______, S(KC_A)  , S(KC_O)  , S(KC_E)  , S(KC_U)  , S(KC_I)  ,              S(KC_D)  , S(KC_H)  , S(KC_T)  , S(KC_N)  ,S(KC_S), S(KC_MINS),
    _______, S(KC_2)  , S(KC_Q)  , S(KC_J)  , S(KC_K)  , S(KC_X)  ,             S(KC_B)  , S(KC_M)  ,S(KC_W),S(KC_V) ,S(KC_Z) ,_______,
		S(KC_NUBS),S(KC_GRV),                                                       S(KC_6), S(KC_QUOT),
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______
),
  [_RAISE] = LAYOUT_5x6(
     KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                         KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
     XXXXXXX,XXXXXXX,KC_HOME,KC_UP,KC_END,XXXXXXX,                         PRINT_SCREEN,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
		 XXXXXXX,XXXXXXX,KC_LEFT,KC_DOWN,KC_RGHT,XXXXXXX,                         KC_TAB,XXXXXXX,KC_ENT,A(KC_SPC),XXXXXXX,XXXXXXX,
     XXXXXXX,XXXXXXX,KC_PGUP,KC_ENT,KC_PGDN,XXXXXXX,                         XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,QK_BOOT,
																		_______,_______,                         KC_INS,_______,
                                     _______,_______,                         _______,_______,
                                     _______,_______,                         _______,_______,
                                     _______,_______,                         _______,_______
  ),

  [_MOUSE] = LAYOUT_5x6(
												_______,_______,_______,_______,_______,_______,                         KC_KB_VOLUME_UP,KC_KB_VOLUME_DOWN,C(KC_LEFT),C(KC_RGHT),DVK,DVK,
												_______,_______,_______,KC_WH_U,KC_BTN3,_______,                         DRAG_SCROLL,G(KC_LBRC),G(KC_RBRC),G(KC_R),XXXXXXX,MOUSE_L,
												_______,_______,_______,KC_WH_D,KC_BTN1,KC_BTN2,                         G(KC_C),KC_BTN1,KC_BTN2,KC_BTN3,XXXXXXX,XXXXXXX,
												_______,_______,_______,KC_WH_L,KC_WH_R,_______,                         G(KC_V),C(KC_PGUP),C(KC_PGDN),XXXXXXX,XXXXXXX,G(KC_W),
                                     _______,_______,                         _______,_______,
                                     _______,KC_LSFT,                         KC_ENT,_______,
																				MOUSE_L,_______,                         _______,KC_ESC,
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
  [_GAMING1] = LAYOUT_5x6(
		KC_ESC,KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         DVK,DVK,DVK,DVK,DVK,DVK,
     KC_TAB,  KC_I,  KC_Q,  KC_W,  KC_E,  KC_R,                          _______,  _______,  _______,  _______,  _______,  _______,  
     KC_LALT,  KC_M,  KC_A,  KC_S,  KC_D,  KC_F,                          _______,  _______,  _______,  _______,  _______,  _______,  
     XXXXXXX,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                          _______,  _______,  _______,  _______,  _______,  _______,  
                                             KC_COMM,KC_DOT,            _______,_______,
                                             KC_LSFT,KC_LCTL,            _______,_______,
                                             GIG3_SPC,GIG2,            _______,_______,
                                             KC_LALT,KC_ENT,            _______,_______
),
  [_GAMING2] = LAYOUT_5x6(
		KC_ESC,KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,                         DVK,DVK,DVK,DVK,DVK,DVK,
     XXXXXXX,  KC_T,  KC_Y,  KC_U,  KC_O,  KC_P,                          _______,  _______,  _______,  _______,  _______,  _______,  
     XXXXXXX,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,                          _______,  _______,  _______,  _______,  _______,  _______,  
     XXXXXXX,  KC_N,  KC_M,  KC_L,  KC_ENT,  KC_ESC,                          _______,  _______,  _______,  _______,  _______,  _______,  
                                             _______,_______,            _______,_______,
                                             KC_LSFT,KC_LCTL,            _______,_______,
                                             _______,KC_SPC,            _______,_______,
                                             _______,KC_ENT,            _______,_______
),
  [_GAMING3] = LAYOUT_5x6(
		KC_ESC,KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5,                         DVK,DVK,DVK,DVK,DVK,DVK,
     XXXXXXX,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,                          _______,  _______,  _______,  _______,  _______,  _______,  
     XXXXXXX,  KC_F11,  KC_F12,  XXXXXXX,  XXXXXXX,  XXXXXXX,                          _______,  _______,  _______,  _______,  _______,  _______,  
     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                          _______,  _______,  _______,  _______,  _______,  _______,  
                                             _______,_______,            _______,_______,
                                             KC_LSFT,KC_LCTL,            _______,_______,
                                             _______,KC_SPC,            _______,_______,
                                             _______,KC_ENT,            _______,_______
),
  };

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
        case LCTL_T(KC_ESC):
            return 150;
        default:
            return TAPPING_TERM;
    }
}

void pointing_device_init_kb(void) {
#ifdef PMW3360_CPI
    pointing_device_set_cpi(PMW3360_CPI);
#endif
}

// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void ql_finished(tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_SLASH);
            break;
        /* case TD_SINGLE_HOLD: */
        /*     layer_on(_MY_LAYER); */
        /*     break; */
        case TD_DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_MOUSE)) {
                // If already set, then switch it off
                layer_off(_MOUSE);
            } else {
                // If not already set, then switch the layer on
                layer_on(_MOUSE);
            }
            break;
        default:
            break;
    }
}

void ql_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_MOUSE);
    }
    ql_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [SLASH_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset)
};

// Set a long-ish tapping term for tap-dance keys
/* uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case QK_TAP_DANCE ... QK_TAP_DANCE_MAX: */
/*             return 275; */
/*         default: */
/*             return TAPPING_TERM; */
/*     } */
/* } */



/*Uncomment to log key input. Use hid_listen.*/
/* void keyboard_post_init_user(void) { */
/*   // Customise these values to desired behaviour */
/*   debug_enable=true; */
/*   debug_matrix=true; */
/*   //debug_keyboard=true; */
/*   //debug_mouse=true; */
/* } */

/* 	bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/* 		// If console is enabled, it will print the matrix position and status of each key pressed */
/* 	#ifdef CONSOLE_ENABLE */
/* 			uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count); */
/* 	#endif */
/* 		return true; */
/* 	} */
