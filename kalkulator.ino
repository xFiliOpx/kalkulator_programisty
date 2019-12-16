#include "Nokia_5110.h"

#define RST 2 //definiowanie pinow z wyswietlacza XDXDtestXDXD
#define CE 3
#define DC 4
#define DIN 5
#define CLK 6

Nokia_5110 lcd = Nokia_5110(RST, CE, DC, DIN, CLK); //ustawianie wyswietlacza

String nastCyfr, caleDzialanie;

void setup() {
  lcd.print("Wait...");
  Serial.begin(9600);
  lcd.clear();
}

void loop() {
  
  nastCyfr = Serial.readString(); //tymczasowe wpisywanie nast cyfr

  if (nastCyfr != "="){ //sprawdzenie czy wykonac juz dzialanie jezeli jest =
    caleDzialanie += nastCyfr;
    }
    
  else { //tutaj bedzie cale sprawdzanie kolejnosci dialan i ich wykonywanie
    lcd.print(caleDzialanie);
    }
    
}
