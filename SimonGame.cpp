#include "SimonGame.h"
#include "LED_and_buttons.h"
#include "LCD_display.h"
#include <Arduino.h>

bool nivel_corect;


//"inima programului"
//implementeaza un sistem de tip finite_state_machine
bool execute_state(int FSM, int nivel, int level)
{
  switch(FSM)
  {
    /*
    starea initiala
    se afiseaza un mesaj de bun venit si se asteapta inceperea jocului
    */
    case 0:
    aprinde_butoane_init();
    welcome();
    while(digitalRead(buton_rosu)==1) {}
    return true;

    /*
    starea 1
    se genereaza secventa de leduri si se afiseaza
    */
    case 1:
    _level(level,5);
    generateSequence(secventa_generata, nivel);
    lightOnLeds( secventa_generata, nivel);
    return true;

    /*
    starea 2
    se primeste si se evalueaza inputul 
    */
    case 2:
    readSequence(secventa_introdusa, nivel);
    if(checkInput(secventa_generata, secventa_introdusa, nivel)==true) nivel_corect=true;
    else nivel_corect=false;
    return true;

    /*
    starea 3
    se ruleaza atunci cand s-a facut o greseala
    pogramul continua cu nivelul 1 al starii 1
    */
    case 3:
    youLost();
    while(digitalRead(buton_rosu)==1) {}
    return true;

    /*
    starea 4(finala)
    se afiseaza daca jocul se castiga
    */
    case 4:
    youWon();
    while(digitalRead(buton_rosu)==HIGH){}
    return true;
  }
}