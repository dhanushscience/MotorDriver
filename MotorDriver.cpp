#include "MotorDriver.h"

MotorDriver::MotorDriver()
    {     
        short M1A=0;
        short M1B=0;
        short M2A=0;
        short M2B=0;
        short EA=0;
        short EB=0; 
        
        int baud = 9600;
    }

void MotorDriver::begin(short EA, short EB, short M1A, short M1B, short M2A, short M2B,int baud = 9600)
        {
            RightForward = M1A;
            RightBackward = M1B;
            LeftForward = M2A;
            LeftBackward = M2B;
            RightEnable = EA;
            LeftEnable = EB;

            if(RightForward == 5,RightBackward == 6, LeftForward == 9, LeftBackward == 10, baud == 9600)
            {
                Serial.println("Deafult Mode selected");
            }
            
            else
            {
                Serial.println("Custom Mode selected");
            }

            pinMode(RightForward,OUTPUT);
            pinMode(RightBackward,OUTPUT);
            pinMode(LeftForward,OUTPUT);
            pinMode(LeftBackward,OUTPUT);

            if(baud != 9600)
            {
                Serial.begin(baud);
            }

            else
            {
                Serial.begin(9600);
            }
            
        }

void MotorDriver::Forward(int speed=100,int time = -1)
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
                analogWrite(LeftForward,pwmValue);
                analogWrite(LeftBackward,0);
            }
            
            if(speed == 100)
            {
                digitalWrite(RightForward,HIGH);
                digitalWrite(RightBackward,LOW);
                digitalWrite(LeftForward,HIGH);
                digitalWrite(LeftBackward,LOW);
            }


            if(time != -1)
            {
                delay(time*1000);
            }
            
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
