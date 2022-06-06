#include <Arduino.h>
#include <WiFi.h>
#include "mqesp.h"
/***Hardware Macros******/
#define         Board                   ("Esp32")
#define         Pin                     (36)
/****Software Macros********/
#define         Type                    ("MQ-2") //MQ2 or other MQ Sensor, if change this verify your a and b values.
#define         Voltage_Resolution      (3.3) // 3V3 <- IMPORTANT. Source: https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/
#define         ADC_Bit_Resolution      (12) // ESP-32 bit resolution. Source: https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/
#define         RatioMQ2CleanAir        (9.83) //RS / R0 = 9.83 ppm

/*****Global*****/
mqsensor MQ2(Board,Voltage_Resolution,ADC_Bit_Resolution,Pin,Type);
/*****************************Globals***********************************************/

const char* ssid     = "your-ssid";
const char* password = "your-password";




void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}