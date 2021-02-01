#include "../domain/entities/sensors/DHT22Sensor.hpp"

class SensorsController {
  private:
    DHT22Sensor dht22 = DHT22Sensor();
  public:
    SensorsController();
    void loop();
};

SensorsController::SensorsController() { }

void SensorsController::loop() {
  delay(2000);
  float h = dht22.getHumidity();
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(h);

}
