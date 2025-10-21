#include "SimonGame.h"

int nivel =3;
int level=1;
int _FINITE_STATE_MACHINE;

void setup()
{
  init_buttons();
  init_leduri();
  lcd.begin(16,2);
  Serial.begin(9600);
  randomSeed(analogRead(A5));
}

void loop()
{
  _FINITE_STATE_MACHINE=0;
  while(execute_state(_FINITE_STATE_MACHINE, nivel, level)==false){}
  
  stare_1:

  _FINITE_STATE_MACHINE=1;
  while(execute_state(_FINITE_STATE_MACHINE, nivel, level)==false){}

  _FINITE_STATE_MACHINE=2;
  while(execute_state(_FINITE_STATE_MACHINE, nivel, level)==false){}

  if(nivel_corect==true)
  {
    if(level<10)
    {
      level++;
      nivel++;
      goto stare_1;
    }
    else
    {
      _FINITE_STATE_MACHINE=4;
      while(execute_state(_FINITE_STATE_MACHINE, nivel, level)==false){}
      nivel=3;
      level=1;
      goto stare_1;
    }
  }
  else
  {
    nivel=3;
    level=1;
    _FINITE_STATE_MACHINE=3;
    while(execute_state(_FINITE_STATE_MACHINE, nivel, level)==false){}
    goto stare_1;
    
  }

}