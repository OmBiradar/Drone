#include <Wire.h>
float RateCalibrationPitch, RateCalibrationRoll, RateCalibrationYaw;
int RateCalibrationNumber;

void gyro_signals(float Rate_rates[]) {
  // format - [RateRoll, RatePitch, RateYaw]
  Wire.beginTransmission(0x68);
  Wire.write(0x1A);
  Wire.write(0x05);
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.write(0x1B);
  Wire.write(0x08);
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.write(0x43);
  Wire.endTransmission(); 
  Wire.requestFrom(0x68,6);
  int16_t GyroX=Wire.read()<<8 | Wire.read();
  int16_t GyroY=Wire.read()<<8 | Wire.read();
  int16_t GyroZ=Wire.read()<<8 | Wire.read();
  Rate_rates[0] =(float)GyroX/65.5;
  Rate_rates[1] =(float)GyroY/65.5;
  Rate_rates[2] =(float)GyroZ/65.5;
  Rate_rates[0]-=RateCalibrationRoll;
  Rate_rates[1]-=RateCalibrationPitch;
  Rate_rates[2]-=RateCalibrationYaw;
}

void gyro_setup() {
  float Rate_rates[3];
  Wire.setClock(400000);
  Wire.begin();
  delay(250);
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();
  for (RateCalibrationNumber=0; RateCalibrationNumber<2000; RateCalibrationNumber ++) {
    gyro_signals(Rate_rates);
    RateCalibrationRoll+=Rate_rates[0];
    RateCalibrationPitch+=Rate_rates[1];
    RateCalibrationYaw+=Rate_rates[2];
    delay(1);
  }
  RateCalibrationRoll/=2000;
  RateCalibrationPitch/=2000;
  RateCalibrationYaw/=2000;
}