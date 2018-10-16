#define SPEAK_PIN 3
#define LED_PIN 5
#define TRIG_PIN 7
#define ECHO_PIN 10
#define NOTE_LENGTH 1000
#define BUFFER_SIZE 20

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(SPEAK_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int duration;
  int avg[BUFFER_SIZE];
  int avgDur = 0;

  for (int count = 0; count < BUFFER_SIZE; count++) {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(5);
    digitalWrite(TRIG_PIN, LOW);
    duration = pulseIn(ECHO_PIN, HIGH);

    duration = max(duration, -duration);
      avg[count] = duration;
      avgDur = 0;
      for (int i = 0; i < BUFFER_SIZE; i++) {
        avgDur += avg[i];
      } //for
      avgDur /= BUFFER_SIZE;
      avgDur = max(avgDur, -avgDur);
      tone(SPEAK_PIN, avgDur, NOTE_LENGTH);
      //analogWrite(LED_PIN, min(avgDur/6, 250)); 
      //analogWrite(LED_PIN, 250);
      Serial.println(avgDur);
  //    Serial.println(duration);
  //    tone(SPEAK_PIN, duration, NOTE_LENGTH);
    
      delay(25);
      if (count == BUFFER_SIZE-1) count = 0;

  } //for
}
