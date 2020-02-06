#include <Adafruit_TCS34725.h>
#include <FastLED.h> // use version 3.3.0

Adafruit_TCS34725 colorSensor = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_154MS, TCS34725_GAIN_1X                                                  );

void setup() {
  Serial.begin( 9600 );
  
  if (colorSensor.begin()) {
    Serial.println( "Found sensor" );
  } else {
    Serial.println( "No TCS34725 found ... check your connections" );
    while( 1 );
  }
}

float r, g, b;
char buff[20];

void loop() {
  colorSensor.getRGB( &r, &g, &b );
  sprintf( buff, "%d %d %d", (byte)r, (byte)g, (byte)b );
  Serial.println(buff);

  // Bonus code!
  //CRGB rgb( r, g, b );
  //CHSV hsv = rgb2hsv_approximate( rgb );
  //Serial.println( hsv.h );
}
