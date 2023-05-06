const int leftMotorForward = 2;
const int leftMotorBackward = 3;
const int rightMotorForward = 4;
const int rightMotorBackward = 5;

int leftTrigger = 8;
int rightTrigger = 9;

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
   if (rightValue > 1700) {
     digitalWrite(leftMotorForward, HIGH);
    digitalWrite(leftMotorBackward, LOW);
    digitalWrite(rightMotorForward, LOW);
    digitalWrite(rightMotorBackward, HIGH);
  } else if (rightValue < 1200) {
    digitalWrite(leftMotorForward, LOW);
    digitalWrite(leftMotorBackward, HIGH);
    digitalWrite(rightMotorForward, HIGH);
    digitalWrite(rightMotorBackward, LOW);
  } else {
   
    if (leftValue > 1700) {
    digitalWrite(leftMotorForward, LOW);
    digitalWrite(leftMotorBackward, HIGH);
    digitalWrite(rightMotorForward, LOW);
    digitalWrite(rightMotorBackward, HIGH);
  } else if (leftValue < 1200) {
    digitalWrite(leftMotorForward, HIGH);
    digitalWrite(leftMotorBackward, LOW);
    digitalWrite(rightMotorForward, HIGH);
    digitalWrite(rightMotorBackward, LOW);
  } else {
    digitalWrite(leftMotorForward, LOW);
    digitalWrite(leftMotorBackward, LOW);
     digitalWrite(rightMotorForward, LOW);
    digitalWrite(rightMotorBackward, LOW);
  }
  
  }
  delay(10);
}
