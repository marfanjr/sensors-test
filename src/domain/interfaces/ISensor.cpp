
#include "ISensor.hpp"

ISensor::ISensor(uint8_t pin) { _pin = pin; _lastPrint = millis(); }

uint8_t ISensor::getMaxValues() { return _maxValues; }

bool ISensor::canRead() {
  return(((millis() - getLastReading()) / 1000) >= _readingInterval);
}

bool ISensor::canPrint() {
  return(((millis() - getLastPrint()) / 1000) >= _printInterval);
}

void ISensor::saveValue(float value, uint32_t readedAt, const char* type) {
  if(isnan(value)) { return; }

  if (sensorValues.size() >= getMaxValues())
    sensorValues.erase(sensorValues.begin());
  sensorValues.push_back(new ISensorValue(value, readedAt, type));
}

void ISensor::printSensorValues() {
  if (!canPrint()) return;

  printSensorValues(sensorValues);
  setLastPrint(millis());
}

void ISensor::printSensorValues(std::vector<ISensorValue*> sv) {
  if (sv.size() == 0) return;

  Serial.println("==================================================");
  Serial.println(getName());
  Serial.println("==================================================");
  for (auto it = sv.begin(); it != sv.end(); ++it) {
    (*it)->print();
  }
  Serial.println("==================================================");
}
