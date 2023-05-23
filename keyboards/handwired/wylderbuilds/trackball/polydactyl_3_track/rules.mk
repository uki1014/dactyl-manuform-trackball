# Board, Bootloader and MCU
MCU = RP2040
SPLIT_KEYBOARD = yes
BOOTLOADER = rp2040
SERIAL_DRIVER = vendor
RGBLIGHT_ENABLE = no
MOUSEKEY_ENABLE = yes
#CONSOLE_ENABLE = yes
OLED_ENABLE = yes
WPM_ENABLE = yes
EXTRAKEY_ENABLE = yes       # Audio control and System control
NKRO_ENABLE = yes           # Enable N-Key Rollover

OPT_DEFS += -DHAL_USE_I2C=TRUE