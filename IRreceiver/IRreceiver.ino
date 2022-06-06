/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>
int LEDpin = 13;
int RECV_PIN = 10;
int num=0;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LEDpin,OUTPUT);
}

void loop() {

  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    
    while(results.value==0xE318261B)
    {
      if(num%2==1)
       {
        digitalWrite(LEDpin, HIGH);
        num++;
        break;
       }
      else if(num%2==0)
      {
        digitalWrite(LEDpin,LOW);
        num++;
        break;
      }
    }
    while(results.value==0xEE886D7F)
    {
      digitalWrite(LEDpin, HIGH);
      delay(50);
      digitalWrite(LEDpin,LOW);
      delay(50);
      digitalWrite(LEDpin, HIGH);
      delay(50);
      digitalWrite(LEDpin,LOW);
      delay(50);
      break;
    }

    irrecv.resume(); // Receive the next value
  }
}
