/*
 * Transmitter FS1000A/XY-FST (3.3V)
 * Receiver XY-MK-5V
 */

#define TX_PIN 32 //RF Transmitter Pin
#define TX_LED 30 //LED Pin to Signal Transmit
#define RX_PIN A7 //RF Receive Pin
#define RX_LED 33 //LED Pin to Signal Receive
#define UP_THRESH 70 //uppser threshold value
#define LOW_THRESH 50 //lower threshold value

unsigned int data = 0; //variable used to store received data
bool flip = true;

void transmit();
void receive();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TX_PIN, OUTPUT);
  pinMode(TX_LED, OUTPUT);
  pinMode(RX_PIN, INPUT);
  pinMode(RX_LED, OUTPUT);
} //setup

void loop() {
  // put your main code here, to run repeatedly:

  //listen for I2C from RPi
  //if need to listen
    //receive()
  //if need to transmit
    //transmit()
  if (flip) {
    transmit();
    flip = false;
  } else {
    receive();
    flip = true;
  } //if-else
    
  delay(1000);
} //loop

void transmit() {
   for (int i=10; i>0; i-=3) {
     digitalWrite(TX_PIN, HIGH);     //Transmit a HIGH signal
     digitalWrite(TX_LED, HIGH);            //Turn the LED on
     delay(i*100);                           //Wait for 1 second
     
     digitalWrite(TX_PIN,LOW);      //Transmit a LOW signal
     digitalWrite(TX_LED, LOW);            //Turn the LED off
     delay(i*100);                            //Variable delay
   } //for
} //transmit

void receive() {
  for (int i = 5; i>0; i--) {
    data=analogRead(RX_PIN);    //listen for data on Analog pin 0
    
    if (data > UP_THRESH) {
      digitalWrite(RX_LED, LOW);   //If a LOW signal is received, turn LED OFF
      Serial.println(data);
    } else if (data < LOW_THRESH) {
      digitalWrite(RX_LED, HIGH);   //If a HIGH signal is received, turn LED ON
      Serial.println(data);
    } //if-else
    delay(50);
  } //for
  digitalWrite(RX_LED, LOW);
} //receive

