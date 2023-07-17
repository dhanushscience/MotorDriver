/*
*********************************************************
   -------------MOTOR DRIVER LIBRARY-------------
     "created by Dhanush Science to the World"

    Licence type: Open-Source (MIT Licence)
    Github:https://github.com/dhanushscience/MotorDriver.git
Issue/recommendation contact : contactdhanush@proton.me
**********************************************************
 BY DEFAULT CONNECTION & BAUD RATE

  CONNECTION: 
  INA1/ M1A ---> D5
  INA2/ M1B ---> D6
  INB1/ M2A ---> D9
  INB2/ M2B ---> D10

  BAUD: 9600
  **NOTE: connect to PWM pin in case of "PWM_Drive" Mode and for "Digital_Drive" you can use any Digital pin

  */

#include <MotorDriver.h>

MotorDriver motor;
void setup()
{
  motor.begin(5,6,9,10,9600); //Declare: (M1A,M1B,M2A,M2B,BaudRate)
  Serial.println("Motor starting");
}
void loop()
{
  motor.Forward(50,5); // (SPEED,TIME) --> speed in percentage (1-100) , Time in Second; "BY DEFAULT 100% SPEED & NO DELAY"
  motor.Backward(50,5); // (SPEED,TIME) --> speed in percentage (1-100) , Time in Second; "BY DEFAULT 100% SPEED & NO DELAY"
  motor.HardRight(50,2); // (SPEED,TIME) --> speed in percentage (1-100) , Time in Second; "BY DEFAULT 100% SPEED & NO DELAY"
  motor.HardLeft(50,2); // (SPEED,TIME) --> speed in percentage (1-100) , Time in Second; "BY DEFAULT 100% SPEED & NO DELAY"
  motor.Hardstop(); // Nothing Required here
  motor.SoftLeft(100,5); // (SPEED,TIME) --> speed in percentage (1-100) , Time in Second; "BY DEFAULT 100% SPEED & NO DELAY"
  motor.SoftRight(100,5); // (SPEED,TIME) --> speed in percentage (1-100) , Time in Second; "BY DEFAULT 100% SPEED & NO DELAY"
  motor.RotateCW(5); // (TIME) Time in Seconds--> "BY DEFAULT 100% SPEED & NO DELAY"
  motor.RotateACW(5); // (TIME) Time in Seconds--> "BY DEFAULT 100% SPEED & NO DELAY"
  motor.SoftStop(); // Nothing Required here
}