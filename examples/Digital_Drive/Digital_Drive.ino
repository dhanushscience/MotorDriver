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
  Serial.begin(9600);
  motor.begin(6,9,2,3,4,5); //Declare: (EA,EB,M1A,M1B,M2A,M2B)
  Serial.println("Motor starting");
}
void loop()
{
  motor.Forward(); // (SPEED,TIME) --> speed in percentage (1-100) , Time in Second; "BY DEFAULT 100% SPEED & NO DELAY"
  motor.Backward(); // (SPEED,TIME) --> speed in percentage (1-100) , Time in Second; "BY DEFAULT 100% SPEED & NO DELAY"
  motor.HardRight(); // (SPEED,TIME) --> speed in percentage (1-100) , Time in Second; "BY DEFAULT 100% SPEED & NO DELAY"
  motor.HardLeft(); // (SPEED,TIME) --> speed in percentage (1-100) , Time in Second; "BY DEFAULT 100% SPEED & NO DELAY"
  motor.Hardstop(); // Nothing Required here
  motor.SoftLeft(); // (SPEED,TIME) --> speed in percentage (1-100) , Time in Second; "BY DEFAULT 100% SPEED & NO DELAY"
  motor.SoftRight(); // (SPEED,TIME) --> speed in percentage (1-100) , Time in Second; "BY DEFAULT 100% SPEED & NO DELAY"
  motor.SoftStop(); // Nothing Required here
}
