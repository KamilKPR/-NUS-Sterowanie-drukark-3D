#include <LiquidCrystal.h>
#define a -5.16520255795299e-07
#define b 8.719375419247528e-04
#define c -0.594359941886608
#define d 2.489426557571541e+02
#define HEATER_0_PIN       10
 int i=0;
double x, y;
#define TEMP_0_PIN         13   // Analog Input 
LiquidCrystal lcd(16, 17, 23, 25, 27, 29);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(20, 4);
  pinMode(HEATER_0_PIN, OUTPUT);
 
  
}

void loop() {

  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  if (i<=50)
    {digitalWrite(HEATER_0_PIN, HIGH);
    i++;}
  else
    digitalWrite(HEATER_0_PIN, LOW);
    
  delay(100);


  x = (double)analogRead(TEMP_0_PIN);
  y = a * x * x * x + b * x * x + c * x + d;
  lcd.print(y);

}
