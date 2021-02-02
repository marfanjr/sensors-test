#ifndef I_DHTSENS_H
#define I_DHTSENS_H

#include <vector>
#include "DHT.h"
#include "ISensor.hpp"
#include "ISensorValue.hpp"

class IDHTSensor: public ISensor {
  private:
    uint8_t type;
    std::vector<ISensorValue*> tempertureValues;
    std::vector<ISensorValue*> humidityValues;
    DHT* dht;

  public:
    static const uint8_t DHT22type = 22;
    static const uint8_t DHT11type = 11;
    IDHTSensor(uint8_t pin, const uint8_t dhtType);
    void read();
    void saveTemperature(float temperature, uint32_t readedAt);
    void saveHumidity(float humidity, uint32_t readedAt);
    void printDHTSensorValues();
};

#endif
