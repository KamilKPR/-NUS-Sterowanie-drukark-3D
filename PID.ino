#include <LiquidCrystal.h>
#define a -5.16520255795299e-07
#define b 8.719375419247528e-04
#define c -0.594359941886608
#define d 2.489426557571541e+02
#define HEATER_0_PIN       10
int i = 0;
double x, y, e,stara,predkosc ,P,I,D;
int u;
double calka = 0;


#define TEMP_0_PIN         13   // Analog Input
LiquidCrystal lcd(16, 17, 23, 25, 27, 29);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(20, 4);
  pinMode(HEATER_0_PIN, OUTPUT);


}

void loop() {


  lcd.setCursor(0, 0);
  //  if (i<=50)
  //    {digitalWrite(HEATER_0_PIN, HIGH);
  //    i++;}
  //  else
  //    digitalWrite(HEATER_0_PIN, LOW);

  //
  //  delay(100);

  x = (double)analogRead(TEMP_0_PIN);
  y = a * x * x * x + b * x * x + c * x + d;
  lcd.print(y);

  e = 100 - y;
  predkosc = (y-stara)/0.1;

  calka = calka + e * 0.1;
  P=255/80;
  I=0.2;
  D=1;
  u = (round(P*e+I*calka+D*predkosc));
  if (u < 0)
  {
    u = 0;
  }

  if (u > 255)
  {
    u = 255;
  }

  analogWrite(10, u);

  stara=y;
  delay(100);

  if (u > 0 && u < 255)
  { lcd.setCursor(0, 1);

    lcd.print("ON");
  }
  else
  { calka = 0;
    lcd.setCursor(0, 1);
    lcd.print("OFF");
  }


  lcd.setCursor(0, 2);
  lcd.print(u);
}
