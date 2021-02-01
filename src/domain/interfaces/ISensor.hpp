#ifndef I_SENSOR_H
#define I_SENSOR_H

#include <OneWire.h>
#include <stdint.h>

class ISensor {
  private:
    uint8_t _pin;
  public:
    ISensor(uint8_t pin);

    uint8_t getPin() {
      return _pin;
    }
};

ISensor::ISensor(uint8_t pin) {
  _pin = pin;
}

#endif