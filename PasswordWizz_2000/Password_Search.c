#include "PasswordWizz.h"

char word[256];
int j,length;



void password_search(){

    clrscr();
    password_search_menu();

//---------------------------- nacitanie hesla + premena na * ----------------------------------------


    check:  printf("---> Check password: \n\n");  //<---------
            printf("-> ");
            memset(word , 0 , sizeof(word));
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

        if((word[j]!=8)&&(word[j]!=32)&&(word[j]!=9)) {
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

    char Question;
    test:
    printf("---> Convert to lowercase(L) or keep original(O)?\n");
    Question=choice();
    if ((Question == 'L')||(Question == 'l'))
    {
        for (unsigned int i = 0; i < strlen(word); i++)
        {
            word[i] = tolower(word[i]);
        }
        printf("\n--> Password converted to lowercase characters.\n");
    }

    else if((Question == 'O')||(Question == 'o'))
    {
        printf("\n--> Password kept original form.\n");
    }

    else
        {
        printf("-----------------------------------------------------\n");
        ChangeColor('r');
        printf("--> Invalid input !\n");
        ChangeColor(' ');
        printf("-----------------------------------------------------\n");
        goto test;
    }

    //----------------------------------------------------------------------------------------------

    if (hladaj("passwordlist_1.txt",word)==1){
        match();
    }
    else if(hladaj("passwordlist_1.txt",word)==0){
        if(hladaj("passwordlist_2.txt",word)==1){
            match();
            return;
        }
        else if(hladaj("passwordlist_3.txt",word)==1){
            match();
            return;
        }
        no_match();
    }


}

void match(){
    printf("\n--> ");
    ChangeColor('r');
    printf("Match found !\n\n");
    ChangeColor(' ');
    printf("--> Not to be used again: ");
    ChangeColor('r');
    printf("%s\n\n",word);
    ChangeColor(' ');

    memset(word, 0, sizeof(word));

}

void no_match(){
    ChangeColor('g');
    printf("\n--> No match found !\n\n");
    ChangeColor(' ');
}

int hladaj(char *file,char *heslo) {


    FILE *list = NULL;
    list = fopen(file, "r");

    if(list==NULL) {
        ChangeColor('r');
        printf("\n--> Invalid file/File loading error !\n");
        printf("--> fopen failed, errno = %d\n\n", errno);
        ChangeColor(' ');
        return 3;
    }

    char buff[256];
    char string[256];

    memset(buff, 0, sizeof(buff));
    memset(string, 0, sizeof(string));

    rewind(list);

    while (fgets(buff, sizeof(buff), list) != NULL) {
        fscanf(list, "%s", string);

        //printf("%s\n",string);  <-----DANGER !!

        if ((strcmp(heslo, string)) == 0) {    //if match found
            return 1;
        }
    }

    return 0;
}
