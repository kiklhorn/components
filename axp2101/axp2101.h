// LilyGo Watch S3 - https://github.com/Xinyuan-LilyGO/TTGO_TWatch_Library/blob/t-watch-s3/src/LilyGoLib.cpp
#ifndef __AXP2101_H__ //pokud mám již vloženo jednou tak celý kód vynechám
#define __AXP2101_H__
// co od externí komponenty chci? Pro začátek pouze inicializaci, tak jak jsem ji dělal v custom_component.cpp
// možná bych ji nyní měl nazvat jinak. Třeba twatch_s3_power
// ale počítám že časem bude univerzálnější - na vše co obsahuje čip AXP2101

//zkusím kód nechat strašně jednoduchý, prostě verze nula.
#define XPOWERS_CHIP_AXP2101
#define I2C_SDA (10)
#define I2C_SCL (11)

#include <stdint.h>
#include <cstddef>
#include <cstdio>
// #include "XPowersLib.h"
// budu pořebovat rodiče: 
#include "esphome/core/component.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
namespace axp2101 {


#define AXP2101_SLAVE_ADDRESS                            (0x34)

#define XPOWERS_AXP2101_CHIP_ID                          (0x4A)

#define XPOWERS_AXP2101_STATUS1                          (0x00)
#define XPOWERS_AXP2101_STATUS2                          (0x01)
#define XPOWERS_AXP2101_IC_TYPE                          (0x03)


#define XPOWERS_AXP2101_DATA_BUFFER1                     (0x04)
#define XPOWERS_AXP2101_DATA_BUFFER2                     (0x05)
#define XPOWERS_AXP2101_DATA_BUFFER3                     (0x06)
#define XPOWERS_AXP2101_DATA_BUFFER4                     (0x07)
#define XPOWERS_AXP2101_DATA_BUFFER_SIZE                 (4u)

#define XPOWERS_AXP2101_COMMON_CONFIG                    (0x10)
#define XPOWERS_AXP2101_BATFET_CTRL                      (0x12)
#define XPOWERS_AXP2101_DIE_TEMP_CTRL                    (0x13)
#define XPOWERS_AXP2101_MIN_SYS_VOL_CTRL                 (0x14)
#define XPOWERS_AXP2101_INPUT_VOL_LIMIT_CTRL             (0x15)
#define XPOWERS_AXP2101_INPUT_CUR_LIMIT_CTRL             (0x16)
#define XPOWERS_AXP2101_RESET_FUEL_GAUGE                 (0x17)
#define XPOWERS_AXP2101_CHARGE_GAUGE_WDT_CTRL            (0x18)


#define XPOWERS_AXP2101_WDT_CTRL                         (0x19)
#define XPOWERS_AXP2101_LOW_BAT_WARN_SET                 (0x1A)


#define XPOWERS_AXP2101_PWRON_STATUS                     (0x20)
#define XPOWERS_AXP2101_PWROFF_STATUS                    (0x21)
#define XPOWERS_AXP2101_PWROFF_EN                        (0x22)
#define XPOWERS_AXP2101_DC_OVP_UVP_CTRL                  (0x23)
#define XPOWERS_AXP2101_VOFF_SET                         (0x24)
#define XPOWERS_AXP2101_PWROK_SEQU_CTRL                  (0x25)
#define XPOWERS_AXP2101_SLEEP_WAKEUP_CTRL                (0x26)
#define XPOWERS_AXP2101_IRQ_OFF_ON_LEVEL_CTRL            (0x27)

#define XPOWERS_AXP2101_FAST_PWRON_SET0                  (0x28)
#define XPOWERS_AXP2101_FAST_PWRON_SET1                  (0x29)
#define XPOWERS_AXP2101_FAST_PWRON_SET2                  (0x2A)
#define XPOWERS_AXP2101_FAST_PWRON_CTRL                  (0x2B)

#define XPOWERS_AXP2101_ADC_CHANNEL_CTRL                 (0x30)
#define XPOWERS_AXP2101_ADC_DATA_RELUST0                 (0x34)
#define XPOWERS_AXP2101_ADC_DATA_RELUST1                 (0x35)
#define XPOWERS_AXP2101_ADC_DATA_RELUST2                 (0x36)
#define XPOWERS_AXP2101_ADC_DATA_RELUST3                 (0x37)
#define XPOWERS_AXP2101_ADC_DATA_RELUST4                 (0x38)
#define XPOWERS_AXP2101_ADC_DATA_RELUST5                 (0x39)
#define XPOWERS_AXP2101_ADC_DATA_RELUST6                 (0x3A)
#define XPOWERS_AXP2101_ADC_DATA_RELUST7                 (0x3B)
#define XPOWERS_AXP2101_ADC_DATA_RELUST8                 (0x3C)
#define XPOWERS_AXP2101_ADC_DATA_RELUST9                 (0x3D)


//XPOWERS INTERRUPT REGISTER
#define XPOWERS_AXP2101_INTEN1                           (0x40)
#define XPOWERS_AXP2101_INTEN2                           (0x41)
#define XPOWERS_AXP2101_INTEN3                           (0x42)


//XPOWERS INTERRUPT STATUS REGISTER
#define XPOWERS_AXP2101_INTSTS1                          (0x48)
#define XPOWERS_AXP2101_INTSTS2                          (0x49)
#define XPOWERS_AXP2101_INTSTS3                          (0x4A)
#define XPOWERS_AXP2101_INTSTS_CNT                       (3u)

#define XPOWERS_AXP2101_TS_PIN_CTRL                      (0x50)
#define XPOWERS_AXP2101_TS_HYSL2H_SET                    (0x52)
#define XPOWERS_AXP2101_TS_LYSL2H_SET                    (0x53)


#define XPOWERS_AXP2101_VLTF_CHG_SET                     (0x54)
#define XPOWERS_AXP2101_VHLTF_CHG_SET                    (0x55)
#define XPOWERS_AXP2101_VLTF_WORK_SET                    (0x56)
#define XPOWERS_AXP2101_VHLTF_WORK_SET                   (0x57)


#define XPOWERS_AXP2101_JIETA_EN_CTRL                    (0x58)
#define XPOWERS_AXP2101_JIETA_SET0                       (0x59)
#define XPOWERS_AXP2101_JIETA_SET1                       (0x5A)
#define XPOWERS_AXP2101_JIETA_SET2                       (0x5B)


#define XPOWERS_AXP2101_IPRECHG_SET                      (0x61)
#define XPOWERS_AXP2101_ICC_CHG_SET                      (0x62)
#define XPOWERS_AXP2101_ITERM_CHG_SET_CTRL               (0x63)

#define XPOWERS_AXP2101_CV_CHG_VOL_SET                   (0x64)

#define XPOWERS_AXP2101_THE_REGU_THRES_SET               (0x65)
#define XPOWERS_AXP2101_CHG_TIMEOUT_SET_CTRL             (0x67)

#define XPOWERS_AXP2101_BAT_DET_CTRL                     (0x68)
#define XPOWERS_AXP2101_CHGLED_SET_CTRL                  (0x69)

#define XPOWERS_AXP2101_BTN_VOL_MIN                      (2600)
#define XPOWERS_AXP2101_BTN_VOL_MAX                      (3300)
#define XPOWERS_AXP2101_BTN_VOL_STEPS                    (100)


#define XPOWERS_AXP2101_BTN_BAT_CHG_VOL_SET              (0x6A)


#define XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL                (0x80)
#define XPOWERS_AXP2101_DC_FORCE_PWM_CTRL                (0x81)
#define XPOWERS_AXP2101_DC_VOL0_CTRL                     (0x82)
#define XPOWERS_AXP2101_DC_VOL1_CTRL                     (0x83)
#define XPOWERS_AXP2101_DC_VOL2_CTRL                     (0x84)
#define XPOWERS_AXP2101_DC_VOL3_CTRL                     (0x85)
#define XPOWERS_AXP2101_DC_VOL4_CTRL                     (0x86)


#define XPOWERS_AXP2101_LDO_ONOFF_CTRL0                  (0x90)
#define XPOWERS_AXP2101_LDO_ONOFF_CTRL1                  (0x91)
#define XPOWERS_AXP2101_LDO_VOL0_CTRL                    (0x92)
#define XPOWERS_AXP2101_LDO_VOL1_CTRL                    (0x93)
#define XPOWERS_AXP2101_LDO_VOL2_CTRL                    (0x94)
#define XPOWERS_AXP2101_LDO_VOL3_CTRL                    (0x95)
#define XPOWERS_AXP2101_LDO_VOL4_CTRL                    (0x96)
#define XPOWERS_AXP2101_LDO_VOL5_CTRL                    (0x97)
#define XPOWERS_AXP2101_LDO_VOL6_CTRL                    (0x98)
#define XPOWERS_AXP2101_LDO_VOL7_CTRL                    (0x99)
#define XPOWERS_AXP2101_LDO_VOL8_CTRL                    (0x9A)


#define XPOWERS_AXP2101_BAT_PARAME                       (0xA1)
#define XPOWERS_AXP2101_FUEL_GAUGE_CTRL                  (0xA2)
#define XPOWERS_AXP2101_BAT_PERCENT_DATA                 (0xA4)

// DCDC 1~5
#define XPOWERS_AXP2101_DCDC1_VOL_MIN                    (1500)
#define XPOWERS_AXP2101_DCDC1_VOL_MAX                    (3400)
#define XPOWERS_AXP2101_DCDC1_VOL_STEPS                  (100u)

#define XPOWERS_AXP2101_DCDC2_VOL1_MIN                  (500u)
#define XPOWERS_AXP2101_DCDC2_VOL1_MAX                  (1200u)
#define XPOWERS_AXP2101_DCDC2_VOL2_MIN                  (1220u)
#define XPOWERS_AXP2101_DCDC2_VOL2_MAX                  (1540u)

#define XPOWERS_AXP2101_DCDC2_VOL_STEPS1                 (10u)
#define XPOWERS_AXP2101_DCDC2_VOL_STEPS2                 (20u)

#define XPOWERS_AXP2101_DCDC2_VOL_STEPS1_BASE            (0u)
#define XPOWERS_AXP2101_DCDC2_VOL_STEPS2_BASE            (71u)


#define XPOWERS_AXP2101_DCDC3_VOL1_MIN                  (500u)
#define XPOWERS_AXP2101_DCDC3_VOL1_MAX                  (1200u)
#define XPOWERS_AXP2101_DCDC3_VOL2_MIN                  (1220u)
#define XPOWERS_AXP2101_DCDC3_VOL2_MAX                  (1540u)
#define XPOWERS_AXP2101_DCDC3_VOL3_MIN                  (1600u)
#define XPOWERS_AXP2101_DCDC3_VOL3_MAX                  (3400u)

#define XPOWERS_AXP2101_DCDC3_VOL_MIN                    (500)
#define XPOWERS_AXP2101_DCDC3_VOL_MAX                    (3400)

#define XPOWERS_AXP2101_DCDC3_VOL_STEPS1                 (10u)
#define XPOWERS_AXP2101_DCDC3_VOL_STEPS2                 (20u)
#define XPOWERS_AXP2101_DCDC3_VOL_STEPS3                 (100u)

#define XPOWERS_AXP2101_DCDC3_VOL_STEPS1_BASE            (0u)
#define XPOWERS_AXP2101_DCDC3_VOL_STEPS2_BASE            (71u)
#define XPOWERS_AXP2101_DCDC3_VOL_STEPS3_BASE            (88u)



#define XPOWERS_AXP2101_DCDC4_VOL1_MIN                  (500u)
#define XPOWERS_AXP2101_DCDC4_VOL1_MAX                  (1200u)
#define XPOWERS_AXP2101_DCDC4_VOL2_MIN                  (1220u)
#define XPOWERS_AXP2101_DCDC4_VOL2_MAX                  (1840u)

#define XPOWERS_AXP2101_DCDC4_VOL_STEPS1                 (10u)
#define XPOWERS_AXP2101_DCDC4_VOL_STEPS2                 (20u)

#define XPOWERS_AXP2101_DCDC4_VOL_STEPS1_BASE            (0u)
#define XPOWERS_AXP2101_DCDC4_VOL_STEPS2_BASE            (71u)



#define XPOWERS_AXP2101_DCDC5_VOL_1200MV                 (1200)
#define XPOWERS_AXP2101_DCDC5_VOL_VAL                    (0x19)
#define XPOWERS_AXP2101_DCDC5_VOL_MIN                    (1400)
#define XPOWERS_AXP2101_DCDC5_VOL_MAX                    (3700)
#define XPOWERS_AXP2101_DCDC5_VOL_STEPS                  (100u)

#define XPOWERS_AXP2101_VSYS_VOL_THRESHOLD_MIN          (2600)
#define XPOWERS_AXP2101_VSYS_VOL_THRESHOLD_MAX          (3300)
#define XPOWERS_AXP2101_VSYS_VOL_THRESHOLD_STEPS        (100)

// ALDO 1~4

#define XPOWERS_AXP2101_ALDO1_VOL_MIN                    (500)
#define XPOWERS_AXP2101_ALDO1_VOL_MAX                    (3500)
#define XPOWERS_AXP2101_ALDO1_VOL_STEPS                  (100u)

#define XPOWERS_AXP2101_ALDO2_VOL_MIN                    (500)
#define XPOWERS_AXP2101_ALDO2_VOL_MAX                    (3500)
#define XPOWERS_AXP2101_ALDO2_VOL_STEPS                  (100u)


#define XPOWERS_AXP2101_ALDO3_VOL_MIN                    (500)
#define XPOWERS_AXP2101_ALDO3_VOL_MAX                    (3500)
#define XPOWERS_AXP2101_ALDO3_VOL_STEPS                  (100u)


#define XPOWERS_AXP2101_ALDO4_VOL_MIN                    (500)
#define XPOWERS_AXP2101_ALDO4_VOL_MAX                    (3500)
#define XPOWERS_AXP2101_ALDO4_VOL_STEPS                  (100u)

// BLDO 1~2

#define XPOWERS_AXP2101_BLDO1_VOL_MIN                    (500)
#define XPOWERS_AXP2101_BLDO1_VOL_MAX                    (3500)
#define XPOWERS_AXP2101_BLDO1_VOL_STEPS                  (100u)

#define XPOWERS_AXP2101_BLDO2_VOL_MIN                    (500)
#define XPOWERS_AXP2101_BLDO2_VOL_MAX                    (3500)
#define XPOWERS_AXP2101_BLDO2_VOL_STEPS                  (100u)

// CPUSLDO

#define XPOWERS_AXP2101_CPUSLDO_VOL_MIN                  (500)
#define XPOWERS_AXP2101_CPUSLDO_VOL_MAX                  (1400)
#define XPOWERS_AXP2101_CPUSLDO_VOL_STEPS                (50)


// DLDO 1~2
#define XPOWERS_AXP2101_DLDO1_VOL_MIN                  (500)
#define XPOWERS_AXP2101_DLDO1_VOL_MAX                  (3400)
#define XPOWERS_AXP2101_DLDO1_VOL_STEPS                (100u)

#define XPOWERS_AXP2101_DLDO2_VOL_MIN                  (500)
#define XPOWERS_AXP2101_DLDO2_VOL_MAX                  (3400)
#define XPOWERS_AXP2101_DLDO2_VOL_STEPS                (100u)


#define XPOWERS_AXP2101_CONVERSION(raw)                 (22.0 + (7274 - raw) / 20.0)


// https://github.com/lewisxhe/XPowersLib/blob/master/src/XPowersParams.hpp

#define _BV(b)                          (1ULL << (uint64_t)(b))

/**
 * @brief PMU PEKEY Press off time parameters.
 */
typedef enum __xpowers_press_off_time {
    XPOWERS_POWEROFF_4S,
    XPOWERS_POWEROFF_6S,
    XPOWERS_POWEROFF_8S,
    XPOWERS_POWEROFF_10S,
} xpowers_press_off_time_t;

/**
 * @brief PMU PEKEY Press on time parameters.
 */
typedef enum __xpowers_press_on_time {
    XPOWERS_POWERON_128MS,
    XPOWERS_POWERON_512MS,
    XPOWERS_POWERON_1S,
    XPOWERS_POWERON_2S,
} xpowers_press_on_time_t;


/**
 * @brief Charging led mode parameters.
 */
typedef enum __xpowers_chg_led_mode {
    XPOWERS_CHG_LED_OFF,
    XPOWERS_CHG_LED_BLINK_1HZ,
    XPOWERS_CHG_LED_BLINK_4HZ,
    XPOWERS_CHG_LED_ON,
    XPOWERS_CHG_LED_CTRL_CHG,    // The charging indicator is controlled by the charger
} xpowers_chg_led_mode_t;

/**
 * @brief axp2101 charge target voltage parameters.
 */
typedef enum __xpowers_axp2101_chg_vol {
    XPOWERS_AXP2101_CHG_VOL_4V = 1,
    XPOWERS_AXP2101_CHG_VOL_4V1,
    XPOWERS_AXP2101_CHG_VOL_4V2,
    XPOWERS_AXP2101_CHG_VOL_4V35,
    XPOWERS_AXP2101_CHG_VOL_4V4,
    XPOWERS_AXP2101_CHG_VOL_MAX
} xpowers_axp2101_chg_vol_t;

/**
 * @brief axp2101 charge currnet voltage parameters.
 */
typedef enum __xpowers_axp2101_chg_curr {
    XPOWERS_AXP2101_CHG_CUR_0MA,
    XPOWERS_AXP2101_CHG_CUR_100MA = 4,
    XPOWERS_AXP2101_CHG_CUR_125MA,
    XPOWERS_AXP2101_CHG_CUR_150MA,
    XPOWERS_AXP2101_CHG_CUR_175MA,
    XPOWERS_AXP2101_CHG_CUR_200MA,
    XPOWERS_AXP2101_CHG_CUR_300MA,
    XPOWERS_AXP2101_CHG_CUR_400MA,
    XPOWERS_AXP2101_CHG_CUR_500MA,
    XPOWERS_AXP2101_CHG_CUR_600MA,
    XPOWERS_AXP2101_CHG_CUR_700MA,
    XPOWERS_AXP2101_CHG_CUR_800MA,
    XPOWERS_AXP2101_CHG_CUR_900MA,
    XPOWERS_AXP2101_CHG_CUR_1000MA,
} xpowers_axp2101_chg_curr_t;


/**
 * @brief axp2101 vbus currnet limit parameters.
 */
typedef enum {
    XPOWERS_AXP2101_VBUS_CUR_LIM_100MA,
    XPOWERS_AXP2101_VBUS_CUR_LIM_500MA,
    XPOWERS_AXP2101_VBUS_CUR_LIM_900MA,
    XPOWERS_AXP2101_VBUS_CUR_LIM_1000MA,
    XPOWERS_AXP2101_VBUS_CUR_LIM_1500MA,
    XPOWERS_AXP2101_VBUS_CUR_LIM_2000MA,
} xpowers_axp2101_vbus_cur_limit_t;

/**
 * @brief XPowersLibInterface interrupt control mask parameters.
 *          Common interrupt interfaces
 * @Example: enableInterrupt(XPOWERS_USB_INSERT_INT|XPOWERS_USB_REMOVE_INT);
 *           disableInterrupt(XPOWERS_CHARGE_START_INT|XPOWERS_PWR_BTN_CLICK_INT);
 */
typedef enum __xpowers_interrupt_enum {
    XPOWERS_USB_INSERT_INT          = _BV(0),
    XPOWERS_USB_REMOVE_INT          = _BV(1),
    XPOWERS_BATTERY_INSERT_INT      = _BV(2),
    XPOWERS_BATTERY_REMOVE_INT      = _BV(3),
    XPOWERS_CHARGE_START_INT        = _BV(4),
    XPOWERS_CHARGE_DONE_INT         = _BV(5),
    XPOWERS_PWR_BTN_CLICK_INT       = _BV(6),
    XPOWERS_PWR_BTN_LONGPRESSED_INT = _BV(7),
    XPOWERS_ALL_INT                 = _BV(8),
} xpowers_interrupt_enum_t;


/**
 * @brief axp2101 interrupt control mask parameters.
 */
typedef enum __xpowers_axp2101_irq {
    //! IRQ1 REG 40H
    XPOWERS_AXP2101_BAT_NOR_UNDER_TEMP_IRQ   = _BV(0),   // Battery Under Temperature in Work
    XPOWERS_AXP2101_BAT_NOR_OVER_TEMP_IRQ    = _BV(1),   // Battery Over Temperature in Work mode
    XPOWERS_AXP2101_BAT_CHG_UNDER_TEMP_IRQ   = _BV(2),   // Battery Under Temperature in Charge mode IRQ(bcut_irq)
    XPOWERS_AXP2101_BAT_CHG_OVER_TEMP_IRQ    = _BV(3),   // Battery Over Temperature in Charge mode IRQ(bcot_irq) enable
    XPOWERS_AXP2101_GAUGE_NEW_SOC_IRQ        = _BV(4),   // Gauge New SOC IRQ(lowsoc_irq) enable ???
    XPOWERS_AXP2101_WDT_TIMEOUT_IRQ          = _BV(5),   // Gauge Watchdog Timeout IRQ(gwdt_irq) enable
    XPOWERS_AXP2101_WARNING_LEVEL1_IRQ       = _BV(6),   // SOC drop to Warning Level1 IRQ(socwl1_irq) enable
    XPOWERS_AXP2101_WARNING_LEVEL2_IRQ       = _BV(7),   // SOC drop to Warning Level2 IRQ(socwl2_irq) enable

    //! IRQ2 REG 41H
    XPOWERS_AXP2101_PKEY_POSITIVE_IRQ        = _BV(8),   // POWERON Positive Edge IRQ(ponpe_irq_en) enable
    XPOWERS_AXP2101_PKEY_NEGATIVE_IRQ        = _BV(9),   // POWERON Negative Edge IRQ(ponne_irq_en) enable
    XPOWERS_AXP2101_PKEY_LONG_IRQ            = _BV(10),  // POWERON Long PRESS IRQ(ponlp_irq) enable
    XPOWERS_AXP2101_PKEY_SHORT_IRQ           = _BV(11),  // POWERON Short PRESS IRQ(ponsp_irq_en) enable
    XPOWERS_AXP2101_BAT_REMOVE_IRQ           = _BV(12),  // Battery Remove IRQ(bremove_irq) enable
    XPOWERS_AXP2101_BAT_INSERT_IRQ           = _BV(13),  // Battery Insert IRQ(binsert_irq) enabl
    XPOWERS_AXP2101_VBUS_REMOVE_IRQ          = _BV(14),  // VBUS Remove IRQ(vremove_irq) enabl
    XPOWERS_AXP2101_VBUS_INSERT_IRQ          = _BV(15),  // VBUS Insert IRQ(vinsert_irq) enable

    //! IRQ3 REG 42H
    XPOWERS_AXP2101_BAT_OVER_VOL_IRQ         = _BV(16),  // Battery Over Voltage Protection IRQ(bovp_irq) enable
    XPOWERS_AXP2101_CHAGER_TIMER_IRQ         = _BV(17),  // Charger Safety Timer1/2 expire IRQ(chgte_irq) enable
    XPOWERS_AXP2101_DIE_OVER_TEMP_IRQ        = _BV(18),  // DIE Over Temperature level1 IRQ(dotl1_irq) enable
    XPOWERS_AXP2101_BAT_CHG_START_IRQ        = _BV(19),  // Charger start IRQ(chgst_irq) enable
    XPOWERS_AXP2101_BAT_CHG_DONE_IRQ         = _BV(20),  // Battery charge done IRQ(chgdn_irq) enable
    XPOWERS_AXP2101_BATFET_OVER_CURR_IRQ     = _BV(21),  // BATFET Over Current Protection IRQ(bocp_irq) enable
    XPOWERS_AXP2101_LDO_OVER_CURR_IRQ        = _BV(22),  // LDO Over Current IRQ(ldooc_irq) enable
    XPOWERS_AXP2101_WDT_EXPIRE_IRQ           = _BV(23),  // Watchdog Expire IRQ(wdexp_irq) enable

    XPOWERS_AXP2101_ALL_IRQ                  = (0xFFFFFFFFUL)
} xpowers_axp2101_irq_t;

// https://github.com/lewisxhe/XPowersLib/blob/master/src/XPowersLibInterface.hpp

/*
| CHIP       | AXP173            | AXP192            | AXP202            | AXP2101                                |
| ---------- | ----------------- | ----------------- | ----------------- | -------------------------------------- |
| DC1        | 0.7V-3.5V /1.2A   | 0.7V-3.5V  /1.2A  | X                 | 1.5-3.4V                        /2A    |
| DC2        | 0.7-2.275V/0.6A   | 0.7-2.275V /1.6A  | 0.7-2.275V /1.6A  | 0.5-1.2V,1.22-1.54V             /2A    |
| DC3        | X                 | 0.7-3.5V   /0.7A  | 0.7-3.5V   /1.2A  | 0.5-1.2V,1.22-1.54V,1.6-3.4V    /2A    |
| DC4        | X                 | x                 | x                 | 0.5-1.2V,1.22-1.84V             /1.5A   |
| DC5        | X                 | x                 | x                 | 1.2V,1.4-3.7V                   /1A    |
| LDO1(VRTC) | 3.3V       /30mA  | 3.3V       /30mA  | 3.3V       /30mA  | 1.8V                            /30mA  |
| LDO2       | 1.8V-3.3V  /200mA | 1.8V-3.3V  /200mA | 1.8V-3.3V  /200mA | x                                      |
| LDO3       | 1.8V-3.3V  /200mA | 1.8-3.3V   /200mA | 0.7-3.5V   /200mA | x                                      |
| LDO4       | 0.7-3.5V   /500mA | X                 | 1.8V-3.3V  /200mA | x                                      |
| LDO5/IO0   | X                 | 1.8-3.3V   /50mA  | 1.8-3.3V   /50mA  | x                                      |
| ALDO1      | x                 | x                 | x                 | 0.5-3.5V                        /300mA |
| ALDO2      | x                 | x                 | x                 | 0.5-3.5V                        /300mA |
| ALDO3      | x                 | x                 | x                 | 0.5-3.5V                        /300mA |
| ALDO4      | x                 | x                 | x                 | 0.5-3.5V                        /300mA |
| BLDO1      | x                 | x                 | x                 | 0.5-3.5V                        /300mA |
| BLDO2      | x                 | x                 | x                 | 0.5-3.5V                        /300mA |
| DLDO1      | x                 | x                 | x                 | 0.5-3.3V/ 0.5-1.4V              /300mA |
| DLDO1      | x                 | x                 | x                 | 0.5-3.3V/ 0.5-1.4V              /300mA |
| CPUSLDO    | x                 | x                 | x                 | 0.5-1.4V                        /30mA  |
|            |                   |                   |                   |                                        |
*/



// @brief Each chip resource is different,please refer to the table above
typedef enum __XPowersPowerChannel {

    XPOWERS_DCDC1,
    XPOWERS_DCDC2,
    XPOWERS_DCDC3,
    XPOWERS_DCDC4,
    XPOWERS_DCDC5,

    XPOWERS_LDO1,
    XPOWERS_LDO2,
    XPOWERS_LDO3,
    XPOWERS_LDO4,
    XPOWERS_LDO5,

    XPOWERS_LDOIO,

    XPOWERS_ALDO1,
    XPOWERS_ALDO2,
    XPOWERS_ALDO3,
    XPOWERS_ALDO4,

    XPOWERS_BLDO1,
    XPOWERS_BLDO2,

    XPOWERS_DLDO1,
    XPOWERS_DLDO2,

    XPOWERS_VBACKUP,

    XPOWERS_CPULDO,

} XPowersPowerChannel_t;

// @brief Chip type
typedef enum __XPowersChipModel {
    XPOWERS_AXP173,
    XPOWERS_AXP192,
    XPOWERS_AXP202,
    XPOWERS_AXP216,
    XPOWERS_AXP2101,
    XPOWERS_UNDEFINED,
} XPowersChipModel_t;


/**
 * @brief  Compatible with subclasses of the Meshtastic-devic project
 */
class HasBatteryLevel
{
public:
    /**
    * @brief  Get battery percentage
    * @retval 0~100% , -1 no battery is connected
    */
    virtual int getBatteryPercent()
    {
        return -1;
    }

