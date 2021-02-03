#ifndef LDRSENSOR_H
#define LDRSENSOR_H

#include "../../interfaces/ISensor.hpp"

class LDRSensor: public ISensor {
  private:
    static const uint8_t PIN = 0;
  public:
    LDRSensor();
    void read() {
      if (!canRead()) return;
      setLastReading(millis());
      double _lux = (double) analogRead(LDRSensor::PIN) / 1000;
      saveValue(_lux, millis(), "LDR");
    }
};
LDRSensor::LDRSensor(): ISensor(LDRSensor::PIN) {
  setName("LDR");
}
#endif