#ifndef I_DHTSENSOR_H
#define I_DHTSENSOR_H

#include "DHT.h"
#include "ISensor.hpp"

class IDHTSensor: public ISensor {
  private:
    DHT dht;
    uint8_t type;
  public:
    static const uint8_t DHT22type = 22;
    static const uint8_t DHT11type = 11;
    IDHTSensor(uint8_t pin, const uint8_t type);
    float getTemperature() {
      return dht.readTemperature();
    }
    float getHumidity() {
      return dht.readHumidity();
    }
};

IDHTSensor::IDHTSensor(uint8_t pin, const uint8_t dhtType): dht(pin, dhtType), ISensor(pin) {
  type = type;
  dht.begin();
}

#endif
