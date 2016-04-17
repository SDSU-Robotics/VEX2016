//This does nothing right now try 38400
//bluetooth_test. This will print what the controlar is outputing.
#include <SoftwareSerial.h>

int incoming =0;
SoftwareSerial mySerial(15,14);

void setup() {
  Serial.begin(9600);
  mySerial.print("AT+BAUD8");
}

void loop() {
  if(Serial.available() >0) {
    Serial.println(Serial.read());
  }
  delay(250);
}
