#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

#include <LiquidCrystal.h>

#define _COUNT_DOWN_DELAY 900



extern LiquidCrystal lcd;

void welcome();
void _level(int nivel, int);
void count_down(int timer, LiquidCrystal_I2C &lcd);
void showButtons(int vector, int nivel);
void youLost();
void youWon();



#endif