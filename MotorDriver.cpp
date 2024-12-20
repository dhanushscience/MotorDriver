#include "MotorDriver.h"

bool EN_CON;
uint8_t time;
		
MotorDriver::MotorDriver()
    {   

      #ifdef MDD3A
        uint8_t M1A=5;
        uint8_t M1B=6;
        uint8_t M2A=9;
        uint8_t M2B=10;

        EN_CON = false;

      #else
        uint8_t M1A=2;
        uint8_t M1B=3;
        uint8_t M2A=4;
        uint8_t M2B=5;
        uint8_t EA=6;
        uint8_t EB=9;
		
      #endif   
    }

void MotorDriver::begin(uint8_t EA , uint8_t EB, uint8_t M1A , uint8_t M1B, uint8_t M2A, uint8_t M2B)
  {
    RightForward = M1A;
    RightBackward = M1B;
    LeftForward = M2A;
    LeftBackward = M2B;
	RightEnable = EA;
    LeftEnable = EB;

    pinMode(RightForward,OUTPUT);
    pinMode(RightBackward,OUTPUT);
    pinMode(LeftForward,OUTPUT);
    pinMode(LeftBackward,OUTPUT);

    EN_CON = true;

    pinMode(RightEnable,OUTPUT);
    pinMode(LeftEnable,OUTPUT);

    #ifdef DEBUG

      if(RightForward == 5 ,RightBackward == 6, LeftForward == 9, LeftBackward == 10)
      {
        #warning "--DEFAULT Mode selected--"
      }
      
      else
      {
        #warning "--CUSTOM Mode selected--"
      }

    #endif
  }

void MotorDriver::begin( uint8_t M1A , uint8_t M1B, uint8_t M2A, uint8_t M2B)
  {
    RightForward = M1A;
    RightBackward = M1B;
    LeftForward = M2A;
    LeftBackward = M2B;

    pinMode(RightForward,OUTPUT);
    pinMode(RightBackward,OUTPUT);
    pinMode(LeftForward,OUTPUT);
    pinMode(LeftBackward,OUTPUT);

      EN_CON = false;

    #ifdef DEBUG

      if(RightForward == 5 ,RightBackward == 6, LeftForward == 9, LeftBackward == 10)
      {
        #warning "--DEFAULT Mode selected--"
      }
      
      else
      {
        #warning "--CUSTOM Mode selected--"
      }

    #endif
  }

void MotorDriver::move(uint8_t RSpeed=255, uint8_t LSpeed=255, bool RFState=LOW, bool RBState=LOW, bool LFState=LOW, bool LBState=LOW,uint8_t time = -1)
  {

    if((RSpeed<0) | (RSpeed>255) | (LSpeed<0) | (LSpeed>255))
    {
      #warning "***ERROR: INVALID SPEED VALUE***"
    }

    if(time !=-1 && time <=0)
    {
      #warning "***ERROR: TIME CANT BE 0 OR LESS THAN ZERO***"
    }

    if(RSpeed == 255 && LSpeed == 255) 
    {
      if(EN_CON)
      {
        digitalWrite(RightEnable, HIGH);
        digitalWrite(LeftEnable,  HIGH);
      }

      digitalWrite(RightForward,  RFState);
      digitalWrite(RightBackward, RBState);
      digitalWrite(LeftForward,   LFState);
      digitalWrite(LeftBackward,  LBState);
    }

    if(RSpeed < 255 && LSpeed < 255)
    {
      #ifdef MDD3A
        analogWrite(RightForward,   RFState*RSpeed);
        analogWrite(RightBackward,  RBState*RSpeed);
        analogWrite(LeftForward,    LFState*LSpeed);
        analogWrite(LeftBackward,   LBState*LSpeed);

      #else
        analogWrite(RightEnable,  RSpeed);
        analogWrite(LeftEnable,   LSpeed);

        digitalWrite(RightForward,  RFState);
        digitalWrite(RightBackward, RBState);
        digitalWrite(LeftForward,   LFState);
        digitalWrite(LeftBackward,  LBState);
      #endif 
    }

    if(time != -1)
    {
        delay(time*1000);
    }
  }

void MotorDriver::Forward(uint8_t speed=100,uint8_t time = -1)
  {
    uint8_t pwmValue = 255*(speed/100);
    move(pwmValue,pwmValue,1,0,1,0,time);
  }

void MotorDriver::Backward(uint8_t speed=100,uint8_t time = -1)
  {
    uint8_t pwmValue = 255*(speed/100);
    move(pwmValue,pwmValue,0,1,0,1,time); 
  }

void MotorDriver::HardRight(uint8_t Rspeed=100, uint8_t Lspeed=100 ,uint8_t time = -1)
  {
    uint8_t pwmValueR = 255*(Rspeed/100);
    uint8_t pwmValueL = 255*(Lspeed/100);

    move(pwmValueR,pwmValueL,1,0,0,1,time);
  }

void MotorDriver::HardLeft(uint8_t Rspeed=100, uint8_t Lspeed=100 ,uint8_t time = -1)
  {
    uint8_t pwmValueR = 255*(Rspeed/100);
    uint8_t pwmValueL = 255*(Lspeed/100);

    move(pwmValueR,pwmValueL,0,1,1,0,time);
  }

void MotorDriver::SoftRight(uint8_t speed=100,uint8_t time = -1)
  {
    uint8_t pwmValue = 255*(speed/100);
    move(pwmValue,pwmValue,1,0,0,0,time); 
  }
        
void MotorDriver::SoftLeft(uint8_t speed=100,uint8_t time = -1)
  {
    uint8_t pwmValue = 255*(speed/100);
    move(pwmValue,pwmValue,0,0,1,0,time); 
  }

void MotorDriver::Hardstop()
  {
    move(0,0,0,0,0,0,time);
  }
void MotorDriver::SoftStop()
  {
    move(0,0,1,1,1,1,time);
  }
