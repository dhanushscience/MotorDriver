### MotorDriver.cpp Documentation

#### Overview
The `MotorDriver` class provides an easy interface to control motor drivers such as MDD3A, L293D, L293N, L298D, and L298N. It allows for controlling motor speed, direction, and enabling or disabling motors.

#### Class: MotorDriver

##### Constructor
- `MotorDriver()`
  Initializes the motor driver pins based on the defined motor driver type.

##### Methods

- `void begin(uint8_t EA, uint8_t EB, uint8_t M1A, uint8_t M1B, uint8_t M2A, uint8_t M2B)`
  Initializes the motor driver with custom pin configurations and enables the motors.
  - `EA`: Enable pin for the right motor.
  - `EB`: Enable pin for the left motor.
  - `M1A`, `M1B`: Control pins for the right motor.
  - `M2A`, `M2B`: Control pins for the left motor.

- `void begin(uint8_t M1A, uint8_t M1B, uint8_t M2A, uint8_t M2B)`
  Initializes the motor driver with custom pin configurations without enabling the motors.
  - `M1A`, `M1B`: Control pins for the right motor.
  - `M2A`, `M2B`: Control pins for the left motor.

- `void move(uint8_t RSpeed=255, uint8_t LSpeed=255, bool RFState=LOW, bool RBState=LOW, bool LFState=LOW, bool LBState=LOW, uint8_t time=-1)`
  Moves the motors with specified speed and direction states.
  - `RSpeed`: Speed of the right motor (0-255).
  - `LSpeed`: Speed of the left motor (0-255).
  - `RFState`, `RBState`: State for the right motor (forward/backward).
  - `LFState`, `LBState`: State for the left motor (forward/backward).
  - `time`: Duration to move the motors in seconds.

- `void Forward(uint8_t speed=100, uint8_t time=-1)`
  Moves both motors forward with the specified speed and duration.
  - `speed`: Speed percentage (0-100).
  - `time`: Duration to move the motors in seconds.

- `void Backward(uint8_t speed=100, uint8_t time=-1)`
  Moves both motors backward with the specified speed and duration.
  - `speed`: Speed percentage (0-100).
  - `time`: Duration to move the motors in seconds.

- `void HardRight(uint8_t Rspeed=100, uint8_t Lspeed=100, uint8_t time=-1)`
  Turns the vehicle hard right by moving the right motor forward and the left motor backward.
  - `Rspeed`, `Lspeed`: Speed percentage for right and left motors (0-100).
  - `time`: Duration to move the motors in seconds.

- `void HardLeft(uint8_t Rspeed=100, uint8_t Lspeed=100, uint8_t time=-1)`
  Turns the vehicle hard left by moving the right motor backward and the left motor forward.
  - `Rspeed`, `Lspeed`: Speed percentage for right and left motors (0-100).
  - `time`: Duration to move the motors in seconds.

- `void SoftRight(uint8_t speed=100, uint8_t time=-1)`
  Turns the vehicle softly to the right by moving the right motor forward and stopping the left motor.
  - `speed`: Speed percentage (0-100).
  - `time`: Duration to move the motors in seconds.

- `void SoftLeft(uint8_t speed=100, uint8_t time=-1)`
  Turns the vehicle softly to the left by stopping the right motor and moving the left motor forward.
  - `speed`: Speed percentage (0-100).
  - `time`: Duration to move the motors in seconds.

- `void Hardstop()`
  Stops both motors immediately.

- `void SoftStop()`
  Stops both motors gradually.

#### Usage Example

```cpp
#include "MotorDriver.h"

MotorDriver motor;

void setup() {
  motor.begin(6, 9, 2, 3, 4, 5); // Custom pin configuration
}

void loop() {
  motor.Forward(100, 5); // Move forward at full speed for 5 seconds
  delay(1000);
  motor.Backward(100, 5); // Move backward at full speed for 5 seconds
  delay(1000);
}
```

This documentation provides an overview of the MotorDriver class and its methods, along with a usage example.
