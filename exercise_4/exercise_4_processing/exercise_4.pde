import processing.serial.*;

Serial myPort;  // Create object from Serial class
String val;     // Data received from the serial port

PFont GT_Bold; 
PFont GT_Regular; 

int slouchCount = 0;
boolean slouching;

void setup() {
  String serialPort = Serial.list()[1]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, serialPort, 9600);

  size(600, 500);
  background(0);

  GT_Bold = createFont("GT-America-Bold.ttf", 24);
  GT_Regular = createFont("GT-America-Regular.otf", 24);
}

void draw() {
  background(255);

  if (myPort.available() > 0) {  // If data is available,
    val = myPort.readStringUntil('\n');              
  
    if (val != null) {
      slouchCount += 1;
    }
  } 

  println(val);
  
  textFont(GT_Regular, 20);   
  textAlign(CENTER);
  fill(0);                       
  text("So far, you've spent " + slouchCount + " seconds slouching today", width/2, height/2);
}
