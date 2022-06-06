#include "mqesp.h"
//mqsensor(String Board,float Voltage_Resolution,int ADC_Bit_Rsolution,int pin,String type);
mqsensor::mqsensor(String Board,float Voltage_Resolution,int ADC_Bit_Resolution,int pin,String type){
    
    Board.toCharArray(this->_Board,20);
    this->_Voltage_Resolution=Voltage_Resolution;
    this->_ADC_Bit_Resolution=ADC_Bit_Resolution;
    this->_pin=pin;
    type.toCharArray(this->_type,6);
}
mqsensor::mqsensor(String Board,String type){
    
    Board.toCharArray(this->_Board,20);  
    type.toCharArray(this->_type,6);
}
void mqsensor::init(){
    pinMode(_pin,INPUT);
}

float mqsensor::getVoltage(bool read,bool injected,int value){
    float voltage;
    if (read)
    {
    float avg=0.0;
    for (int i = 0; i < retries; i++)
    {
        _adc=analogRead(this->_pin);
        avg+=_adc;
        delay(retry_interval);
    }
    voltage=(avg/retries)*_Voltage_Resolution/(pow(2,_ADC_Bit_Resolution)-1);
    
    }
    
}

void mqsensor::update(){
_sensor_volt =this->getVoltage();

}
