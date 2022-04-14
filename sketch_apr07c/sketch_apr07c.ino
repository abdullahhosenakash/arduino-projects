void setup() {
    pinMode(2, INPUT_PULLUP);
Serial.begin(9600);
}
boolean buttonState = 0;
void loop() {
  buttonState = digitalRead(2);
  if(buttonState == LOW)
  {
    const char text[] = "Your Button State is HIGH";
//    radio.write(&text, sizeof(text));
    Serial.println(buttonState);
  }

}