    /**
    * @brief  Get battery Voltage
    * @retval Voltage unit: millivolt , 0 is no battery is connected
    */
    virtual uint16_t getBattVoltage()
    {
        return 0;
    }

    /**
     * @brief Query whether the current battery is connected
     * @retval true to access,false to not access
     */
    virtual bool isBatteryConnect()
    {
        return false;
    }

    /**
     * @brief Query whether the current USB is connected
     * @retval true to access,false to not access
     */
    virtual bool isVbusIn()
    {
        return false;
    }

    /**
    * @brief Query whether it is currently in charging state
    * @retval true to charge,false to not charge
    */
    virtual bool isCharging()
    {
        return false;
    }
};

// @brief Power resource interface class
class XPowersLibInterface : public HasBatteryLevel
{
public:

    XPowersLibInterface() : __chipModel(XPOWERS_UNDEFINED), __protectedMask(0) {};

    virtual ~XPowersLibInterface() {}

    /**
     * @brief  Calling the XPowersLibInterface interface class
     *         requires calling init for initialization
     * @retval
     */
    virtual bool init() = 0;

    /**
     * @brief  When calling the XPowersLibInterface interface class,
     *         calling deinit releases the Wire handle
     * @retval None
     */
    virtual void deinit() = 0;


    /**
     * @brief  Set the PMU sleep flag,
     *         need to manually close the power channel after setting
     * @retval true success false failed
     */
    virtual bool enableSleep() = 0;


    /**
     * @brief  Set shutdown, calling shutdown will turn off all power channels,
     *         only VRTC belongs to normal power supply
     * @retval None
     */
    virtual void shutdown() = 0;


    /**
     * @brief Get PMU satatus register
     * @note
     * @retval register value
     */
    virtual uint16_t status() = 0;


    /**
     * @brief Query chip ID
     * @retval  Chip ID
     */
    virtual uint8_t getChipID() = 0;

    //Status function
    /**
    * @brief Query whether it is currently in charging state
    * @retval true to charge,false to not charge
    */
    // virtual bool isCharging() = 0;

    /**
     * @brief Query whether the current USB is connected
     * @retval true to access,false to not access
     */
    // virtual bool isVbusIn() = 0;

    /**
     * @brief Query whether the current battery is connected
     * @retval true to access,false to not access
     */
    // virtual bool isBatteryConnect() = 0;

    /**
     * @brief Query whether the current is in the discharge state
     * @retval true the battery is discharged,false is not discharged
     */
    virtual bool isDischarge() = 0;

    //Power Channel Control

    /**
     * @brief  Turn on the power channel
     * @param  channel: Parameters See XPowersPowerChannel_t enumeration
     * @retval true success false failed
     */
    virtual bool enablePowerOutput(uint8_t channel) = 0;

    /**
     * @brief  Turn off the power channel
     * @param  channel: Parameters See XPowersPowerChannel_t enumeration
     * @retval true success false failed
     */
    virtual bool disablePowerOutput(uint8_t channel) = 0;

    /**
     * @brief  Get whether the power channel is enabled
     * @param  channel: Parameters See XPowersPowerChannel_t enumeration
     * @retval true success false failed
     */
    virtual bool isPowerChannelEnable(uint8_t channel) = 0;

    /**
     * @brief  Get the set voltage of the power channel
     * @param  channel: Parameters See XPowersPowerChannel_t enumeration
     * @retval true success false failed
     */
    virtual uint16_t getPowerChannelVoltage(uint8_t channel) = 0;

    /**
     * @brief  Set the output voltage of a channel power supply
     * @param  channel: Parameters See XPowersPowerChannel_t enumeration
     * @retval true success false failed
     */
    virtual bool setPowerChannelVoltage(uint8_t channel, uint16_t millivolt) = 0;

    /**
     * @brief  Set a channel power protection,after setting this channel
     *         will not be able to be set and closed
     * @param  channel: Parameters See XPowersPowerChannel_t enumeration
     */
    virtual void setProtectedChannel(uint8_t channel);

    /**
     * @brief  Unprotect the channel, call this to unprotect the channel lock
     * @param  channel: Parameters See XPowersPowerChannel_t enumeration
     */
    virtual void setUnprotectChannel(uint8_t channel);

    /**
     * * @brief  Get whether a channel power supply has been protected
     * @param  channel: Parameters See XPowersPowerChannel_t enumeration
     * @retval true is set,false is not set
     */
    virtual bool getProtectedChannel(uint8_t channel);


    /**
     * @brief  Query whether the PMU input parameter channel is valid
     * @param  channel: Parameters See XPowersPowerChannel_t enumeration
     * @retval true valid false invalid
     */
    virtual bool isChannelAvailable(uint8_t channel);


    //battery
    /**
    * @brief  Get battery Voltage
    * @retval Voltage unit: millivolt , 0 is no battery is connected
    */
    // virtual uint16_t getBattVoltage() = 0;

    /**
    * @brief  Get battery percentage
    * @retval 0~100% , -1 no battery is connected
    */
    // virtual int getBatteryPercent(void);

    // Vbus
    /**
    * @brief  Get PMU VBUS/USB Voltage
    * @retval Voltage unit: millivolt , 0 is no vbus is connected
    */
    virtual uint16_t getVbusVoltage();


    /**
     * @brief  Set VBUS Current Input Limit.
     * @param  opt: View the related chip type xpowers_axpxxx_vbus_cur_limit_t enumeration
     *              parameters in "XPowersParams.hpp"
     * @retval true valid false invalid
     */
    virtual bool setVbusCurrentLimit(uint8_t opt) = 0;

    /**
    * @brief  Get VBUS Current Input Limit.
    * @retval View the related chip type xpowers_axpxxx_vbus_cur_limit_t enumeration
    *              parameters in "XPowersParams.hpp"
    */
    virtual uint8_t getVbusCurrentLimit(void) = 0;


    // SYS
    /**
    * @brief  Get PMU SYS main Voltage
    * @retval Voltage unit: millivolt
    */
    virtual uint16_t getSystemVoltage() = 0;

    /**
     * @brief  Set PMU Low Voltage Shutdown Threshold
     * @param  millivolt: 2600mV ~ 3300mV
     * @retval true valid false invalid
     */
    virtual bool setSysPowerDownVoltage(uint16_t millivolt) = 0;

    /**
     * @brief  Get PMU Low Voltage Shutdown Threshold
     * @retval Voltage unit: millivolt
     */
    virtual uint16_t getSysPowerDownVoltage() = 0;

    /**
     * @brief  Set charge target voltage.
     * @param  opt: View the related chip type xpowers_axpxxx_chg_vol_t enumeration
     *              parameters in "XPowersParams.hpp"
     * @retval true valid false invalid
     */
    virtual bool setChargeTargetVoltage(uint8_t opt) = 0;

    /**
     * @brief  Get charge target voltage.
     * @retval View the related chip type xpowers_axpxxx_chg_vol_t enumeration
     *         parameters in "XPowersParams.hpp"
     *   parameters in "XPowersParams.hpp"
     */
    virtual uint8_t getChargeTargetVoltage() = 0;

    /**
     * @brief  Set charge current.
     * @param  opt: View the related chip type xpowers_axpxxx_chg_curr_t enumeration
     *              parameters in "XPowersParams.hpp"
     * @retval true valid false invalid
     */
    virtual bool setChargerConstantCurr(uint8_t opt) = 0;

    /**
     * @brief  Get charge current.
     * @retval View the related chip type xpowers_axpxxx_chg_curr_t enumeration
     *         parameters in "XPowersParams.hpp"
     */
    virtual uint8_t getChargerConstantCurr() = 0;


    //!PMU Interrupt control
    /*
     *  Example of interrupt usage
     *  if (pmuInterrupt) {
     *      pmuInterrupt = false;
     *
     *      Read interrupt status
     *      uint64_t mask =  PMU->getIrqStatus();
     *      Serial.print("IRQ Mask:0b");
     *      Serial.println(mask,BIN);
     *
     *      if (PMU->isPekeyShortPressIrq()) {
     *          Serial.println("isPekeyShortPressIrq");
     *      }
     *      if (PMU->isBatChagerStartIrq()) {
     *          Serial.println("isBatChagerStart");
     *      }
     *      ......
     *
     *      After reading the interrupt status,you need to manually clear the status register
     *      PMU->clearIrqStatus();
     *  }
     * * * */


    /**
    * @brief  Get the interrupt controller mask value.
    * @retval   Mask value corresponds to xpowers_axpxxx_irq_t ,
    */
    virtual uint64_t getIrqStatus() = 0;


    /**
     * @brief  Clear interrupt controller state.
     */
    virtual void clearIrqStatus() = 0;

    /**
     * @brief  Eanble PMU interrupt control mask .
     * @param  opt: View the related chip type xpowers_axpxxx_irq_t enumeration
     *              parameters in "XPowersParams.hpp"
     * @retval true valid false invalid
     */
    virtual bool enableIRQ(uint64_t opt) = 0;

    /**
     * @brief  Disable PMU interrupt control mask .
     * @param  opt: View the related chip type xpowers_axpxxx_irq_t enumeration
     *              parameters in "XPowersParams.hpp"
     * @retval true valid false invalid
     */
    virtual bool disableIRQ(uint64_t opt) = 0;

    /**
     * @brief   .
     * @param  opt: View the related chip type xpowers_interrupt_enum_t enumeration
     *              parameters in "XPowersParams.hpp"
     * @retval true valid false invalid
     */
    bool enableInterrupt(uint32_t opt);

    /**
     * @brief   .
     * @param  opt: View the related chip type xpowers_interrupt_enum_t enumeration
     *              parameters in "XPowersParams.hpp"
     * @retval true valid false invalid
     */
    bool disableInterrupt(uint32_t opt);

    /**
     * @brief   .
     * @param  opt: View the related chip type xpowers_interrupt_enum_t enumeration
     *              parameters in "XPowersParams.hpp"
     * @retval true valid false invalid
     */
    bool setInterruptMask(uint32_t option, bool enable);

