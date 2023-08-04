#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String LCD_ROW_1 = "This text is for row 0 and longer than 16 characters.";
String LCD_ROW_2 = " ABCD EFGH";

boolean SCROLL_FLAG = true;

char SCROLL_DIRECTION = 'R';

int SCROLL_WAIT = 1000;
byte customs[] = {
  B01110,
  B10001,
  B01000,
  B00100,
  B00010,
  B10001,
  B01110,
  B00100
};
byte customCharc[] = {
  B01110,
  B10001,
  B10000,
  B10000,
  B10000,
  B10001,
  B01110,
  B00100
};
byte customCharg[] = {
  B11111,
  B01110,
  B10001,
  B10001,
  B10000,
  B10111,
  B10001,
  B01110
};
byte customCharo[] = {
  B01010,
  B01110,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B01110
};
byte customCharu[] = {
  B01010,
  B00000,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B01110
};
byte customChari[] = {
  B00100,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B11111
};


void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.createChar(0, customs);
  lcd.createChar(1, customCharc);
  lcd.createChar(2, customCharo);
  lcd.createChar(3, customCharg);
  lcd.createChar(4, customChari);
  lcd.createChar(5, customCharu);
  lcd.setCursor(0,0);
  lcd.write(0);
  lcd.write(1);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  
}

void loop() {
 /* unsigned int a = 0;
  unsigned int b = 0;
  unsigned int cursor = 0;
  while (true) {
    long start_time = micros();
    unsigned int counter;
    if (cursor % SCROLL_WAIT == 0) {
      lcd.clear();
      if (LCD_ROW_1.length() > 16) {
        for (counter = 0; counter < 16; counter++) {
          lcd.setCursor(counter, 0);
          if ((counter + a) > 0) lcd.print(LCD_ROW_1.charAt((counter + a) % LCD_ROW_1.length()));
          else lcd.print(LCD_ROW_1.charAt((LCD_ROW_1.length() + (counter + a)) % LCD_ROW_1.length()));
        }
      }
      else {
        for (counter = 0; counter < LCD_ROW_1.length(); counter++) {
          if ((counter + a) > 0) lcd.setCursor((counter + a) % 16, 0);
          else lcd.setCursor((16 + (counter + a)) % 16, 0);
          lcd.print(LCD_ROW_1.charAt(counter));
        }
      }
      if (LCD_ROW_2.length() > 16) {
        for (counter = 0; counter < 16; counter++) {
          lcd.setCursor(counter, 1);
          if ((counter + b) >= 0 && (counter + b) < 15) lcd.print(LCD_ROW_2.charAt((counter + b) % LCD_ROW_2.length()));
          else lcd.print(" ");
        }
      }
      else {
        for (counter = 0; counter < LCD_ROW_2.length(); counter++) {
          lcd.setCursor(15 - ((-counter + a) % 16), 1);
          lcd.print(LCD_ROW_2.charAt(counter));
        }
      }

      if (SCROLL_FLAG) {
        if (SCROLL_DIRECTION == 'L') a++;
        else a--;
      }
      if (SCROLL_FLAG) {
        if (SCROLL_DIRECTION == 'R') b++;
        else b--;
      }
    }
    long end_time = micros();
    if ((1000 - (end_time - start_time)) > 0) delayMicroseconds(1000 - (end_time - start_time));
    cursor++;
  }*/
}
