// qmk compile -kb keebio/iris_ce/rev1 -km veevidify

#include QMK_KEYBOARD_H

enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE_LEFT,
    _RAISE_RIGHT,
    _LAYER4
};

// macros as custom keycodes
enum custom_keycodes {
  // starting the seq from a safe range
  ALTW = SAFE_RANGE,  // switch app
  SCRSH, // macos screen shot (draw)
  ZOOMI, // cmd + (zoom in)
  ZOOMO, // cmd - (zoom out)
  FULLS, // full screen (rect)
  LSNAP, // snap left 2/3 (rect)
  RSNAP, // snap right 2/3 (rect)
  LHSNP, // left half snap (rect)
  RHSNP, // right half snap (rect)
  LCSNP, // left corner snap (rect)
  RCSNP, // right corner snap (rect)
  WORDP, // alt left (previous word)
  WORDN, // alt right (next word)
  LINEB, // cmd left (line begin)
  LINEE  // cmd right (line end)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌─────────────┬────────┬────────┬─────────────┬─────────────┬─────────────┐                          ┌─────────────┬─────────────┬─────────────┬────────┬────────┬──────────────┐
     KC_GRV,       KC_1,    KC_2,    KC_3,         KC_4,         KC_5,                                    KC_6,         KC_7,         KC_8,         KC_9,    KC_0,    KC_VOLU,
  //├─────────────┼────────┼────────┼─────────────┼─────────────┼─────────────┤                          ├─────────────┼─────────────┼─────────────┼────────┼────────┼──────────────┤
     KC_TAB,       KC_Q,    KC_W,    KC_E,         KC_R,         KC_T,                                    KC_Y,         KC_U,         KC_I,         KC_O,    KC_BSLS, KC_VOLD,
  //├─────────────┼────────┼────────┼─────────────┼─────────────┼─────────────┤                          ├─────────────┼─────────────┼─────────────┼────────┼────────┼──────────────┤
     KC_LSFT,      KC_A,    KC_S,    LCTL_T(KC_D), LGUI_T(KC_F), LALT_T(KC_G),                            LALT_T(KC_H), LGUI_T(KC_J), LCTL_T(KC_K), KC_L,    KC_P,    TO(4),
  //├─────────────┼────────┼────────┼─────────────┼─────────────┼─────────────┼────────┐        ┌────────┼─────────────┼─────────────┼─────────────┼────────┼────────┼──────────────┤
     LT(3,KC_ESC), KC_Z,    KC_X,    KC_C,         KC_V,         KC_B,         KC_ESC,           KC_BSPC, KC_N,         KC_M,         KC_COMM,      KC_DOT,  KC_SLSH, LT(2,KC_BSPC),
  //└─────────────┴────────┴────────┴─────────────┼────────┬────┴───┬─────────┼────────┘        └────────┼─────────┬───┴────┬────────┼─────────────┴────────┴────────┴──────────────┘
                                                   ALTW,    TL_LOWR, KC_SPC,                              KC_ENT,   KC_RSFT, KC_DEL
                                //                └────────┴────────┴─────────┘                          └─────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //                    ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
                         KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, ZOOMI,
  //                    ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                         ALTW,    _______, _______, _______, KC_DQUO, KC_QUOT,                            KC_QUES, KC_PPLS, KC_LBRC, KC_RBRC, _______, ZOOMO,
  //                    ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                         SCRSH,   _______, _______, KC_PIPE, KC_MINS, KC_COLN,                            KC_EQL,  KC_SCLN, KC_LCBR, KC_RCBR, _______, _______,
  //                    ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                         _______, _______, _______, _______, KC_UNDS, KC_BSPC, FULLS,            RSNAP,   _______, KC_TILD, KC_LT,   KC_GT,   KC_SLSH, _______,
  //                    └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                                        _______, _______, _______,                   _______, _______, _______
                                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE_LEFT] = LAYOUT(
  //                    ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
                         KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //                    ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                         _______, _______, MS_WHLL, MS_UP,   MS_WHLR, MS_WHLU,                            _______, _______, _______, _______, _______, _______,
  //                    ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                         _______, _______, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD,                            _______, _______, _______, _______, _______, _______,
  //                    ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                         _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, MS_BTN3, LHSNP,            RHSNP,   _______, _______, _______, _______, _______, _______,
  //                    └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                                        MS_BTN2, TO(0),   MS_BTN1,                   _______, TO(0),   _______
                                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE_RIGHT] = LAYOUT(
  //                    ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
                         KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //                    ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                         _______, _______, _______, _______, _______, _______,                            LINEB,   WORDP,   WORDN,   LINEE,   _______, _______,
  //                    ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                         _______, _______, _______, _______, _______, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP, _______,
  //                    ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                         _______, _______, _______, _______, _______, _______, LCSNP,            RCSNP,   _______, _______, KC_HOME, KC_END,  KC_PGDN, _______,
  //                    └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                                        _______, TO(0),   _______,                   _______, TO(0),   _______
                                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LAYER4] = LAYOUT(
  //                    ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
                         TO(0),   TO(0),   TO(0),   TO(0),   QK_BOOT, EE_CLR,                             EE_CLR,  QK_BOOT, TO(0),   TO(0),   TO(0),   TO(0),
  //                    ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                         TO(0),   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, TO(0),
  //                    ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                         _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //                    ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                         _______, RGB_RMOD,RGB_TOG, RGB_MOD, RGB_VAD, RGB_VAI, _______,          _______, _______, _______, _______, _______, _______, _______,
  //                    └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                                        TO(0),   TO(0),   _______,                   _______, TO(0),   _______
                                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

// tap hold decision mode for hold lt (2/backspace) - accept interrupt
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Immediately select the hold action when another key is pressed.
    case LT(2, KC_BSPC):
      return true;
    case LT(2, KC_DEL):
      return true;
    case LT(3, KC_ESC):
      return true;
    // Do not select the hold action when another key is pressed.
    default:
      return false;
  }
}

