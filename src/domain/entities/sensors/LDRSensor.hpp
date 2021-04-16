#ifndef LDRSENSOR_H
#define LDRSENSOR_H

#include "../../interfaces/ISensor.hpp"

class LDRSensor : public ISensor{
    private:
    static const uint8_t PIN = 2;
    float getLux();
    
    public:
    LDRSensor();
    void read(){
        if(!canRead()) return;
        saveValue(getLux(), millis(), "lux");
    }
};

float LDRSensor::getLux() {
    uint16_t digitalValue = analogRead(PIN);
    float analogValue = map (digitalValue, 0, 1024, 0, 1);
    return analogValue;
}

LDRSensor::LDRSensor(): ISensor(LDRSensor::PIN){
    setName("LDR");
}

#endif