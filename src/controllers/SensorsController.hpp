#ifndef SENSORS_CONTROLLER_H
#define SENSORS_CONTROLLER_H

#include "../domain/interfaces/IController.hpp"
#include "../domain/entities/sensors/DHT11Sensor.hpp"
#include "../domain/entities/sensors/DHT22Sensor.hpp"
#include "../domain/entities/sensors/DS18B20Sensor.hpp"
#include "../domain/entities/sensors/LDRSensor.hpp"

class SensorsController: public IController {
  private:
    DHT11Sensor dht11 = DHT11Sensor();
    DHT22Sensor dht22 = DHT22Sensor();
    DS18B20Sensor dsProbe = DS18B20Sensor();
    LDRSensor ldr = LDRSensor();
  public:
    SensorsController();
    void loop();
};

SensorsController::SensorsController() { }

void SensorsController::loop() {
  ldr.read();
  dht11.read();
  dht22.read();
  dsProbe.read();

  ldr.printSensorValues();
  dht11.printDHTSensorValues();
  dht22.printDHTSensorValues();
  dsProbe.printSensorValues();
}

#endif
