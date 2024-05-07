// This program currenctly is capable of 
// - Getting signals from Gyroscope
// - Getting User inputs from reciever


#include "gyro_signals.h"
#include "RC_module.h"
float GyroScope[3];  // format - [RateRoll, RatePitch, RateYaw]
int User_input[4]; // format - [Throttle, Yaw, Pitch, Roll]

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  gyro_setup();
  RC_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  gyro_signals(GyroScope);
  for (int i = 0; i < 3; i++) {
    Serial.print(GyroScope[i]);
    Serial.print(",");
  }
  reciever_signals(User_input);
  for (int i = 0; i < 4; i++) {
    Serial.print(User_input[i]);
    Serial.print(",");
  }
  Serial.println();
}
