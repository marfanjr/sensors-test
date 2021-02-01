#include "Arduino.h"
#include "controllers/sensors_controller.hpp"

SensorsController sensorController = SensorsController();

void setup() {
  Serial.begin(115200);
}

void loop() {
  sensorController.loop();
}