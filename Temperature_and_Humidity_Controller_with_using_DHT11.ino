#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN A0
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

/* LCD configuration */
LiquidCrystal lcd(12,11,6,5,4,3);

/* Pins */
int relayPin = 9;
int buzzerPin = 7;
int tempPot = A1;
int humPot = A2;

void setup()
{
  lcd.begin(16,2);
  dht.begin();
  delay(2000);

  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int tempValue = analogRead(tempPot);
  int humValue = analogRead(humPot);

  float tempSet = map(tempValue,0,1023,20,40);
  float humSet  = map(humValue,0,1023,40,80);

  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print((char)223);
  lcd.print("C ");

  lcd.setCursor(9,0);
  lcd.print("H:");
  lcd.print(humidity);
  lcd.print("%");

  lcd.setCursor(0,1);
  lcd.print("TS:");
  lcd.print(tempSet);
  lcd.print(" ");

  lcd.setCursor(8,1);
  lcd.print("HS:");
  lcd.print(humSet);

  /* Relay control */
  if(temperature > tempSet)
  {
    digitalWrite(relayPin,HIGH);
  }
  else
  {
    digitalWrite(relayPin,LOW);
  }

  /* Alarm condition */
  if(temperature > 40 || humidity > 85)
  {
    digitalWrite(buzzerPin,HIGH);
  }
  else
  {
    digitalWrite(buzzerPin,LOW);
  }

  delay(2000);
}