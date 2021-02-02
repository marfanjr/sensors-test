#ifndef DTH22SENSOR_H
#define DTH22SENSOR_H

#include "../../interfaces/IDHTSensor.hpp"
#include "DHT.h"

class DHT22Sensor: public IDHTSensor {
  private:
    static const uint8_t PIN = 4;
  public:
    DHT22Sensor();
};

DHT22Sensor::DHT22Sensor(): IDHTSensor(DHT22Sensor::PIN, DHT22) { 
  setName("DHT22");
}

#endif
