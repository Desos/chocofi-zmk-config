#include QMK_KEYBOARD_H


enum dasbob_layers {
  _ALPHA,
  _WASD,
  _LEFT_NAV,
  _RIGHT_NAV,
  _NUMER,
  _LEFT_MODS,
  _RIGHT_MODS,
  _UP_NAV,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALPHA] = LAYOUT_split_3x5_3(
        KC_Q,  	KC_K,  	KC_F,  	KC_P,  	KC_B,     	KC_SCLN,   	KC_L,  	KC_U,   	KC_Y,   	KC_W,   
        KC_A,  	KC_R,  	KC_S,  	KC_T,  	KC_SPC,   	KC_COMM,   	KC_N,  	KC_E,   	KC_I,   	KC_O,   
        KC_Z,  	KC_X,  	KC_C,  	KC_D,  	KC_V,     	KC_QUOT,   	KC_H,  	KC_M,   	KC_G,   	KC_J,   


        LT(_LEFT_NAV, KC_ESC), LT(_LEFT_MODS, KC_ENT),  OSL(_NUMER),  OSM(MOD_RSFT),  LT(_RIGHT_MODS, KC_TAB),  LT(_RIGHT_NAV, KC_F12)
    ),

    [_WASD] = LAYOUT_split_3x5_3(
        KC_1,     KC_2,  KC_3,  KC_4,  KC_5,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_LSFT,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_LCTL,  KC_A,  KC_S,  KC_D,  KC_F,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

        KC_TAB,      KC_Z,      KC_SPC,       KC_TRNS,       MO(_RIGHT_NAV),       MO(_LEFT_NAV)     
    ),
    
    [_LEFT_NAV] = LAYOUT_split_3x5_3(
        KC_LCTL,       KC_LEFT,     KC_UP,    KC_RGHT,     LCTL(KC_V),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_LGUI,       KC_BSPC,     KC_LSFT,  KC_DEL,      LCTL(KC_C),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        MEH(KC_LGUI),  LCTL(KC_Z),  KC_DOWN,  LCTL(KC_Y),  LCTL(KC_X),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNSy
y    ),    

    [_RIGHT_NAV] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_VOLU,   KC_HOME,   KC_PGUP,   KC_END,   TG(_WASD),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_VOLD,   KC_MPRV,   MT(MOD_LSFT, KC_APP),   KC_MNXT,   KC_MUTE,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_MPLY,   KC_BSPC,   KC_PGDN,   KC_DEL,   KC_PSCR,

        LT(_UP_NAV, KC_ENT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    
    [_NUMER] = LAYOUT_split_3x5_3(
        KC_CIRC, 	KC_1, 	KC_2, 	KC_3, 	KC_DOT, 	KC_EXLM, 	KC_AT,  	KC_DLR,  	KC_HASH, 	KC_PIPE, 
        KC_ASTR, 	KC_4, 	KC_5, 	KC_6, 	KC_MINS, 	KC_SLSH, 	KC_LT,  	KC_LPRN, 	KC_LBRC, 	KC_LCBR, 
        KC_PLUS, 	KC_7, 	KC_8, 	KC_9, 	KC_0,    	KC_EQL,  	KC_AMPR, 	KC_TILD, 	KC_UNDS, 	KC_PERC, 

        KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS, RSFT(KC_TAB), RSFT(KC_F12)     
    ),                        

    [_RIGHT_MODS] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   TG(_WASD),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   MT(MOD_LCTL, KC_TRNS),   MT(MOD_LSFT, KC_TRNS),   MT(MOD_LALT,KC_TRNS),   MT(MOD_LGUI, KC_TRNS),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    
    [_LEFT_MODS] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   TG(_WASD),
        MT(MOD_LGUI, KC_TRNS), MT(MOD_LALT, KC_TRNS), MT(MOD_LSFT, KC_TRNS), MT(MOD_LCTL, KC_TRNS), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_UP_NAV] = LAYOUT_split_3x5_3(
        KC_TRNS, 	QK_MOUSE_CURSOR_LEFT, 	QK_MOUSE_CURSOR_UP, 	QK_MOUSE_CURSOR_RIGHT, 	KC_TRNS, 	KC_TRNS, 	QK_MOUSE_BUTTON_1,  	QK_MOUSE_BUTTON_3,  	QK_MOUSE_BUTTON_2, 	KC_TRNS, 
        KC_LGUI, 	KC_LALT, 	KC_LSFT, 	KC_LCTL, 	KC_TRNS, 	KC_TRNS, 	KC_LCTL,  	KC_LSFT, 	KC_LALT, 	KC_LGUI, 
        KC_TRNS, 	KC_TRNS, 	QK_MOUSE_CURSOR_DOWN, 	KC_TRNS, 	KC_TRNS,    	KC_TRNS,  	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 

        KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS     
    ),                        
};


#define RSFT_OVERRIDE(TRIGGER, REPLACEMENT) \
const key_override_t ko_##TRIGGER = { \
  .trigger = TRIGGER, \
  .trigger_mods = MOD_BIT(KC_RSFT), \
  .layers = ~0, \
  .negative_mod_mask = 0, \
  .suppressed_mods = MOD_BIT(KC_RSFT), \
  .replacement = REPLACEMENT, \
  .options = ko_options_default, \
  .custom_action = NULL, \
  .context = NULL, \
  .enabled = NULL \
};

RSFT_OVERRIDE(KC_1, KC_F1)
RSFT_OVERRIDE(KC_2, KC_F2)
RSFT_OVERRIDE(KC_3, KC_F3)
RSFT_OVERRIDE(KC_4, KC_F4)
RSFT_OVERRIDE(KC_5, KC_F5)
RSFT_OVERRIDE(KC_6, KC_F6)
RSFT_OVERRIDE(KC_7, KC_F7)
RSFT_OVERRIDE(KC_8, KC_F8)
RSFT_OVERRIDE(KC_9, KC_F9)
RSFT_OVERRIDE(KC_0, KC_F10)
RSFT_OVERRIDE(KC_SLSH, KC_BSLS)
RSFT_OVERRIDE(KC_COMM, KC_DOT)
RSFT_OVERRIDE(KC_LT, KC_GT)
RSFT_OVERRIDE(KC_LPRN, KC_RPRN)
RSFT_OVERRIDE(KC_LCBR, KC_RCBR)
RSFT_OVERRIDE(KC_LBRC, KC_RBRC)
RSFT_OVERRIDE(KC_EQL, KC_GRV)
RSFT_OVERRIDE(KC_EXLM, KC_QUES)


// Now list all the overrides in the key_overrides array.
const key_override_t *key_overrides[] = {
    &ko_KC_1, &ko_KC_2, &ko_KC_3, &ko_KC_4, &ko_KC_5,
    &ko_KC_6, &ko_KC_7, &ko_KC_8, &ko_KC_9, &ko_KC_0, &ko_KC_EQL,
    &ko_KC_SLSH, &ko_KC_COMM, &ko_KC_LT, &ko_KC_LPRN, &ko_KC_LCBR, &ko_KC_LBRC, &ko_KC_EXLM};
