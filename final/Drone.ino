#include "gyro_signals.h"
#include "RC_module.h"
#include <SimpleKalmanFilter.h>
#include <Servo.h>

float GyroScope[3];  // format - [RateRoll, RatePitch, RateYaw]
int User_input[4];   // format - [Throttle, Yaw, Pitch, Roll]

// Kalman filter variables
SimpleKalmanFilter kalmanRoll(1, 1, 0.01);  // Initialize Kalman filter for roll
SimpleKalmanFilter kalmanPitch(1, 1, 0.01); // Initialize Kalman filter for pitch
SimpleKalmanFilter kalmanYaw(1, 1, 0.01);   // Initialize Kalman filter for yaw

// Filtered outputs
float filteredRoll, filteredPitch, filteredYaw;

// ESC control pins
const int escPins[4] = {9, 10, 11, 12}; // Define pins for 4 ESCs
Servo esc[4];  // Create Servo objects for each ESC

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  gyro_setup();
  RC_setup();

  // Attach ESCs to their respective pins
  for (int i = 0; i < 4; i++) {
    esc[i].attach(escPins[i]); // Attach each ESC to its pin
    esc[i].writeMicroseconds(1000); // Initialize ESCs with a low signal (0 throttle)
    delay(2000); // Wait for ESCs to initialize
  }
}

void loop() {
  // Get raw gyroscope data
  gyro_signals(GyroScope); 

  // Apply Kalman filter to gyro data
  filteredRoll  = kalmanRoll.updateEstimate(GyroScope[0]);
  filteredPitch = kalmanPitch.updateEstimate(GyroScope[1]);
  filteredYaw   = kalmanYaw.updateEstimate(GyroScope[2]);

  // Print filtered gyro data
  Serial.print("Filtered Roll: ");
  Serial.print(filteredRoll);
  Serial.print(", Filtered Pitch: ");
  Serial.print(filteredPitch);
  Serial.print(", Filtered Yaw: ");
  Serial.print(filteredYaw);
  Serial.println();

  // Get signals from the receiver
  reciever_signals(User_input);
  for (int i = 0; i < 4; i++) {
    Serial.print("User_input[");
    Serial.print(i);
    Serial.print("]: ");
    Serial.print(User_input[i]);
    Serial.print(",");
  }
  Serial.println();

  // Control ESCs based on user input and filtered gyro signals
  int throttle = User_input[0]; // Throttle from user input
  int yaw = User_input[1];       // Yaw from user input
  int pitch = User_input[2];     // Pitch from user input
  int roll = User_input[3];      // Roll from user input

  // Map user input to ESC control signals
  // This is a basic implementation, adjust as needed for your drone
  int escSignal[4];
  escSignal[0] = throttle + roll + pitch - yaw; // Front-left ESC
  escSignal[1] = throttle - roll + pitch + yaw; // Front-right ESC
  escSignal[2] = throttle + roll - pitch + yaw; // Back-left ESC
  escSignal[3] = throttle - roll - pitch - yaw; // Back-right ESC

  // Ensure ESC signals are within bounds
  for (int i = 0; i < 4; i++) {
    escSignal[i] = constrain(escSignal[i], 1000, 2000); // Constrain to [1000, 2000] µs
    esc[i].writeMicroseconds(escSignal[i]); // Output to ESC
  }

  delay(20); // Short delay to avoid flooding the ESCs
}
