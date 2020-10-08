import processing.serial.*;

Serial myPort;  // Create object from Serial class
String val;     // Data received from the serial port

float posX, posY, amplitude = 40, variationY, speed = 0, WaveSpeed, cycle;
int step=10;

float freq = 2.5;

void setup() {
  String serialPort = Serial.list()[1]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, serialPort, 9600);

  size(600, 500);
  background(0);

  noStroke();
  smooth();
  rectMode(CENTER);
}

void draw() {
  if ( myPort.available() > 0) {  // If data is available,
    val = myPort.readStringUntil('\n');         // read it and store it in val
    if (val != null) {
      freq = float(val)/100;
      println("New Freq:" + " " + freq);
    } 
  }

  background(0);
  cycle = (TWO_PI*freq)/float(width);

  fill(200, 150, 0);
  posY = height/2;
  WaveSpeed = 0.00005;

  for (int i = 1; i<width; i+=step) {
    speed += (millis()%i)*WaveSpeed;
    variationY = sin((i+speed)*cycle);
    variationY*=amplitude;
    ellipse(i, (posY+variationY), 3, 3);
  }
}
