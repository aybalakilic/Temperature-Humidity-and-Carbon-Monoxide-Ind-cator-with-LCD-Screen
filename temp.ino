#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>
#define DHTPIN 6
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
LiquidCrystal lcd(12,11,5,4,3,2);
int buzzer=7;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  lcd.begin(16,2);
  dht.begin();

  lcd.setCursor(4,0);
  lcd.print("WELCOME");
  
  lcd.setCursor(2,1);
  lcd.print("THE INDICATOR");
  delay(2000);
}

void loop()
{
  int gase_rate=analogRead(A0);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.setCursor(12,0);
  lcd.print(t);

  lcd.setCursor(0,1);
  lcd.print("Humidity:");
  lcd.setCursor(9,1);
  lcd.print(t);

  delay(200);
  if(gase_rate>440)
  {
    lcd.setCursor(4,0);
    lcd.print("WARNING!:");
    lcd.setCursor(1,1);
    lcd.print("SMOKE DETECKED");
    digitalWrite(buzzer,HIGH);
    delay(100);
  }
  else
  digitalWrite(buzzer,LOW);
}