#ifndef DTH11SENSOR_H
#define DTH11SENSOR_H

#include "../../interfaces/IDHTSensor.hpp"
#include "DHT.h"

class DHT11Sensor: public IDHTSensor {
  private:
  public:
    static const uint8_t _pin = 14;
    DHT11Sensor();
};

DHT11Sensor::DHT11Sensor(): IDHTSensor(DHT11Sensor::_pin, DHT22) { }

#endif
