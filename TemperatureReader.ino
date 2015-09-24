#include <SoftwareSerial.h>

#define BT_RX 0
#define BT_TX 1
#define THERMISTOR_V_OUT A1
#define DELAY_MS 500

SoftwareSerial BT(BT_RX,BT_TX);

float Vo;
float R;
float temp;
float sensorValue;  

void setup() {
  BT.begin(9600);
}

void loop() {
  sensorValue = analogRead(THERMISTOR_V_OUT);
  
  Vo = sensorValue*(5.0 / 1023.0);
  
  R = -(Vo*2.4)/(Vo-5.);
  
  temp = 40.307*pow(2.718, -0.051*R);
  
  BT.println(temp);
  delay(DELAY_MS);

}
