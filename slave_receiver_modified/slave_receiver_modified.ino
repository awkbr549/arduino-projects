// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
#define ADDR 8
#define BUF_SIZE 32

void setup() {
  Wire.begin(ADDR);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  delay(10);
  char data[BUF_SIZE];
  short i;
  for (i = 0; i < BUF_SIZE; i++) {
    data[i] = Wire.read();
  } //for
//  data[i] = '\n';

  Serial.println(data);

  
//  while (0 < Wire.available()) { // loop through all but the last
//    char c = Wire.read(); // receive byte as a character
//    Serial.print(c);         // print the character
//  }
//  Serial.println();

  
//  int x = Wire.read();    // receive byte as an integer
//  Serial.println(x);         // print the integer
}
