#include "LCD_display.h"
#include <Arduino.h>
#include <LiquidCrystal.h>


const int rs = 12, en = 13, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



//afiseaza mesajul de bun-venit si instructiunile de incepere
void  welcome()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WELCOME");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TO  START");
  lcd.setCursor(0,1);
  lcd.print("PRESS  RED");
}


//face o numaratoare inversa de la un numr dat
void count_down(int timer, LiquidCrystal &lcd)
{
  for(int i=timer; i>=0; i--)
  {
    lcd.print("  ");
    lcd.print(i);
    delay(_COUNT_DOWN_DELAY);
  }
}


//afiseaza ecranul pentru nivelul curent
void _level(int nivel, int timer)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Level  ");
  lcd.print(nivel);
  lcd.setCursor(0,1);
  count_down(timer, lcd);
}


//printeaza culoarea pe masura ce sunt apasate butoanele
void showButtons(int buton, int index)
{
  
  switch(buton)
  {
    case 2:
    lcd.setCursor(index, 1);
    lcd.print("R");
    break;

    case 3:
    lcd.setCursor(index, 1);
    lcd.print("B");
    break;

    case 4:
    lcd.setCursor(index, 1);
    lcd.print("G");
    break;

    case 5:
    lcd.setCursor(index, 1);
    lcd.print("O");
    break;

    case 6:
    lcd.setCursor(index, 1);
    lcd.print("Y");
    break;
  }
}


//se ruleaza daca user-ul a gresit
void youLost()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WRONG   :-(");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("For  RESET");
  lcd.setCursor(0,1);
  lcd.print("press RED");
}


//se ruleaza cand s-a atins nivelul maxim
void youWon()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" CONGRATS!!!");
  delay(3000);
  lcd.setCursor(0,1);
  lcd.print("YOU WON!!!");
  lcd.clear();
  delay(4000);
  lcd.setCursor(0,0);
  lcd.print("To play again");
  lcd.setCursor(0,1);
  lcd.print("press RED");
}


