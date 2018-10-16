#define PWM 5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PWM, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int out = 0;
  for (; out < 250; out += 25) {
    analogWrite(PWM, out);
    delay(50);
  } //for
  for (; out > 0; out -= 25) {
    analogWrite(PWM, out);
    delay(50);    
  } //for
}
