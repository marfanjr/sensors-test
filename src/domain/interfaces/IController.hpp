#ifndef I_CONTROLLER_H
#define I_CONTROLLER_H
#include "Arduino.h"

class IController {
  private:
  public:
    virtual void loop() = 0;
};

#endif
