#include <Servo.h> 
#include <Adafruit_TCS34725.h>
#include <FastLED.h>

#define SERVO_PIN 9
#define SERVO2_PIN 10
#define DROP_ANG 10
#define COLOR_ANG 110
#define TOP_ANG 160

Servo myservo;
Servo myservo2;
// TCS34725_INTEGRATIONTIME_700MS
Adafruit_TCS34725 colorSensor = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_154MS, TCS34725_GAIN_16X                                                  );

void setup() {
  myservo.attach( SERVO_PIN, 560, 2540 );
  myservo2.attach( SERVO2_PIN, 560, 2540 );
  Serial.begin( 9600 );
  myservo.write( TOP_ANG );
  delay( 2000 );
  
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
  myservo.write( COLOR_ANG );
  delay( 1000 );
  colorSensor.getRGB( &r, &g, &b );
  sprintf( buff, "%d %d %d", (byte)r, (byte)g, (byte)b );
  CRGB rgb( r, g, b );
  CHSV hsv = rgb2hsv_approximate( rgb );
  Serial.println( hsv.h );
  //Serial.println(buff);
  myservo.write( DROP_ANG );
  delay( 500 );
  myservo.write( TOP_ANG );
  delay( 2000 );
}
