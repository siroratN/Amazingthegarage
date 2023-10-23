#include <Servo.h>
Servo myservo;

const int triggerPin = 4;  // Trigger pin of the ultrasonic sensor (HC-SR04)
const int echoPin = 2;     // Echo pin of the ultrasonic sensor (HC-SR04)
const int ledPin = 7;      // Pin for the LED

const int threshold = 120;
int status_light = 0;
int status_door = 0;

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(9);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  myservo.write(90);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  unsigned long pulseWidth = pulseIn(echoPin, HIGH);
  float distance = pulseWidth / 29.0 / 2.0;

  // Read sound sensor
  int sensorValue = analogRead(A0);
  Serial.print("Sound : ");
  Serial.println(sensorValue);

  Serial.print("Distance (cm): ");
  Serial.println(distance);

  if ((distance < 7) && (status_light == 0) && (status_door == 0)) {
    digitalWrite(ledPin, HIGH);
    Serial.println("open door");
    myservo.write(80);
    delay(500);
    myservo.write(70);
    delay(500);
    myservo.write(60);
    delay(500);
    myservo.write(55);
    delay(500);
    myservo.write(50);
    delay(500);
    myservo.write(45);
    delay(500);
    myservo.write(40);
    delay(500);
    myservo.write(35);
    delay(500);
    myservo.write(30);
    delay(500);
    myservo.write(25);
    delay(500);
    myservo.write(20);
    delay(500);
    myservo.write(15);
    delay(500);
    myservo.write(10);
    status_light = 1;
    status_door = 1;
    delay(5000);
    Serial.println("close door");
    myservo.write(15);
    delay(500);
    myservo.write(20);
    delay(500);
    myservo.write(25);
    delay(500);
    myservo.write(40);
    delay(500);
    myservo.write(50);
    delay(500);
    myservo.write(60);
    delay(500);
    myservo.write(70);
    delay(500);
    myservo.write(80);
    delay(500);
    myservo.write(90);
    status_door = 0;
  }
  else if ((sensorValue > 114) && (status_light == 1) && (status_door == 0)) {
    Serial.print("open door \n");
    digitalWrite(ledPin, LOW);
    myservo.write(80);
    delay(500);
    myservo.write(75);
    delay(500);
    myservo.write(70);
    delay(500);
    myservo.write(65);
    delay(500);
    myservo.write(60);
    delay(500);
    myservo.write(55);
    delay(500);
    myservo.write(50);
    delay(500);
    myservo.write(45);
    delay(500);
    myservo.write(40);
    delay(500);
    myservo.write(35);
    delay(500);
    myservo.write(30);
    delay(500);
    myservo.write(25);
    delay(500);
    myservo.write(20);
    delay(500);
    myservo.write(15);
    delay(500);
    myservo.write(10);
    status_light = 0;
    status_door = 1;
    delay(3000);
    Serial.print("close door \n");
    myservo.write(15);
    delay(500);
    myservo.write(20);
    delay(500);
    myservo.write(25);
    delay(500);
    myservo.write(40);
    delay(500);
    myservo.write(50);
    delay(500);
    myservo.write(60);
    delay(500);
    myservo.write(70);
    delay(500);
    myservo.write(80);
    delay(500);
    myservo.write(90);
    status_door = 0;
  }
  delay(500);
}