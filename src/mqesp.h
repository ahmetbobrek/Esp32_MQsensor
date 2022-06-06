#if !defined(MQESP_H)
#define MQESP_H

#include <Arduino.h>
#include <stdint.h>
/*Software Macros*/
#define         retries                 2
#define         retry_interval          20

class mqsensor{

public:
//MQUnifiedsensor MQ2(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin, Type);
// MQUnifiedsensor(String Placa = "Arduino", float Voltage_Resolution =  5, int ADC_Bit_Resolution = 10, int pin = 1, String type = "CUSTOM MQ");
mqsensor(String Board,float Voltage_Resolution,int ADC_Bit_Resolution,int pin,String type);
mqsensor(String Board,String type);
void init();
float getVoltage(bool read=true,bool injected=false,int value=0);
void update();
void externalADCUpdate(float volt);
void setR0(float R0 = 10);
void setRL(float RL = 10);
void setA(float a);
void setB(float b);
void setRegressionMethod(int regressionMethod);
void setVoltResolution(float voltage_resolution =  5);
void serialDebug(bool onSetup = false); //Show on serial port information about sensor
void setADC(int value); //For external ADC Usage




private:
/*
 byte _pin;
    byte _firstFlag = false;
    float _VOLT_RESOLUTION  = 5.0; // if 3.3v use 3.3
    float _RL = 10; //Value in KiloOhms
    byte _ADC_Bit_Resolution = 10;
    byte _regressionMethod = 1; // 1 -> Exponential || 2 -> Linear
    
    float _adc, _a, _b, _sensor_volt;
    float  _R0, RS_air, _ratio, _PPM, _RS_Calc;  
    
    char _type[6];
    char _placa[20]; */
char _Board[20];
float _Voltage_Resolution;
byte _ADC_Bit_Resolution;
byte _pin;
char _type[6];
float _adc;
float _sensor_volt;
float _R0;
float _RL=10;//kiloohms
float _a;
float _b;
byte _regressionMethod = 1; // 1 -> Exponential || 2 -> Linear
float _VOLT_RESOLUTION  = 5.0; // if 3.3v use 3.3
byte _firstFlag = false;
float _RS_Calc;
float _ratio;
float _PPM;


};



#endif // MQESP_H
