#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "MAIN"

#define pdSECOND pdMS_TO_TICKS(1000)

#include "gpio.h"

class Main final
{
public:
  esp_err_t setup(void);
  void loop(void);
  Gpio::GpioOutput led{GPIO_NUM_2, true};
};