    /**
     * @brief  Interrupt response when PMU PEKEY is short pressed
     * @retval true valid false invalid
     */
    virtual bool isPekeyShortPressIrq() = 0;

    /**
     * @brief  Interrupt response when PMU PEKEY is long pressed
     * @retval true valid false invalid
     */
    virtual bool isPekeyLongPressIrq() = 0;

    /**
     * @brief  Interrupt response when PMU battery is connected
     * @retval true valid false invalid
     */
    virtual bool isBatInsertIrq() = 0;

    /**
     * @brief  Interrupt response when PMU battery is removed
     * @retval true valid false invalid
     */
    virtual bool isBatRemoveIrq() = 0;

    /**
     * @brief  Interrupt response when PMU USB is plugged in
     * @retval true valid false invalid
     */
    virtual bool isVbusInsertIrq() = 0;

    /**
     * @brief  Interrupt response when PMU USB is removed
     * @retval true valid false invalid
     */
    virtual bool isVbusRemoveIrq() = 0;

    /**
     * @brief  Interrupt response when PMU charging is complete
     * @retval true valid false invalid
     */
    virtual bool isBatChagerDoneIrq() = 0;

    /**
     * @brief  Interrupt response when PMU charging starts
     * @retval true valid false invalid
     */
    virtual bool isBatChagerStartIrq() = 0;


    //Data collection function

    /**
     * @brief  Enable battery detection function,the default is on
     * @retval true success false failed
     */
    virtual bool enableBattDetection() = 0;

    /**
     * @brief  Disable battery detection
     * @retval true success false failed
     */
    virtual bool disableBattDetection() = 0;

    /**
     * @brief  Enable USB input voltage detection
     * @retval true success false failed
     */
    virtual bool enableVbusVoltageMeasure(void) = 0;

    /**
     * @brief  Disable USB input voltage detection
     * @retval true success false failed
     */
    virtual bool disableVbusVoltageMeasure(void) = 0;

    /**
     * @brief  Enable system voltage detection
     * @retval true success false failed
     */
    virtual bool enableSystemVoltageMeasure(void) = 0;

    /**
     * @brief  Disable system voltage detection
     * @retval true success false failed
     */
    virtual bool disableSystemVoltageMeasure(void) = 0;

    /**
     * @brief  Enable PMU internal temperature sensor detection
     * @retval true success false failed
     */
    virtual bool enableTemperatureMeasure(void) = 0;

    /**
     * @brief  Disable PMU internal temperature sensor detection
     * @retval true success false failed
     */
    virtual bool disableTemperatureMeasure(void) = 0;

    /**
     * @brief  Enable battery input voltage detection
     * @retval true success false failed
     */
    virtual bool enableBattVoltageMeasure(void) = 0;

    /**
     * @brief  Disable battery input voltage detection
     * @retval true success false failed
     */
    virtual bool disableBattVoltageMeasure(void) = 0;

    /**
     * @brief  Enable NTC thermistor detection (requires hardware support)
     * @retval true success false failed
     */
    virtual bool enableTSPinMeasure(void) = 0;

    /**
     * @brief  Disable NTC thermistor detection (requires hardware support)
     * @retval true success false failed
     */
    virtual bool disableTSPinMeasure(void) = 0;

    // Charge indicator function
    /**
    * @brief  Set charging led mode
    * @param  opt: View the related chip type xpowers_chg_led_mode_t enumeration
    *              parameters in "XPowersParams.hpp"
    */
    virtual void setChargingLedMode(uint8_t mode) = 0;



    // PMU PEKEY settings
    /**
    * @brief  Set PEKEY press power on time
    * @param  opt: View the related chip type xpowers_press_on_time_t enumeration
    *              parameters in "XPowersParams.hpp"
    * @retval true success false failed
    */
    virtual bool setPowerKeyPressOnTime(uint8_t opt) = 0;

    /**
     * @brief Get PEKEY press power on time
     * @retval View the related chip type xpowers_press_on_time_t enumeration
     *              parameters in "XPowersParams.hpp"
     */
    virtual uint8_t getPowerKeyPressOnTime() = 0;

    /**
     * @brief Set PEKEY press power off time
     * @param  opt: View the related chip type xpowers_press_off_time_t enumeration
     *              parameters in "XPowersParams.hpp"
     * @retval true success false failed
     */
    virtual bool setPowerKeyPressOffTime(uint8_t opt) = 0;

    /**
     * @brief Get PEKEY press power off time
     * @retval View the related chip type xpowers_press_off_time_t enumeration
     *              parameters in "XPowersParams.hpp"
     */
    virtual uint8_t getPowerKeyPressOffTime() = 0;

    /**
     * @brief Get the chip model
     * @retval See XPowersChipModel_t enumeration
     */
    uint8_t getChipModel()
    {
        return __chipModel;
    }

protected:

    void setChipModel(uint8_t m)
    {
        __chipModel = m;
    }

    uint8_t __chipModel;
    uint32_t __protectedMask;

};

// https://github.com/lewisxhe/XPowersLib/blob/master/src/XPowersAXP2101.tpp

/**
 *
 * @license MIT License
 *
 * Copyright (c) 2022 lewis he
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @file      XPowersAXP2101.tpp
 * @author    Lewis He (lewishe@outlook.com)
 * @date      2022-05-07
 *
 */


/**
 *
 * @license MIT License
 *
 * Copyright (c) 2022 lewis he
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @file      XPowersCommon.h
 * @author    Lewis He (lewishe@outlook.com)
 * @date      2022-05-07
 *
 */



#ifdef _BV
#undef _BV
#endif
#define _BV(b)                          (1ULL << (uint64_t)(b))


#ifndef constrain
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#endif



#define XPOWERS_ATTR_NOT_IMPLEMENTED    __attribute__((error("Not implemented")))
#define IS_BIT_SET(val,mask)            (((val)&(mask)) == (mask))

// #if !defined(ARDUINO)
#define log_e(...)
#define log_i(...)
#define log_d(...)

#define LOW                 0x0
#define HIGH                0x1

//GPIO FUNCTIONS
#define INPUT               0x01
#define OUTPUT              0x03
#define PULLUP              0x04
#define INPUT_PULLUP        0x05
#define PULLDOWN            0x08
#define INPUT_PULLDOWN      0x09

#define RISING              0x01
#define FALLING             0x02
// #endif

#ifndef ESP32
#ifndef log_e
#define log_e(...)          Serial.printf(__VA_ARGS__)
#endif
#ifndef log_i
#define log_i(...)          Serial.printf(__VA_ARGS__)
#endif
#ifndef log_d
#define log_d(...)          Serial.printf(__VA_ARGS__)
#endif
#endif


template <class chipType>
class XPowersCommon
{
    typedef int (*iic_fptr_t)(uint8_t devAddr, uint8_t regAddr, uint8_t *data, uint8_t len);

public:


    bool begin(uint8_t addr, iic_fptr_t readRegCallback, iic_fptr_t writeRegCallback)
    {
        if (__has_init)return thisChip().initImpl();
        __has_init = true;
        thisReadRegCallback = readRegCallback;
        thisWriteRegCallback = writeRegCallback;
        __addr = addr;
        return thisChip().initImpl();
    }

    int readRegister(uint8_t reg)
    {
        uint8_t val = 0;
        if (thisReadRegCallback) {
            if (thisReadRegCallback(__addr, reg, &val, 1) != 0) {
                return 0;
            }
            return val;
        }
        return -1;
    }

    int writeRegister(uint8_t reg, uint8_t val)
    {
        if (thisWriteRegCallback) {
            return thisWriteRegCallback(__addr, reg, &val, 1);
        }
        return -1;
    }

    int readRegister(uint8_t reg, uint8_t *buf, uint8_t lenght)
    {
        if (thisReadRegCallback) {
            return thisReadRegCallback(__addr, reg, buf, lenght);
        }
        return -1;
    }

    int writeRegister(uint8_t reg, uint8_t *buf, uint8_t lenght)
    {
        if (thisWriteRegCallback) {
            return thisWriteRegCallback(__addr, reg, buf, lenght);
        }
        return -1;
    }


    bool inline clrRegisterBit(uint8_t registers, uint8_t bit)
    {
        int val = readRegister(registers);
        if (val == -1) {
            return false;
        }
        return  writeRegister(registers, (val & (~_BV(bit)))) == 0;
    }

    bool inline setRegisterBit(uint8_t registers, uint8_t bit)
    {
        int val = readRegister(registers);
        if (val == -1) {
            return false;
        }
        return  writeRegister(registers, (val | (_BV(bit)))) == 0;
    }

    bool inline getRegisterBit(uint8_t registers, uint8_t bit)
    {
        int val = readRegister(registers);
        if (val == -1) {
            return false;
        }
        return val & _BV(bit);
    }

    uint16_t inline readRegisterH8L4(uint8_t highReg, uint8_t lowReg)
    {
        int h8 = readRegister(highReg);
        int l4 = readRegister(lowReg);
        if (h8 == -1 || l4 == -1)return 0;
        return (h8 << 4) | (l4 & 0x0F);
    }

    uint16_t inline readRegisterH8L5(uint8_t highReg, uint8_t lowReg)
    {
        int h8 = readRegister(highReg);
        int l5 = readRegister(lowReg);
        if (h8 == -1 || l5 == -1)return 0;
        return (h8 << 5) | (l5 & 0x1F);
    }

    uint16_t inline readRegisterH6L8(uint8_t highReg, uint8_t lowReg)
    {
        int h6 = readRegister(highReg);
        int l8 = readRegister(lowReg);
        if (h6 == -1 || l8 == -1)return 0;
        return ((h6 & 0x3F) << 8) | l8;
    }

    uint16_t inline readRegisterH5L8(uint8_t highReg, uint8_t lowReg)
    {
        int h5 = readRegister(highReg);
        int l8 = readRegister(lowReg);
        if (h5 == -1 || l8 == -1)return 0;
        return ((h5 & 0x1F) << 8) | l8;
    }

    /*
     * CRTP Helper
     */
protected:

    bool begin()
    {
        return thisChip().initImpl();
    }

    void end()
    {
    }


    inline const chipType &thisChip() const
    {
        return static_cast<const chipType &>(*this);
    }

    inline chipType &thisChip()
    {
        return static_cast<chipType &>(*this);
    }

protected:
    bool        __has_init              = false;
    int         __sda                   = -1;
    int         __scl                   = -1;
    uint8_t     __addr                  = 0xFF;
    iic_fptr_t  thisReadRegCallback     = NULL;
    iic_fptr_t  thisWriteRegCallback    = NULL;
};


typedef enum {
    XPOWERS_AXP2101_IRQ_TIME_1S,
    XPOWERS_AXP2101_IRQ_TIME_1S5,
    XPOWERS_AXP2101_IRQ_TIME_2S,
    XPOWERS_AXP2101_PRESSOFF_2S5,
} xpowers_irq_time_t;



typedef enum {
    XPOWERS_AXP2101_PRECHARGE_0MA,
    XPOWERS_AXP2101_PRECHARGE_25MA,
    XPOWERS_AXP2101_PRECHARGE_50MA,
    XPOWERS_AXP2101_PRECHARGE_75MA,
    XPOWERS_AXP2101_PRECHARGE_100MA,
    XPOWERS_AXP2101_PRECHARGE_125MA,
    XPOWERS_AXP2101_PRECHARGE_150MA,
    XPOWERS_AXP2101_PRECHARGE_175MA,
    XPOWERS_AXP2101_PRECHARGE_200MA,
} xpowers_prechg_t;

typedef enum {
    XPOWERS_AXP2101_CHG_ITERM_0MA,
    XPOWERS_AXP2101_CHG_ITERM_25MA,
    XPOWERS_AXP2101_CHG_ITERM_50MA,
    XPOWERS_AXP2101_CHG_ITERM_75MA,
    XPOWERS_AXP2101_CHG_ITERM_100MA,
    XPOWERS_AXP2101_CHG_ITERM_125MA,
    XPOWERS_AXP2101_CHG_ITERM_150MA,
    XPOWERS_AXP2101_CHG_ITERM_175MA,
    XPOWERS_AXP2101_CHG_ITERM_200MA,
} xpowers_axp2101_chg_iterm_t;


typedef enum {
    XPOWERS_AXP2101_THREMAL_60DEG,
    XPOWERS_AXP2101_THREMAL_80DEG,
    XPOWERS_AXP2101_THREMAL_100DEG,
    XPOWERS_AXP2101_THREMAL_120DEG,
} xpowers_thermal_t;

typedef enum {
    XPOWERS_AXP2101_CHG_TRI_STATE,   //tri_charge
    XPOWERS_AXP2101_CHG_PRE_STATE,   //pre_charge
    XPOWERS_AXP2101_CHG_CC_STATE,    //constant charge
    XPOWERS_AXP2101_CHG_CV_STATE,    //constant voltage
    XPOWERS_AXP2101_CHG_DONE_STATE,  //charge done
    XPOWERS_AXP2101_CHG_STOP_STATE,  //not chargin
} xpowers_chg_status_t;

typedef enum {
    XPOWERS_AXP2101_WAKEUP_IRQ_PIN_TO_LOW = _BV(4),
    XPOWERS_AXP2101_WAKEUP_PWROK_TO_LOW   = _BV(3),
    XPOWERS_AXP2101_WAKEUP_DC_DLO_SELECT  = _BV(2),
} xpowers_wakeup_t;

typedef enum {
    XPOWERS_AXP2101_FAST_DCDC1,
    XPOWERS_AXP2101_FAST_DCDC2,
    XPOWERS_AXP2101_FAST_DCDC3,
    XPOWERS_AXP2101_FAST_DCDC4,
    XPOWERS_AXP2101_FAST_DCDC5,
    XPOWERS_AXP2101_FAST_ALDO1,
    XPOWERS_AXP2101_FAST_ALDO2,
    XPOWERS_AXP2101_FAST_ALDO3,
    XPOWERS_AXP2101_FAST_ALDO4,
    XPOWERS_AXP2101_FAST_BLDO1,
    XPOWERS_AXP2101_FAST_BLDO2,
    XPOWERS_AXP2101_FAST_CPUSLDO,
    XPOWERS_AXP2101_FAST_DLDO1,
    XPOWERS_AXP2101_FAST_DLDO2,
} xpowers_fast_on_opt_t;


typedef enum {
    XPOWERS_AXP2101_SEQUENCE_LEVEL_0,
    XPOWERS_AXP2101_SEQUENCE_LEVEL_1,
    XPOWERS_AXP2101_SEQUENCE_LEVEL_2,
    XPOWERS_AXP2101_SEQUENCE_DISABLE,
} xpower_start_sequence_t;

typedef enum {
    XPOWERS_AXP2101_WDT_IRQ_TO_PIN,             //Just interrupt to pin
    XPOWERS_AXP2101_WDT_IRQ_AND_RSET,           //IRQ to pin and reset pmu system
    XPOWERS_AXP2101_WDT_IRQ_AND_RSET_PD_PWROK,  //IRQ to pin and reset pmu system,pull down pwrok
    XPOWERS_AXP2101_WDT_IRQ_AND_RSET_ALL_OFF,   //IRQ to pin and reset pmu system,turn off dcdc & ldo ,pull down pwrok
} xpowers_wdt_config_t;

typedef enum {
    XPOWERS_AXP2101_WDT_TIMEOUT_1S,
    XPOWERS_AXP2101_WDT_TIMEOUT_2S,
    XPOWERS_AXP2101_WDT_TIMEOUT_4S,
    XPOWERS_AXP2101_WDT_TIMEOUT_8S,
    XPOWERS_AXP2101_WDT_TIMEOUT_16S,
    XPOWERS_AXP2101_WDT_TIMEOUT_32S,
    XPOWERS_AXP2101_WDT_TIMEOUT_64S,
    XPOWERS_AXP2101_WDT_TIMEOUT_128S,
} xpowers_wdt_timeout_t;



typedef enum {
    XPOWERS_AXP2101_VBUS_VOL_LIM_3V88,
    XPOWERS_AXP2101_VBUS_VOL_LIM_3V96,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V04,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V12,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V20,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V28,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V36,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V44,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V52,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V60,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V68,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V76,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V84,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V92,
    XPOWERS_AXP2101_VBUS_VOL_LIM_5V,
    XPOWERS_AXP2101_VBUS_VOL_LIM_5V08,
} xpower_vbus_vol_limit_t;

typedef enum {
    XPOWERS_AXP2101_VSYS_VOL_4V1,
    XPOWERS_AXP2101_VSYS_VOL_4V2,
    XPOWERS_AXP2101_VSYS_VOL_4V3,
    XPOWERS_AXP2101_VSYS_VOL_4V4,
    XPOWERS_AXP2101_VSYS_VOL_4V5,
    XPOWERS_AXP2101_VSYS_VOL_4V6,
    XPOWERS_AXP2101_VSYS_VOL_4V7,
    XPOWERS_AXP2101_VSYS_VOL_4V8,
} xpower_chg_dpm_t;

typedef enum {
    XPOWER_POWERON_SRC_POWERON_LOW,                     //POWERON low for on level when POWERON Mode as POWERON Source
    XPOWER_POWERON_SRC_IRQ_LOW,                         //IRQ PIN Pull-down as POWERON Source
    XPOWER_POWERON_SRC_VBUS_INSERT,                     //Vbus Insert and Good as POWERON Source
    XPOWER_POWERON_SRC_BAT_CHARGE,                      //Vbus Insert and Good as POWERON Source
    XPOWER_POWERON_SRC_BAT_INSERT,                      //Battery Insert and Good as POWERON Source
    XPOWER_POWERON_SRC_ENMODE,                          //POWERON always high when EN Mode as POWERON Source
    XPOWER_POWERON_SRC_UNKONW,                          //Unkonw
} xpower_power_on_source_t;

typedef enum {
    XPOWER_POWEROFF_SRC_PWEKEY_PULLDOWN,            //POWERON Pull down for off level when POWERON Mode as POWEROFF Source
    XPOWER_POWEROFF_SRC_SOFT_OFF,                   //Software configuration as POWEROFF Source
    XPOWER_POWEROFF_SRC_PWEKEY_LOW,                 //POWERON always low when EN Mode as POWEROFF Source
    XPOWER_POWEROFF_SRC_UNDER_VSYS,                 //Vsys Under Voltage as POWEROFF Source
    XPOWER_POWEROFF_SRC_OVER_VBUS,                  //VBUS Over Voltage as POWEROFF Source
    XPOWER_POWEROFF_SRC_UNDER_VOL,                  //DCDC Under Voltage as POWEROFF Source
    XPOWER_POWEROFF_SRC_OVER_VOL,                   //DCDC Over Voltage as POWEROFF Source
    XPOWER_POWEROFF_SRC_OVER_TEMP,                  //Die Over Temperature as POWEROFF Source
    XPOWER_POWEROFF_SRC_UNKONW,                     //Unkonw
} xpower_power_off_source_t;

typedef enum {
    XPOWER_PWROK_DELAY_8MS,
    XPOWER_PWROK_DELAY_16MS,
    XPOWER_PWROK_DELAY_32MS,
    XPOWER_PWROK_DELAY_64MS,
} xpower_pwrok_delay_t;

class XPowersAXP2101 :
    public XPowersCommon<XPowersAXP2101>, public XPowersLibInterface
{
    friend class XPowersCommon<XPowersAXP2101>;

public:


    XPowersAXP2101()
    {

        __addr = AXP2101_SLAVE_ADDRESS;
    }

    ~XPowersAXP2101()
    {
        log_i("~XPowersAXP2101");
        deinit();
    }


    bool init()
    {
        return begin();
    }

    void deinit()
    {
        end();
    }

    /*
     * PMU status functions
     */
    uint16_t status()
    {
        uint16_t status1 = readRegister(XPOWERS_AXP2101_STATUS1) & 0x1F;
        uint16_t status2 = readRegister(XPOWERS_AXP2101_STATUS2) & 0x1F;;
        return (status1 << 8) | (status2);
    }

    bool isVbusGood(void)
    {
        return  getRegisterBit(XPOWERS_AXP2101_STATUS1, 5);
    }

    bool getBatfetState(void)
    {
        return  getRegisterBit(XPOWERS_AXP2101_STATUS1, 4);
    }

    // getBatPresentState
    bool isBatteryConnect(void)
    {
        return  getRegisterBit(XPOWERS_AXP2101_STATUS1, 3);
    }

    bool isBatInActiveModeState(void)
    {
        return  getRegisterBit(XPOWERS_AXP2101_STATUS1, 2);
    }

    bool getThermalRegulationStatus(void)
    {
        return  getRegisterBit(XPOWERS_AXP2101_STATUS1, 1);
    }

    bool getCurrnetLimitStatus(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_STATUS1, 0);
    }

