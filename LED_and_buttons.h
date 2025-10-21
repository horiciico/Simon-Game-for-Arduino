#ifndef LED_AND_BUTTONS_H
#define LED_AND_BUTTONS_H

//pinii la care se conecteaza butoanele
#define buton_rosu A0
#define buton_albastru A1
#define buton_verde A2
#define buton_portocaliu A3
#define buton_galben A4

//pinii la care se conecteaza led-urile
#define LED_ROSU 2
#define LED_ALBASTRU 3
#define LED_VERDE 4
#define LED_PORTOCALIU 5
#define LED_GALBEN 6

#define _NUMAR_MAXIM_NIVELURI 16
#define _TIMP_LEDURI_APRINSE 950
#define _DELAY_BUTON 150
#define _init_delay 300

//prototipul functilor
void init_buttons();
void init_leduri();
void generateSequence(int *vector, int nivel);
void readSequence(int *vector, int nivel);
void lightOnLeds(int *vector, int nivel);
bool checkInput(int vector1[], int vector2[], int nivel);
void aprinde_butoane_init();


//variabile necesare
extern int secventa_generata[_NUMAR_MAXIM_NIVELURI];
extern int secventa_introdusa[_NUMAR_MAXIM_NIVELURI];


#endif