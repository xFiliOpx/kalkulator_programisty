#include "Nokia_5110.h"

#define RST 2 //definiowanie pinow z wyswietlacza
#define CE 3
#define DC 4
#define DIN 5
#define CLK 6

Nokia_5110 lcd = Nokia_5110(RST, CE, DC, DIN, CLK); //ustawianie wyswietlacza

String nacisnieto();{ //(tymczasowo z portu szeregowego) pobieranie nast cyfry/dzialania
  String x = Serial.readString();
  return x;
  }


void setup() {
  lcd.print("Wait...");
  String nastCyfr, caleDzialanie;
  Serial.begin(9600);
  lcd.clear();
}

void loop() {
  nastCyfr = nacisnieto();

  if (nastCyfr != "="){ //sprawdzenie czy wykonac juz dzialanie jezeli jest =
    caleDzalanie += nastCyfr;
    }
  else { //tutaj bedzie cale sprawdzanie kolejnosci dialan i ich wykonywanie
    
    }
  
    lcd.clear();//to cale na puzniej zeby wyswietlac
    a = Serial.readString();
    lcd.print("Wpisane: ");
    lcd.print(a);
    delay(500);
}
