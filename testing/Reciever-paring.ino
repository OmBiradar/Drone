#define Throttle_pin 4
#define Yaw_pin 5
#define Pitch_pin 2
#define Roll_pin 15

int Throttle;
int Yaw;
int Pitch;
int Roll;

void setup() {
  Serial.begin(9600);
  pinMode(Throttle_pin, INPUT);
  pinMode(Yaw_pin, INPUT);
  pinMode(Pitch_pin, INPUT);
  pinMode(Roll_pin, INPUT);
}

void reciever_signals() {
  Throttle = pulseIn(Throttle_pin, HIGH);
  Yaw = pulseIn(Yaw_pin, HIGH);
  Pitch = pulseIn(Pitch_pin, HIGH);
  Roll = pulseIn(Roll_pin, HIGH);
  Throttle = (Throttle - 1000) / 10;
  Yaw = (Yaw - 1000) / 10;
  Pitch = (Pitch - 1000) / 10;
  Roll = (Roll - 1000) / 10;
}

void loop() {
  reciever_signals();
  Serial.println(Throttle);
  Serial.println(Yaw);
  Serial.println(Pitch);
  Serial.println(Roll);
}
