#ifndef DTH22SENSOR_H
#define DTH22SENSOR_H

#include "../../interfaces/IDHTSensor.hpp"
#include "DHT.h"

class DHT22Sensor: public IDHTSensor {
  private:
  public:
    static const uint8_t _pin = 4;
    DHT22Sensor();
};

DHT22Sensor::DHT22Sensor(): IDHTSensor(DHT22Sensor::_pin, DHT22) { }

#endif
