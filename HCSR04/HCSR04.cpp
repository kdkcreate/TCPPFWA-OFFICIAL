#include "HCSR04.h"

HCSR04::HCSR04(uint8_t trig, uint8_t echo) {
  trigPin = trig;
  echoPin = echo;
}

void HCSR04::begin() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
}

long HCSR04::getDistanceCM() {
  // Clear trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Trigger the sensor by setting the trigPin high for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, pulseIn returns duration in microseconds
  long duration = pulseIn(echoPin, HIGH, 30000); // timeout 30ms (max ~5m)

  // Calculate distance: speed of sound is 343m/s or 0.0343 cm/us
  // distance = (duration / 2) * 0.0343
  long distanceCm = duration / 58; // Commonly used formula for HC-SR04

  if (distanceCm == 0) {
    return -1; // No object detected or out of range
  }
  
  return distanceCm;
}

long HCSR04::getDistanceIN() {
  long distanceCm = getDistanceCM();
  if (distanceCm == -1) return -1;
  return distanceCm / 2.54;
}

