#include "IDHTSensor.hpp"

IDHTSensor::IDHTSensor(uint8_t pin, const uint8_t dhtType): ISensor(pin) {
  dht = new DHT(pin, dhtType);
  type = dhtType;
  dht->begin();
}

void IDHTSensor::read() {
  if(!canRead()) return;

  setLastReading(millis());
  saveHumidity(dht->readHumidity(), millis());
  saveTemperature(dht->readTemperature(), millis());
}

void IDHTSensor::saveTemperature(float temperature, uint32_t readedAt) {
  if (tempertureValues.size() >= getMaxValues()) {
    tempertureValues.erase(tempertureValues.begin());
  }
  tempertureValues.push_back(new ISensorValue(temperature,
                                              readedAt,
                                              "temperature"));
}

void IDHTSensor::saveHumidity(float humidity, uint32_t readedAt) {
  if (humidityValues.size() >= getMaxValues()) {
    humidityValues.erase(humidityValues.begin());
  }
  humidityValues.push_back(new ISensorValue(humidity,
                                            readedAt,
                                            "humidity"));
}


void IDHTSensor::printDHTSensorValues() {
  if (!canPrint()) return;

  printSensorValues(tempertureValues);
  printSensorValues(humidityValues);
  setLastPrint(millis());
}