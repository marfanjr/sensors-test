#ifndef SENSORS_CONTROLLER_H
#define SENSORS_CONTROLLER_H

#include "../domain/entities/sensors/DHT11Sensor.hpp"
#include "../domain/entities/sensors/DHT22Sensor.hpp"
#include "../domain/entities/sensors/DS18B20Sensor.hpp"
#include "../domain/interfaces/IController.hpp"

class SensorsController: public IController {
  private:
    DHT11Sensor dht11 = DHT11Sensor();
    DHT22Sensor dht22 = DHT22Sensor();
    DS18B20Sensor dsProbe = DS18B20Sensor();
    float h;
    float t;
  public:
    SensorsController();
    void loop();
};

SensorsController::SensorsController() { }

void SensorsController::loop() {
  delay(2000);
  h = dht22.getHumidity();
  t = dht22.getTemperature();

  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("[DHT22] Humidity: ");
  Serial.println(h);
  Serial.print("[DHT22] Temperature: ");
  Serial.println(t);

  t = dsProbe.getTemperature();

  Serial.print("[DS18B] Temperature: ");
  Serial.println(t);
}

#endif
