//Receiver

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);
const byte address[6] = "00001";

int x,y;
int leftright;
int frontback;
int input = 5;

void sendValue(boolean state1, boolean state2,boolean  state3,boolean  state4)
{
  digitalWrite(3, state1);
  digitalWrite(4, state2);
  digitalWrite(5, state3);
  digitalWrite(6, state4);
}

void setup() 
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() 
{
  if (radio.available())
  {
    digitalWrite(2, 0);
    char text[32]= "";
//    radio.read(&text, sizeof(text));
    radio.read(&input, sizeof(input));
    
//    Serial.print(text);
//    Serial.print("   ");
//    Serial.println(input);
    
    if(input == 8)
    {
      sendValue(1,0,0,0);
    }
    else if(input == 2)
    {
      sendValue(0,1,0,0);
    }
    else if(input == 4)
    {
      sendValue(0,0,0,1);
    }
    else if(input == 6)
    {
      sendValue(0,0,1,0);
    }
    else
    {
      sendValue(0,0,0,0);
    }
    
  }
  else
  {
    sendValue(0,0,0,0);
    tone(2, 15);
    delay(500);
    noTone(2);
    delay(500);
  }
  delay(50);
  
  
}
