// LilyGo Watch S3 - https://github.com/Xinyuan-LilyGO/TTGO_TWatch_Library/blob/t-watch-s3/src/LilyGoLib.cpp

// budeme potřebovat hlavičkový soubor a logovat

#include "axp2101.h"
#include "esphome/core/log.h"

namespace esphome {
namespace axp2101 {
    
static const char *TAG = "axp2101";

float AXP2101Component::get_setup_priority() const { return esphome::setup_priority::IO; }

void AXP2101Component::setup() {

// This will be called once to set up the component
// think of it as the setup() call in Arduino
  ESP_LOGD(TAG, "AXP2101 component setup");
  uint8_t addr = AXP2101_SLAVE_ADDRESS;
  if (this->read_register(XPOWERS_AXP2101_INPUT_VOL_LIMIT_CTRL, &addr, 1) != i2c::ERROR_OK) {
    ESP_LOGE(TAG, "Failed to read AXP2101_FW register");
    this->mark_failed();
    return;
  }
  // if (!PMU.begin(Wire, AXP2101_SLAVE_ADDRESS, I2C_SDA, I2C_SCL)) {
  //   ESP_LOGE(TAG, "Failed to initialize power.....");
  //   while (1) {
  //     // delay(5000);
  //   }
  // }

  //   if (!PMU.begin(AXP2101_SLAVE_ADDRESS, I2C_SDA, I2C_SCL)) {
  //   ESP_LOGE(TAG, "Failed to initialize power.....");
  //   while (1) {
  //     // delay(5000);
  //   }
  // }
  // Set the minimum common working voltage of the PMU VBUS input,
  // below this value will turn off the PMU
  PMU.setVbusVoltageLimit(XPOWERS_AXP2101_VBUS_VOL_LIM_4V36);

  // Set the maximum current of the PMU VBUS input,
  // higher than this value will turn off the PMU
  PMU.setVbusCurrentLimit(XPOWERS_AXP2101_VBUS_CUR_LIM_100MA);

  // Set VSY off voltage as 2600mV , Adjustment range 2600mV ~ 3300mV
  PMU.setSysPowerDownVoltage(2600);

  // Turn off not use power channel
  PMU.disableDC2();
  PMU.disableDC3();
  PMU.disableDC4();
  PMU.disableDC5();

  PMU.disableBLDO1();

  PMU.disableCPUSLDO();
  PMU.disableDLDO1();
  PMU.disableDLDO2();

  // ! ESP32S3 VDD, Don't change
  // setDC1Voltage(3300);

  //! RTC VBAT , Don't change
  PMU.setALDO1Voltage(3300);
  PMU.enableALDO1();

  //! TFT BACKLIGHT VDD , Don't change
  PMU.setALDO2Voltage(3300);
  PMU.enableALDO2();
  ESP_LOGD(TAG, "Backlight ALDO2 enabled");

  //! Screen touch VDD , Don't change
  PMU.setALDO3Voltage(3300);
  PMU.enableALDO3();

  //! Radio VDD , Don't change
  PMU.setALDO4Voltage(3300);
  PMU.enableALDO4();

  //! DRV2605 enable
  PMU.setBLDO2Voltage(3300);
  PMU.enableBLDO2();

  PMU.clearIrqStatus();

  // Set the time of pressing the button to turn off
  PMU.setPowerKeyPressOffTime(XPOWERS_POWEROFF_4S);

  // Set the button power-on press time
  PMU.setPowerKeyPressOnTime(XPOWERS_POWERON_128MS);

  // It is necessary to disable the detection function of the TS pin on the board
  // without the battery temperature detection function, otherwise it will cause abnormal charging
  PMU.disableTSPinMeasure();

  // Enable internal ADC detection
  PMU.enableBattDetection();
  PMU.enableVbusVoltageMeasure();
  PMU.enableBattVoltageMeasure();
  PMU.enableSystemVoltageMeasure();
  PMU.disableTemperatureMeasure();

  // t-watch no chg led
  //setChargingLedMode(XPOWERS_CHG_LED_OFF);

  // Disable all interrupts
  PMU.disableIRQ(XPOWERS_AXP2101_ALL_IRQ);
  // Clear all interrupt flags
  PMU.clearIrqStatus();
  // Enable the required interrupt function
  PMU.enableIRQ(XPOWERS_AXP2101_BAT_INSERT_IRQ | XPOWERS_AXP2101_BAT_REMOVE_IRQ |     // BATTERY
                XPOWERS_AXP2101_VBUS_INSERT_IRQ | XPOWERS_AXP2101_VBUS_REMOVE_IRQ |   // VBUS
                XPOWERS_AXP2101_PKEY_SHORT_IRQ | XPOWERS_AXP2101_PKEY_LONG_IRQ |      // POWER KEY
                XPOWERS_AXP2101_BAT_CHG_DONE_IRQ | XPOWERS_AXP2101_BAT_CHG_START_IRQ  // CHARGE
                // XPOWERS_PKEY_NEGATIVE_IRQ | XPOWERS_PKEY_POSITIVE_IRQ   |   //POWER KEY
  );

  // Set the precharge charging current
  PMU.setPrechargeCurr(XPOWERS_AXP2101_PRECHARGE_50MA);
  // Set constant current charge current limit
  PMU.setChargerConstantCurr(XPOWERS_AXP2101_CHG_CUR_300MA);
  // Set stop charging termination current
  PMU.setChargerTerminationCurr(XPOWERS_AXP2101_CHG_ITERM_25MA);

  // Set charge cut-off voltage
  PMU.setChargeTargetVoltage(XPOWERS_AXP2101_CHG_VOL_4V35);

  // Set RTC Battery voltage to 3.3V
  PMU.setButtonBatteryChargeVoltage(3300);

  PMU.enableButtonBatteryCharge();

  // Set the time of pressing the button to turn off
  PMU.setPowerKeyPressOffTime(XPOWERS_POWEROFF_4S);
}


void AXP2101Component::dump_config() {
  ESP_LOGCONFIG(TAG, "AXP2101:");
  LOG_I2C_DEVICE(this);
}

// https://github.com/lewisxhe/XPowersLib/blob/master/src/XPowersLibInterface.cpp
bool XPowersLibInterface::isChannelAvailable(uint8_t channel)
{
    if (__chipModel == XPOWERS_AXP2101) {
        switch (channel) {
        case XPOWERS_DCDC1:
        case XPOWERS_DCDC2:
        case XPOWERS_DCDC3:
        case XPOWERS_DCDC4:
        case XPOWERS_DCDC5:
        case XPOWERS_ALDO1:
        case XPOWERS_ALDO2:
        case XPOWERS_ALDO3:
        case XPOWERS_ALDO4:
        case XPOWERS_BLDO1:
        case XPOWERS_BLDO2:
        case XPOWERS_VBACKUP:
        case XPOWERS_CPULDO:
            return true;
        default:
            // DLDO is not available, will also return false
            return false;
        }
    }
    return false;
}

void XPowersLibInterface::setProtectedChannel(uint8_t channel)
{
    __protectedMask |= _BV(channel);
}

void XPowersLibInterface::setUnprotectChannel(uint8_t channel)
{
    __protectedMask &= (~_BV(channel));
}

bool XPowersLibInterface::getProtectedChannel(uint8_t channel)
{
    return __protectedMask & _BV(channel);
}


uint16_t XPowersLibInterface::getVbusVoltage()
{
    return 0;
}

static uint64_t inline check_params(uint32_t opt, uint32_t params, uint64_t mask)
{
    return ((opt & params) == params) ? mask : 0;
}

bool XPowersLibInterface::enableInterrupt(uint32_t option)
{
    return setInterruptMask(option, true);
}

bool XPowersLibInterface::disableInterrupt(uint32_t option)
{
    return setInterruptMask(option, false);
}

bool XPowersLibInterface::setInterruptMask(uint32_t option, bool enable)
{
    uint64_t params = 0;
    switch (__chipModel) {

    case XPOWERS_AXP2101:
        params |=  check_params(option, XPOWERS_USB_INSERT_INT, XPOWERS_AXP2101_VBUS_INSERT_IRQ);
        params |=  check_params(option, XPOWERS_USB_REMOVE_INT, XPOWERS_AXP2101_VBUS_REMOVE_IRQ);
        params |=  check_params(option, XPOWERS_BATTERY_INSERT_INT, XPOWERS_AXP2101_BAT_INSERT_IRQ);
        params |=  check_params(option, XPOWERS_BATTERY_REMOVE_INT, XPOWERS_AXP2101_BAT_REMOVE_IRQ);
        params |=  check_params(option, XPOWERS_CHARGE_START_INT, XPOWERS_AXP2101_BAT_CHG_START_IRQ);
        params |=  check_params(option, XPOWERS_CHARGE_DONE_INT, XPOWERS_AXP2101_BAT_CHG_DONE_IRQ);
        params |=  check_params(option, XPOWERS_PWR_BTN_CLICK_INT, XPOWERS_AXP2101_PKEY_SHORT_IRQ);
        params |=  check_params(option, XPOWERS_PWR_BTN_LONGPRESSED_INT, XPOWERS_AXP2101_PKEY_LONG_IRQ);
        params |=  check_params(option, XPOWERS_ALL_INT, XPOWERS_AXP2101_ALL_IRQ);
        return enable ? enableIRQ(params) : disableIRQ(params);
        break;
    default:
        break;
    }
    return false;
}

} // namespace axp2101
} // namespace esphome
