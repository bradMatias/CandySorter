// Example by Tom Igoe

import processing.serial.*;

Serial myPort;  // The serial port

void setup() {
  // List all the available serial ports:
  printArray(Serial.list());
  // Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[0], 9600);
  size(640, 360);
  background(0);  
  noStroke();
}

void draw() {
  while (myPort.available() > 0) {
    String inBuffer = myPort.readStringUntil('\n');   
    if (inBuffer != null) {
      println(inBuffer);
      String[] bytes = splitTokens( inBuffer );
      if( bytes.length == 3 ) {
        background( Integer.parseInt( bytes[0] ),
                    Integer.parseInt( bytes[1] ),
                    Integer.parseInt( bytes[2] ) );
      }
    }
  }
}