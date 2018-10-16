const int echoPin1 = 13;
const int trigPin1 = 12;

const int echoPin2 = 10;
const int trigPin2 = 9;

long duration, cm;

void setup() {
  Serial.begin(9600);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin2, OUTPUT);
} //setup

void loop() {
  //sending out trigger signal for Ping 1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); //from datasheet
  digitalWrite(trigPin1, LOW);

  //reading echo signal
  duration = pulseIn(echoPin1, HIGH);

  //converting duration to distance
  cm = duration / 29 / 2;
  Serial.print(cm);
  Serial.println(" cm Ping 1");

  //sending out trigger signal for Ping 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); //from datasheet
  digitalWrite(trigPin2, LOW);

  //reading echo signal
  duration = pulseIn(echoPin2, HIGH);

  //converting duration to distance
  cm = duration / 29 / 2;
  Serial.print(cm);
  Serial.println(" cm Ping 2");  

  //don't need to read super fast
  delay(500);
} //loop
