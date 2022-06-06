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
void update();
/*float getVoltage(bool read = true, bool injected = false, int value = 0);*/
float getVoltage(bool read=true,bool injected=false,int value=0);


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


};



#endif // MQESP_H
