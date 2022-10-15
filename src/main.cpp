#include <Arduino.h>

#define BOARD_LED 2
#define RELAY_SOIL1 33
#define RELAY_SOIL2 25
#define RELAY_SOIL3 26
#define RELAY_SOIL4 27
#define RELAY_SOIL5 14
#define RELAY_SOIL6 12

#define SOIL_PIN1 0
#define SOIL_PIN2 4
#define SOIL_PIN3 16
#define SOIL_PIN4 17
#define SOIL_PIN5 5
#define SOIL_PIN6 18

const int dry = 1000;
const int wet = 3000;

void updateWatering(int soilPin, int relayPin)
{

  int soilValue = analogRead(soilPin);
  int dryPercent = map(soilValue, wet, dry, 100, 0);
  Serial.print("soil =");
  Serial.println(soilValue);
  Serial.print("soil percent=");
  Serial.println(dryPercent);
  if (dryPercent > 60)
  {
    digitalWrite(relayPin, HIGH);
  }
  else
  {
    digitalWrite(relayPin, LOW);
  }
}

void setup()
{
  Serial.begin(115200);

  pinMode(BOARD_LED, OUTPUT);
  // pinMode(RELAY_SOIL1, OUTPUT);
  pinMode(RELAY_SOIL2, OUTPUT);
  pinMode(RELAY_SOIL3, OUTPUT);
  pinMode(RELAY_SOIL4, OUTPUT);
  // pinMode(RELAY_SOIL5, OUTPUT);
  // pinMode(RELAY_SOIL6, OUTPUT);
}

void loop()
{

  digitalWrite(BOARD_LED, HIGH);
  delay(2000);

  updateWatering(SOIL_PIN2, RELAY_SOIL2);
  delay(200);
  updateWatering(SOIL_PIN3, RELAY_SOIL3);
  delay(200);
  updateWatering(SOIL_PIN4, RELAY_SOIL4);

  digitalWrite(BOARD_LED, LOW);
  delay(2000);
}