    bool isCharging(void)
    {
        return (readRegister(XPOWERS_AXP2101_STATUS2) >> 5) == 0x01;
    }

    bool isDischarge(void)
    {
        return (readRegister(XPOWERS_AXP2101_STATUS2) >> 5) == 0x02;
    }

    bool isStandby(void)
    {
        return (readRegister(XPOWERS_AXP2101_STATUS2) >> 5) == 0x00;
    }

    bool isPowerOn(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_STATUS2, 4);
    }

    bool isPowerOff(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_STATUS2, 4);
    }

    bool isVbusIn(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_STATUS2, 3) == 0 && isVbusGood();
    }

    xpowers_chg_status_t getChargerStatus(void)
    {
        int val = readRegister(XPOWERS_AXP2101_STATUS2);
        if (val == -1)return XPOWERS_AXP2101_CHG_STOP_STATE;
        val &= 0x07;
        return (xpowers_chg_status_t)val;
    }

    /*
     * Data Buffer
     */

    bool writeDataBuffer(uint8_t *data, uint8_t size)
    {
        if (size > XPOWERS_AXP2101_DATA_BUFFER_SIZE)return false;
        return writeRegister(XPOWERS_AXP2101_DATA_BUFFER1, data, size);
    }

    bool readDataBuffer(uint8_t *data, uint8_t size)
    {
        if (size > XPOWERS_AXP2101_DATA_BUFFER_SIZE)return false;
        return readRegister(XPOWERS_AXP2101_DATA_BUFFER1, data, size);
    }

    /*
     * PMU common configuration
     */

    /**
     * @brief   Internal off-discharge enable for DCDC & LDO & SWITCH
     */

    void enableInternalDischarge(void)
    {
        setRegisterBit(XPOWERS_AXP2101_COMMON_CONFIG, 5);
    }

    void disableInternalDischarge(void)
    {
        clrRegisterBit(XPOWERS_AXP2101_COMMON_CONFIG, 5);
    }


    /**
     * @brief   PWROK PIN pull low to Restart
     */
    void enablePwrOkPinPullLow(void)
    {
        setRegisterBit(XPOWERS_AXP2101_COMMON_CONFIG, 3);
    }

    void disablePwrOkPinPullLow(void)
    {
        clrRegisterBit(XPOWERS_AXP2101_COMMON_CONFIG, 3);
    }

    void enablePwronShutPMIC(void)
    {
        setRegisterBit(XPOWERS_AXP2101_COMMON_CONFIG, 2);
    }

    void disablePwronShutPMIC(void)
    {
        clrRegisterBit(XPOWERS_AXP2101_COMMON_CONFIG, 2);
    }


    /**
     * @brief  Restart the SoC System, POWOFF/POWON and reset the related registers
     * @retval None
     */
    void reset(void)
    {
        setRegisterBit(XPOWERS_AXP2101_COMMON_CONFIG, 1);
    }

    /**
     * @brief  Set shutdown, calling shutdown will turn off all power channels,
     *         only VRTC belongs to normal power supply
     * @retval None
     */
    void shutdown(void)
    {
        setRegisterBit(XPOWERS_AXP2101_COMMON_CONFIG, 0);
    }

    /**
     * @brief  BATFET control / REG 12H
     * @note   DIE Over Temperature Protection Level1 Configuration
     * @param  opt: 0:115 , 1:125 , 2:135
     * @retval None
     */
    void setBatfetDieOverTempLevel1(uint8_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_BATFET_CTRL);
        if (val == -1)return;
        val &= 0xF9;
        writeRegister(XPOWERS_AXP2101_BATFET_CTRL, val | (opt << 1));
    }

    uint8_t getBatfetDieOverTempLevel1(void)
    {
        return (readRegister(XPOWERS_AXP2101_BATFET_CTRL) & 0x06);
    }

    void enableBatfetDieOverTempDetect(void)
    {
        setRegisterBit(XPOWERS_AXP2101_BATFET_CTRL, 0);
    }

    void disableBatfetDieOverTempDetect(void)
    {
        clrRegisterBit(XPOWERS_AXP2101_BATFET_CTRL, 0);
    }

    /**
     * @param  opt: 0:115 , 1:125 , 2:135
     */
    void setDieOverTempLevel1(uint8_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_DIE_TEMP_CTRL);
        if (val == -1)return;
        val &= 0xF9;
        writeRegister(XPOWERS_AXP2101_DIE_TEMP_CTRL, val | (opt << 1));
    }

    uint8_t getDieOverTempLevel1(void)
    {
        return (readRegister(XPOWERS_AXP2101_DIE_TEMP_CTRL) & 0x06);
    }

    void enableDieOverTempDetect(void)
    {
        setRegisterBit(XPOWERS_AXP2101_DIE_TEMP_CTRL, 0);
    }

    void disableDieOverTempDetect(void)
    {
        clrRegisterBit(XPOWERS_AXP2101_DIE_TEMP_CTRL, 0);
    }

    // Linear Charger Vsys voltage dpm
    void setLinearChargerVsysDpm(xpower_chg_dpm_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_MIN_SYS_VOL_CTRL);
        if (val == -1)return;
        val &= 0x8F;
        writeRegister(XPOWERS_AXP2101_MIN_SYS_VOL_CTRL, val | (opt << 4));
    }

    uint8_t getLinearChargerVsysDpm(void)
    {
        int val = readRegister(XPOWERS_AXP2101_MIN_SYS_VOL_CTRL);
        if (val == -1)return 0;
        val &= 0x70;
        return (val & 0x70) >> 4;
    }

    // Set the minimum common working voltage of the PMU VBUS input,
    // below this value will turn off the PMU
    void setVbusVoltageLimit(xpower_vbus_vol_limit_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_INPUT_VOL_LIMIT_CTRL);
        if (val == -1)return;
        val &= 0xF0;
        writeRegister(XPOWERS_AXP2101_INPUT_VOL_LIMIT_CTRL, val | (opt & 0x0F));
    }

    uint8_t getVbusVoltageLimit(void)
    {
        return (readRegister(XPOWERS_AXP2101_INPUT_VOL_LIMIT_CTRL) & 0x0F);
    }

    /**
    * @brief  Set VBUS Current Input Limit.
    * @param  opt: View the related chip type xpowers_axp2101_vbus_cur_limit_t enumeration
    *              parameters in "XPowersParams.hpp"
    * @retval true valid false invalid
    */
    bool setVbusCurrentLimit(uint8_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_INPUT_CUR_LIMIT_CTRL);
        if (val == -1)return false;
        val &= 0xF8;
        return 0 == writeRegister(XPOWERS_AXP2101_INPUT_CUR_LIMIT_CTRL, val | (opt & 0x07));
    }

    /**
    * @brief  Get VBUS Current Input Limit.
    * @retval View the related chip type xpowers_axp2101_vbus_cur_limit_t enumeration
    *              parameters in "XPowersParams.hpp"
    */
    uint8_t getVbusCurrentLimit(void)
    {
        return (readRegister(XPOWERS_AXP2101_INPUT_CUR_LIMIT_CTRL) & 0x07);
    }

    /**
     * @brief  Reset the fuel gauge
     */
    void resetGauge(void)
    {
        setRegisterBit(XPOWERS_AXP2101_RESET_FUEL_GAUGE, 3);
    }

    /**
     * @brief   reset the gauge besides reset
     */
    void resetGaugeBesides(void)
    {
        setRegisterBit(XPOWERS_AXP2101_RESET_FUEL_GAUGE, 2);
    }

    /**
     * @brief Gauge Module
     */
    void enableGauge(void)
    {
        setRegisterBit(XPOWERS_AXP2101_CHARGE_GAUGE_WDT_CTRL, 3);
    }

    void disableGauge(void)
    {
        clrRegisterBit(XPOWERS_AXP2101_CHARGE_GAUGE_WDT_CTRL, 3);
    }

    /**
     * @brief  Button Battery charge
     */
    bool enableButtonBatteryCharge(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_CHARGE_GAUGE_WDT_CTRL, 2);
    }

    bool disableButtonBatteryCharge(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_CHARGE_GAUGE_WDT_CTRL, 2);
    }

    bool isEanbleButtonBatteryCharge()
    {
        return getRegisterBit(XPOWERS_AXP2101_CHARGE_GAUGE_WDT_CTRL, 2);
    }


    //Button battery charge termination voltage setting
    bool setButtonBatteryChargeVoltage(uint16_t millivolt)
    {
        if (millivolt % XPOWERS_AXP2101_BTN_VOL_STEPS) {
            log_e("Mistake ! Button battery charging step voltage is %u mV", XPOWERS_AXP2101_BTN_VOL_STEPS);
            return false;
        }
        if (millivolt < XPOWERS_AXP2101_BTN_VOL_MIN) {
            log_e("Mistake ! The minimum charge termination voltage of the coin cell battery is %u mV", XPOWERS_AXP2101_BTN_VOL_MIN);
            return false;
        } else if (millivolt > XPOWERS_AXP2101_BTN_VOL_MAX) {
            log_e("Mistake ! The minimum charge termination voltage of the coin cell battery is %u mV", XPOWERS_AXP2101_BTN_VOL_MAX);
            return false;
        }
        int val =  readRegister(XPOWERS_AXP2101_BTN_BAT_CHG_VOL_SET);
        if (val == -1)return 0;
        val  &= 0xF8;
        val |= (millivolt - XPOWERS_AXP2101_BTN_VOL_MIN) / XPOWERS_AXP2101_BTN_VOL_STEPS;
        return 0 == writeRegister(XPOWERS_AXP2101_BTN_BAT_CHG_VOL_SET, val);
    }

    uint16_t getButtonBatteryVoltage(void)
    {
        int val =  readRegister(XPOWERS_AXP2101_BTN_BAT_CHG_VOL_SET);
        if (val == -1)return 0;
        return (val & 0x07) * XPOWERS_AXP2101_BTN_VOL_STEPS + XPOWERS_AXP2101_BTN_VOL_MIN;
    }


    /**
     * @brief Cell Battery charge
     */
    void enableCellbatteryCharge(void)
    {
        setRegisterBit(XPOWERS_AXP2101_CHARGE_GAUGE_WDT_CTRL, 1);
    }

    void disableCellbatteryCharge(void)
    {
        clrRegisterBit(XPOWERS_AXP2101_CHARGE_GAUGE_WDT_CTRL, 1);
    }

    /**
     * @brief  Watchdog Module
     */
    void enableWatchdog(void)
    {
        setRegisterBit(XPOWERS_AXP2101_CHARGE_GAUGE_WDT_CTRL, 0);
        enableIRQ(XPOWERS_AXP2101_WDT_EXPIRE_IRQ);
    }

    void disableWatchdog(void)
    {
        disableIRQ(XPOWERS_AXP2101_WDT_EXPIRE_IRQ);
        clrRegisterBit(XPOWERS_AXP2101_CHARGE_GAUGE_WDT_CTRL, 0);
    }

    /**
     * @brief Watchdog Config
     * @note
     * @param  opt: 0: IRQ Only 1: IRQ and System reset  2: IRQ, System Reset and Pull down PWROK 1s  3: IRQ, System Reset, DCDC/LDO PWROFF & PWRON
     * @retval None
     */
    void setWatchdogConfig(xpowers_wdt_config_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_WDT_CTRL);
        if (val == -1)return;
        val &= 0xCF;
        writeRegister(XPOWERS_AXP2101_WDT_CTRL, val | (opt << 4));
    }

    uint8_t getWatchConfig(void)
    {
        return (readRegister(XPOWERS_AXP2101_WDT_CTRL) & 0x30) >> 4;
    }

    void clrWatchdog(void)
    {
        setRegisterBit(XPOWERS_AXP2101_WDT_CTRL, 3);
    }


    void setWatchdogTimeout(xpowers_wdt_timeout_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_WDT_CTRL);
        if (val == -1)return;
        val &= 0xF8;
        writeRegister(XPOWERS_AXP2101_WDT_CTRL, val | opt);
    }

    uint8_t getWatchdogTimerout(void)
    {
        return readRegister(XPOWERS_AXP2101_WDT_CTRL) & 0x07;
    }

    /**
     * @brief  Low battery warning threshold 5-20%, 1% per step
     * @param  opt:   5 ~ 20
     * @retval None
     */
    void setLowBatWarnThreshold(uint8_t opt)
    {
        if (opt < 5 || opt > 20)return;
        int val = readRegister(XPOWERS_AXP2101_LOW_BAT_WARN_SET);
        if (val == -1)return;
        val &= 0x0F;
        writeRegister(XPOWERS_AXP2101_LOW_BAT_WARN_SET, val | (opt << 4));
    }

    uint8_t getLowBatWarnThreshold(void)
    {
        return (readRegister(XPOWERS_AXP2101_LOW_BAT_WARN_SET) & 0xF0) >> 4;
    }

    /**
     * @brief  Low battery shutdown threshold 5-20%, 1% per step
     * @param  opt:   5 ~ 20
     * @retval None
     */
    void setLowBatShutdownThreshold(uint8_t opt)
    {
        if (opt < 5 || opt > 20)return;
        int val = readRegister(XPOWERS_AXP2101_LOW_BAT_WARN_SET);
        if (val == -1)return;
        val &= 0xF0;
        writeRegister(XPOWERS_AXP2101_LOW_BAT_WARN_SET, val | opt);
    }

    uint8_t getLowBatShutdownThreshold(void)
    {
        return (readRegister(XPOWERS_AXP2101_LOW_BAT_WARN_SET) & 0x0F);
    }

    //!  PWRON statu  20
    // POWERON always high when EN Mode as POWERON Source
    bool isPoweronAlwaysHighSource()
    {
        return getRegisterBit(XPOWERS_AXP2101_PWRON_STATUS, 5);
    }

    // Battery Insert and Good as POWERON Source
    bool isBattInsertOnSource()
    {
        return getRegisterBit(XPOWERS_AXP2101_PWRON_STATUS, 4);
    }

    // Battery Voltage > 3.3V when Charged as Source
    bool isBattNormalOnSource()
    {
        return getRegisterBit(XPOWERS_AXP2101_PWRON_STATUS, 3);
    }

    // Vbus Insert and Good as POWERON Source
    bool isVbusInsertOnSource()
    {
        return getRegisterBit(XPOWERS_AXP2101_PWRON_STATUS, 2);
    }

    // IRQ PIN Pull-down as POWERON Source
    bool isIrqLowOnSource()
    {
        return getRegisterBit(XPOWERS_AXP2101_PWRON_STATUS, 1);
    }

    // POWERON low for on level when POWERON Mode as POWERON Source
    bool isPwronLowOnSource()
    {
        return getRegisterBit(XPOWERS_AXP2101_PWRON_STATUS, 0);
    }

    xpower_power_on_source_t getPowerOnSource()
    {
        int val = readRegister(XPOWERS_AXP2101_PWRON_STATUS);
        if (val == -1) return XPOWER_POWERON_SRC_UNKONW;
        return (xpower_power_on_source_t)val;
    }

    //!  PWROFF status  21
    // Die Over Temperature as POWEROFF Source
    bool isOverTemperatureOffSource()
    {
        return getRegisterBit(XPOWERS_AXP2101_PWROFF_STATUS, 7);
    }

    // DCDC Over Voltage as POWEROFF Source
    bool isDcOverVoltageOffSource()
    {
        return getRegisterBit(XPOWERS_AXP2101_PWROFF_STATUS, 6);
    }

    // DCDC Under Voltage as POWEROFF Source
    bool isDcUnderVoltageOffSource()
    {
        return getRegisterBit(XPOWERS_AXP2101_PWROFF_STATUS, 5);
    }

    // VBUS Over Voltage as POWEROFF Source
    bool isVbusOverVoltageOffSource()
    {
        return getRegisterBit(XPOWERS_AXP2101_PWROFF_STATUS, 4);
    }

    // Vsys Under Voltage as POWEROFF Source
    bool isVsysUnderVoltageOffSource()
    {
        return getRegisterBit(XPOWERS_AXP2101_PWROFF_STATUS, 3);
    }

    // POWERON always low when EN Mode as POWEROFF Source
    bool isPwronAlwaysLowOffSource()
    {
        return getRegisterBit(XPOWERS_AXP2101_PWROFF_STATUS, 2);
    }

    // Software configuration as POWEROFF Source
    bool isSwConfigOffSource()
    {
        return getRegisterBit(XPOWERS_AXP2101_PWROFF_STATUS, 1);
    }

    // POWERON Pull down for off level when POWERON Mode as POWEROFF Source
    bool isPwrSourcePullDown()
    {
        return getRegisterBit(XPOWERS_AXP2101_PWROFF_STATUS, 0);
    }

    xpower_power_off_source_t getPowerOffSource()
    {
        int val = readRegister(XPOWERS_AXP2101_PWROFF_STATUS);
        if (val == -1) return XPOWER_POWEROFF_SRC_UNKONW;
        return (xpower_power_off_source_t)val;
    }

    //!REG 22H
    void enableOverTemperatureLevel2PowerOff()
    {
        setRegisterBit(XPOWERS_AXP2101_PWROFF_EN, 2);
    }

    void disableOverTemperaturePowerOff()
    {
        clrRegisterBit(XPOWERS_AXP2101_PWROFF_EN, 2);
    }

    // CHANGE:  void enablePwrOnOverVolOffLevelPowerOff()
    void enableLongPressShutdown()
    {
        setRegisterBit(XPOWERS_AXP2101_PWROFF_EN, 1);
    }

    // CHANGE:  void disablePwrOnOverVolOffLevelPowerOff()
    void disableLongPressShutdown()
    {
        clrRegisterBit(XPOWERS_AXP2101_PWROFF_EN, 1);
    }

    //CHANGE: void enablePwrOffSelectFunction()
    void setLongPressRestart()
    {
        setRegisterBit(XPOWERS_AXP2101_PWROFF_EN, 0);
    }

    //CHANGE: void disablePwrOffSelectFunction()
    void setLongPressPowerOFF()
    {
        clrRegisterBit(XPOWERS_AXP2101_PWROFF_EN, 0);
    }

    //!REG 23H
    // DCDC 120%(130%) high voltage turn off PMIC function
    void enableDCHighVoltageTurnOff()
    {
        setRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 5);
    }

    void disableDCHighVoltageTurnOff()
    {
        clrRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 5);
    }

    // DCDC5 85% low voltage turn Off PMIC function
    void enableDC5LowVoltageTurnOff()
    {
        setRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 4);
    }

    void disableDC5LowVoltageTurnOff()
    {
        clrRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 4);
    }

    // DCDC4 85% low voltage turn Off PMIC function
    void enableDC4LowVoltageTurnOff()
    {
        setRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 3);
    }

    void disableDC4LowVoltageTurnOff()
    {
        clrRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 3);
    }

    // DCDC3 85% low voltage turn Off PMIC function
    void enableDC3LowVoltageTurnOff()
    {
        setRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 2);
    }

    void disableDC3LowVoltageTurnOff()
    {
        clrRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 2);
    }

    // DCDC2 85% low voltage turn Off PMIC function
    void enableDC2LowVoltageTurnOff()
    {
        setRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 1);
    }

    void disableDC2LowVoltageTurnOff()
    {
        clrRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 1);
    }

    // DCDC1 85% low voltage turn Off PMIC function
    void enableDC1LowVoltageTurnOff()
    {
        setRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 0);
    }

    void disableDC1LowVoltageTurnOff()
    {
        clrRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 0);
    }


    // Set the minimum system operating voltage inside the PMU,
    // below this value will shut down the PMU,Adjustment range 2600mV~3300mV
    bool setSysPowerDownVoltage(uint16_t millivolt)
    {
        if (millivolt % XPOWERS_AXP2101_VSYS_VOL_THRESHOLD_STEPS) {
            log_e("Mistake ! The steps is must %u mV", XPOWERS_AXP2101_VSYS_VOL_THRESHOLD_STEPS);
            return false;
        }
        if (millivolt < XPOWERS_AXP2101_VSYS_VOL_THRESHOLD_MIN) {
            log_e("Mistake ! The minimum settable voltage of VSYS is %u mV", XPOWERS_AXP2101_VSYS_VOL_THRESHOLD_MIN);
            return false;
        } else if (millivolt > XPOWERS_AXP2101_VSYS_VOL_THRESHOLD_MAX) {
            log_e("Mistake ! The maximum settable voltage of VSYS is %u mV", XPOWERS_AXP2101_VSYS_VOL_THRESHOLD_MAX);
            return false;
        }
        int val = readRegister(XPOWERS_AXP2101_VOFF_SET);
        if (val == -1)return false;
        val &= 0xF8;
        return 0 == writeRegister(XPOWERS_AXP2101_VOFF_SET, val | ((millivolt - XPOWERS_AXP2101_VSYS_VOL_THRESHOLD_MIN) / XPOWERS_AXP2101_VSYS_VOL_THRESHOLD_STEPS));
    }

    uint16_t getSysPowerDownVoltage(void)
    {
        int val = readRegister(XPOWERS_AXP2101_VOFF_SET);
        if (val == -1)return false;
        return (val & 0x07) * XPOWERS_AXP2101_VSYS_VOL_THRESHOLD_STEPS + XPOWERS_AXP2101_VSYS_VOL_THRESHOLD_MIN;
    }

    //  PWROK setting and PWROFF sequence control 25.
    // Check the PWROK Pin enable after all dcdc/ldo output valid 128ms
    void enablePwrOk()
    {
        setRegisterBit(XPOWERS_AXP2101_PWROK_SEQU_CTRL, 4);
    }

    void disablePwrOk()
    {
        clrRegisterBit(XPOWERS_AXP2101_PWROK_SEQU_CTRL, 4);
    }

    // POWEROFF Delay 4ms after PWROK enable
    void eanblePowerOffDelay()
    {
        setRegisterBit(XPOWERS_AXP2101_PWROK_SEQU_CTRL, 3);
    }

    // POWEROFF Delay 4ms after PWROK disable
    void disablePowerOffDelay()
    {
        clrRegisterBit(XPOWERS_AXP2101_PWROK_SEQU_CTRL, 3);
    }

    // POWEROFF Sequence Control the reverse of the Startup
    void eanblePowerSequence()
    {
        setRegisterBit(XPOWERS_AXP2101_PWROK_SEQU_CTRL, 2);
    }

    // POWEROFF Sequence Control at the same time
    void disablePowerSequence()
    {
        clrRegisterBit(XPOWERS_AXP2101_PWROK_SEQU_CTRL, 2);
    }

    // Delay of PWROK after all power output good
    bool setPwrOkDelay(xpower_pwrok_delay_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_PWROK_SEQU_CTRL);
        if (val == -1)return false;
        val &= 0xFC;
        return 0 == writeRegister(XPOWERS_AXP2101_PWROK_SEQU_CTRL, val | opt);
    }

    xpower_pwrok_delay_t getPwrOkDelay()
    {
        int val = readRegister(XPOWERS_AXP2101_PWROK_SEQU_CTRL);
        if (val == -1)return XPOWER_PWROK_DELAY_8MS;
        return (xpower_pwrok_delay_t)(val & 0x03);
    }

    //  Sleep and 26
    void wakeupControl(xpowers_wakeup_t opt, bool enable)
    {
        int val = readRegister(XPOWERS_AXP2101_SLEEP_WAKEUP_CTRL);
        if (val == -1)return;
        enable ? (val |= opt) : (val &= (~opt));
        writeRegister(XPOWERS_AXP2101_SLEEP_WAKEUP_CTRL, val);
    }

    bool enableWakeup(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_SLEEP_WAKEUP_CTRL, 1);
    }

    bool disableWakeup(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_SLEEP_WAKEUP_CTRL, 1);
    }

    bool enableSleep(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_SLEEP_WAKEUP_CTRL, 0);
    }

    bool disableSleep(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_SLEEP_WAKEUP_CTRL, 0);
    }


    //  RQLEVEL/OFFLEVEL/ONLEVEL setting 27
    /**
     * @brief  IRQLEVEL configur
     * @param  opt: 0:1s  1:1.5s  2:2s 3:2.5s
     */
    void setIrqLevel(uint8_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_IRQ_OFF_ON_LEVEL_CTRL);
        if (val == -1)return;
        val &= 0xFC;
        writeRegister(XPOWERS_AXP2101_IRQ_OFF_ON_LEVEL_CTRL, val | (opt << 4));
    }

    /**
     * @brief  OFFLEVEL configuration
     * @param  opt:  0:4s 1:6s 2:8s 3:10s
     */
    void setOffLevel(uint8_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_IRQ_OFF_ON_LEVEL_CTRL);
        if (val == -1)return;
        writeRegister(XPOWERS_AXP2101_IRQ_OFF_ON_LEVEL_CTRL, val | (opt << 2));
    }

    /**
     * @brief  ONLEVEL configuration
     * @param  opt: 0:128ms 1:512ms 2:1s  3:2s
     */
    void setOnLevel(uint8_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_IRQ_OFF_ON_LEVEL_CTRL);
        if (val == -1)return;
        writeRegister(XPOWERS_AXP2101_IRQ_OFF_ON_LEVEL_CTRL, val | opt);
    }

    // Fast pwron setting 0  28
    // Fast Power On Start Sequence
    void setDc4FastStartSequence(xpower_start_sequence_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET0);
        if (val == -1)return;
        writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET0, val | ((opt & 0x3) << 6));
    }

    void setDc3FastStartSequence(xpower_start_sequence_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET0);
        if (val == -1)return;
        writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET0, val | ((opt & 0x3) << 4));
    }
    void setDc2FastStartSequence(xpower_start_sequence_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET0);
        if (val == -1)return;
        writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET0, val | ((opt & 0x3) << 2));
    }
    void setDc1FastStartSequence(xpower_start_sequence_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET0);
        if (val == -1)return;
        writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET0, val | (opt & 0x3));
    }

    //  Fast pwron setting 1  29
    void setAldo3FastStartSequence(xpower_start_sequence_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET1);
        if (val == -1)return;
        writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET1, val | ((opt & 0x3) << 6));
    }
    void setAldo2FastStartSequence(xpower_start_sequence_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET1);
        if (val == -1)return;
        writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET1, val | ((opt & 0x3) << 4));
    }
    void setAldo1FastStartSequence(xpower_start_sequence_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET1);
        if (val == -1)return;
        writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET1, val | ((opt & 0x3) << 2));
    }

    void setDc5FastStartSequence(xpower_start_sequence_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET1);
        if (val == -1)return;
        writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET1, val | (opt & 0x3));
    }

    //  Fast pwron setting 2  2A
    void setCpuldoFastStartSequence(xpower_start_sequence_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET2);
        if (val == -1)return;
        writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET2, val | ((opt & 0x3) << 6));
    }

    void setBldo2FastStartSequence(xpower_start_sequence_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET2);
        if (val == -1)return;
        writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET2, val | ((opt & 0x3) << 4));
    }

    void setBldo1FastStartSequence(xpower_start_sequence_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET2);
        if (val == -1)return;
        writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET2, val | ((opt & 0x3) << 2));
    }

    void setAldo4FastStartSequence(xpower_start_sequence_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET2);
        if (val == -1)return;
        writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET2, val | (opt & 0x3));
    }

    //  Fast pwron setting 3  2B
    void setDldo2FastStartSequence(xpower_start_sequence_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_FAST_PWRON_CTRL);
        if (val == -1)return;
        writeRegister(XPOWERS_AXP2101_FAST_PWRON_CTRL, val | ((opt & 0x3) << 2));
    }

    void setDldo1FastStartSequence(xpower_start_sequence_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_FAST_PWRON_CTRL);
        if (val == -1)return;
        writeRegister(XPOWERS_AXP2101_FAST_PWRON_CTRL, val | (opt & 0x3));
    }

    /**
     * @brief   Setting Fast Power On Start Sequence
     */
    void setFastPowerOnLevel(xpowers_fast_on_opt_t opt, xpower_start_sequence_t seq_level)
    {
        uint8_t val = 0;
        switch (opt) {
        case XPOWERS_AXP2101_FAST_DCDC1:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET0);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET0, val | seq_level);
            break;
        case XPOWERS_AXP2101_FAST_DCDC2:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET0);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET0, val | (seq_level << 2));
            break;
        case XPOWERS_AXP2101_FAST_DCDC3:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET0);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET0, val | (seq_level << 4));
            break;
        case XPOWERS_AXP2101_FAST_DCDC4:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET0);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET0, val | (seq_level << 6));
            break;
        case XPOWERS_AXP2101_FAST_DCDC5:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET1);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET1, val | seq_level);
            break;
        case XPOWERS_AXP2101_FAST_ALDO1:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET1);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET1, val | (seq_level << 2));
            break;
        case XPOWERS_AXP2101_FAST_ALDO2:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET1);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET1, val | (seq_level << 4));
            break;
        case XPOWERS_AXP2101_FAST_ALDO3:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET1);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET1, val | (seq_level << 6));
            break;
        case XPOWERS_AXP2101_FAST_ALDO4:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET2);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET2, val | seq_level);
            break;
        case XPOWERS_AXP2101_FAST_BLDO1:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET2);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET2, val | (seq_level << 2));
            break;
        case XPOWERS_AXP2101_FAST_BLDO2:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET2);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET2, val | (seq_level << 4));
            break;
        case XPOWERS_AXP2101_FAST_CPUSLDO:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET2);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET2, val | (seq_level << 6));
            break;
        case XPOWERS_AXP2101_FAST_DLDO1:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_CTRL);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_CTRL, val | seq_level);
            break;
        case XPOWERS_AXP2101_FAST_DLDO2:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_CTRL);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_CTRL, val | (seq_level << 2));
            break;
        default:
            break;
        }
    }

    void disableFastPowerOn(xpowers_fast_on_opt_t opt)
    {
        uint8_t val = 0;
        switch (opt) {
        case XPOWERS_AXP2101_FAST_DCDC1:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET0);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET0, val & 0xFC);
            break;
        case XPOWERS_AXP2101_FAST_DCDC2:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET0);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET0, val & 0xF3);
            break;
        case XPOWERS_AXP2101_FAST_DCDC3:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET0);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET0, val & 0xCF);
            break;
        case XPOWERS_AXP2101_FAST_DCDC4:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET0);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET0, val & 0x3F);
            break;
        case XPOWERS_AXP2101_FAST_DCDC5:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET1);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET1, val & 0xFC);
            break;
        case XPOWERS_AXP2101_FAST_ALDO1:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET1);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET1, val & 0xF3);
            break;
        case XPOWERS_AXP2101_FAST_ALDO2:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET1);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET1, val & 0xCF);
            break;
        case XPOWERS_AXP2101_FAST_ALDO3:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET1);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET1, val & 0x3F);
            break;
        case XPOWERS_AXP2101_FAST_ALDO4:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET2);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET2, val & 0xFC);
            break;
        case XPOWERS_AXP2101_FAST_BLDO1:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET2);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET2, val & 0xF3);
            break;
        case XPOWERS_AXP2101_FAST_BLDO2:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET2);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET2, val & 0xCF);
            break;
        case XPOWERS_AXP2101_FAST_CPUSLDO:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_SET2);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_SET2, val & 0x3F);
            break;
        case XPOWERS_AXP2101_FAST_DLDO1:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_CTRL);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_CTRL, val & 0xFC);
            break;
        case XPOWERS_AXP2101_FAST_DLDO2:
            val = readRegister(XPOWERS_AXP2101_FAST_PWRON_CTRL);
            writeRegister(XPOWERS_AXP2101_FAST_PWRON_CTRL, val & 0xF3);
            break;
        default:
            break;
        }
    }

    void enableFastPowerOn(void)
    {
        setRegisterBit(XPOWERS_AXP2101_FAST_PWRON_CTRL, 7);
    }

    void disableFastPowerOn(void)
    {
        clrRegisterBit(XPOWERS_AXP2101_FAST_PWRON_CTRL, 7);
    }

    void enableFastWakeup(void)
    {
        setRegisterBit(XPOWERS_AXP2101_FAST_PWRON_CTRL, 6);
    }

    void disableFastWakeup(void)
    {
        clrRegisterBit(XPOWERS_AXP2101_FAST_PWRON_CTRL, 6);
    }

    // DCDC 120%(130%) high voltage turn off PMIC function
    void setDCHighVoltagePowerDowm(bool en)
    {
        en ? setRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 5) : clrRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 5);
    }

    bool getDCHighVoltagePowerDowmEn()
    {
        return getRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 5);
    }

    // DCDCS force PWM control
    void setDcUVPDebounceTime(uint8_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_DC_FORCE_PWM_CTRL);
        val &= 0xFC;
        writeRegister(XPOWERS_AXP2101_DC_FORCE_PWM_CTRL, val | opt);
    }

    void settDC1WorkModeToPwm(uint8_t enable)
    {
        enable ?
        setRegisterBit(XPOWERS_AXP2101_DC_FORCE_PWM_CTRL, 2)
        : clrRegisterBit(XPOWERS_AXP2101_DC_FORCE_PWM_CTRL, 2);
    }

    void settDC2WorkModeToPwm(uint8_t enable)
    {
        enable ? setRegisterBit(XPOWERS_AXP2101_DC_FORCE_PWM_CTRL, 3)
        : clrRegisterBit(XPOWERS_AXP2101_DC_FORCE_PWM_CTRL, 3);
    }

    void settDC3WorkModeToPwm(uint8_t enable)
    {
        enable ?
        setRegisterBit(XPOWERS_AXP2101_DC_FORCE_PWM_CTRL, 4)
        : clrRegisterBit(XPOWERS_AXP2101_DC_FORCE_PWM_CTRL, 4);
    }

    void settDC4WorkModeToPwm( uint8_t enable)
    {
        enable ?
        setRegisterBit(XPOWERS_AXP2101_DC_FORCE_PWM_CTRL, 5)
        :  clrRegisterBit(XPOWERS_AXP2101_DC_FORCE_PWM_CTRL, 5);
    }

    //1 = 100khz 0=50khz
    void setDCFreqSpreadRange(uint8_t opt)
    {
        opt ?
        setRegisterBit(XPOWERS_AXP2101_DC_FORCE_PWM_CTRL, 6)
        :  clrRegisterBit(XPOWERS_AXP2101_DC_FORCE_PWM_CTRL, 6);
    }

    void setDCFreqSpreadRangeEn(bool en)
    {
        en ?
        setRegisterBit(XPOWERS_AXP2101_DC_FORCE_PWM_CTRL, 7)
        :  clrRegisterBit(XPOWERS_AXP2101_DC_FORCE_PWM_CTRL, 7);
    }

    void enableCCM()
    {
        setRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 6);
    }

    void disableCCM()
    {
        clrRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 6);
    }

    bool isEanbleCCM()
    {
        return getRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 6);
    }

    enum DVMRamp {
        XPOWERS_AXP2101_DVM_RAMP_15_625US,
        XPOWERS_AXP2101_DVM_RAMP_31_250US,
    };

    //args:enum DVMRamp
    void setDVMRamp(uint8_t opt)
    {
        if (opt > 2)return;
        opt == 0 ? clrRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 5) : setRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 5);
    }



    /*
     * Power control DCDC1 functions
     */
    bool isEnableDC1(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 0);
    }

    bool enableDC1(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 0);
    }

    bool disableDC1(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 0);
    }

    bool setDC1Voltage(uint16_t millivolt)
    {
        if (millivolt % XPOWERS_AXP2101_DCDC1_VOL_STEPS) {
            log_e("Mistake ! The steps is must %u mV", XPOWERS_AXP2101_DCDC1_VOL_STEPS);
            return false;
        }
        if (millivolt < XPOWERS_AXP2101_DCDC1_VOL_MIN) {
            log_e("Mistake ! DC1 minimum voltage is %u mV", XPOWERS_AXP2101_DCDC1_VOL_MIN);
            return false;
        } else if (millivolt > XPOWERS_AXP2101_DCDC1_VOL_MAX) {
            log_e("Mistake ! DC1 maximum voltage is %u mV", XPOWERS_AXP2101_DCDC1_VOL_MAX);
            return false;
        }
        return 0 == writeRegister(XPOWERS_AXP2101_DC_VOL0_CTRL, (millivolt - XPOWERS_AXP2101_DCDC1_VOL_MIN) / XPOWERS_AXP2101_DCDC1_VOL_STEPS);
    }

    uint16_t getDC1Voltage(void)
    {
        return (readRegister(XPOWERS_AXP2101_DC_VOL0_CTRL) & 0x1F) * XPOWERS_AXP2101_DCDC1_VOL_STEPS + XPOWERS_AXP2101_DCDC1_VOL_MIN;
    }



    // DCDC1 85% low voltage turn off PMIC function
    void setDC1LowVoltagePowerDowm(bool en)
    {
        en ? setRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 0) : clrRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 0);
    }

    bool getDC1LowVoltagePowerDowmEn()
    {
        return getRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 0);
    }

    /*
     * Power control DCDC2 functions
     */
    bool isEnableDC2(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 1);
    }

    bool enableDC2(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 1);
    }

    bool disableDC2(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 1);
    }

    bool setDC2Voltage(uint16_t millivolt)
    {
        int val = readRegister(XPOWERS_AXP2101_DC_VOL1_CTRL);
        if (val == -1)return 0;
        val &= 0x80;
        if (millivolt >= XPOWERS_AXP2101_DCDC2_VOL1_MIN && millivolt <= XPOWERS_AXP2101_DCDC2_VOL1_MAX) {
            if (millivolt % XPOWERS_AXP2101_DCDC2_VOL_STEPS1) {
                log_e("Mistake !  The steps is must %umV", XPOWERS_AXP2101_DCDC2_VOL_STEPS1);
                return false;
            }
            return  0 == writeRegister(XPOWERS_AXP2101_DC_VOL1_CTRL, val | (millivolt - XPOWERS_AXP2101_DCDC2_VOL1_MIN) / XPOWERS_AXP2101_DCDC2_VOL_STEPS1);
        } else if (millivolt >= XPOWERS_AXP2101_DCDC2_VOL2_MIN && millivolt <= XPOWERS_AXP2101_DCDC2_VOL2_MAX) {
            if (millivolt % XPOWERS_AXP2101_DCDC2_VOL_STEPS2) {
                log_e("Mistake !  The steps is must %umV", XPOWERS_AXP2101_DCDC2_VOL_STEPS2);
                return false;
            }
            val |= (((millivolt - XPOWERS_AXP2101_DCDC2_VOL2_MIN) / XPOWERS_AXP2101_DCDC2_VOL_STEPS2) + XPOWERS_AXP2101_DCDC2_VOL_STEPS2_BASE);
            return  0 == writeRegister(XPOWERS_AXP2101_DC_VOL1_CTRL, val);
        }
        return false;
    }

    uint16_t getDC2Voltage(void)
    {
        int val = readRegister(XPOWERS_AXP2101_DC_VOL1_CTRL);
        if (val ==  -1)return 0;
        val &= 0x7F;
        if (val < XPOWERS_AXP2101_DCDC2_VOL_STEPS2_BASE) {
            return (val  * XPOWERS_AXP2101_DCDC2_VOL_STEPS1) +  XPOWERS_AXP2101_DCDC2_VOL1_MIN;
        } else  {
            return (val  * XPOWERS_AXP2101_DCDC2_VOL_STEPS2) - 200;
        }
        return 0;
    }

    uint8_t getDC2WorkMode(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_DCDC2_VOL_STEPS2, 7);
    }

    void setDC2LowVoltagePowerDowm(bool en)
    {
        en ? setRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 1) : clrRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 1);
    }

    bool getDC2LowVoltagePowerDowmEn()
    {
        return getRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 1);
    }

    /*
     * Power control DCDC3 functions
     */

    bool isEnableDC3(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 2);
    }

    bool enableDC3(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 2);
    }

    bool disableDC3(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 2);
    }

    /**
        0.5~1.2V,10mV/step,71steps
        1.22~1.54V,20mV/step,17steps
        1.6~3.4V,100mV/step,19steps
     */
    bool setDC3Voltage(uint16_t millivolt)
    {
        int val = readRegister(XPOWERS_AXP2101_DC_VOL2_CTRL);
        if (val == -1)return false;
        val &= 0x80;
        if (millivolt >= XPOWERS_AXP2101_DCDC3_VOL1_MIN && millivolt <= XPOWERS_AXP2101_DCDC3_VOL1_MAX) {
            if (millivolt % XPOWERS_AXP2101_DCDC3_VOL_STEPS1) {
                log_e("Mistake ! The steps is must %umV", XPOWERS_AXP2101_DCDC3_VOL_STEPS1);
                return false;
            }
            return  0 == writeRegister(XPOWERS_AXP2101_DC_VOL2_CTRL, val | (millivolt - XPOWERS_AXP2101_DCDC3_VOL_MIN) / XPOWERS_AXP2101_DCDC3_VOL_STEPS1);
        } else if (millivolt >= XPOWERS_AXP2101_DCDC3_VOL2_MIN && millivolt <= XPOWERS_AXP2101_DCDC3_VOL2_MAX) {
            if (millivolt % XPOWERS_AXP2101_DCDC3_VOL_STEPS2) {
                log_e("Mistake ! The steps is must %umV", XPOWERS_AXP2101_DCDC3_VOL_STEPS2);
                return false;
            }
            val |= (((millivolt - XPOWERS_AXP2101_DCDC3_VOL2_MIN) / XPOWERS_AXP2101_DCDC3_VOL_STEPS2) + XPOWERS_AXP2101_DCDC3_VOL_STEPS2_BASE);
            return  0 == writeRegister(XPOWERS_AXP2101_DC_VOL2_CTRL, val);
        } else if (millivolt >= XPOWERS_AXP2101_DCDC3_VOL3_MIN && millivolt <= XPOWERS_AXP2101_DCDC3_VOL3_MAX) {
            if (millivolt % XPOWERS_AXP2101_DCDC3_VOL_STEPS3) {
                log_e("Mistake ! The steps is must %umV", XPOWERS_AXP2101_DCDC3_VOL_STEPS3);
                return false;
            }
            val |= (((millivolt - XPOWERS_AXP2101_DCDC3_VOL3_MIN) / XPOWERS_AXP2101_DCDC3_VOL_STEPS3) + XPOWERS_AXP2101_DCDC3_VOL_STEPS3_BASE);
            return  0 == writeRegister(XPOWERS_AXP2101_DC_VOL2_CTRL, val);
        }
        return false;
    }


    uint16_t getDC3Voltage(void)
    {
        int val = readRegister(XPOWERS_AXP2101_DC_VOL2_CTRL) & 0x7F;
        if (val < XPOWERS_AXP2101_DCDC3_VOL_STEPS2_BASE) {
            return (val  * XPOWERS_AXP2101_DCDC3_VOL_STEPS1) +  XPOWERS_AXP2101_DCDC3_VOL_MIN;
        } else if (val >= XPOWERS_AXP2101_DCDC3_VOL_STEPS2_BASE && val < XPOWERS_AXP2101_DCDC3_VOL_STEPS3_BASE) {
            return (val  * XPOWERS_AXP2101_DCDC3_VOL_STEPS2) - 200;
        } else  {
            return (val  * XPOWERS_AXP2101_DCDC3_VOL_STEPS3)  - 7200;
        }
        return 0;
    }

    uint8_t getDC3WorkMode(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_DC_VOL2_CTRL, 7);
    }

    // DCDC3 85% low voltage turn off PMIC function
    void setDC3LowVoltagePowerDowm(bool en)
    {
        en ? setRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 2) : clrRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 2);
    }

    bool getDC3LowVoltagePowerDowmEn()
    {
        return getRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 2);
    }


    /*
    * Power control DCDC4 functions
    */
    /**
        0.5~1.2V,10mV/step,71steps
        1.22~1.84V,20mV/step,32steps
     */
    bool isEnableDC4(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 3);
    }

    bool enableDC4(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 3);
    }

    bool disableDC4(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 3);
    }

    bool setDC4Voltage(uint16_t millivolt)
    {
        int val = readRegister(XPOWERS_AXP2101_DC_VOL3_CTRL);
        if (val == -1)return false;
        val &= 0x80;
        if (millivolt >= XPOWERS_AXP2101_DCDC4_VOL1_MIN && millivolt <= XPOWERS_AXP2101_DCDC4_VOL1_MAX) {
            if (millivolt % XPOWERS_AXP2101_DCDC4_VOL_STEPS1) {
                log_e("Mistake ! The steps is must %umV", XPOWERS_AXP2101_DCDC4_VOL_STEPS1);
                return false;
            }
            return  0 == writeRegister(XPOWERS_AXP2101_DC_VOL3_CTRL, val | (millivolt - XPOWERS_AXP2101_DCDC4_VOL1_MIN) / XPOWERS_AXP2101_DCDC4_VOL_STEPS1);

        } else if (millivolt >= XPOWERS_AXP2101_DCDC4_VOL2_MIN && millivolt <= XPOWERS_AXP2101_DCDC4_VOL2_MAX) {
            if (millivolt % XPOWERS_AXP2101_DCDC4_VOL_STEPS2) {
                log_e("Mistake ! The steps is must %umV", XPOWERS_AXP2101_DCDC4_VOL_STEPS2);
                return false;
            }
            val |= (((millivolt - XPOWERS_AXP2101_DCDC4_VOL2_MIN) / XPOWERS_AXP2101_DCDC4_VOL_STEPS2) + XPOWERS_AXP2101_DCDC4_VOL_STEPS2_BASE);
            return  0 == writeRegister(XPOWERS_AXP2101_DC_VOL3_CTRL, val);

        }
        return false;
    }

    uint16_t getDC4Voltage(void)
    {
        int val = readRegister(XPOWERS_AXP2101_DC_VOL3_CTRL);
        if (val == -1)return 0;
        val &= 0x7F;
        if (val < XPOWERS_AXP2101_DCDC4_VOL_STEPS2_BASE) {
            return (val  * XPOWERS_AXP2101_DCDC4_VOL_STEPS1) +  XPOWERS_AXP2101_DCDC4_VOL1_MIN;
        } else  {
            return (val  * XPOWERS_AXP2101_DCDC4_VOL_STEPS2) - 200;
        }
        return 0;
    }

    // DCDC4 85% low voltage turn off PMIC function
    void setDC4LowVoltagePowerDowm(bool en)
    {
        en ? setRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 3) : clrRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 3);
    }

    bool getDC4LowVoltagePowerDowmEn()
    {
        return getRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 3);
    }

    /*
    * Power control DCDC5 functions,Output to gpio pin
    */
    bool isEnableDC5(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 4);
    }

    bool enableDC5(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 4);
    }

    bool disableDC5(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_DC_ONOFF_DVM_CTRL, 4);
    }

    bool setDC5Voltage(uint16_t millivolt)
    {
        if (millivolt % XPOWERS_AXP2101_DCDC5_VOL_STEPS) {
            log_e("Mistake ! The steps is must %u mV", XPOWERS_AXP2101_DCDC5_VOL_STEPS);
            return false;
        }
        if (millivolt != XPOWERS_AXP2101_DCDC5_VOL_1200MV && millivolt < XPOWERS_AXP2101_DCDC5_VOL_MIN) {
            log_e("Mistake ! DC5 minimum voltage is %umV ,%umV", XPOWERS_AXP2101_DCDC5_VOL_1200MV, XPOWERS_AXP2101_DCDC5_VOL_MIN);
            return false;
        } else if (millivolt > XPOWERS_AXP2101_DCDC5_VOL_MAX) {
            log_e("Mistake ! DC5 maximum voltage is %umV", XPOWERS_AXP2101_DCDC5_VOL_MAX);
            return false;
        }

        int val =  readRegister(XPOWERS_AXP2101_DC_VOL4_CTRL);
        if (val == -1)return false;
        val &= 0xE0;
        if (millivolt == XPOWERS_AXP2101_DCDC5_VOL_1200MV) {
            return 0 == writeRegister(XPOWERS_AXP2101_DC_VOL4_CTRL, val | XPOWERS_AXP2101_DCDC5_VOL_VAL);
        }
        val |= (millivolt - XPOWERS_AXP2101_DCDC5_VOL_MIN) / XPOWERS_AXP2101_DCDC5_VOL_STEPS;
        return 0 == writeRegister(XPOWERS_AXP2101_DC_VOL4_CTRL, val);
    }

    uint16_t getDC5Voltage(void)
    {
        int val = readRegister(XPOWERS_AXP2101_DC_VOL4_CTRL) ;
        if (val == -1)return 0;
        val &= 0x1F;
        if (val == XPOWERS_AXP2101_DCDC5_VOL_VAL)return XPOWERS_AXP2101_DCDC5_VOL_1200MV;
        return  (val * XPOWERS_AXP2101_DCDC5_VOL_STEPS) + XPOWERS_AXP2101_DCDC5_VOL_MIN;
    }

    bool isDC5FreqCompensationEn(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_DC_VOL4_CTRL, 5);
    }

    void enableDC5FreqCompensation()
    {
        setRegisterBit(XPOWERS_AXP2101_DC_VOL4_CTRL, 5);
    }

    void disableFreqCompensation()
    {
        clrRegisterBit(XPOWERS_AXP2101_DC_VOL4_CTRL, 5);
    }

    // DCDC4 85% low voltage turn off PMIC function
    void setDC5LowVoltagePowerDowm(bool en)
    {
        en ? setRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 4) : clrRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 4);
    }

    bool getDC5LowVoltagePowerDowmEn()
    {
        return getRegisterBit(XPOWERS_AXP2101_DC_OVP_UVP_CTRL, 4);
    }

    /*
    * Power control ALDO1 functions
    */
    bool isEnableALDO1(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 0);
    }

    bool enableALDO1(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 0);
    }

    bool disableALDO1(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 0);
    }

    bool setALDO1Voltage(uint16_t millivolt)
    {
        if (millivolt % XPOWERS_AXP2101_ALDO1_VOL_STEPS) {
            log_e("Mistake ! The steps is must %u mV", XPOWERS_AXP2101_ALDO1_VOL_STEPS);
            return false;
        }
        if (millivolt < XPOWERS_AXP2101_ALDO1_VOL_MIN) {
            log_e("Mistake ! ALDO1 minimum output voltage is  %umV", XPOWERS_AXP2101_ALDO1_VOL_MIN);
            return false;
        } else if (millivolt > XPOWERS_AXP2101_ALDO1_VOL_MAX) {
            log_e("Mistake ! ALDO1 maximum output voltage is  %umV", XPOWERS_AXP2101_ALDO1_VOL_MAX);
            return false;
        }
        uint16_t val =  readRegister(XPOWERS_AXP2101_LDO_VOL0_CTRL) & 0xE0;
        val |= (millivolt - XPOWERS_AXP2101_ALDO1_VOL_MIN) / XPOWERS_AXP2101_ALDO1_VOL_STEPS;
        return 0 == writeRegister(XPOWERS_AXP2101_LDO_VOL0_CTRL, val);
    }

    uint16_t getALDO1Voltage(void)
    {
        uint16_t val =  readRegister(XPOWERS_AXP2101_LDO_VOL0_CTRL) & 0x1F;
        return val * XPOWERS_AXP2101_ALDO1_VOL_STEPS + XPOWERS_AXP2101_ALDO1_VOL_MIN;
    }

    /*
    * Power control ALDO2 functions
    */
    bool isEnableALDO2(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 1);
    }

    bool enableALDO2(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 1);
    }

    bool disableALDO2(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 1);
    }

    bool setALDO2Voltage(uint16_t millivolt)
    {
        if (millivolt % XPOWERS_AXP2101_ALDO2_VOL_STEPS) {
            log_e("Mistake ! The steps is must %u mV", XPOWERS_AXP2101_ALDO2_VOL_STEPS);
            return false;
        }
        if (millivolt < XPOWERS_AXP2101_ALDO2_VOL_MIN) {
            log_e("Mistake ! ALDO2 minimum output voltage is  %umV", XPOWERS_AXP2101_ALDO2_VOL_MIN);
            return false;
        } else if (millivolt > XPOWERS_AXP2101_ALDO2_VOL_MAX) {
            log_e("Mistake ! ALDO2 maximum output voltage is  %umV", XPOWERS_AXP2101_ALDO2_VOL_MAX);
            return false;
        }
        uint16_t val =  readRegister(XPOWERS_AXP2101_LDO_VOL1_CTRL) & 0xE0;
        val |= (millivolt - XPOWERS_AXP2101_ALDO2_VOL_MIN) / XPOWERS_AXP2101_ALDO2_VOL_STEPS;
        return 0 == writeRegister(XPOWERS_AXP2101_LDO_VOL1_CTRL, val);
    }

    uint16_t getALDO2Voltage(void)
    {
        uint16_t val =  readRegister(XPOWERS_AXP2101_LDO_VOL1_CTRL) & 0x1F;
        return val * XPOWERS_AXP2101_ALDO2_VOL_STEPS + XPOWERS_AXP2101_ALDO2_VOL_MIN;
    }

    /*
     * Power control ALDO3 functions
     */
    bool isEnableALDO3(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 2);
    }

    bool enableALDO3(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 2);
    }

    bool disableALDO3(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 2);
    }

    bool setALDO3Voltage(uint16_t millivolt)
    {
        if (millivolt % XPOWERS_AXP2101_ALDO3_VOL_STEPS) {
            log_e("Mistake ! The steps is must %u mV", XPOWERS_AXP2101_ALDO3_VOL_STEPS);
            return false;
        }
        if (millivolt < XPOWERS_AXP2101_ALDO3_VOL_MIN) {
            log_e("Mistake ! ALDO3 minimum output voltage is  %umV", XPOWERS_AXP2101_ALDO3_VOL_MIN);
            return false;
        } else if (millivolt > XPOWERS_AXP2101_ALDO3_VOL_MAX) {
            log_e("Mistake ! ALDO3 maximum output voltage is  %umV", XPOWERS_AXP2101_ALDO3_VOL_MAX);
            return false;
        }
        uint16_t val =  readRegister(XPOWERS_AXP2101_LDO_VOL2_CTRL) & 0xE0;
        val |= (millivolt - XPOWERS_AXP2101_ALDO3_VOL_MIN) / XPOWERS_AXP2101_ALDO3_VOL_STEPS;
        return 0 == writeRegister(XPOWERS_AXP2101_LDO_VOL2_CTRL, val);
    }

    uint16_t getALDO3Voltage(void)
    {
        uint16_t val =  readRegister(XPOWERS_AXP2101_LDO_VOL2_CTRL) & 0x1F;
        return val * XPOWERS_AXP2101_ALDO3_VOL_STEPS + XPOWERS_AXP2101_ALDO3_VOL_MIN;
    }

    /*
     * Power control ALDO4 functions
     */
    bool isEnableALDO4(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 3);
    }

    bool enableALDO4(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 3);
    }

    bool disableALDO4(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 3);
    }

    bool setALDO4Voltage(uint16_t millivolt)
    {
        if (millivolt % XPOWERS_AXP2101_ALDO4_VOL_STEPS) {
            log_e("Mistake ! The steps is must %u mV", XPOWERS_AXP2101_ALDO4_VOL_STEPS);
            return false;
        }
        if (millivolt < XPOWERS_AXP2101_ALDO4_VOL_MIN) {
            log_e("Mistake ! ALDO4 minimum output voltage is  %umV", XPOWERS_AXP2101_ALDO4_VOL_MIN);
            return false;
        } else if (millivolt > XPOWERS_AXP2101_ALDO4_VOL_MAX) {
            log_e("Mistake ! ALDO4 maximum output voltage is  %umV", XPOWERS_AXP2101_ALDO4_VOL_MAX);
            return false;
        }
        uint16_t val =  readRegister(XPOWERS_AXP2101_LDO_VOL3_CTRL) & 0xE0;
        val |= (millivolt - XPOWERS_AXP2101_ALDO4_VOL_MIN) / XPOWERS_AXP2101_ALDO4_VOL_STEPS;
        return 0 == writeRegister(XPOWERS_AXP2101_LDO_VOL3_CTRL, val);
    }

    uint16_t getALDO4Voltage(void)
    {
        uint16_t val =  readRegister(XPOWERS_AXP2101_LDO_VOL3_CTRL) & 0x1F;
        return val * XPOWERS_AXP2101_ALDO4_VOL_STEPS + XPOWERS_AXP2101_ALDO4_VOL_MIN;
    }

    /*
    * Power control BLDO1 functions
    */
    bool isEnableBLDO1(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 4);
    }

    bool enableBLDO1(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 4);
    }

    bool disableBLDO1(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 4);
    }

    bool setBLDO1Voltage(uint16_t millivolt)
    {
        if (millivolt % XPOWERS_AXP2101_BLDO1_VOL_STEPS) {
            log_e("Mistake ! The steps is must %u mV", XPOWERS_AXP2101_BLDO1_VOL_STEPS);
            return false;
        }
        if (millivolt < XPOWERS_AXP2101_BLDO1_VOL_MIN) {
            log_e("Mistake ! BLDO1 minimum output voltage is  %umV", XPOWERS_AXP2101_BLDO1_VOL_MIN);
            return false;
        } else if (millivolt > XPOWERS_AXP2101_BLDO1_VOL_MAX) {
            log_e("Mistake ! BLDO1 maximum output voltage is  %umV", XPOWERS_AXP2101_BLDO1_VOL_MAX);
            return false;
        }
        int val =  readRegister(XPOWERS_AXP2101_LDO_VOL4_CTRL);
        if (val == -1)return  false;
        val &= 0xE0;
        val |= (millivolt - XPOWERS_AXP2101_BLDO1_VOL_MIN) / XPOWERS_AXP2101_BLDO1_VOL_STEPS;
        return 0 == writeRegister(XPOWERS_AXP2101_LDO_VOL4_CTRL, val);
    }

    uint16_t getBLDO1Voltage(void)
    {
        int val =  readRegister(XPOWERS_AXP2101_LDO_VOL4_CTRL);
        if (val == -1)return 0;
        val &= 0x1F;
        return val * XPOWERS_AXP2101_BLDO1_VOL_STEPS + XPOWERS_AXP2101_BLDO1_VOL_MIN;
    }

    /*
    * Power control BLDO2 functions
    */
    bool isEnableBLDO2(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 5);
    }

    bool enableBLDO2(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 5);
    }

    bool disableBLDO2(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 5);
    }

    bool setBLDO2Voltage(uint16_t millivolt)
    {
        if (millivolt % XPOWERS_AXP2101_BLDO2_VOL_STEPS) {
            log_e("Mistake ! The steps is must %u mV", XPOWERS_AXP2101_BLDO2_VOL_STEPS);
            return false;
        }
        if (millivolt < XPOWERS_AXP2101_BLDO2_VOL_MIN) {
            log_e("Mistake ! BLDO2 minimum output voltage is  %umV", XPOWERS_AXP2101_BLDO2_VOL_MIN);
            return false;
        } else if (millivolt > XPOWERS_AXP2101_BLDO2_VOL_MAX) {
            log_e("Mistake ! BLDO2 maximum output voltage is  %umV", XPOWERS_AXP2101_BLDO2_VOL_MAX);
            return false;
        }
        uint16_t val =  readRegister(XPOWERS_AXP2101_LDO_VOL5_CTRL) & 0xE0;
        val |= (millivolt - XPOWERS_AXP2101_BLDO2_VOL_MIN) / XPOWERS_AXP2101_BLDO2_VOL_STEPS;
        return 0 == writeRegister(XPOWERS_AXP2101_LDO_VOL5_CTRL, val);
    }

    uint16_t getBLDO2Voltage(void)
    {
        int val =  readRegister(XPOWERS_AXP2101_LDO_VOL5_CTRL);
        if (val == -1)return 0;
        val &= 0x1F;
        return val * XPOWERS_AXP2101_BLDO2_VOL_STEPS + XPOWERS_AXP2101_BLDO2_VOL_MIN;
    }

    /*
    * Power control CPUSLDO functions
    */
    bool isEnableCPUSLDO(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 6);
    }

    bool enableCPUSLDO(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 6);
    }

    bool disableCPUSLDO(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 6);
    }

    bool setCPUSLDOVoltage(uint16_t millivolt)
    {
        if (millivolt % XPOWERS_AXP2101_CPUSLDO_VOL_STEPS) {
            log_e("Mistake ! The steps is must %u mV", XPOWERS_AXP2101_CPUSLDO_VOL_STEPS);
            return false;
        }
        if (millivolt < XPOWERS_AXP2101_CPUSLDO_VOL_MIN) {
            log_e("Mistake ! CPULDO minimum output voltage is  %umV", XPOWERS_AXP2101_CPUSLDO_VOL_MIN);
            return false;
        } else if (millivolt > XPOWERS_AXP2101_CPUSLDO_VOL_MAX) {
            log_e("Mistake ! CPULDO maximum output voltage is  %umV", XPOWERS_AXP2101_CPUSLDO_VOL_MAX);
            return false;
        }
        uint16_t val =  readRegister(XPOWERS_AXP2101_LDO_VOL6_CTRL) & 0xE0;
        val |= (millivolt - XPOWERS_AXP2101_CPUSLDO_VOL_MIN) / XPOWERS_AXP2101_CPUSLDO_VOL_STEPS;
        return 0 == writeRegister(XPOWERS_AXP2101_LDO_VOL6_CTRL, val);
    }

    uint16_t getCPUSLDOVoltage(void)
    {
        int val =  readRegister(XPOWERS_AXP2101_LDO_VOL6_CTRL);
        if (val == -1)return 0;
        val &= 0x1F;
        return val * XPOWERS_AXP2101_CPUSLDO_VOL_STEPS + XPOWERS_AXP2101_CPUSLDO_VOL_MIN;
    }


    /*
    * Power control DLDO1 functions
    */
    bool isEnableDLDO1(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 7);
    }

    bool enableDLDO1(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 7);
    }

    bool disableDLDO1(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL0, 7);
    }

    bool setDLDO1Voltage(uint16_t millivolt)
    {
        if (millivolt % XPOWERS_AXP2101_DLDO1_VOL_STEPS) {
            log_e("Mistake ! The steps is must %u mV", XPOWERS_AXP2101_DLDO1_VOL_STEPS);
            return false;
        }
        if (millivolt < XPOWERS_AXP2101_DLDO1_VOL_MIN) {
            log_e("Mistake ! DLDO1 minimum output voltage is  %umV", XPOWERS_AXP2101_DLDO1_VOL_MIN);
            return false;
        } else if (millivolt > XPOWERS_AXP2101_DLDO1_VOL_MAX) {
            log_e("Mistake ! DLDO1 maximum output voltage is  %umV", XPOWERS_AXP2101_DLDO1_VOL_MAX);
            return false;
        }
        uint16_t val =  readRegister(XPOWERS_AXP2101_LDO_VOL7_CTRL) & 0xE0;
        val |= (millivolt - XPOWERS_AXP2101_DLDO1_VOL_MIN) / XPOWERS_AXP2101_DLDO1_VOL_STEPS;
        return 0 == writeRegister(XPOWERS_AXP2101_LDO_VOL7_CTRL, val);
    }

    uint16_t getDLDO1Voltage(void)
    {
        int val =  readRegister(XPOWERS_AXP2101_LDO_VOL7_CTRL);
        if (val == -1)return 0;
        val &= 0x1F;
        return val * XPOWERS_AXP2101_DLDO1_VOL_STEPS + XPOWERS_AXP2101_DLDO1_VOL_MIN;
    }

    /*
    * Power control DLDO2 functions
    */
    bool isEnableDLDO2(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL1, 0);
    }

    bool enableDLDO2(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL1, 0);
    }

    bool disableDLDO2(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_LDO_ONOFF_CTRL1, 0);
    }

    bool setDLDO2Voltage(uint16_t millivolt)
    {
        if (millivolt % XPOWERS_AXP2101_DLDO2_VOL_STEPS) {
            log_e("Mistake ! The steps is must %u mV", XPOWERS_AXP2101_DLDO2_VOL_STEPS);
            return false;
        }
        if (millivolt < XPOWERS_AXP2101_DLDO2_VOL_MIN) {
            log_e("Mistake ! DLDO2 minimum output voltage is  %umV", XPOWERS_AXP2101_DLDO2_VOL_MIN);
            return false;
        } else if (millivolt > XPOWERS_AXP2101_DLDO2_VOL_MAX) {
            log_e("Mistake ! DLDO2 maximum output voltage is  %umV", XPOWERS_AXP2101_DLDO2_VOL_MAX);
            return false;
        }
        uint16_t val =  readRegister(XPOWERS_AXP2101_LDO_VOL8_CTRL) & 0xE0;
        val |= (millivolt - XPOWERS_AXP2101_DLDO2_VOL_MIN) / XPOWERS_AXP2101_DLDO2_VOL_STEPS;
        return 0 == writeRegister(XPOWERS_AXP2101_LDO_VOL8_CTRL, val);
    }

    uint16_t getDLDO2Voltage(void)
    {
        int val =  readRegister(XPOWERS_AXP2101_LDO_VOL8_CTRL);
        if (val == -1)return 0;
        val &= 0x1F;
        return val * XPOWERS_AXP2101_DLDO2_VOL_STEPS + XPOWERS_AXP2101_DLDO2_VOL_MIN;
    }


    /*
     * Power ON OFF IRQ TIMMING Control method
     */

    void setIrqLevelTime(xpowers_irq_time_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_IRQ_OFF_ON_LEVEL_CTRL);
        if (val == -1)return;
        val &= 0xCF;
        writeRegister(XPOWERS_AXP2101_IRQ_OFF_ON_LEVEL_CTRL, val | (opt << 4));
    }

    xpowers_irq_time_t getIrqLevelTime(void)
    {
        return (xpowers_irq_time_t)((readRegister(XPOWERS_AXP2101_IRQ_OFF_ON_LEVEL_CTRL) & 0x30) >> 4);
    }

    /**
    * @brief Set the PEKEY power-on long press time.
    * @param opt: See xpowers_press_on_time_t enum for details.
    * @retval
    */
    bool setPowerKeyPressOnTime(uint8_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_IRQ_OFF_ON_LEVEL_CTRL);
        if (val == -1)return false;
        val  &= 0xFC;
        return 0 ==  writeRegister(XPOWERS_AXP2101_IRQ_OFF_ON_LEVEL_CTRL, val | opt);
    }

    /**
    * @brief Get the PEKEY power-on long press time.
    * @retval See xpowers_press_on_time_t enum for details.
    */
    uint8_t getPowerKeyPressOnTime(void)
    {
        int val =  readRegister(XPOWERS_AXP2101_IRQ_OFF_ON_LEVEL_CTRL);
        if (val == -1)return 0;
        return (val & 0x03) ;
    }

    /**
    * @brief Set the PEKEY power-off long press time.
    * @param opt: See xpowers_press_off_time_t enum for details.
    * @retval
    */
    bool setPowerKeyPressOffTime(uint8_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_IRQ_OFF_ON_LEVEL_CTRL);
        if (val == -1)return false;
        val  &= 0xF3;
        return 0 == writeRegister(XPOWERS_AXP2101_IRQ_OFF_ON_LEVEL_CTRL, val | (opt << 2));
    }

    /**
    * @brief Get the PEKEY power-off long press time.
    * @retval See xpowers_press_off_time_t enum for details.
    */
    uint8_t getPowerKeyPressOffTime(void)
    {
        return ((readRegister(XPOWERS_AXP2101_IRQ_OFF_ON_LEVEL_CTRL) & 0x0C) >> 2);
    }

    /*
     * ADC Control method
     */
    bool enableGeneralAdcChannel(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_ADC_CHANNEL_CTRL, 5);
    }

    bool disableGeneralAdcChannel(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_ADC_CHANNEL_CTRL, 5);
    }

    bool enableTemperatureMeasure(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_ADC_CHANNEL_CTRL, 4);
    }

    bool disableTemperatureMeasure(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_ADC_CHANNEL_CTRL, 4);
    }

    float getTemperature(void)
    {
        uint16_t raw = readRegisterH6L8(XPOWERS_AXP2101_ADC_DATA_RELUST8, XPOWERS_AXP2101_ADC_DATA_RELUST9);
        return XPOWERS_AXP2101_CONVERSION(raw);
    }

    bool enableSystemVoltageMeasure(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_ADC_CHANNEL_CTRL, 3);
    }

    bool disableSystemVoltageMeasure(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_ADC_CHANNEL_CTRL, 3);
    }

    uint16_t getSystemVoltage(void)
    {
        return readRegisterH6L8(XPOWERS_AXP2101_ADC_DATA_RELUST6, XPOWERS_AXP2101_ADC_DATA_RELUST7);
    }

    bool enableVbusVoltageMeasure(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_ADC_CHANNEL_CTRL, 2);
    }

    bool disableVbusVoltageMeasure(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_ADC_CHANNEL_CTRL, 2);
    }

    uint16_t getVbusVoltage(void)
    {
        if (!isVbusIn()) {
            return 0;
        }
        return readRegisterH6L8(XPOWERS_AXP2101_ADC_DATA_RELUST4, XPOWERS_AXP2101_ADC_DATA_RELUST5);
    }

    bool enableTSPinMeasure(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_ADC_CHANNEL_CTRL, 1);
    }

    bool disableTSPinMeasure(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_ADC_CHANNEL_CTRL, 1);
    }

    bool enableTSPinLowFreqSample(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_ADC_CHANNEL_CTRL, 7);
    }

    bool disableTSPinLowFreqSample(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_ADC_DATA_RELUST2, 7);
    }

    uint16_t getTsTemperature(void)
    {
        return readRegisterH6L8(XPOWERS_AXP2101_ADC_DATA_RELUST2, XPOWERS_AXP2101_ADC_DATA_RELUST3);
    }

    bool enableBattVoltageMeasure(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_ADC_CHANNEL_CTRL, 0);
    }

    bool disableBattVoltageMeasure(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_ADC_CHANNEL_CTRL, 0);
    }

    bool enableBattDetection(void)
    {
        return setRegisterBit(XPOWERS_AXP2101_BAT_DET_CTRL, 0);
    }

    bool disableBattDetection(void)
    {
        return clrRegisterBit(XPOWERS_AXP2101_BAT_DET_CTRL, 0);
    }

    uint16_t getBattVoltage(void)
    {
        if (!isBatteryConnect()) {
            return 0;
        }
        return readRegisterH5L8(XPOWERS_AXP2101_ADC_DATA_RELUST0, XPOWERS_AXP2101_ADC_DATA_RELUST1);
    }

    int getBatteryPercent(void)
    {
        if (!isBatteryConnect()) {
            return -1;
        }
        return readRegister(XPOWERS_AXP2101_BAT_PERCENT_DATA);
    }

    /*
    * CHG LED setting and control
    */
    // void enableChargingLed(void)
    // {
    //     setRegisterBit(XPOWERS_AXP2101_CHGLED_SET_CTRL, 0);
    // }

    // void disableChargingLed(void)
    // {
    //     clrRegisterBit(XPOWERS_AXP2101_CHGLED_SET_CTRL, 0);
    // }

    /**
    * @brief Set charging led mode.
    * @retval See xpowers_chg_led_mode_t enum for details.
    */
    void setChargingLedMode(uint8_t mode)
    {
        int val;
        switch (mode) {
        case XPOWERS_CHG_LED_OFF:
        // clrRegisterBit(XPOWERS_AXP2101_CHGLED_SET_CTRL, 0);
        // break;
        case XPOWERS_CHG_LED_BLINK_1HZ:
        case XPOWERS_CHG_LED_BLINK_4HZ:
        case XPOWERS_CHG_LED_ON:
            val = readRegister(XPOWERS_AXP2101_CHGLED_SET_CTRL);
            if (val == -1)return;
            val &= 0xC8;
            val |= 0x05;    //use manual ctrl
            val |= (mode << 4);
            writeRegister(XPOWERS_AXP2101_CHGLED_SET_CTRL, val);
            break;
        case XPOWERS_CHG_LED_CTRL_CHG:
            val = readRegister(XPOWERS_AXP2101_CHGLED_SET_CTRL);
            if (val == -1)return;
            val &= 0xF9;
            writeRegister(XPOWERS_AXP2101_CHGLED_SET_CTRL, val | 0x01); // use type A mode
            // writeRegister(XPOWERS_AXP2101_CHGLED_SET_CTRL, val | 0x02); // use type B mode
            break;
        default:
            break;
        }
    }

    uint8_t getChargingLedMode()
    {
        int val = readRegister(XPOWERS_AXP2101_CHGLED_SET_CTRL);
        if (val == -1)return XPOWERS_CHG_LED_OFF;
        val >>= 1;
        if ((val & 0x02) == 0x02) {
            val >>= 4;
            return val & 0x03;
        }
        return XPOWERS_CHG_LED_CTRL_CHG;
    }

    /**
     * @brief 预充电充电电流限制
     * @note  Precharge current limit 25*N mA
     * @param  opt: 25 * opt
     * @retval None
     */
    void setPrechargeCurr(xpowers_prechg_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_IPRECHG_SET);
        if (val == -1)return;
        val &= 0xFC;
        writeRegister(XPOWERS_AXP2101_IPRECHG_SET, val | opt);
    }

    xpowers_prechg_t getPrechargeCurr(void)
    {
        return (xpowers_prechg_t)(readRegister(XPOWERS_AXP2101_IPRECHG_SET) & 0x03);
    }


    /**
    * @brief Set charge current.
    * @param  opt: See xpowers_axp2101_chg_curr_t enum for details.
    * @retval
    */
    bool setChargerConstantCurr(uint8_t opt)
    {
        if (opt > XPOWERS_AXP2101_CHG_CUR_1000MA)return false;
        int val = readRegister(XPOWERS_AXP2101_ICC_CHG_SET);
        if (val == -1)return false;
        val &= 0xE0;
        return 0 == writeRegister(XPOWERS_AXP2101_ICC_CHG_SET, val | opt);
    }

    /**
     * @brief Get charge current settings.
    *  @retval See xpowers_axp2101_chg_curr_t enum for details.
     */
    uint8_t getChargerConstantCurr(void)
    {
        int val = readRegister(XPOWERS_AXP2101_ICC_CHG_SET);
        if (val == -1)return 0;
        return val & 0x1F;
    }

    /**
     * @brief  充电终止电流限制
     * @note   Charging termination of current limit
     * @retval
     */
    void setChargerTerminationCurr(xpowers_axp2101_chg_iterm_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_ITERM_CHG_SET_CTRL);
        if (val == -1)return;
        val &= 0xF0;
        writeRegister(XPOWERS_AXP2101_ICC_CHG_SET, val | opt);
    }

    xpowers_axp2101_chg_iterm_t getChargerTerminationCurr(void)
    {
        return (xpowers_axp2101_chg_iterm_t)(readRegister(XPOWERS_AXP2101_ITERM_CHG_SET_CTRL) & 0x0F);
    }

    void enableChargerTerminationLimit(void)
    {
        int val = readRegister(XPOWERS_AXP2101_ITERM_CHG_SET_CTRL);
        if (val == -1)return;
        writeRegister(XPOWERS_AXP2101_ITERM_CHG_SET_CTRL, val | 0x10);
    }

    void disableChargerTerminationLimit(void)
    {
        int val = readRegister(XPOWERS_AXP2101_ITERM_CHG_SET_CTRL);
        if (val == -1)return;
        writeRegister(XPOWERS_AXP2101_ITERM_CHG_SET_CTRL, val & 0xEF);
    }

    bool isChargerTerminationLimit(void)
    {
        return getRegisterBit(XPOWERS_AXP2101_ITERM_CHG_SET_CTRL, 4);
    }


    /**
    * @brief Set charge target voltage.
    * @param  opt: See xpowers_axp2101_chg_vol_t enum for details.
    * @retval
    */
    bool setChargeTargetVoltage(uint8_t opt)
    {
        if (opt >= XPOWERS_AXP2101_CHG_VOL_MAX)return false;
        int val = readRegister(XPOWERS_AXP2101_CV_CHG_VOL_SET);
        if (val == -1)return false;
        val &= 0xFC;
        return 0 == writeRegister(XPOWERS_AXP2101_CV_CHG_VOL_SET, val | opt);
    }

    /**
     * @brief Get charge target voltage settings.
     * @retval See xpowers_axp2101_chg_vol_t enum for details.
     */
    uint8_t getChargeTargetVoltage(void)
    {
        return (readRegister(XPOWERS_AXP2101_CV_CHG_VOL_SET) & 0x03);
    }


    /**
     * @brief  设定热阈值
     * @note   Thermal regulation threshold setting
     */
    void setThermaThreshold(xpowers_thermal_t opt)
    {
        int val = readRegister(XPOWERS_AXP2101_THE_REGU_THRES_SET);
        if (val == -1)return;
        val &= 0xFC;
        writeRegister(XPOWERS_AXP2101_THE_REGU_THRES_SET, val | opt);
    }

    xpowers_thermal_t getThermaThreshold(void)
    {
        return (xpowers_thermal_t)(readRegister(XPOWERS_AXP2101_THE_REGU_THRES_SET) & 0x03);
    }

    uint8_t getBatteryParameter()
    {
        return  readRegister(XPOWERS_AXP2101_BAT_PARAME);
    }

    void fuelGaugeControl(bool writeROM, bool enable)
    {
        if (writeROM) {
            clrRegisterBit(XPOWERS_AXP2101_FUEL_GAUGE_CTRL, 4);
        } else {
            setRegisterBit(XPOWERS_AXP2101_FUEL_GAUGE_CTRL, 4);
        }
        if (enable) {
            setRegisterBit(XPOWERS_AXP2101_FUEL_GAUGE_CTRL, 0);
        } else {
            clrRegisterBit(XPOWERS_AXP2101_FUEL_GAUGE_CTRL, 0);
        }
    }

    /*
     * Interrupt status/control functions
     */

    /**
    * @brief  Get the interrupt controller mask value.
    * @retval   Mask value corresponds to xpowers_axp2101_irq_t ,
    */
    uint64_t getIrqStatus(void)
    {
        statusRegister[0] = readRegister(XPOWERS_AXP2101_INTSTS1);
        statusRegister[1] = readRegister(XPOWERS_AXP2101_INTSTS2);
        statusRegister[2] = readRegister(XPOWERS_AXP2101_INTSTS3);
        return (uint32_t)(statusRegister[0] << 16) | (uint32_t)(statusRegister[1] << 8) | (uint32_t)(statusRegister[2]);
    }


    /**
     * @brief  Clear interrupt controller state.
     */
    void clearIrqStatus(void)
    {
        for (int i = 0; i < XPOWERS_AXP2101_INTSTS_CNT; i++) {
            writeRegister(XPOWERS_AXP2101_INTSTS1 + i, 0xFF);
            statusRegister[i] = 0;
        }
    }

    /*
    *  @brief  Debug interrupt setting register
    * */
    void printIntRegister()
    {
        for (int i = 0; i < XPOWERS_AXP2101_INTSTS_CNT; i++) {
            uint8_t val =  readRegister(XPOWERS_AXP2101_INTEN1 + i);
            printf("INT[%d] HEX:0x%X\n", i, val);
        }
    }

    /**
     * @brief  Eanble PMU interrupt control mask .
     * @param  opt: View the related chip type xpowers_axp2101_irq_t enumeration
     *              parameters in "XPowersParams.hpp"
     * @retval
     */
    bool enableIRQ(uint64_t opt)
    {
        return setInterruptImpl(opt, true);
    }

    /**
     * @brief  Disable PMU interrupt control mask .
     * @param  opt: View the related chip type xpowers_axp2101_irq_t enumeration
     *              parameters in "XPowersParams.hpp"
     * @retval
     */
    bool disableIRQ(uint64_t opt)
    {
        return setInterruptImpl(opt, false);
    }

    //IRQ STATUS 0
    bool isDropWarningLevel2Irq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_WARNING_LEVEL2_IRQ;
        if (intRegister[0] & mask) {
            return IS_BIT_SET(statusRegister[0], mask);
        }
        return false;
    }

    bool isDropWarningLevel1Irq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_WARNING_LEVEL1_IRQ;
        if (intRegister[0] & mask) {
            return IS_BIT_SET(statusRegister[0], mask);
        }
        return false;
    }

    bool isGaugeWdtTimeoutIrq()
    {
        uint8_t mask = XPOWERS_AXP2101_WDT_TIMEOUT_IRQ;
        if (intRegister[0] & mask) {
            return IS_BIT_SET(statusRegister[0], mask);
        }
        return false;
    }

    bool isBatChargerOverTemperatureIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_BAT_CHG_OVER_TEMP_IRQ;
        if (intRegister[0] & mask) {
            return IS_BIT_SET(statusRegister[0], mask);
        }
        return false;
    }

    bool isBatChargerUnderTemperatureIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_BAT_CHG_UNDER_TEMP_IRQ;
        if (intRegister[0] & mask) {
            return IS_BIT_SET(statusRegister[0], mask);
        }
        return false;
    }

    bool isBatWorkOverTemperatureIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_BAT_NOR_OVER_TEMP_IRQ;
        if (intRegister[0] & mask) {
            return IS_BIT_SET(statusRegister[0], mask);
        }
        return false;
    }

    bool isBatWorkUnderTemperatureIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_BAT_NOR_UNDER_TEMP_IRQ;
        if (intRegister[0] & mask) {
            return IS_BIT_SET(statusRegister[0], mask);
        }
        return false;
    }

    //IRQ STATUS 1
    bool isVbusInsertIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_VBUS_INSERT_IRQ  >> 8;
        if (intRegister[1] & mask) {
            return IS_BIT_SET(statusRegister[1], mask);
        }
        return false;
    }

    bool isVbusRemoveIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_VBUS_REMOVE_IRQ  >> 8;
        if (intRegister[1] & mask) {
            return IS_BIT_SET(statusRegister[1], mask);
        }
        return false;
    }

    bool isBatInsertIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_BAT_INSERT_IRQ  >> 8;
        if (intRegister[1] & mask) {
            return IS_BIT_SET(statusRegister[1], mask);
        }
        return false;
    }

    bool isBatRemoveIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_BAT_REMOVE_IRQ  >> 8;
        if (intRegister[1] & mask) {
            return IS_BIT_SET(statusRegister[1], mask);
        }
        return false;
    }

    bool isPekeyShortPressIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_PKEY_SHORT_IRQ  >> 8;
        if (intRegister[1] & mask) {
            return IS_BIT_SET(statusRegister[1], mask);
        }
        return false;

    }

    bool isPekeyLongPressIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_PKEY_LONG_IRQ  >> 8;
        if (intRegister[1] & mask) {
            return IS_BIT_SET(statusRegister[1], mask);
        }
        return false;
    }

    bool isPekeyNegativeIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_PKEY_NEGATIVE_IRQ  >> 8;
        if (intRegister[1] & mask) {
            return IS_BIT_SET(statusRegister[1], mask);
        }
        return false;
    }

    bool isPekeyPositiveIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_PKEY_POSITIVE_IRQ  >> 8;
        if (intRegister[1] & mask) {
            return IS_BIT_SET(statusRegister[1], mask);
        }
        return false;
    }

    //IRQ STATUS 2
    bool isWdtExpireIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_WDT_EXPIRE_IRQ  >> 16;
        if (intRegister[2] & mask) {
            return IS_BIT_SET(statusRegister[2], mask);
        }
        return false;
    }

    bool isLdoOverCurrentIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_LDO_OVER_CURR_IRQ  >> 16;
        if (intRegister[2] & mask) {
            return IS_BIT_SET(statusRegister[2], mask);
        }
        return false;
    }

    bool isBatfetOverCurrentIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_BATFET_OVER_CURR_IRQ  >> 16;
        if (intRegister[2] & mask) {
            return IS_BIT_SET(statusRegister[2], mask);
        }
        return false;
    }

    bool isBatChagerDoneIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_BAT_CHG_DONE_IRQ  >> 16;
        if (intRegister[2] & mask) {
            return IS_BIT_SET(statusRegister[2], mask);
        }
        return false;
    }

    bool isBatChagerStartIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_BAT_CHG_START_IRQ  >> 16;
        if (intRegister[2] & mask) {
            return IS_BIT_SET(statusRegister[2], mask);
        }
        return false;
    }

    bool isBatDieOverTemperatureIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_DIE_OVER_TEMP_IRQ  >> 16;
        if (intRegister[2] & mask) {
            return IS_BIT_SET(statusRegister[2], mask);
        }
        return false;
    }

    bool isChagerOverTimeoutIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_CHAGER_TIMER_IRQ  >> 16;
        if (intRegister[2] & mask) {
            return IS_BIT_SET(statusRegister[2], mask);
        }
        return false;
    }

    bool isBatOverVoltageIrq(void)
    {
        uint8_t mask = XPOWERS_AXP2101_BAT_OVER_VOL_IRQ  >> 16;
        if (intRegister[2] & mask) {
            return IS_BIT_SET(statusRegister[2], mask);
        }
        return false;
    }


    uint8_t getChipID(void)
    {
        return readRegister(XPOWERS_AXP2101_IC_TYPE);
    }

