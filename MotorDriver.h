#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include"Arduino.h"

class MotorDriver
{
    private:

        int RightForward;
        int RightBackward;
        int LeftForward;
        int LeftBackward;

    public:

        MotorDriver();

        void begin(int M1A, int M1B, int M2A, int M2B,int baud = 9600);
        void Forward(int speed=100,int time = -1);
        void Backward(int speed=100,int time = -1);
        void HardRight(int speed=100,int time = -1);
        void HardLeft(int speed=100,int time = -1);
        void SoftRight(int speed=100,int time = -1);
        void SoftLeft(int speed=100,int time = -1);
        void RotateCW(int time = -1);
        void RotateACW(int time = -1);
        void Hardstop();
        void SoftStop();
};

#endif