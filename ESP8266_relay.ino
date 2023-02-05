#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//Define the relay pins
#define relay1 D0
#define relay2 D1


#define BLYNK_AUTH_TOKEN "EJ-Db4mJEZQoUfOOvfvkXLyOb7AyFs8O" 

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Habish";//Enter your WIFI name
char pass[] = "Habish@1406";//Enter your WIFI password

//Get the button values
BLYNK_WRITE(V0) {
  bool value1 = param.asInt();
  
  if (value1 == 1) {
    digitalWrite(relay1, LOW);
  } else {
    digitalWrite(relay1, HIGH);
  }
}

BLYNK_WRITE(V1) {
  bool value2 = param.asInt();
  
  if (value2 == 1) {
    digitalWrite(relay2, LOW);
  } else {
    digitalWrite(relay2, HIGH);
  }
}




void setup() {
  
  pinMode(relay1, OUTPUT);

  pinMode(relay2, OUTPUT);

  
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);


  
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  
  Blynk.run();
}
