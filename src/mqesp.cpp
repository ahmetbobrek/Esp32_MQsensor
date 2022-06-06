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
void mqsensor::getVoltage(){
    
}
void mqsensor::update(){

}
