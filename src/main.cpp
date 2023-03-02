#include <Arduino.h>

// LDR sensor pins
#define IR_LEFT A1
#define IR_RIGHT A2

// Motor pins
#define MOTOR_L1 2
#define MOTOR_L2 3
#define MOTOR_R1 4
#define MOTOR_R2 5

void setup()
{
  Serial.begin(9600);
  // Set motor pins as output
  pinMode(MOTOR_L1, OUTPUT);
  pinMode(MOTOR_L2, OUTPUT);
  pinMode(MOTOR_R1, OUTPUT);
  pinMode(MOTOR_R2, OUTPUT);

  // Set IR sensor pins as input
}

void bk()
{
  digitalWrite(MOTOR_L1, HIGH);
  digitalWrite(MOTOR_L2, LOW);
  digitalWrite(MOTOR_R1, LOW);
  digitalWrite(MOTOR_R2, HIGH);
}
void fr()
{
  digitalWrite(MOTOR_L1, LOW);
  digitalWrite(MOTOR_L2, HIGH);
  digitalWrite(MOTOR_R1, HIGH);
  digitalWrite(MOTOR_R2, LOW);
}
void lt()
{
  digitalWrite(MOTOR_L1, LOW);
  digitalWrite(MOTOR_L2, HIGH);
  digitalWrite(MOTOR_R1, LOW);
  digitalWrite(MOTOR_R2, HIGH);
}
void rt()
{
  digitalWrite(MOTOR_L1, HIGH);
  digitalWrite(MOTOR_L2, LOW);
  digitalWrite(MOTOR_R1, HIGH);
  digitalWrite(MOTOR_R2, LOW);
}
void st()
{
  digitalWrite(MOTOR_L1, LOW);
  digitalWrite(MOTOR_L2, LOW);
  digitalWrite(MOTOR_R1, LOW);
  digitalWrite(MOTOR_R2, LOW);
}
void loop()
{

  if ((analogRead(IR_LEFT) > 200) && (analogRead(IR_RIGHT) > 200))
  {
    fr();
  }
  else if ((analogRead(IR_LEFT) < 200) && (analogRead(IR_RIGHT) < 200))
  {
    st();
  }

  else if ((analogRead(IR_LEFT) < 200) && (analogRead(IR_RIGHT) > 200))
  {
    lt();
  }
  else if ((analogRead(IR_LEFT) > 200) && (analogRead(IR_RIGHT) < 200))
  {
    rt();
  }
}