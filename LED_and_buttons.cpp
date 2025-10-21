#include "LED_and_buttons.h"
#include <Arduino.h>
#include "LCD_display.h"
#include <LiquidCrystal.h>

//initializeaza butoanele
void init_buttons() {
  pinMode(buton_albastru, INPUT_PULLUP);
  pinMode(buton_verde, INPUT_PULLUP);
  pinMode(buton_galben, INPUT_PULLUP);
  pinMode(buton_rosu, INPUT_PULLUP);
  pinMode(buton_portocaliu, INPUT_PULLUP);
}


//initializeza led-urile
void init_leduri()
{
  pinMode(LED_ROSU, OUTPUT);
  pinMode(LED_ALBASTRU, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_PORTOCALIU, OUTPUT);
  pinMode(LED_GALBEN, OUTPUT);
}


int secventa_generata[_NUMAR_MAXIM_NIVELURI];
int secventa_introdusa[_NUMAR_MAXIM_NIVELURI];


//genereaza secventa de aprindere a led-urilor
void generateSequence(int * secventa_generata, int nivel)
{
  Serial.print("Secventa: ");
  for(int i=0; i<nivel; i++)
  {
    secventa_generata[i]=random(2,7);
    if(secventa_generata[i-1]==secventa_generata[i] && i>0) secventa_generata[i]=random(2,7);
    delay(25);
  }
  for(int i=0; i<nivel; i++) Serial.print(secventa_generata[i]-1);
  Serial.println(" ");
}


//aprinde led-urile in secventa data
void lightOnLeds(int *secventa_generata, int nivel)
{
  for(int i=0; i<nivel; i++)
  {
    digitalWrite(secventa_generata[i], HIGH);
    delay(_TIMP_LEDURI_APRINSE);
    digitalWrite(secventa_generata[i], LOW);
    delay(150);
  }
}


//primeste secventa apasarilor butoanelor
void readSequence(int *secventa_introdusa, int nivel)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Secventa: ");
  int index = 0;
  while(index < nivel)
  {
    if(digitalRead(buton_rosu) == 0)
    {
      secventa_introdusa[index] = 2;
      while(digitalRead(buton_rosu) == 0); // asteapta eliberare
      showButtons(secventa_introdusa[index], index);
       ++index;
      delay(_DELAY_BUTON);
    }
    else if(digitalRead(buton_verde) == 0)
    {
      secventa_introdusa[index] = 4;
      while(digitalRead(buton_verde) == 0);
      showButtons(secventa_introdusa[index], index);
      ++index;
      delay(_DELAY_BUTON);
    }
    else if(digitalRead(buton_albastru) == 0)
    {
      secventa_introdusa[index] = 3;
      while(digitalRead(buton_albastru) == 0);
      showButtons(secventa_introdusa[index], index);
      ++index;
      delay(_DELAY_BUTON);
    }
    else if(digitalRead(buton_portocaliu) == 0)
    {
      secventa_introdusa[index] = 5;
      while(digitalRead(buton_portocaliu) == 0);
      showButtons(secventa_introdusa[index], index);
      ++index;
      delay(_DELAY_BUTON);
    }
    else if(digitalRead(buton_galben) == 0)
    {
      secventa_introdusa[index] = 6;
      while(digitalRead(buton_galben) == 0);
      showButtons(secventa_introdusa[index], index);
      ++index;
      delay(_DELAY_BUTON);
    }

    delay(20); // debounce scurt intre iteratii
  }
}


//verifica daca input-ul este corect
bool checkInput(int secventa_introdusa[], int secventa_generata[], int nivel)
{
  for(int i=0; i<nivel; i++)
  {
    if(secventa_introdusa[i]!=secventa_generata[i]) return false;
  }
  return true;
}



void aprinde_butoane_init()
{
  digitalWrite(LED_ROSU,HIGH);
  delay(_init_delay);
  digitalWrite(LED_ROSU,LOW);

  digitalWrite(LED_ALBASTRU,HIGH);
  delay(_init_delay);
  digitalWrite(LED_ALBASTRU,LOW);

  digitalWrite(LED_VERDE,HIGH);
  delay(_init_delay);
  digitalWrite(LED_VERDE,LOW);

  digitalWrite(LED_PORTOCALIU,HIGH);
  delay(_init_delay);
  digitalWrite(LED_PORTOCALIU,LOW);

  digitalWrite(LED_GALBEN,HIGH);
  delay(_init_delay);
  digitalWrite(LED_GALBEN,LOW);
  delay(145);

  for(int i=1; i<=3; i++)
  {
    digitalWrite(LED_ROSU,HIGH);
    digitalWrite(LED_ALBASTRU,HIGH);
    digitalWrite(LED_VERDE,HIGH);
    digitalWrite(LED_PORTOCALIU,HIGH);
    digitalWrite(LED_GALBEN,HIGH);
    delay(300);
    digitalWrite(LED_ROSU,LOW);
    digitalWrite(LED_ALBASTRU,LOW);
    digitalWrite(LED_VERDE,LOW);
    digitalWrite(LED_PORTOCALIU,LOW);
    digitalWrite(LED_GALBEN,LOW);
    delay(300);
  }
}




