#include<Servo.h>
//int pos;
//Servo Myservo;
void setup() {
// put your setup code here, to run once:
pinMode(A0, INPUT);//smoke sensor
pinMode(7, OUTPUT);//led1
pinMode(8, OUTPUT);//led2
Serial.begin(9600);
pinMode(3, OUTPUT);//exhaust fan
pinMode(6, OUTPUT);//buzzer
//Myservo.attach(10);//Servo motor
}
void loop() {
// put your main code here, to run repeatedly:
int a=analogRead(A0);
Serial.println(a);
delay(200);
if(a>50){
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
digitalWrite(3,LOW);
tone(6,1000);
}
else
{
digitalWrite(8,HIGH);
digitalWrite(7,LOW);
digitalWrite(3,HIGH);
noTone(6);
}
}
