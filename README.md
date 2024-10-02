# Drone Control Project

This project implements a drone control system using an ESP32 microcontroller, an MPU6050 sensor for motion sensing, and an RC transmitter and receiver for user inputs. The project incorporates a Kalman filter for improved stability and precision in flight control.

## Table of Contents

- [Components](#components)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Testing](#testing)
- [License](#license)

## Components

### Hardware Components

- **ESP32**: A powerful microcontroller with built-in Wi-Fi and Bluetooth capabilities, perfect for IoT applications.
  
- **MPU6050**: A 6-axis motion tracking device that includes a gyroscope and an accelerometer. It provides orientation data which is crucial for stabilizing the drone.

- **Electronic Speed Controllers (ESC)**: Used to control the speed of the brushless motors. The project uses 4 ESCs to control the motors of the drone.

- **RC Transmitter and Receiver**: A radio control system that allows the user to send throttle, yaw, pitch, and roll commands to the drone.

### Software Components

- **Arduino IDE**: The development environment used to write, upload, and debug the Arduino sketches.
  
- **Kalman Filter**: An algorithm used to combine data from the MPU6050 sensor and improve the accuracy of motion tracking by minimizing noise.

## Project Structure

```
project-root/
├── final/                            # Final working codes
│   ├── Drone.ino                     # Main drone control code
│   ├── gyro_signals.h                # Header file for gyroscope signals
│   └── RC_module.h                   # Header file for RC module
├── testing/                           # Testing codes
│   ├── basic-bluetooth-connectivity.ino # Testing Bluetooth connectivity
│   └── Reciever-paring.ino           # Testing receiver pairing
├── docs/                              # Documentation (optional)
│   ├── README.md                      # Documentation for the project
│   └── LICENSE                        # License file
└── .gitignore                         # Git ignore file (optional)
```

## Installation

To set up the project on your local machine, follow these steps:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/OmBiradar/drone-control-project.git
   cd drone-control-project
   ```

2. **Open the Project in Arduino IDE**:
   - Launch the Arduino IDE and open the `.ino` files from the `final/` directory.

3. **Install Required Libraries**:
   - Ensure that you have installed the required libraries for the MPU6050 and any other dependencies in the Arduino IDE.

4. **Upload the Code**:
   - Connect your ESP32 to your computer and upload the `Drone.ino` file to the microcontroller.

## Usage

1. **Power On the Drone**: Make sure all components are connected correctly and powered on.

2. **Connect RC Transmitter**: Ensure the RC transmitter is bound to the receiver.

3. **Launch the Drone**: Use the throttle, yaw, pitch, and roll controls on the transmitter to control the drone. 

4. **Monitor Output**: Use the Serial Monitor in the Arduino IDE to observe the gyroscope signals and user inputs in real time.

## Testing

Testing code is located in the `testing/` directory. Each test file corresponds to specific components of the project:

- **basic-bluetooth-connectivity.ino**: Contains tests for validating Bluetooth connectivity.
- **Reciever-paring.ino**: Contains tests for validating the receiver pairing functionality.

### Running Tests
To run tests, open the respective test `.ino` file in the Arduino IDE and upload it to the ESP32.

## Acknowledgments

- Thanks to the open-source community for their libraries and resources that made this project possible.
- Special thanks to the contributors of the Arduino and ESP32 platforms.
