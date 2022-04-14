//SENDER
int x,y;
int leftright;
int frontback;
//boolean state1, state2, state3, state4;

void sendValue(boolean state1, boolean state2,boolean  state3,boolean  state4){
  digitalWrite(3, state1);
  digitalWrite(4, state2);
  digitalWrite(5, state3);
  digitalWrite(6, state4);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}
void loop() {
  x = analogRead(A0);
  y = analogRead(A1);
  leftright = map(x, 0, 1023, 0, 255);
  frontback = map(y, 0, 1023, 0, 255);
  
  if (frontback > 180) {
    sendValue(1,0,0,0);
  }

  else if (frontback < 50) {
    sendValue(0,1,0,0);
  }

  else if (leftright > 180) {
    sendValue(0,0,1,0);
  }

  else if (leftright < 50) {
    sendValue(0,0,0,1);
  }
  else
  {
    sendValue(0,0,0,0);
  }
//  Serial.print("Front Back= ");
//  Serial.print(frontback);
//  Serial.print("    Left Right= ");
//  Serial.println(leftright);
//  delay(500);
}
