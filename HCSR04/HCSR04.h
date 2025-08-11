#ifndef HCSR04_H
#define HCSR04_H

#include <Arduino.h>

class HCSR04 {
  private:
    uint8_t trigPin;
    uint8_t echoPin;
    
  public:
    // Constructor: specify trigger and echo pins
    HCSR04(uint8_t trig, uint8_t echo);

    // Initialize pins (call in setup)
    void begin();

    // Measure distance in centimeters
    long getDistanceCM();

    // Measure distance in inches
    long getDistanceIN();
};

#endif

