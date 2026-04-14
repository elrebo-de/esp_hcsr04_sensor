/*
 * Example program to measure ultrasonic distance with elrebo-de/hcsr04_sensor
   every second for 10 seconds
 */

#include <string>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "hcsr04_sensor.hpp"
#include "esp_log.h"

static const char *tag = "ultrasonic_distance";

extern "C" void app_main(void)
{
     /* Configure the Ultrasonic module
        assuming an ESP32 M5Atom using triggerPin 26 and echoPin 32 */
     Hcsr04Sensor sensor(
         std::string("Water Level"), // Tag for ESP_LOG
		 (gpio_num_t) 26, // triggerPin
	     (gpio_num_t) 32, // echoPin
	     100.0); // maxDistance

    /* measure the distance every second for 10 seconds */

    for(int i=0; i<10; i++) {
        float distance = sensor.GetDistance();
        ESP_LOGI(tag, "The distance is %5.1f cm.", distance);
        vTaskDelay(1000 / portTICK_PERIOD_MS); // delay 1 second
    }
}

