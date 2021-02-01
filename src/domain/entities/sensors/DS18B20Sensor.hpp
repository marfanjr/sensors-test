#ifndef DS18B20SENSOR_H
#define DS18B20SENSOR_H

#include "../../interfaces/ISensor.hpp"
#include "OneWire.h"
#include "DallasTemperature.h"

class DS18B20Sensor: public ISensor {
  private:
    static const uint8_t _pin = 14;

    OneWire oneWire;
    DallasTemperature dsProbe;
  public:
    DS18B20Sensor();
    float getTemperature() {
      dsProbe.requestTemperatures();
      return dsProbe.getTempCByIndex(0);
    }
};

DS18B20Sensor::DS18B20Sensor(): oneWire(DS18B20Sensor::_pin),
                                dsProbe(&oneWire),
                                ISensor(DS18B20Sensor::_pin) { }

#endif
