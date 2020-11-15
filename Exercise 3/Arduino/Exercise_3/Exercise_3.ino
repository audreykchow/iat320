#include <Adafruit_CircuitPlayground.h>

int vals[7] = {3, 2, 0, 1, 6, 9, 10};
float pitches[7] = {261.626, 293.665, 329.628, 349.228, 391.995, 440.0, 493.883};

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  //send 'Hello, world!' over the serial port
  
  for (int i = 0; i < 8; i++) {
    int x = CircuitPlayground.readCap(vals[i]);
    if (x > 1000) {
      CircuitPlayground.playTone(pitches[i], 500);
      Serial.println(pitches[i]);
    }
  }
  delay(100);
}
