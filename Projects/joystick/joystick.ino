int frontback;
int leftright;
int a0;
int a1;
void setup() {
  Serial.begin(9600);

}

void loop() {
  a0=analogRead(A0);
  a1=analogRead(A1);
  frontback=map(a0,0,1023,0,255);
  leftright=map(a1,0,1023,0,255);
  Serial.print("Front Back= ");
  Serial.print(frontback);
  Serial.print("    Left Right= ");
  Serial.println(leftright);
  delay(500);
}
