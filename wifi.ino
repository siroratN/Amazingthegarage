void Line_Notify1(String message1) ;

#include <WiFi.h>
#include <WiFiClientSecure.h>

#define WIFI_SSID "OPPO Reno8 T 5G"   
#define WIFI_PASSWORD "811010za"    

#define LINE_TOKEN_PIR "K2s2yyjnTwRmYrfGK1QcPtRWz7WfuErGy1VMhVZKhAK"

#define PirPin 16
#define LED 17

String message1 = "Your car has back.";      
String message2 = "Your car has left.";  
uint32_t time1, time2;

void setup() {

  Serial.begin(115200);
  Serial.println();

  pinMode(PirPin, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);


  Serial.println("connecting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("connecting");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  delay(5000);
  Serial.println("Pir Ready!!");

  time1 = time2 = millis();
}

void loop() {

  time1 = millis();

  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(LED, HIGH);
  }


  if ((digitalRead(PirPin) == 1) && (WiFi.status() == WL_CONNECTED)) {
    while (digitalRead(PirPin) == 1) delay(100);
    Serial.println("back");
    digitalWrite(LED, HIGH);
    Line_Notify1(message1);
  }else if ((digitalRead(PirPin) == 0) && (WiFi.status() == WL_CONNECTED)) {
    while (digitalRead(PirPin) == 0) delay(100);
    Serial.println("left");
    digitalWrite(LED, HIGH);
    Line_Notify1(message2);
  }
  delay(10);

}

void Line_Notify1(String message) {
  WiFiClientSecure client;
  client.setInsecure();           // ถ้าเป็น ESP32 เวอร์ชั่น 1.0.4 ให้ปิดส่วนนี้ไว้
  if (!client.connect("notify-api.line.me", 443)) {
    Serial.println("connection failed");
    delay(2000);
    return;
  }

  String req = "";
  req += "POST /api/notify HTTP/1.1\r\n";
  req += "Host: notify-api.line.me\r\n";
  req += "Authorization: Bearer " + String(LINE_TOKEN_PIR) + "\r\n";
  req += "Cache-Control: no-cache\r\n";
  req += "User-Agent: ESP8266\r\n";
  req += "Content-Type: application/x-www-form-urlencoded\r\n";
  req += "Content-Length: " + String(String("message=" + message).length()) + "\r\n";
  req += "\r\n";
  req += "message=" + message;
  // Serial.println(req);
  client.print(req);

  delay(20);

  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }
}