#define Throttle_pin 4
#define Yaw_pin 5
#define Pitch_pin 2
#define Roll_pin 15

int Throttle;
int Yaw;
int Pitch;
int Roll;

void RC_setup () {
  pinMode(Throttle_pin, INPUT);
  pinMode(Yaw_pin, INPUT);
  pinMode(Pitch_pin, INPUT);
  pinMode(Roll_pin, INPUT);
}

void reciever_signals(int signals[]) {
  pinMode(Throttle_pin, INPUT);
  pinMode(Yaw_pin, INPUT);
  pinMode(Pitch_pin, INPUT);
  pinMode(Roll_pin, INPUT);
  Throttle = pulseIn(Throttle_pin, HIGH);
  Yaw = pulseIn(Yaw_pin, HIGH);
  Pitch = pulseIn(Pitch_pin, HIGH);
  Roll = pulseIn(Roll_pin, HIGH);
  Throttle = (Throttle - 1000) / 10;
  Yaw = (Yaw - 1000) / 10;
  Pitch = (Pitch - 1000) / 10;
  Roll = (Roll - 1000) / 10;
  signals[0] = Throttle;
  signals[1] = Yaw;
  signals[2] = Pitch;
  signals[3] = Roll;
}