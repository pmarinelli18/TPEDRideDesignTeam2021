// Basic bluetooth test sketch. HC-06_01
// HC-06 ZS-040 
// 
// 
//  Uses hardware serial to talk to the host computer and software serial for communication with the bluetooth module
//
//  Pins
//  BT VCC to Arduino 5V out. 
//  BT GND to GND
//  BT RX to Arduino pin 3 (through a voltage divider)
//  BT TX  to Arduino pin 2 (no need voltage divider)
//
//  When a command is entered in the serial monitor on the computer 
//  the Arduino will relay it to the bluetooth module and display the result.
//
//  These HC-06 modules require capital letters and no line ending
//


// https://www.instructables.com/AT-command-mode-of-HC-05-Bluetooth-module/

#include <SoftwareSerial.h>
SoftwareSerial BTserial(11, 12); // RX | TX

char c = ' ';
 
void setup() 
{
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
 
  // HC-06 default baud rate is 9600
  BTserial.begin(9600);  
}
 
void loop()
{
  
  // Keep reading from HC-06 and send to Arduino Serial Monitor
  if (BTserial.available())
    Serial.write(BTserial.read());
 
  // Keep reading from Arduino Serial Monitor and send to HC-06
  if (Serial.available())
    BTserial.write(Serial.read());
  
}
