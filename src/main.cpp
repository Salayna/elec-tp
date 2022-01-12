#include <Arduino.h>

const int  buttonPin = 13;
const int LED_1 = D8;
const int LED_2 = D9;
const int LED_3 = D10;
const int LED_4 = D11;

const int BUTTON_1 = A0;
const int BUTTON_2 = A0;
const int BUTTON_3 = A0;
const int BUTTON_4 = A0;

int buttonState = LOW;
void setup (){
 pinMode (LED_1,OUTPUT);
 pinMode (LED_2,OUTPUT);
 pinMode (LED_3,OUTPUT);
 pinMode (LED_4,OUTPUT);
 Serial.begin(9600);
 }
void loop(){
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_4, HIGH);
}