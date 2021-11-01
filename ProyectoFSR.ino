#include  <LiquidCrystal.h>
//int pin_lectura = A0;
int valor;
int voltaje;
float Newton=0.0;
float X=0.0;
float Vout=0.0;
double F=0.0;
double Rs=0.0;
double W=0.0;

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop()
{

  lcd.begin(16, 2);
  lcd.home();
  lcd.print("Goiz Alvarez");
  lcd.setCursor ( 0, 1 );
  lcd.print("Cesar Andre");
  delay(1000);
  lcd.clear();
  
  
  Vout=((analogRead(A0))*5.0)/1023.0;
  Rs=15.0*((5.0/Vout)-1);
  F=pow(Rs/6.0042,-1.428571429);
  W=(F*0.102);
  
  
  lcd.begin(16,2);
  lcd.home();
  lcd.print("Fuerza=");
  lcd.print(F,4);
  lcd.print("\tN");
  lcd.setCursor(0,1);
  lcd.print("Peso=");
  lcd.print(W,4);
  lcd.print("\tKg");
  delay(1000);
}
