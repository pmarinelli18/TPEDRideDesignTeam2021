// Basic Bluetooth sketch HC-05_AT_MODE_01
// Connect the HC-05 module and communicate using the serial monitor
//
// The HC-05 defaults to commincation mode when first powered on you will need to manually enter AT mode
// The default baud rate for AT mode is 38400
// See www.martyncurrey.com for details
//

// Make sure the pins are valid for RX and TX there are only certain ones
// The TX and RX may be reversed
// https://remotexy.com/en/help/bluetooth/
// check the baud rate in AT mode with commands in the following link
// https://www.instructables.com/Changing-Baud-Rate-of-HC-05-Bluetooth/
// http://www.martyncurrey.com/connecting-2-arduinos-by-bluetooth-using-a-hc-05-and-a-hc-06-easy-method-using-cmode/

#include <SoftwareSerial.h>
SoftwareSerial BTserial(11, 12); // RX | TX
// Connect the HC-05 TX to Arduino pin 11 RX. 
// Connect the HC-05 RX to Arduino pin 12 TX through a voltage divider.
// 

char c = ' ';
 
void setup() 
{
    Serial.begin(9600);
    Serial.println("Arduino is ready");
    Serial.println("Remember to select Both NL & CR in the serial monitor");
 
    // HC-05 default serial speed for AT mode is 38400
    BTserial.begin(38400);  
}

void loop()
{
 
    // Keep reading from HC-05 and send to Arduino Serial Monitor
    if (BTserial.available())
    {  
        c = BTserial.read();
        Serial.write(c);
    }
 
    // Keep reading from Arduino Serial Monitor and send to HC-05
    if (Serial.available())
    {
        c =  Serial.read();
        BTserial.write(c);  
    }
}
