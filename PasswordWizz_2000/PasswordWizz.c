
#include "PasswordWizz.h"

void ChangeColor(char color)
{
    #define BLUE 1
    #define GREEN 2
    #define RED 4

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (color)
    {
        case 'g': SetConsoleTextAttribute(hConsole,GREEN); break;

        case 'r': SetConsoleTextAttribute(hConsole,RED); break;

        case 'b': SetConsoleTextAttribute(hConsole,BLUE); break;

        case 'y': SetConsoleTextAttribute(hConsole,RED | GREEN); break;

        case 'p': SetConsoleTextAttribute(hConsole,RED | BLUE); break;

        case 'l': SetConsoleTextAttribute(hConsole,GREEN | BLUE); break;
        //backround behind text
        case 'W': SetConsoleTextAttribute(hConsole,BACKGROUND_RED| BACKGROUND_GREEN| BACKGROUND_BLUE| BACKGROUND_INTENSITY); break;

        default: SetConsoleTextAttribute(hConsole,RED | GREEN | BLUE); break;
    }
}


void clrscr()
{
    system("@cls||clear");
}
