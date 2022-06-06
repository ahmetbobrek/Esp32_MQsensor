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
void mqsensor::externalADCUpdate(float volt)
{
  _sensor_volt = volt;
}
void mqsensor::setR0(float R0) {
  this->_R0 = R0;
}
void mqsensor::setRL(float RL) {
  this->_RL = RL;
}
void mqsensor::setA(float a) {
  this->_a = a;
}
void mqsensor::setB(float b) {
  this->_b = b;
}
void mqsensor::setRegressionMethod(int regressionMethod)
{
  //this->_regressionMethod = regressionMethod;
  this->_regressionMethod = regressionMethod;
}
void mqsensor::setVoltResolution(float voltage_resolution)
{
   _Voltage_Resolution= voltage_resolution;
  
}
void mqsensor::serialDebug(bool onSetup)
{
  if(onSetup)
  {
    Serial.println();
    Serial.println("************************************************************************************************************************************************");
    Serial.println("MQ sensor reading library for arduino");

    Serial.println("Note: remember that all the parameters below can be modified during the program execution with the methods:");
    Serial.println("setR0, setRL, setA, setB where you will have to send as parameter the new value, example: mySensor.setR0(20); //R0 = 20KΩ");

    Serial.println("Authors: Miguel A. Califa U - Yersson R. Carrillo A - Ghiordy F. Contreras C");
    Serial.println("Contributors: Andres A. Martinez - Juan A. Rodríguez - Mario A. Rodríguez O ");

    Serial.print("Sensor: "); Serial.println(_type);
    Serial.print("Supply voltage: "); Serial.print(_VOLT_RESOLUTION); Serial.println(" VDC");
    Serial.print("ADC Resolution: "); Serial.print(_ADC_Bit_Resolution); Serial.println(" Bits");
    Serial.print("R0: "); Serial.print(_R0); Serial.println(" KΩ");
    Serial.print("RL: "); Serial.print(_RL); Serial.println(" KΩ");

    Serial.print("Model: "); if(_regressionMethod == 1) Serial.println("Exponential"); else Serial.println("Linear");
    Serial.print(_type); Serial.print(" -> a: "); Serial.print(_a); Serial.print(" | b: "); Serial.println(_b);

    Serial.print("Development board: "); Serial.println(_Board);
  }
  else 
  {
    if(!_firstFlag)
    {
      Serial.print("| ********************************************************************"); Serial.print(_type); Serial.println("*********************************************************************|");
      Serial.println("|ADC_In | Equation_V_ADC | Voltage_ADC |        Equation_RS        | Resistance_RS  |    EQ_Ratio  | Ratio (RS/R0) | Equation_PPM |     PPM    |");
      _firstFlag = true;  //Headers are printed
    }
    else
    {
      Serial.print("|"); Serial.print(_adc);  Serial.print("| v = ADC*"); Serial.print(_VOLT_RESOLUTION); Serial.print("/"); Serial.print((pow(2, _ADC_Bit_Resolution)) - 1); Serial.print("  |    "); Serial.print(_sensor_volt);
      Serial.print("     | RS = ((" ); Serial.print(_VOLT_RESOLUTION ); Serial.print("*RL)/Voltage) - RL|      "); Serial.print(_RS_Calc); Serial.print("     | Ratio = RS/R0|    ");
      Serial.print(_ratio);  Serial.print( "       |   ");
      if(_regressionMethod == 1) Serial.print("ratio*a + b");
      else Serial.print("pow(10, (log10(ratio)-b)/a)");
      Serial.print("  |   "); Serial.print(_PPM); Serial.println("  |");
    }
  }
}
void mqsensor::setADC(int value)
{
  this-> _sensor_volt = (value) * _VOLT_RESOLUTION / ((pow(2, _ADC_Bit_Resolution)) - 1); 
  this-> _adc =  value;
}