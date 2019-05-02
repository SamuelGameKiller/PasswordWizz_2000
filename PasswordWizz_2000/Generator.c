#include "PasswordWizz.h"

    char passwordType[2];
    char password[512]={0};
    char test[17]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};
    int passwordLength;
    int m,passwordTimes;


void generator(){
    srand(time(NULL));  //mozno nemusi byt
    clrscr();
    menu_gen();
    passwordLength=0;
    passwordTimes=0;
    m=0;
    int ok;
    for(int i=0;i<2;i++) passwordType[i]=0;

    try1:   printf("---> Enter any type given above(a-p): \n\n"); //<----1
            fflush(stdin);
            printf("-> ");
            scanf("%1s",passwordType);  // nacita od uzivatela zvolenu moznost
            passwordType[0] = tolower(passwordType[0]);

    ok=0;

    for (int i=0;i<16;i++) {
        if (passwordType[0]== test[i]){    //test passwordType ci neni nepodporovany znak
            ok=1;
        }
    }

    if(ok==0) {
        ChangeColor('r');
        printf("\n--> Invalid input !\n\n");
        ChangeColor(' ');
        goto try1;   //<------1

    }

    try2:   printf("\n---> Enter the length of password(1-99): \n\n"); //<------2
            passwordLength=0;
            fflush(stdin);
            printf("-> ");
            scanf("%d", &passwordLength);     // nacita od uzivatela dlzku
    ok=0;

    if((passwordLength>0)&&(passwordLength<100))ok=1;    //test passwordLength ci cislo a <100

    if(ok==0){
        ChangeColor('r');
        printf("\n--> Invalid input !\n\n");
        ChangeColor(' ');
    goto try2;   //<------2
    }

    try3:   printf("\n---> Number of passwords to be generated(1-99): \n\n"); //<------3
            passwordTimes=0;
            fflush(stdin);
            printf("-> ");
            scanf("%d", &passwordTimes);
    ok=0;

    if((passwordTimes>0)&&(passwordTimes<100))ok=1;      //test passwordTimes ci cislo a <100

    if(ok==0){
        ChangeColor('r');
        printf("\n--> Invalid input !\n\n");
        ChangeColor(' ');
        goto try3;   //<------3
    }

    printf("\n");
    m = passwordTimes;

        while (m > 0) {

            printPassword();

            m--;

        }
}

