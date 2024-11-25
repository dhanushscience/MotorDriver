#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include"Arduino.h"
#include <stdint.h>

bool EN_CON;

class MotorDriver
{
    private:

        uint8_t RightForward;
        uint8_t RightBackward;
        uint8_t LeftForward;
        uint8_t LeftBackward;
        uint8_t RightEnable;
        uint8_t LeftEnable;

    public:

        MotorDriver();

        void begin(int8_t EA = -1, int8_t EB = -1, uint8_t M1A, uint8_t M1B, uint8_t M2A, uint8_t M2B);
        void move(uint8_t RSpeed=255, uint8_t LSpeed=255, bool RFState=LOW, bool RBState=LOW, bool LFState=LOW, bool LBState=LOW, uint8_t time = -1);
        void Forward(uint8_t speed=100,uint8_t time = -1);
        void Backward(uint8_t speed=100,uint8_t time = -1);
        void HardRight(uint8_t Rspeed=100, uint8_t Lspeed=100 ,uint8_t time = -1);
        void HardLeft(uint8_t Rspeed=100, uint8_t Lspeed=100 ,uint8_t time = -1);
        void SoftRight(int speed=100,int time = -1);
        void SoftLeft(int speed=100,int time = -1);
        void Hardstop();
        void SoftStop();
};

#endif
