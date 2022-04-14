//Transmitter

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);

const byte address[6] = "00001";
int leftright;
int frontback;
int x,y;
int input = 5;
const char text[] = "Transmitting";

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  x = analogRead(A0);
  y = analogRead(A1);
  leftright = map(x, 0, 1023, 0, 255);
  frontback = map(y, 0, 1023, 0, 255);

  if (frontback > 180) {
    input = 8;
  }

  else if (frontback < 50) {
    input = 2;
  }

  else if (leftright > 180) {
    input = 6;
  }

  else if (leftright < 50) {
    input = 4;
  }
  else
  {
    input = 5;
  }
  radio.write(&input, sizeof(input));
  delay(10);
}
