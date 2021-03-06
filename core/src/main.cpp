#include "main.h"

static Main myMain; 

extern "C" void app_main(void) 
{
  ESP_ERROR_CHECK(myMain.setup());
  while(true)
  {
    myMain.loop();
  }
}

esp_err_t Main::setup(void)
{
  esp_err_t status{ESP_OK};
  ESP_LOGI(LOG_TAG, "Setup");

  status = led.init();

  return status;
}

void Main::loop(void)
{
  ESP_LOGI(LOG_TAG, "ON");
  led.set(true);
  vTaskDelay(pdSECOND);
  ESP_LOGI(LOG_TAG, "OFF");
  led.set(false);
  vTaskDelay(pdSECOND);
}