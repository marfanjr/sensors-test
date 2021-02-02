#ifndef DS18B20SENSOR_H
#define DS18B20SENSOR_H

#include "../../interfaces/ISensor.hpp"
#include "OneWire.h"
#include "DallasTemperature.h"

class DS18B20Sensor: public ISensor {
  private:
    static const uint8_t PIN = 14;
    OneWire* oneWire;
    DallasTemperature* dsProbe;
  public:
    DS18B20Sensor();
    void read() {
      if(!canRead()) return;

      setLastReading(millis());
      dsProbe->requestTemperatures();
      float temp = dsProbe->getTempCByIndex(0);
      saveValue(temp, millis(), "temperature");
    }
};

DS18B20Sensor::DS18B20Sensor(): ISensor(DS18B20Sensor::PIN) {
  oneWire = new OneWire(DS18B20Sensor::PIN);
  dsProbe = new DallasTemperature(oneWire);
  setName("DS18B20");

}

#endif