int generateRandomNumbers(){

    int random;

    int r;

    // based on passwordType the user needs, generating random numbers

    switch (passwordType[0]){

        case ('a'):

            random = (rand() % (122 + 1 - 97)) + 97;

            break;

        case 'b':

            random = (rand() % (90 + 1 - 65)) + 65;

            break;

        case 'c':

            random = (rand() % (57 + 1 - 48)) + 48;

            break;

        case 'd':

            while (1){

                r = (rand() % (256 + 1 - 0)) + 0;

                if (((r<=47) && (r>=33)) || ((r<=64) && (r>=58)) || ((r<=96) && (r>=91)) || ((r<=126) && (r>=123))){

                    random = r;

                    break;

                }

            }

            break;

        case 'e':

            random = (rand() % (126 + 1 - 33)) + 33;

            break;

        case 'f':

            while (1){

                r = (rand() % (256 + 1 - 0)) + 0;

                if (((r<=90) && (r>=65)) || ((r<=122) && (r>=97))){

                    random = r;

                    break;

                }

            }

            break;

        case 'g':

            while (1){

                r = (rand() % (256 + 1 - 0)) + 0;

                if (((r<=57) && (r>=48)) || ((r<=122) && (r>=97))){

                    random = r;

                    break;

                }

            }

            break;

        case 'h':

            while (1){

                r = (rand() % (256 + 1 - 0)) + 0;

                if (((r<=122) && (r>=97)) ||((r<=47) && (r>=33)) || ((r<=64) && (r>=58)) || ((r<=96) && (r>=91)) || ((r<=126) && (r>=123))){

                    random = r;

                    break;

                }

            }

            break;

        case 'i':

            while (1){

                r = (rand() % (256 + 1 - 0)) + 0;

                if (((r<=90) && (r>=65)) || ((r<=57) && (r>=48))){

                    random = r;

                    break;

                }

            }

            break;

        case 'j':

            while (1){

                r = (rand() % (256 + 1 - 0)) + 0;

                if (((r<=90) && (r>=65)) ||((r<=47) && (r>=33)) || ((r<=64) && (r>=58)) || ((r<=96) && (r>=91)) || ((r<=126) && (r>=123))){

                    random = r;

                    break;

                }

            }

            break;

        case 'k':

            while (1){

                r = (rand() % (256 + 1 - 0)) + 0;

                if (((r<=57) && (r>=48)) || ((r<=47) && (r>=33)) || ((r<=64) && (r>=58)) || ((r<=96) && (r>=91)) || ((r<=126) && (r>=123))){

                    random = r;

                    break;

                }

            }

            break;

        case 'l':

            while (1){

                r = (rand() % (256 + 1 - 0)) + 0;

                if(((r<=122) && (r>=97)) || ((r<=90) && (r>=65)) || ((r<=57) && (r>=48))){

                    random = r;

                    break;

                }

            }

            break;

        case 'm':

            while (1){

                r = (rand() % (256 + 1 - 0)) + 0;

                if(((r<=90) && (r>=65)) || ((r<=57) && (r>=48)) || ((r<=47) && (r>=33)) || ((r<=64) && (r>=58)) || ((r<=96) && (r>=91)) || ((r<=126) && (r>=123))){

                    random = r;

                    break;

                }

            }

            break;

        case 'n':

            while (1){

                r = (rand() % (256 + 1 - 0)) + 0;

                if(((r<=122) && (r>=97)) || ((r<=57) && (r>=48)) || ((r<=47) && (r>=33)) || ((r<=64) && (r>=58)) || ((r<=96) && (r>=91)) || ((r<=126) && (r>=123))){

                    random = r;

                    break;

                }

            }

            break;

        case 'o':

            while (1){

                r = (rand() % (256 + 1 - 0)) + 0;

                if(((r<=122) && (r>=97)) || ((r<=90) && (r>=65)) || ((r<=47) && (r>=33)) || ((r<=64) && (r>=58)) || ((r<=96) && (r>=91)) || ((r<=126) && (r>=123))){

                    random = r;

                    break;

                }

            }

            break;

        case 'p':

            while (1){

                r = (rand() % (256 + 1 - 0)) + 0;

                if(((r<=122) && (r>=97)) || ((r<=90) && (r>=65)) || ((r<=57) && (r>=48)) || ((r<=47) && (r>=33)) || ((r<=64) && (r>=58)) || ((r<=96) && (r>=91)) || ((r<=126) && (r>=123))){

                    random = r;

                    break;

                }

            }

            break;



        default: {
            ChangeColor('r');
            printf("\n--> Invalid Input ! \n");
            ChangeColor(' ');
            random=0;
            break;
        }
    }

    return random;

}

// Here is the main function which prints the password to the user

void printPassword(){
    int randomNumber=0;

    int k;

    int length=0;
    //converting password length string to ineger to loop

    length = passwordLength;
    //looping and generating random numbers and storing in password array

    for (int i=0;i<512;i++) {
        password[i]=0;       //bug bez tohoto vypisuje viac znakov v hesle ako chceme
    }


    for (k = 0; k < length; k++) {

        randomNumber = generateRandomNumbers();

        password[k] = randomNumber;

    }

    for (int j = 0; j < length+21; j++) {

        printf("=");

    }

    printf("\n");

    //Here Printing the password to the user
    ChangeColor('y');
    printf("-> Your password is: ");
    ChangeColor('g');
    printf("%s", password);
    ChangeColor(' ');
    printf("\n");

    for (int a = 0; a < length+21; a++) {

        printf("=");

    }

    printf("\n");
}