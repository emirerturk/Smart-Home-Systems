#include <LiquidCrystal.h>
#include <Keypad.h>

const byte rows = 4;
const byte cols = 3;
char keys[rows][cols] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'#', '0', '*'}
};
byte rowPins[rows] = {4, 3, 2, 1};
byte colPins[cols] = {5, 6, 7};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int sayac = 0;
int sicaklik = 0;
int deger = 0;
int deger2 = 0;
int temp = 0;
void setup()
{

  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  analogReference(INTERNAL2V56);
}

void loop() {

  while (temp == 0)
  {

    char code = keypad.getKey();

    //sifre 1425
    if (code == '1' && sayac == 0)
    {
      sayac++;
    }
    if (code == '4' && sayac == 1)
    {
      sayac++;
    }
    if (code == '2' && sayac == 2)
    {
      sayac++;
    }
    if (code == '5' && sayac == 3)
    {
      sayac++;
    }
    if (code == '#')
    {
      if (sayac == 4)
      {
        digitalWrite(23, HIGH);
        delay(250);
        digitalWrite(23, LOW);
        sayac = 0;
      }
      else
      {
        digitalWrite(22, HIGH);
        delay(250);
        digitalWrite(22, LOW);
        sayac = 0;
      }
    }
    if (code == '*')
    {
      digitalWrite(23, HIGH);
      digitalWrite(22, HIGH);
      delay(250);
      digitalWrite(23, LOW);
      digitalWrite(22, LOW);
      temp++;
      break;
    }
  }
  int Flame = digitalRead(A0);

  if (Flame == HIGH)
  {
    digitalWrite(52, HIGH);


  }
  else
  {
    digitalWrite(52, LOW);
  }
  int pir = digitalRead(A1);

  if (pir == HIGH)
  {
    digitalWrite(53, HIGH);


  }
  else
  {
    digitalWrite(53, LOW);
  }
  sicaklik = analogRead(A2);
  sicaklik = sicaklik / 4;

  lcd.print("Sicaklik :");
  lcd.print(sicaklik);
  lcd.print(" C");
  delay(500);
  lcd.clear();


  if (deger == 0 && sicaklik < 20)
  {

    lcd.print("Sicaklik dustu");
    delay(500);
    lcd.clear();
    deger++;
  }

  else if (deger2 == 0 && sicaklik > 30)
  {

    lcd.print("Sicaklik yukseldi");
    delay(500);
    lcd.clear();
    deger2++;
  }
  else if (sicaklik > 20 && sicaklik < 30)
  {
    deger = 0;
    deger2 = 0;
  }

}
