#include "ISensorValue.hpp"

ISensorValue::ISensorValue(float v, uint32_t time, const char* type) {
  setType(type);
  value = v;
  readedAt = time;
  type = type;
}

void ISensorValue::printValue() {
  Serial.print("value: ");
  Serial.print(value);
}

void ISensorValue::printType() {
  Serial.print("[");
  Serial.print(type);
  Serial.print("] ");
}

void ISensorValue::printReadedAt() {
  Serial.print(" readedAt: ");
  printSecondsAgo();
}

void ISensorValue::printSecondsAgo(){
  Serial.print((millis() - readedAt) / 1000);
  Serial.println(" seconds ago");
}

void ISensorValue::print() {
  printType();
  printValue();
  printReadedAt();
}

