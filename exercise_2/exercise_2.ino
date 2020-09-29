#include <Adafruit_CircuitPlayground.h>

float x, y, z, totalAccel;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_8_G);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Grab x, y acceleration values (in m/s^2).
  x = CircuitPlayground.motionX();

  boolean left_tilt = x < -5.0;
  boolean right_tilt = x > 5.0;
  boolean no_tilt = abs(x) < 4.0;

  if (left_tilt) {
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 102, 255, 255);
    }
  } else if (right_tilt) {
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 255, 0, 102);
    }
  }

  float acc = abs(CircuitPlayground.motionX()) + abs(CircuitPlayground.motionY()) + abs(CircuitPlayground.motionZ());
  
  if (acc > 25) {
    CircuitPlayground.setPixelColor(0, 204, 0, 102);
    CircuitPlayground.setPixelColor(1, 0, 102, 255);
    CircuitPlayground.setPixelColor(2, 102, 255, 102);
    CircuitPlayground.setPixelColor(3, 255, 153, 51);
    CircuitPlayground.setPixelColor(4, 153, 51, 255);
    CircuitPlayground.setPixelColor(5, 204, 0, 102);
    CircuitPlayground.setPixelColor(6, 0, 102, 255);
    CircuitPlayground.setPixelColor(7, 102, 255, 102);
    CircuitPlayground.setPixelColor(8, 0, 255, 255);
    CircuitPlayground.setPixelColor(9, 255, 153, 51);
  }
  
  delay(10);

}