protected:

    uint16_t getPowerChannelVoltage(uint8_t channel)
    {
        switch (channel) {
        case XPOWERS_DCDC1:
            return getDC1Voltage();
        case XPOWERS_DCDC2:
            return getDC2Voltage();
        case XPOWERS_DCDC3:
            return getDC3Voltage();
        case XPOWERS_DCDC4:
            return getDC4Voltage();
        case XPOWERS_DCDC5:
            return getDC5Voltage();
        case XPOWERS_ALDO1:
            return getALDO1Voltage();
        case XPOWERS_ALDO2:
            return getALDO2Voltage();
        case XPOWERS_ALDO3:
            return getALDO3Voltage();
        case XPOWERS_ALDO4:
            return getALDO4Voltage();
        case XPOWERS_BLDO1:
            return getBLDO1Voltage();
        case XPOWERS_BLDO2:
            return getBLDO2Voltage();
        case XPOWERS_DLDO1:
            return getDLDO1Voltage();
        case XPOWERS_DLDO2:
            return getDLDO2Voltage();
        case XPOWERS_VBACKUP:
            return getButtonBatteryVoltage();
        default:
            break;
        }
        return 0;
    }

    bool inline enablePowerOutput(uint8_t channel)
    {
        switch (channel) {
        case XPOWERS_DCDC1:
            return enableDC1();
        case XPOWERS_DCDC2:
            return enableDC2();
        case XPOWERS_DCDC3:
            return enableDC3();
        case XPOWERS_DCDC4:
            return enableDC4();
        case XPOWERS_DCDC5:
            return enableDC5();
        case XPOWERS_ALDO1:
            return enableALDO1();
        case XPOWERS_ALDO2:
            return enableALDO2();
        case XPOWERS_ALDO3:
            return enableALDO3();
        case XPOWERS_ALDO4:
            return enableALDO4();
        case XPOWERS_BLDO1:
            return enableBLDO1();
        case XPOWERS_BLDO2:
            return enableBLDO2();
        case XPOWERS_DLDO1:
            return enableDLDO1();
        case XPOWERS_DLDO2:
            return enableDLDO2();
        case XPOWERS_VBACKUP:
            return enableButtonBatteryCharge();
        default:
            break;
        }
        return false;
    }

    bool inline disablePowerOutput(uint8_t channel)
    {
        if (getProtectedChannel(channel)) {
            log_e("Failed to disable the power channel, the power channel has been protected");
            return false;
        }
        switch (channel) {
        case XPOWERS_DCDC1:
            return disableDC1();
        case XPOWERS_DCDC2:
            return disableDC2();
        case XPOWERS_DCDC3:
            return disableDC3();
        case XPOWERS_DCDC4:
            return disableDC4();
        case XPOWERS_DCDC5:
            return disableDC5();
        case XPOWERS_ALDO1:
            return disableALDO1();
        case XPOWERS_ALDO2:
            return disableALDO2();
        case XPOWERS_ALDO3:
            return disableALDO3();
        case XPOWERS_ALDO4:
            return disableALDO4();
        case XPOWERS_BLDO1:
            return disableBLDO1();
        case XPOWERS_BLDO2:
            return disableBLDO2();
        case XPOWERS_DLDO1:
            return disableDLDO1();
        case XPOWERS_DLDO2:
            return disableDLDO2();
        case XPOWERS_VBACKUP:
            return disableButtonBatteryCharge();
        case XPOWERS_CPULDO:
            return disableCPUSLDO();
        default:
            break;
        }
        return false;
    }

    bool inline isPowerChannelEnable(uint8_t channel)
    {
        switch (channel) {
        case XPOWERS_DCDC1:
            return isEnableDC1();
        case XPOWERS_DCDC2:
            return isEnableDC2();
        case XPOWERS_DCDC3:
            return isEnableDC3();
        case XPOWERS_DCDC4:
            return isEnableDC4();
        case XPOWERS_DCDC5:
            return isEnableDC5();
        case XPOWERS_ALDO1:
            return isEnableALDO1();
        case XPOWERS_ALDO2:
            return isEnableALDO2();
        case XPOWERS_ALDO3:
            return isEnableALDO3();
        case XPOWERS_ALDO4:
            return isEnableALDO4();
        case XPOWERS_BLDO1:
            return isEnableBLDO1();
        case XPOWERS_BLDO2:
            return isEnableBLDO2();
        case XPOWERS_DLDO1:
            return isEnableDLDO1();
        case XPOWERS_DLDO2:
            return isEnableDLDO2();
        case XPOWERS_VBACKUP:
            return isEanbleButtonBatteryCharge();
        case XPOWERS_CPULDO:
            return isEnableCPUSLDO();
        default:
            break;
        }
        return false;
    }

    bool inline setPowerChannelVoltage(uint8_t channel, uint16_t millivolt)
    {
        if (getProtectedChannel(channel)) {
            log_e("Failed to set the power channel, the power channel has been protected");
            return false;
        }
        switch (channel) {
        case XPOWERS_DCDC1:
            return setDC1Voltage(millivolt);
        case XPOWERS_DCDC2:
            return setDC2Voltage(millivolt);
        case XPOWERS_DCDC3:
            return setDC3Voltage(millivolt);
        case XPOWERS_DCDC4:
            return setDC4Voltage(millivolt);
        case XPOWERS_DCDC5:
            return setDC5Voltage(millivolt);
        case XPOWERS_ALDO1:
            return setALDO1Voltage(millivolt);
        case XPOWERS_ALDO2:
            return setALDO2Voltage(millivolt);
        case XPOWERS_ALDO3:
            return setALDO3Voltage(millivolt);
        case XPOWERS_ALDO4:
            return setALDO4Voltage(millivolt);
        case XPOWERS_BLDO1:
            return setBLDO1Voltage(millivolt);
        case XPOWERS_BLDO2:
            return setBLDO1Voltage(millivolt);
        case XPOWERS_DLDO1:
            return setDLDO1Voltage(millivolt);
        case XPOWERS_DLDO2:
            return setDLDO1Voltage(millivolt);
        case XPOWERS_VBACKUP:
            return setButtonBatteryChargeVoltage(millivolt);
        case XPOWERS_CPULDO:
            return setCPUSLDOVoltage(millivolt);
        default:
            break;
        }
        return false;
    }

    bool initImpl()
    {
        if (getChipID() == XPOWERS_AXP2101_CHIP_ID) {
            setChipModel(XPOWERS_AXP2101);
            disableTSPinMeasure();      //Disable NTC temperature detection by default
            return true;
        }
        return  false;
    }

    /*
     * Interrupt control functions
     */
    bool setInterruptImpl(uint32_t opts, bool enable)
    {
        int res = 0;
        uint8_t data = 0, value = 0;
        log_d("%s - HEX:0x%lx \n", enable ? "ENABLE" : "DISABLE", opts);
        if (opts & 0x0000FF) {
            value = opts & 0xFF;
            // log_d("Write INT0: %x\n", value);
            data = readRegister(XPOWERS_AXP2101_INTEN1);
            intRegister[0] =  enable ? (data | value) : (data & (~value));
            res |= writeRegister(XPOWERS_AXP2101_INTEN1, intRegister[0]);
        }
        if (opts & 0x00FF00) {
            value = opts >> 8;
            // log_d("Write INT1: %x\n", value);
            data = readRegister(XPOWERS_AXP2101_INTEN2);
            intRegister[1] =  enable ? (data | value) : (data & (~value));
            res |= writeRegister(XPOWERS_AXP2101_INTEN2, intRegister[1]);
        }
        if (opts & 0xFF0000) {
            value = opts >> 16;
            // log_d("Write INT2: %x\n", value);
            data = readRegister(XPOWERS_AXP2101_INTEN3);
            intRegister[2] =  enable ? (data | value) : (data & (~value));
            res |= writeRegister(XPOWERS_AXP2101_INTEN3, intRegister[2]);
        }
        return res == 0;
    }

    const char  *getChipNameImpl(void)
    {
        return "AXP2101";
    }

private:
    uint8_t statusRegister[XPOWERS_AXP2101_INTSTS_CNT];
    uint8_t intRegister[XPOWERS_AXP2101_INTSTS_CNT];
};


typedef XPowersAXP2101 XPowersPMU;

// udělám si deklaraci komponenty a metod, definice bude v axp2101.cpp    
class AXP2101Component : public Component, public i2c::I2CDevice {
  public:
    void setup() override;
    float get_setup_priority() const override;
    void dump_config() override;
  private:
    XPowersPMU PMU; // zatím využuji externí knihovnu vloženou přes yaml XPowersLib=https://github.com/lewisxhe/XPowersLib.git
};


} // namespace axp2101
} // namespace esphome
#endif

