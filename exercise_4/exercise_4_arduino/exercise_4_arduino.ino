#include <Adafruit_CircuitPlayground.h>

#define GRAVITY 9.80665
#define RAD2DEG 57.29579
#define SLOUCH_ANGLE 10
#define SLOUCH_TIME 100

float targetAngle;
float currentAngle;
unsigned long slouchStartTime;
bool slouching;

int freq = 100;

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
  targetAngle = 0;
}

void loop() {
  
 currentAngle = RAD2DEG * asin(-CircuitPlayground.motionZ() / GRAVITY);
  
 if ((CircuitPlayground.leftButton()) || (CircuitPlayground.rightButton())) {
  targetAngle = currentAngle;
  CircuitPlayground.playTone(900,100);
  delay(100);
  CircuitPlayground.playTone(900, 100);
  delay(100);
 }

 if (currentAngle - targetAngle > SLOUCH_ANGLE) {
  if (!slouching) {
    slouchStartTime = millis();
    slouching = true;
  } 
 } else {
    slouching = false;
  }

  if (slouching) {
    if (millis() - slouchStartTime > SLOUCH_TIME) {
      CircuitPlayground.playTone(freq, 100);
      Serial.println("slouching");
    } 

    if (freq < 1500) {
      freq += 1;
    } else {
      freq = 1500;
    }
  } else {
    freq = 100;
  }

  
}
