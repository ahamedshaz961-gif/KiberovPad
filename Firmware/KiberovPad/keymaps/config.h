#pragma once

// Encoder

#define ENCODER_A_PINS { GP21 }
#define ENCODER_B_PINS { GP20 }

// RGB

#define WS2812_DI_PIN GP10
#define RGBLIGHT_LED_COUNT 9

// OLED / I2C

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7