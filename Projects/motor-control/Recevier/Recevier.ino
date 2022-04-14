#include<AFMotor.h>
AF_DCMotor frontLeft(1);
AF_DCMotor frontRight(4);
AF_DCMotor backLeft(2);
AF_DCMotor backRight(3);

int frontback, leftright, front, back, left, right;

void goForward() {
  frontLeft.run(FORWARD);
  frontRight.run(FORWARD);
  backLeft.run(BACKWARD);
  backRight.run(BACKWARD);
}

void goBackward() {
  frontLeft.run(BACKWARD);
  frontRight.run(BACKWARD);
  backLeft.run(FORWARD);
  backRight.run(FORWARD);
}

void turnLeft() {
  frontLeft.run(BACKWARD);
  frontRight.run(FORWARD);
  backLeft.run(FORWARD);
  backRight.run(BACKWARD);
}

void turnRight() {
  frontLeft.run(FORWARD);
  frontRight.run(BACKWARD);
  backLeft.run(BACKWARD);
  backRight.run(FORWARD);
}

void carStop()
{
  frontLeft.run(RELEASE);
  frontRight.run(RELEASE);
  backLeft.run(RELEASE);
  backRight.run(RELEASE);
}

void setup() {

  frontLeft.setSpeed(100);
  backLeft.setSpeed(100);
  frontRight.setSpeed(100);
  backRight.setSpeed(100);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  Serial.begin(9600);

}

void loop() {
  front = digitalRead(A0);
  back = digitalRead(A1);
  right = digitalRead(A2);
  left = digitalRead(A3);

  if (front) {
    goForward();
  }

  else if (back) {
    goBackward();
  }

  else if (right) {
    turnRight();
  }

  else if (left) {
    turnLeft();
  }
  else
  {
    carStop();
  }
//Serial.print("Front= ");
//  Serial.print(front);
//  Serial.print("    Back= ");
//  Serial.print(back);
//  Serial.print("        Left= ");
//  Serial.print(left);
//  Serial.print("            Right= ");
//  Serial.println(right);
//  delay(1000);
}
