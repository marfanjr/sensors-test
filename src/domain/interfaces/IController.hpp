#include "../domain/entities/sensors/DHT22Sensor.hpp"

class IController {
  private:
  public:
    virtual void loop() = 0;
};
