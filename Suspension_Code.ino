#include <Servo.h>

#define TRIG_PIN1 10
#define ECHO_PIN1 11
#define TRIG_PIN2 4
#define ECHO_PIN2 3

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;


int servoPin1 = 9;
int servoPin2 = 8;
int servoPin3 = 7;
int servoPin4 = 6;
int servoPos1 = 90;
int servoPos2 = 90;
int servoPos3 = 90;
int servoPos4 = 90;

float minGoalDistance1 = 6.0; // Set the minimum goal distance for sensor 1 to 6cm
float maxGoalDistance1 = 8.0; // Set the maximum goal distance for sensor 1 to 7.5cm
float minGoalDistance2 = 7.0; // Set the minimum goal distance for sensor 2 to 8cm
float maxGoalDistance2 = 9.0; // Set the maximum goal distance for sensor 2 to 9.5cm

void setup() {
pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);


  servo1.attach(servoPin1);
  servo1.write(servoPos1);
  
  servo2.attach(servoPin2);
  servo2.write(servoPos2);
  
  servo3.attach(servoPin3);
  servo3.write(servoPos3);
  
  servo4.attach(servoPin4);
  servo4.write(servoPos4);
  
  Serial.begin(9600);

}
void loop() {
  // Send ultrasonic pulse for sensor 1
  digitalWrite(TRIG_PIN1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN1, LOW);

  // Receive echo and calculate distance for sensor 1
  long duration1 = pulseIn(ECHO_PIN1, HIGH);
  float distance1 = duration1 / 58.0;

  // Send ultrasonic pulse for sensor 2
  digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);

  // Receive echo and calculate distance for sensor 2
  long duration2 = pulseIn(ECHO_PIN2, HIGH);
  float distance2 = duration2 / 58.0;

  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.println(" CM");

  Serial.print("Distance 2: ");
  Serial.print(distance2);
  Serial.println(" CM");

  // Check if distance is within the acceptable range for sensor 1
  if (distance1 >= minGoalDistance1 && distance1 <= maxGoalDistance1) {
    // Do nothing if distance is within acceptable range for sensor 1
  } else {
    // Calculate the difference between the current distance and the goal distance for sensor 1
    float distanceDiff1 = (distance1 < minGoalDistance1) ? minGoalDistance1 - distance1 : distance1 - maxGoalDistance1;

    // Move servos 1 and 2 to adjust the height of the car for sensor 1
    if (distance1 < minGoalDistance1) {
      // Move servos 1 and 2 down to lower the car for sensor 1
      servoPos1 += 5;
      if (servoPos1 > 180) {
        servoPos1 = 180;
      }

      servoPos2 -= 5;
      if (servoPos2 > 180) {
        servoPos2 = 180;
      }
    } else {
      // Move servos 1 and 2 up to raise the car for sensor 1
      servoPos1 -= 5;
      if (servoPos1 < 0) {
        servoPos1 = 0;
      }

      servoPos2 += 5;
      if (servoPos2 < 0) {
        servoPos2 = 0;
      }
    }

    // Set the new positions for servos 1 and 2 for sensor 1
    servo1.write(servoPos1);
    servo2.write(servoPos2);
  }
// Control servo 3 and servo 4 based on the readings from the second ultrasonic sensor
 if (distance2 >= minGoalDistance2 && distance2 <= maxGoalDistance2) {
    // Do nothing if distance is within acceptable range for sensor 1
  } else {
    // Calculate the difference between the current distance and the goal distance for sensor 1
    float distanceDiff2 = (distance2 < minGoalDistance2) ? minGoalDistance2 - distance2 : distance2 - maxGoalDistance2;

 
  if (distance2 < minGoalDistance2) {
    // Move both servos down to lower the car
    servoPos3 += 5;
    if (servoPos3 > 180) {
      servoPos3 = 180;
    }
    
    servoPos4 -= 5;
    if (servoPos4 > 180) {
      servoPos4 = 180;
    }
  } else {
    // Move both servos up to raise the car
    servoPos3 -= 5;
    if (servoPos3 < 0) {
      servoPos3 = 0;
    }
    
    servoPos4 += 5;
    if (servoPos4 < 0) {
      servoPos4 = 0;
    }
  }
  
  // Set the new positions for servos for second sensor
  servo3.write(servoPos3);
  servo4.write(servoPos4);


delay(100);  }}
