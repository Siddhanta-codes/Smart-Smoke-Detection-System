#include <I2Cdev.h>
#include <LiquidCrystal_I2C.h>
//#include <LiquidCrystal_I2C.h>
#include<SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
//#include <LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
const char* ssid = "Siddhanta";
const char* password = "121242121";
const char* host = "maker.ifttt.com";
const int httpsPort = 443;
const char* ch = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
// Use web browser to view and copy
// SHA1 fingerprint of the certificate
const char* fingerprint = "616275faea5f64954af6090f59c90de71e6d66a3";
SoftwareSerial mySerial(D3,D4);
void setup() {
// put your setup code here, to run once:
Serial.begin(115200);
mySerial.begin(9600);
Serial.println();
Serial.print("connecting to ");
Serial.println(ssid);
// WiFi.mode(WIFI_STA);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
//pinMode(smokeA0, INPUT);
}
Serial.println("");
Serial.println("WiFi connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
lcd.begin();
lcd.backlight();
14
15
}
void loop() {
// put your main code here, to run repeatedly:
String msg = mySerial.readStringUntil(’\r’);
Serial.println(msg);
int num;
num=msg.toInt();
if(num>50){
WiFiClientSecure client;
Serial.print("connecting to ");
Serial.println(host);
Serial.print("Using fingerprint: ");
Serial.println(fingerprint);
client.setFingerprint(fingerprint);
if (!client.connect(host, httpsPort))
{
Serial.println("connection failed");
return;
}
String url = "/trigger/Smoke_detected/json/with/key/bmKuHq_SOHNIQbfSerial.print("requesting URL: ");
Serial.println(url);
client.print(String("GET ") + url + " HTTP/1.1\r\n" +
"Host: " + host + "\r\n" +
"User-Agent: BuildFailureDetectorESP8266\r\n" +
"Connection: close\r\n\r\n");
Serial.println("request sent");
}
else{
Serial.println("ALL ok");
lcd.setCursor(0,0);
lcd.print("hello");
}
}
