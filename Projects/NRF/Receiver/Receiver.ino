//Receiver

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);

const byte address[6] = "00001";
boolean buttonState = 1;
int ledPin = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()){
    char text[32]= "";
    radio.read(&text, sizeof(text));
    radio.read(&buttonState, sizeof(buttonState));
    if(buttonState == 0)
    {
      digitalWrite(ledPin, HIGH);
      Serial.println(text);
    }
    else
    {
      digitalWrite(ledPin, LOW);
      Serial.println(text);
      Serial.println(buttonState);
    }
  }
  delay(500);
}
