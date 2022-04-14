//RECEIVER
int x,y;
int leftright=0;
int frontback=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
//  pinMode(3, OUTPUT);
//  pinMode(5, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  frontback = analogRead(A0);
  leftright = analogRead(A1);
//  analogWrite(3, frontback);
//  analogWrite(5, leftright);
  
  Serial.print("Front Back= ");
  Serial.println(frontback);
  //Serial.print("    Left Right= ");
  //Serial.println(leftright);
  delay(1000);
}
