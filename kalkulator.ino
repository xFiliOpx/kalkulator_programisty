#include "Nokia_5110.h"

#define gndMat1 0
#define gndMat2 1
#define gndMat3 12
#define gndMat4 13

#define kolMat1 8
#define kolMat2 9
#define kolMat3 10
#define kolMat4 11

#define RST 2 //definiowanie pinow z wyswietlacza
#define CE 3
#define DC 4
#define DIN 5
#define CLK 6

Nokia_5110 lcd = Nokia_5110(RST, CE, DC, DIN, CLK); //ustawianie wyswietlacza

String nastCyfr, caleDzialanie;

bool klik;

String matrix(){
  for (int i = 1; i <= 4; i++){
    digitalWrite(gndMat1, HIGH);
    digitalWrite(gndMat2, HIGH);
    digitalWrite(gndMat3, HIGH);
    digitalWrite(gndMat4, HIGH);
    switch(i){
      case 1:
        digitalWrite(gndMat1, LOW);
        if (digitalRead(kolMat1) == 1) return "7";
        if (digitalRead(kolMat2) == 1) return "8";
        if (digitalRead(kolMat3) == 1) return "9";
        if (digitalRead(kolMat4) == 1) return "+";
      break;
      case 2:
      digitalWrite(gndMat2, LOW);
        if (digitalRead(kolMat1) == 1) return "4";
        if (digitalRead(kolMat2) == 1) return "5";
        if (digitalRead(kolMat3) == 1) return "6";
        if (digitalRead(kolMat4) == 1) return "-";
      break;
      case 3:
      digitalWrite(gndMat3, LOW);
        if (digitalRead(kolMat1) == 1) return "1";
        if (digitalRead(kolMat2) == 1) return "2";
        if (digitalRead(kolMat3) == 1) return "3";
        if (digitalRead(kolMat4) == 1) return "*";
      break;
      case 4:
      digitalWrite(gndMat4, LOW);
        if (digitalRead(kolMat1) == 1) return ".";
        if (digitalRead(kolMat2) == 1) return "0";
        if (digitalRead(kolMat3) == 1) return "=";
        if (digitalRead(kolMat4) == 1) return "/";
      break;
      }
    }
    return "";
  }


void setup() {
  lcd.print("Wait...");
  
  Serial.begin(9600);
  
  pinMode(kolMat1, INPUT);
  pinMode(kolMat2, INPUT);
  pinMode(kolMat3, INPUT);
  pinMode(kolMat4, INPUT);

  pinMode(gndMat1, OUTPUT);
  pinMode(gndMat2, OUTPUT);
  pinMode(gndMat3, OUTPUT);
  pinMode(gndMat4, OUTPUT);
  
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
