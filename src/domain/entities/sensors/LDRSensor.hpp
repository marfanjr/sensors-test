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
        setLastReading(millis());
        float _lux = getLux();
        saveValue(_lux, millis(), "lux");
    }
};

float LDRSensor::getLux() {
    uint16_t _digitalValue = analogRead(LDRSensor::PIN);
    float _analogValue = map (_digitalValue, 0, 1024, 0.0, 1.0);
    return _analogValue;
}

LDRSensor::LDRSensor(): ISensor(LDRSensor::PIN){
    setName("LDR");
}

#endif