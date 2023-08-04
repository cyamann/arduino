#include <DHT.h>
#define DHTPIN A0        // Pin connected to DHT11 data pin
#define DHTTYPE DHT11   // DHT sensor type
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

int TEMPERATURE_MIN = 25;
int TEMPERATURE_MAX = 35;
int HUMIDITY_MIN = 30;
int HUMIDITY_MAX = 70;
int LIGHT_MIN = 300;
int LIGHT_MAX = 700;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  dht.begin();
}

void loop() {
  bool flag = false;
  delay(2000);  // Wait for 2 seconds between measurements
  float humidity = dht.readHumidity();
  float tempature = dht.readTemperature();
  int ldr_sensor = analogRead(A1);

  if(humidity<HUMIDITY_MIN){
    flag = true;
    lcd.setCursor(0, 0);
    lcd.print("HUMI IS TOO LOW");
    lcd.setCursor(0, 1);
    lcd.print("HMIN:");
    lcd.print(HUMIDITY_MIN);
    lcd.print(" HCUR:");
    lcd.print(humidity);
  }
  else if(humidity>HUMIDITY_MAX){
    flag = true;
    lcd.setCursor(0, 0);
    lcd.print("HUMI IS TOO HIGH");
    lcd.setCursor(0, 1);
    lcd.print("HMAX:");
    lcd.print(HUMIDITY_MAX);
    lcd.print(" HCUR:");
    lcd.print(humidity);

  }
  if(tempature<TEMPERATURE_MIN){
    flag = true;
    lcd.setCursor(0, 0);
    lcd.print("TEMP IS TOO LOW");
    lcd.setCursor(0, 1);
    lcd.print("TMIN:");
    lcd.print(TEMPERATURE_MIN);
    lcd.print(" TCUR:");
    lcd.print(tempature);

  }
  else if(tempature > TEMPERATURE_MAX){
    flag = true;
    lcd.setCursor(0, 0);
    lcd.print("TEMP IS TOO HIGH");
    lcd.setCursor(0, 1);
    lcd.print("TMAX:");
    lcd.print(TEMPERATURE_MAX);
    lcd.print(" TCUR:");
    lcd.print(tempature);
  }
  if(ldr_sensor<LIGHT_MIN){
    flag = true;
    lcd.setCursor(0,0);
    lcd.print("LIGH IS TOO LOW");
    lcd.setCursor(0,1);
    lcd.print("LMIN:");
    lcd.print(LIGHT_MIN);
    lcd.print(" LCUR:");
    lcd.print(ldr_sensor);
  }
  else if(ldr_sensor>LIGHT_MAX){
    flag = true;
    lcd.setCursor(0,0);
    lcd.print("LIGH IS TOO HIGH");
    lcd.setCursor(0,1);
    lcd.print("LMAX:");
    lcd.print(LIGHT_MAX);
    lcd.print(" LCUR:");
    lcd.print(ldr_sensor);
  }
  if(!flag){
  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.print(tempature);
  lcd.print(" H:");
  lcd.print(humidity);
  lcd.print(" L:");
  lcd.print(ldr_sensor);
  lcd.setCursor(0,1);
  lcd.print("STATUS : OPTIMAL");
  }
}
