//Transmitter

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);

const byte address[6] = "00001";
int buttonPin = 2;
boolean buttonState;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {

  buttonState = digitalRead(buttonPin);
  if(buttonState == 0)
  {
    const char text[] = "Your Button State is HIGH";
    radio.write(&text, sizeof(text));
//    Serial.print(buttonState);
//    Serial.println(text);
  }
  else
  {
    const char text[] = "Your Button State is LOW";
    radio.write(&text, sizeof(text));
//    Serial.println(buttonState);
//    Serial.println(text);
  }
  radio.write(&buttonState, sizeof(buttonState));
  delay(1000);
}
