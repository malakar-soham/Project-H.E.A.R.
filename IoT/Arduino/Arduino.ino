#include <TinyGPS++.h>
#include <SoftwareSerial.h>

SoftwareSerial ArduinoUno(7,8); //Connection with ESP32

String out;
int analogPin = A0;
int readValue = 0;
float temperature = 0;
static const int RXPin = 3, TXPin = 4;
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup(){
  Serial.begin(9600);
  ArduinoUno.begin(115200);
  ss.begin(GPSBaud);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){

 for(int i = 0; i < 100; i++)
 readValue = readValue + analogRead(analogPin);

 readValue = readValue / 100;

 temperature = (readValue * 0.49);
 Serial.println(temperature);

  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      // Latitude in degrees (double)
      Serial.print("Latitude= ");
      Serial.print(gps.location.lat(), 6);
      // Longitude in degrees (double)
      Serial.print(" Longitude= ");
      Serial.println(gps.location.lng(), 6);
    if(temperature>=70){
      digitalWrite(LED_BUILTIN, HIGH);
      out = String('t')+String(gps.location.lat(), 6)+String(',')+String(gps.location.lng(), 6);
    }
    else{
      digitalWrite(LED_BUILTIN, LOW);
      out = String('f')+String(gps.location.lat(), 6)+String(',')+String(gps.location.lng(), 6);
    }
    ArduinoUno.print(out);
    Serial.println(out);
    delay(2000);
  }
 }
}
