#ifndef PASSWORDWIZZ_PASSWORDWIZZ_H
#define PASSWORDWIZZ_PASSWORDWIZZ_H

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <windows.h>
#include <locale.h>

typedef enum  {A,B,C,Q,H,K} t_akce;
t_akce choice();

void clrscr();        //colors etc.
void ChangeColor(char color);

void title();
void intro();        //Printables
void menu_gen();
void select_menu();
void password_search_menu();
void help_menu();
void credits();

void generator();
int generateRandomNumbers();   //gen
void printPassword();

void strength_menu();     //tester
void strength_tester();


void password_search();
int hladaj(char *file,char *heslo);
void match();                       //searcher
void no_match();


#endif //PASSWORDWIZZ_PASSWORDWIZZ_H
