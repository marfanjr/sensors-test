#ifndef DTH11SENSOR_H
#define DTH11SENSOR_H

#include "../../interfaces/IDHTSensor.hpp"
#include "DHT.h"

class DHT11Sensor: public IDHTSensor {
  private:
    static const uint8_t PIN = 14;
  public:
    DHT11Sensor();
};

DHT11Sensor::DHT11Sensor(): IDHTSensor(DHT11Sensor::PIN, DHT11) {
  setName("DHT11");
}

#endif
