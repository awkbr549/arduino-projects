
/*
 * Ultrasonic Ranging Module HC - SR04
 */

const int echoPin = 13;
const int trigPin = 12;

long duration, cm;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
} //setup

void loop() {
  //sending out trigger signal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); //from datasheet
  digitalWrite(trigPin, LOW);

  //reading echo signal
  duration = pulseIn(echoPin, HIGH);

  //converting duration to distance
  cm = duration / 29 / 2;
  Serial.print(cm);
  Serial.println("cm");

  //don't need to read super fast
  delay(100);
} //loop
