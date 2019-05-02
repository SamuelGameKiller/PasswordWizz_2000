#include "PasswordWizz.h"

char word[256];
int repeatU,repeatL,repeatN,cascadeU,cascadeL,cascadeN,repeatS,lowercase,uppercase,number,symbol;
int j;
float result,penalty,strength;
unsigned int length;

void strength_tester(){

    clrscr();
    strength_menu();

    check:  printf("---> Check password: \n\n");  //<---------
            printf("-> ");
            memset(word, 0, sizeof(word));

            j=0;
    do{
        word[j]=getch();  //ak da sipky alebo delete tak zobere ako znak
        int ok=0;
        if(word[0]!=13)ok=1;

        if(ok==0){
            ChangeColor('r');
            printf("\n\n--> Invalid input !\n\n");
            ChangeColor(' ');
            goto check;   //<------
        }

        if((word[j]!=8)&&(word[j]!=32)&&(word[j]!=9)&&(word[j]!=127)) {
            if (word[j] != '\r') {                //Char -> * conversion
                printf("*");
            }
        }else j--;
        j++;
    }while(word[j-1]!='\r');
    word[j-1]='\0';

    length=strlen(word);

    if(length>=100){
        ChangeColor('r');
        printf("\n\n--> Limit reached!\n\n");
        ChangeColor(' ');
        goto check;
    }

    printf("\n\n--> Password registered.\n\n");



    repeatU=0;
    repeatL=0;
    repeatN=0;
    repeatS=0;

    lowercase=0;
    uppercase=0;
    number=0;
    symbol=0;

    cascadeN=-1;
    cascadeL=-1;
    cascadeU=-1;



    for(unsigned int i=0;i<length;i++){

            if(islower(word[i]))
            {
                lowercase++;
                }

            else if(isupper(word[i]))
            {
                uppercase++;
                }

            else if(isdigit(word[i]))
            {
                number++;
                }

            else if (ispunct(word[i]))
            {
                symbol++;
                }
            if (word[i] == word[i + 1]) {
                if (isupper(word[i]))
                    repeatU++;

                else if (islower(word[i]))
                    repeatL++;

                else if (isdigit(word[i]))
                    repeatN++;

                else if (ispunct(word[i]))
                    repeatS++;
            }
    }


    for(unsigned int i=0;i<(length-1);i++)
    {

        if (((word[i+1]) == (word[i] + 1))||((word[i+1] == (word[i] - 1))))
        {
            if (isupper(word[i]))
                cascadeU++;

            else if (islower(word[i]))
                cascadeL++;

            else if (isdigit(word[i]))
                cascadeN++;

        }
    }

    penalty=0;
    result=0;
    strength=0;

    /*STRENGTH FORMULA*/
//---------------------------------------------
    if(length>0){
        result+=length*4;
    }

    if(lowercase>0){
        result+=(length-lowercase)*2+2;    //lowecase + 2 because u got lowercase
    }

    if(uppercase>0){
        result+=(length-uppercase)*2+2;  //uppercase + 2 because u got uppercase
    }

    if(number>0){
        result+=number*4+2;              //number + 2 because u got number
    }

    if(symbol>0){
        result+=symbol*6+2;              //symbol + 2 because u got symbol
    }

   // printf("result= %.1f\n",result);


    if((lowercase==0)&&(uppercase==0)&&(symbol==0))  //numbers only
        penalty+=number*5;

    else if((number==0)&&(symbol==0)) //letters only
            penalty+=lowercase+uppercase*4;

    if(repeatU>0)          //repeating upper letters
        penalty+=repeatU*2;

    if(repeatL>0)          //repeating lower letters
        penalty+=repeatL*2;

    if(repeatN>0)          //repeating numbers
        penalty+=repeatN*2;

    if(repeatS>0)          //repeating Symbols
        penalty+=repeatS*3;

    if(((repeatL==lowercase-1)||(repeatU==uppercase-1))&&((repeatL>=3)||(repeatU>=3)))
        penalty+=length*3;  //poistka proti opakovacim znakom U/L

    if(((repeatN==number-1)||(repeatS==symbol-1))&&((repeatN>=3)||(repeatS>=3)))
        penalty+=length*7;  //poistka proti opakovacim znakom S/N

    if(cascadeU>0)          //sequential UpperCase
        penalty+=cascadeU*3;

    if(cascadeL>0)         //sequential LowerCase
        penalty+=cascadeL*3;

    if(cascadeN>0)          //sequential Numbers
        penalty+=cascadeN*3;




  // printf("\npenalty= %.2f\n",penalty);



//----------------------------------------------------



    printf("--> Characteristic that your password contains: \n\n");

    if(number>0)printf("-> Number.\n");
    if(lowercase>0)printf("-> Lowercase.\n");

    if(uppercase>0)printf("-> Uppercase.\n");
    if(symbol>0)printf("-> Symbol.\n");

    if(repeatU>0)printf("-> Repeating upper letters.\n");
    if(repeatL>0)printf("-> Repeating lower letters.\n");
    if(repeatN>0)printf("-> Repeating numbers.\n");
    if(repeatS>0)printf("-> Repeating symbols.\n");

    if(cascadeU>0)printf("-> Sequential uppercase letters.\n");
    if(cascadeL>0)printf("-> Sequential lowercase letters.\n");
    if(cascadeN>0)printf("-> Sequential numbers.\n");


    strength=result-penalty;
    if(strength>100)strength=100;
    else if(strength<0)strength=0;

    ChangeColor(' ');
    printf("\n");
    printf("--> Overall length of your password: %d\n\n",length);
    printf("--> Final strength of your password: ");

   if (strength<20.0)
       ChangeColor('r');

   else if((strength>=20.0)&&(strength<40.0))
       ChangeColor('b');

   else if((strength>=40.0)&&(strength<60.0))
       ChangeColor('p');

   else if((strength>=60.0)&&(strength<80.0))
       ChangeColor('l');

   else if((strength>=80.0)&&(strength<95.0))
       ChangeColor('y');

   else if(strength>=95)
       ChangeColor('g');

    printf("%0.1f\n\n",strength);
    ChangeColor(' ');

    for(int i=0;i<256;i++)
        word[i]=' ';    // final secure delete

    length=0;
}
