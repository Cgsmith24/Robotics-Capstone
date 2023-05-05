const int leftMotorForward = 9;
const int leftMotorBackward = 10;
const int rightMotorForward = 11;
const int rightMotorBackward = 12;

int leftTrigger = 2;
int rightTrigger = 3;

void setup() {
  Serial.begin(9600);
  
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
  
  pinMode(leftTrigger, INPUT);
  pinMode(rightTrigger, INPUT);
}

void loop() {
  int leftValue = pulseIn(leftTrigger, HIGH);
  int rightValue = pulseIn(rightTrigger, HIGH);
  
  Serial.print("Left: ");
  Serial.println(leftValue);
  
  Serial.print("Right: ");
  Serial.println(rightValue);
  
  if (leftValue > 1500) {
    digitalWrite(leftMotorForward, HIGH);
    digitalWrite(leftMotorBackward, LOW);
  } else if (leftValue < 1500) {
    digitalWrite(leftMotorForward, LOW);
    digitalWrite(leftMotorBackward, HIGH);
  } else {
    digitalWrite(leftMotorForward, LOW);
    digitalWrite(leftMotorBackward, LOW);
  }
  
  if (rightValue > 1500) {
    digitalWrite(rightMotorForward, HIGH);
    digitalWrite(rightMotorBackward, LOW);
  } else if (rightValue < 1500) {
    digitalWrite(rightMotorForward, LOW);
    digitalWrite(rightMotorBackward, HIGH);
  } else {
    digitalWrite(rightMotorForward, LOW);
    digitalWrite(rightMotorBackward, LOW);
  }
}
