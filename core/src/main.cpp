#include "main.h"

extern "C" void app_main(void) 
{
  while(true)
  {
    ESP_LOGI(LOG_TAG, "Hello World");
    vTaskDelay(pdSECOND);
  }
}