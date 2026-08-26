// before u look at the comments and say its ai generated , no , i wrote it ms cause idk C much and is new to QMK and needed commemts to edit they keys in the future
#include QMK_KEYBOARD_H // including the QMK library
#include "oled_animation.h" // including the oled animation library
enum layer_names // defining the layers
{
    _BASE,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = // giving vales to each key in the matrix
{
    [_BASE] = LAYOUT_3x3(
                        LCTL(LSFT(KC_TAB)), LCTL(KC_TAB),    LCTL(KC_C),
                        LALT(LSFT(KC_TAB)), LALT(KC_TAB),    LCTL(KC_V),
                        LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RGHT)), LCTL(KC_X)
                        )
};
#ifdef ENCODER_ENABLE // for encoder
bool encoder_update_user(uint8_t index, bool clockwise) 
{
    if (index == 0) 
    {
        if (clockwise) 
        {
            tap_code(KC_VOLU);
        } 
        else 
        {
            tap_code(KC_VOLD);
        }
    }
    return false;
}
#endif
#ifdef OLED_ENABLE // for oled
bool oled_task_user(void) 
{
    static uint8_t frame = 0;
    static uint32_t last_frame = 0;

    if (timer_elapsed32(last_frame) >= 100) {
        last_frame = timer_read32();

        oled_clear();
        oled_write_raw_P((const char *)epd_bitmap_allArray[frame], 512);

        frame++;

        if (frame >= epd_bitmap_allArray_LEN) {
            frame = 0;
        }
    }

    return false;
}
#endif