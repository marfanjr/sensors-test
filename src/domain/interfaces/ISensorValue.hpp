#ifndef I_SENSOR_VALUE_H
#define I_SENSOR_VALUE_H

#include <stdint.h>
#include <string>
#include "Arduino.h"
class ISensorValue {
  private:
    float value;
    char type[32];
    uint32_t readedAt;
  public:
    ISensorValue(float v, uint32_t time, const char* type);

    void setType(const char* type) { strcpy(this->type, type); };
    char * getType() { return type; };

    float getValue() { return value; }
    float getReadedAt() { return readedAt; }
    void printType();
    void printValue();
    void printReadedAt();
    void printSecondsAgo();
    void print();
};


#endif
