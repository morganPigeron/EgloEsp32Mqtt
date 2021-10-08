#pragma once

#include "driver/gpio.h"

namespace Gpio
{
  class GpioBase
  {
  protected:
    const gpio_num_t _pin;
    const bool _invertedLogic = false;
    const gpio_config_t _config;
    
  public:
    constexpr GpioBase(const gpio_num_t pin, const gpio_config_t& config, const bool invertedLogic = false) :
    _pin{pin},
    _invertedLogic{invertedLogic},
    _config{config}
    {

    }

    virtual bool state(void) =0;
    virtual esp_err_t set(const bool state) =0;

    [[nodiscard]] esp_err_t init(void);

  };

  class GpioOutput : public GpioBase
  {
  private:
    bool _state = false;

  public:
    constexpr GpioOutput(const gpio_num_t pin, const bool invertedLogic = false) : 
    GpioBase{
      pin,
      gpio_config_t{
        .pin_bit_mask = static_cast<uint64_t>(1) << pin,
        .mode         = GPIO_MODE_OUTPUT,
        .pull_up_en   = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_ENABLE,
        .intr_type    = GPIO_INTR_DISABLE 
      },
      invertedLogic}
    {

    }

    [[nodiscard]] esp_err_t init(void);
    esp_err_t set(const bool state);
    //esp_err_t toggle(void);
    bool state(void) {return _state;}
  };
  
  class GpioInput
  {
  private:
    
    gpio_num_t _pin;
    const bool _invertedLogic = false;

  public:
    esp_err_t init(void);

    bool state(void);

  };
}
