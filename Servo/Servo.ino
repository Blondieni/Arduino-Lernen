#include <Servo.h>

Servo meinMotor;

void setup() {
  meinMotor.attach(9);
}

void loop() {
  for (int i = 0; i <= 180; i++){
    meinMotor.write(i);
    delay(15);
  }

  for (int i = 180; i >= 0; i--){
    meinMotor.write(i);
    delay(15);
  }
}
