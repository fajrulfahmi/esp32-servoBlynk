#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

//#define BLYNK_NO_BUILTIN
//#define BLYNK_NO_FLOAT
#define BLYNK_TEMPLATE_ID "TMPLFj4S4eGp"
#define BLYNK_DEVICE_NAME "servo"
#define BLYNK_AUTH_TOKEN "jH4NQJwKelj36mc64HXxYpZasaRq7R7r"
#define BLYNK_PRINT Serial

#include <Servo.h>
Servo servo;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Mii";
char pass[] = "aa123456";

BLYNK_WRITE(V0) {
  int s0 = param.asInt();
  servo.write(0);
  Blynk.virtualWrite(V0, s0);
}

void setup() {
  Serial.begin(9600);
  servo.attach(13);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);  //Blynk Config
  //  Serial.println(Blynk.connected());
  //  Serial.println("OK");
}

void loop() {
  Blynk.run();
}
