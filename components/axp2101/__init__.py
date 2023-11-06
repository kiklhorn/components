# import esphome.config_validation as cv

# CONF_MY_REQUIRED_KEY = 'my_required_key'
# CONF_MY_OPTIONAL_KEY = 'my_optional_key'

# CONFIG_SCHEMA = cv.Schema({
#   cv.Required(CONF_MY_REQUIRED_KEY): cv.string,
#   cv.Optional(CONF_MY_OPTIONAL_KEY, default=10): cv.int_,
# }).extend(cv.COMPONENT_SCHEMA)


# import esphome.codegen as cg

# def to_code(config):
#     var = cg.new_Pvariable(config[CONF_ID])
#     yield cg.register_component(var)

#     cg.add(var.set_my_required_key(config[CONF_MY_REQUIRED_KEY]))

import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import i2c
from esphome.const import CONF_ID
# from esphome.const import CONF_ID,\
#     CONF_BATTERY_LEVEL, CONF_BRIGHTNESS, UNIT_PERCENT, ICON_BATTERY, CONF_MODEL

DEPENDENCIES = ['i2c']

axp2101_ns = cg.esphome_ns.namespace('axp2101')
AXP2101Component = axp2101_ns.class_('AXP2101Component', cg.Component, i2c.I2CDevice)
# AXP2101Model = axp2101_ns.enum("AXP2101Model")

# MODELS = {
#     "M5CORE2": AXP192Model.AXP192_M5CORE2,
#     "M5STICKC": AXP192Model.AXP192_M5STICKC,
#     "M5TOUGH": AXP192Model.AXP192_M5TOUGH,
# }

# AXP192_MODEL = cv.enum(MODELS, upper=True, space="_")

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(AXP2101Component),
    # cv.Required(CONF_MODEL): AXP192_MODEL,
    # cv.Optional(CONF_BATTERY_LEVEL):
    #     sensor.sensor_schema(
    #         unit_of_measurement=UNIT_PERCENT,
    #         accuracy_decimals=1,
    #         icon=ICON_BATTERY,
    #     ),
#     cv.Optional(CONF_BRIGHTNESS, default=1.0): cv.percentage,
# }).extend(cv.polling_component_schema('60s')).extend(i2c.i2c_device_schema(0x77))
}).extend(i2c.i2c_device_schema(0x34))

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    yield i2c.register_i2c_device(var, config)

    # cg.add(var.set_model(config[CONF_MODEL]))
    # if CONF_BATTERY_LEVEL in config:
    #     conf = config[CONF_BATTERY_LEVEL]
    #     sens = yield sensor.new_sensor(conf)
    #     cg.add(var.set_batterylevel_sensor(sens))

    # if CONF_BRIGHTNESS in config:
    #     conf = config[CONF_BRIGHTNESS]
    #     cg.add(var.set_brightness(conf))