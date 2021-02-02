#ifndef I_ISENSOR_H
#define I_ISENSOR_H

#include <OneWire.h>
#include <stdint.h>
#include "ISensorValue.hpp"
#include <vector>
class ISensor {
  private:
    uint8_t _pin;
    const uint8_t _readingInterval = 2; // in seconds
    const uint8_t _printInterval = 5; // in seconds
    unsigned long _lastReading;
    unsigned long _lastPrint;
    const uint8_t _maxValues = 5;
    std::vector<ISensorValue*> sensorValues;
    char name[32];
  public:
    ISensor(uint8_t pin);

    virtual void read() = 0;
    bool canRead();
    bool canPrint();

    void setName(const char* name) { strcpy(this->name, name); };
    void setLastReading(unsigned long millis) { _lastReading = millis; }
    void setLastPrint(unsigned long millis) { _lastPrint = millis; }

    char * getName() { return name; };
    uint8_t getMaxValues();
    unsigned long getLastReading() { return _lastReading; }
    unsigned long getLastPrint() { return _lastPrint; }

    void saveValue(float value, uint32_t readedAt, const char* type);

    void printSensorValues();
    void printSensorValues(std::vector<ISensorValue*> sensorValues);
};

#endif
