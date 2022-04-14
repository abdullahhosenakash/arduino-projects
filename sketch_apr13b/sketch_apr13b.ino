//SENDER
int x,y;
int leftright;
int frontback;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  x = analogRead(A0);
  y = analogRead(A1);
  leftright = map(x, 0, 1023, 0, 255);
  frontback = map(y, 0, 1023, 0, 255);
  analogWrite(3, frontback);
  analogWrite(5, leftright);
  Serial.print("Front Back= ");
  Serial.print(frontback);
  Serial.print("    Left Right= ");
  Serial.println(leftright);
  delay(500);
}
