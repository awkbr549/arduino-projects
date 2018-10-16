// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
#define SLAVE 8
#define BUF_SIZE 32

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  pinMode(LED_BUILTIN, OUTPUT);
//  Serial.begin(9600);
}

byte x = 0;

void loop() {
  char data[BUF_SIZE];
  short i;
  for (i = 0; i < BUF_SIZE; i++) {
    if (i % 3 == 0) {
      data[i] = random(48, 57);
    } else if (i % 3 == 1) {
      data[i] = random(65, 70);
    } else {
      data[i] = ' ';
    } //if-else
  } //for
  data[i] = '\0';
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  Wire.beginTransmission(SLAVE);
  Wire.write(data, BUF_SIZE);
  Wire.endTransmission();
  delay(500);
  
//  Serial.println("Sending data...");
//  digitalWrite(LED_BUILTIN, HIGH);
//  delay(100);
//  digitalWrite(LED_BUILTIN, LOW);
//  Wire.beginTransmission(8); // transmit to device #8
//  Wire.write("x is ");        // sends five bytes
//  Wire.write(x);              // sends one byte
//  Wire.endTransmission();    // stop transmitting
//
//  x++;
//  delay(500);
}
