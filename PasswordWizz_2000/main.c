
#include "PasswordWizz.h"

char passwordType[2];
int passwordLength;
int key;

int main() {

    srand(time(NULL));
    clrscr();

    if (key==0){
        title();
        intro();
    }

    key=0;
    select_menu();
    key=choice();   //nastavi si key na input klavesy od usera

    switch (key){
        case A : {   //Generator
            char Question;

            generator();
            start: //<------A
            printf("---------------------------------------------------------------------------------\n\n");
            ChangeColor('l');
            printf("---> Generate password again(y/n)?\n");
            ChangeColor(' ');
            Question=choice();

            if ((Question == 'y')||(Question == 'Y')){

                generator();
                goto start; //<---------A

            } else if ((Question == 'n')||(Question == 'N')){
                printf("\n--> Exiting PasswordWizz_Generator...\n");
                sleep(2);
                main();

            } else{
                ChangeColor('r');
                printf("\n--> Invalid input !\n\n");
                ChangeColor(' ');
                goto start; //<-------A

            }
            break;
        }

        case B : {   //Strength_Tester
            char Question;

            strength_tester();
            tester:  //<--------B
            printf("----------------------------------------------------------------------\n\n");
            ChangeColor('l');
            printf("---> Measure password again(y/n)?\n");
            ChangeColor(' ');
            Question=choice();

            if ((Question == 'y')||(Question == 'Y')){

                strength_tester();
                goto tester;  //<-----------B

            } else if ((Question == 'n')||(Question == 'N')){
                printf("\n--> Exiting PasswordWizz_Strength_Tester...\n");
                sleep(2);
                main();

            } else{
                ChangeColor('r');
                printf("\n--> Invalid input !\n\n");
                ChangeColor(' ');
                goto tester; //<-------B

            }

            break;

        }

        case C : {        //password Search
            char Question;

            password_search();
            call:  //<--------C
            printf("----------------------------------------------------------------------\n\n");
            ChangeColor('l');
            printf("---> Check password again(y/n)?\n");
            ChangeColor(' ');
            Question=choice();

            if ((Question == 'y')||(Question == 'Y')){

                password_search();
                goto call;  //<-----------C

            } else if ((Question == 'n')||(Question == 'N')){
                printf("\n--> Exiting PasswordWizz_HackProof_Tester...\n");
                sleep(2);
                main();

            } else{
                ChangeColor('r');
                printf("\n--> Invalid input !\n\n");
                ChangeColor(' ');
                goto call; //<---------C

            }

            break;
        }

        case H : {      //help sheet
            char Question;
            clrscr();
            help_menu();
            help:   //<-------H
            printf("----------------------------------------------------------------------------------------------------\n\n");
            ChangeColor('l');
            printf("---> Back to menu(y/n)?\n");
            ChangeColor(' ');
            Question=choice();

            if ((Question == 'y')||(Question == 'Y')){
                printf("\n--> Exiting PasswordWizz_Help_Sheet...\n");
                sleep(2);
                main();

            } else if ((Question == 'n')||(Question == 'N')){
                printf("\n--> Okey.......\n");
                sleep(4);
                printf("--> What about now ?\n\n");
                sleep(2);
                goto help; //<----------H

            } else{
                ChangeColor('r');
                printf("\n--> Invalid input !\n\n");
                ChangeColor(' ');
                goto help; //<---------H

            }
            break;
        }

        case K : {  //Credits
            char Question;
            clrscr();
            setlocale(LC_ALL,"");  //nejde
            credits();
            credit:   //<-------K
            printf("----------------------------------------------------------------------------------------------------\n\n");
            ChangeColor('l');
            printf("---> Back to menu(y/n)?\n");
            ChangeColor(' ');
            Question = choice();

            if ((Question == 'y') || (Question == 'Y')) {
                printf("\n--> Exiting PasswordWizz_Credits...\n");
                sleep(2);
                main();

            } else if ((Question == 'n') || (Question == 'N')) {
                printf("\n--> Okey.......\n");
                sleep(4);
                printf("--> What about now ?\n\n");
                sleep(2);
                goto credit; //<----------K

            } else {
                ChangeColor('r');
                printf("\n--> Invalid input !\n\n");
                ChangeColor(' ');
                goto credit; //<---------K

            }
            break;
        }

        case Q : {  //END
            ChangeColor('l');
            printf("\n--> Thanks for using PasswordWizz_2000 !!\n");
            ChangeColor(' ');
            sleep(2);
            break;
        }

        default: main();
    }


    return 0;

}

