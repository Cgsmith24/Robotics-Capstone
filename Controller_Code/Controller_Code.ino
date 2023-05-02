// Define motor control pins
const int controlPin1 = 3;
const int controlPin2 = 2;
const int controlPin3 = 4;
const int controlPin4 = 5;

// Define RC receiver pins
const int yawPin = 2;

// Define variables to store RC channel values
int yawValue;

void setup() {
// Set motor control pins as outputs
pinMode(controlPin1, OUTPUT);
pinMode(controlPin2, OUTPUT);
pinMode(controlPin3, OUTPUT);
pinMode(controlPin4, OUTPUT);

// Set RC receiver pin as input
pinMode(yawPin, INPUT);

// Start serial communication
Serial.begin(9600);
}

void loop() {
// Read RC receiver values
yawValue = pulseIn(yawPin, HIGH, 25000);

// Map yaw value to motor speed
int motorSpeed = map(yawValue, 1000, 2000, -255, 255);

// Set motor speed and direction
if (motorSpeed > 0) {
digitalWrite(controlPin1, LOW);
digitalWrite(controlPin2, HIGH);
analogWrite(controlPin3, motorSpeed);
analogWrite(controlPin4, motorSpeed);
} else {
digitalWrite(controlPin1, HIGH);
digitalWrite(controlPin2, LOW);
analogWrite(controlPin3, -motorSpeed);
analogWrite(controlPin4, -motorSpeed);
}

// Print yaw value to serial monitor
Serial.print("Yaw: ");
Serial.println(yawValue);

// Wait for a short time
delay(10);
}