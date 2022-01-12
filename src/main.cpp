#include <Arduino.h>
#include <Arduino_LSM6DS3.h>

const int  buttonPin = 13;
const int LED_1 = D8;
const int LED_2 = D9;
const int LED_3 = D10;
const int LED_4 = D11;

const int BUTTON_1 = A0;
const int BUTTON_2 = A1;
const int BUTTON_3 = A2;
const int BUTTON_4 = A3;

int button1State = LOW;
int button2State = LOW;
int button3State = LOW;
int button4State = LOW;

void setup (){
 pinMode (LED_1,OUTPUT);
 pinMode (LED_2,OUTPUT);
 pinMode (LED_3,OUTPUT);
 pinMode (LED_4,OUTPUT);
 pinMode(BUTTON_1, INPUT);
 pinMode(BUTTON_2, INPUT);
 pinMode(BUTTON_3, INPUT);
 pinMode(BUTTON_4, INPUT);
 Serial.begin(9600);
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");

    while (1);
  }

  Serial.print("Gyroscope sample rate = ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Gyroscope in degrees/second");
  Serial.println("X\tY\tZ");
 }
void loop(){
  button1State = digitalRead(BUTTON_1);
  button2State = digitalRead(BUTTON_2);
  button3State = digitalRead(BUTTON_3);
  button4State = digitalRead(BUTTON_4);
  digitalWrite(LED_1, !button1State);
  digitalWrite(LED_2, !button2State);
  digitalWrite(LED_3, !button3State);
  digitalWrite(LED_4, !button4State);

   float x, y, z;

  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(x, y, z);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);
  }
}