// permissive hold for mod tap
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Immediately select the hold action when another key is tapped.
    // case LCTL_T(KC_D):
    //   return true;
    case LGUI_T(KC_F):
      return true;
    case LGUI_T(KC_J):
      return true;
    // case LCTL_T(KC_K):
    //   return true;

    // Do not select the hold action when another key is tapped.
    default:
      return false;
  }
}

// macros
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case ALTW: // switch app
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_W))); // alt W
      }
      return false;
    case SCRSH: // macos screen shot (draw)
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_4))));
      }
      return false;
    case ZOOMI: // cmd + (zoom in)
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_EQL)));
      }
      return false;
    case ZOOMO: // cmd - (zoom out)
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_MINS)));
      }
      return false;
    case FULLS: // full screen (rect)
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_F))));
      }
      return false;
    case LSNAP: // snap left 2/3 (rect)
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LGUI(SS_LSFT(SS_TAP(X_LEFT)))));
      }
      return false;
    case RSNAP: // snap right 2/3 (rect)
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LGUI(SS_LSFT(SS_TAP(X_RGHT)))));
      }
      return false;
    case LHSNP: // left half snap (rect)
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_LEFT))));
      }
      return false;
    case RHSNP: // right half snap (rect)
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_RGHT))));
      }
      return false;
    case LCSNP: // left corner snap (rect)
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_LEFT))));
      }
      return false;
    case RCSNP: // right corner snap (rect)
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_RGHT))));
      }
      return false;
    case WORDP: // alt left (previous word)
      if (record->event.pressed) {
        SEND_STRING(SS_LOPT(SS_TAP(X_LEFT)));
      }
      return false;
    case WORDN: // alt right (next word)
      if (record->event.pressed) {
        SEND_STRING(SS_LOPT(SS_TAP(X_RGHT)));
      }
      return false;
    case LINEB: // cmd left (line begin)
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
      }
      return false;
    case LINEE: // cmd right (line end)
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_RGHT)));
      }
      return false;
  }
  return true;
}

// layer-based rgb
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  HSV l0 = {252, 55,  50}; // default layer - purple-ish
  HSV l1 = {240, 100, 100}; // blue
  HSV l2 = {40,  100, 100}; // orange
  HSV l3 = {40,  100, 100}; // orange
  HSV l4 = {120, 100, 100}; // green

  if (get_highest_layer(layer_state) > 0) {
    uint8_t layer = get_highest_layer(layer_state);

    // check which key has keymap defined and has associated led
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
      for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
        uint8_t index = g_led_config.matrix_co[row][col];

        if (
          index >= led_min && index < led_max && index != NO_LED &&
          keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS
        ) {
          HSV hsv = l0;
          switch (layer) {
            case 1:
              hsv = l1;
              hsv.v = rgb_matrix_get_val() + 20; // force brighter - not sure if ok
              break;
            case 2:
              hsv = l2;
              hsv.v = rgb_matrix_get_val() + 20; // force brighter - not sure if ok
              break;
            case 3:
              hsv = l3;
              hsv.v = rgb_matrix_get_val() + 20; // force brighter - not sure if ok
              break;
            case 4:
              hsv = l4;
              hsv.v = rgb_matrix_get_val() + 50; // force brighter - not sure if ok
              break;
            default:
              break;
          }
          RGB rgb = hsv_to_rgb(hsv);
          rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
        }
      }
    }
  } else { // default layer just display all
    for (uint8_t i = led_min; i < led_max; i++) {
      if (l0.v > rgb_matrix_get_val()) {
        l0.v = rgb_matrix_get_val(); // force brighter - not sure if ok
      }
      RGB r0 = hsv_to_rgb(l0);
      if (HAS_FLAGS(g_led_config.flags[i], 0x01)) { // 0x01 == LED_FLAG_MODIFIER
        rgb_matrix_set_color(i, r0.r, r0.g, r0.b);
      }
    }
  }
  return false;
}
