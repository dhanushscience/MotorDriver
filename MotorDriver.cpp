#include "MotorDriver.h"

MotorDriver::MotorDriver()
    {   
      #ifdef MDD3A
        short M1A=5;
        short M1B=6;
        short M2A=9;
        short M2B=10;

        bool EN_CON = false;

      #else
        short M1A=2;
        short M1B=3;
        short M2A=4;
        short M2B=5;
        short EA=6;
        short EB=9;

        bool EN_CON=false;
      #endif   
    }

void MotorDriver::begin(short EA = -1, short EB = -1, short M1A, short M1B, short M2A, short M2B)
  {
    RightForward = M1A;
    RightBackward = M1B;
    LeftForward = M2A;
    LeftBackward = M2B;

    pinMode(RightForward,OUTPUT);
    pinMode(RightBackward,OUTPUT);
    pinMode(LeftForward,OUTPUT);
    pinMode(LeftBackward,OUTPUT);

    if(EA != -1 && EB != -1)
    {
      RightEnable = EA;
      LeftEnable = EB;

      EN_CON = true;

      pinMode(RightEnable,OUTPUT);
      pinMode(LeftEnable,OUTPUT);
    }

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

void MotorDriver::move(uint8_t RSpeed=255, uint8_t LSpeed=255, bool RFState=LOW, bool RBState=LOW, bool LFState=LOW, bool LBState=LOW, short time = -1)
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

void MotorDriver::Forward(int speed=100,int time = -1)
    {

      ////mkkkkk 
    }
void MotorDriver::Backward(int speed=100,int time = -1)
        {
                       if(speed<0 || speed>100)
            {
                Serial.println("***INVALID SPEED VALUE***");
                return;
            }

            if(time !=-1 && time <=0)
            {
                Serial.println("***TIME CANT BE 0 OR LESS THAT ZERO***");
                return;
            }

            if(speed < 100)
            {
                int pwmValue = 255*(speed/100);

                analogWrite(RightForward,0);
                analogWrite(RightBackward,pwmValue);
                analogWrite(LeftForward,0);
                analogWrite(LeftBackward,pwmValue);
            }
            
            if(speed == 100)
            {
                digitalWrite(RightForward,LOW);
                digitalWrite(RightBackward,HIGH);
                digitalWrite(LeftForward,LOW);
                digitalWrite(LeftBackward,HIGH);
            }


            if(time != -1)
            {
                delay(time*1000);
            }
        }

void MotorDriver::HardRight(int speed=100,int time = -1)
        {
            if(speed<0 || speed>100)
            {
                Serial.println("***INVALID SPEED VALUE***");
                return;
            }

            if(time !=-1 && time <=0)
            {
                Serial.println("***TIME CANT BE 0 OR LESS THAT ZERO***");
                return;
            }

            if(speed < 100)
            {
                int pwmValue = 255*(speed/100);

                analogWrite(RightForward,pwmValue);
                analogWrite(RightBackward,0);
                analogWrite(LeftForward,0);
                analogWrite(LeftBackward,pwmValue);
            }
            
            if(speed == 100)
            {
                digitalWrite(RightForward,HIGH);
                digitalWrite(RightBackward,LOW);
                digitalWrite(LeftForward,LOW);
                digitalWrite(LeftBackward,HIGH);
            }


            if(time != -1)
            {
                delay(time*1000);
            }
            
        }
void MotorDriver::HardLeft(int speed=100,int time = -1)
        {
             if(speed<0 || speed>100)
            {
                Serial.println("***INVALID SPEED VALUE***");
                return;
            }

            if(time !=-1 && time <=0)
            {
                Serial.println("***TIME CANT BE 0 OR LESS THAT ZERO***");
                return;
            }

            if(speed < 100)
            {
                int pwmValue = 255*(speed/100);

                analogWrite(RightForward,0);
                analogWrite(RightBackward,pwmValue);
                analogWrite(LeftForward,pwmValue);
                analogWrite(LeftBackward,0);
            }
            
            if(speed == 100)
            {
                digitalWrite(RightForward,LOW);
                digitalWrite(RightBackward,HIGH);
                digitalWrite(LeftForward,HIGH);
                digitalWrite(LeftBackward,LOW);
            }


            if(time != -1)
            {
                delay(time*1000);
            }
            
        }
void MotorDriver::SoftRight(int speed=100,int time = -1)
        {
            if(speed<0 || speed>100)
            {
                Serial.println("***INVALID SPEED VALUE***");
                return;
            }

            if(time !=-1 && time <=0)
            {
                Serial.println("***TIME CANT BE 0 OR LESS THAT ZERO***");
                return;
            }

            if(speed < 100)
            {
                int pwmValue = 255*(speed/100);

                analogWrite(RightForward,pwmValue);
                analogWrite(RightBackward,0);
                analogWrite(LeftForward,0);
                analogWrite(LeftBackward,0);
            }
            
            if(speed == 100)
            {
                digitalWrite(RightForward,HIGH);
                digitalWrite(RightBackward,LOW);
                digitalWrite(LeftForward,LOW);
                digitalWrite(LeftBackward,LOW);
            }


            if(time != -1)
            {
                delay(time*1000);
            }
            
        }
        
void MotorDriver::SoftLeft(int speed=100,int time = -1)
        {
            if(speed<0 || speed>100)
            {
                Serial.println("***INVALID SPEED VALUE***");
                return;
            }

            if(time !=-1 && time <=0)
            {
                Serial.println("***TIME CANT BE 0 OR LESS THAT ZERO***");
                return;
            }

            if(speed < 100)
            {
                int pwmValue = 255*(speed/100);

                analogWrite(RightForward,0);
                analogWrite(RightBackward,0);
                analogWrite(LeftForward,pwmValue);
                analogWrite(LeftBackward,0);
            }
            
            if(speed == 100)
            {
                digitalWrite(RightForward,LOW);
                digitalWrite(RightBackward,LOW);
                digitalWrite(LeftForward,HIGH);
                digitalWrite(LeftBackward,LOW);
            }


            if(time != -1)
            {
                delay(time*1000);
            }
        }
void MotorDriver::RotateCW(int time = -1)
        {

            digitalWrite(RightForward,LOW);
            digitalWrite(RightBackward,HIGH);
            digitalWrite(LeftForward,HIGH);
            digitalWrite(LeftBackward,LOW);


            if(time != -1)
            {
                delay(time*1000);
            }
        }
void MotorDriver::RotateACW(int time = -1)
        {
    
            digitalWrite(RightForward,LOW);
            digitalWrite(RightBackward,HIGH);
            digitalWrite(LeftForward,HIGH);
            digitalWrite(LeftBackward,LOW);

            if(time != -1)
            {
                delay(time*1000);
            }
        }
void MotorDriver::Hardstop()
        {
            digitalWrite(RightForward,LOW);
            digitalWrite(RightBackward,LOW);
            digitalWrite(LeftForward,LOW);
            digitalWrite(LeftBackward,LOW);
        }
void MotorDriver::SoftStop()
        {
            digitalWrite(RightForward,HIGH);
            digitalWrite(RightBackward,HIGH);
            digitalWrite(LeftForward,HIGH);
            digitalWrite(LeftBackward,HIGH);
        }
