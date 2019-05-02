#include "PasswordWizz.h"

void title()
{

    ChangeColor('r');
    printf("\n\t\t   ----> Welcome To PasswordWizz_2000 <----\n\n");
}

void intro()
{

    ChangeColor('y');
    printf("--------------------------------> Features <--------------------------------\n\n");
    printf("\t--> Generate any kind of password of any length and variety.\n");
    printf("\t--> Test your password strength.\n");
    printf("\t--> Check if your password is hack-proof.\n");
    printf("\t--> Completely safe and free from hidden data transfers and others.\n\n");
    printf("----------------------------------------------------------------------------\n");
}

void select_menu()
{

    ChangeColor('g');
    printf("\n\t\t\t ----> App Selection <----\n\n");

    printf("----------------------------------------------------------------------------\n");
    printf(" [A]--> Password generator.\n");
    printf(" [B]--> Password strength tester.\n");
    printf(" [C]--> Password hack-proof tester.\n");
    printf(" [H]--> Help sheet.\n");
    printf(" [K]--> Credits.\n");
    printf(" [Q]--> Exit.\n");
    printf("----------------------------------------------------------------------------\n");
    ChangeColor(' ');
}

void menu_gen()
{
    ChangeColor('g');
    printf("\t\t\t----> PasswordWizz_Generator <----\n");
    ChangeColor(' ');
    printf("---------------------------------------------------------------------------------\n\n");
    ChangeColor('l');
    printf("Ingredients:\t\t Methods:\n\n");
    ChangeColor(' ');

    printf("I)   a -> z\t\t A) I\t   E) Random\t I) II + III\t M) II+III+IV\n"
           "II)  A -> Z\t\t B) II\t   F) I + II\t J) II + IV\t N) I+III+IV\n"
           "III) 0 -> 9\t\t C) III\t   G) I + III\t K) III + IV\t O) I+II+IV\n"
           "IV)  Symbols\t\t D) IV\t   H) I + IV\t L) I+II+III\t P) I+II+III+IV\n\n");

    printf("---------------------------------------------------------------------------------\n\n");
}


void strength_menu()
{

    ChangeColor('g');
    printf("\t\t\t----> PasswordWizz_Strength_Tester <----\n");
    ChangeColor(' ');
    printf("------------------------------------------------------------------------------------\n\n");
    printf("  --> Tester main use scenario is to determine the strength of your password.\n");
    printf("  --> Strength depends on length and variety of characters used in your password.\n");
    printf("  --> Program si completely safe, no passwords stored or archived.\n\n");
    printf("------------------------------------------------------------------------------------\n\n");

}

void password_search_menu()
{
    ChangeColor('g');
    printf("\t\t\t----> PasswordWizz_HackProof_Tester <----\n");
    ChangeColor(' ');
    printf("------------------------------------------------------------------------------------\n\n");
    printf("  --> Allows to compare your password with 1M+ collection of hacked passwords.\n");
    printf("  --> Collection of exposed passwords containing human-use passwords only.\n");
    printf("  --> Program si completely safe, no passwords stored or archived.\n\n");
    printf("------------------------------------------------------------------------------------\n\n");
}

void help_menu() {
    ChangeColor('g');
    printf("\n\n\t\t\t\t----> PasswordWizz_Help_Sheet <----\n\n");
    ChangeColor(' ');
    printf("----------------------------------------------------------------------------------------------------\n\n");
    ChangeColor('y');
    printf("\t\t\t\t----> PasswordWizz_Generator <----\n\n");
    ChangeColor(' ');
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("  --> Every password must contain at least one ingredient and is created by a chosen method.\n");
    printf("  --> In order to achieve generating password successfully, you have to choose desired ingredient\n");
    printf("      and of course suitable combo(a-p) used to generate password.\n");
    printf("  --> Once decided, choose desired length(<100) of your password and the amount(<100) of them\n");
    printf("      to be generated.\n");
    printf("  --> Changed your mind ? You want different password ? Length or something else?\n");
    printf("  --> Simply answer yes(y) to question to run the generator again.\n");
    printf("  --> If not simply answer no(n) and you will be transferred to app selection menu. \n");
    printf("----------------------------------------------------------------------------------------------------\n\n");
    ChangeColor('y');
    printf("\t\t\t     ----> PasswordWizz_Strength_Tester <----\n\n");
    ChangeColor(' ');
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("  --> Any word, symbol, character, number or sentence you write will be run trough complex\n");
    printf("      algorithm to determine the overall strength of your password.\n");
    printf("  --> The strength value depends heavily on length(<100), variety of characters and their diversity, but\n");
    printf("      also by increasing repetitiveness and simplicity the value decreases.\n");
    printf("  --> Like previously, to measure strength simply answer yes(y), for return, answer no(n).\n");
    printf("----------------------------------------------------------------------------------------------------\n\n");
    ChangeColor('y');
    printf("\t\t\t     ----> PasswordWizz_HackProof_Tester <----\n\n");
    ChangeColor(' ');
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("  --> Any word, symbol, character, number or sentence you write will be run trough enormous list\n");
    printf("      of password that were stolen or exposed anywhere on the internet.\n");
    printf("  --> Program prompts you to decide if you want your password to be checked using lowercase\n");
    printf("      conversion or keep the original form to be checked.\n");
    printf("  --> Program outputs only if the match is positive or negative. \n");
    printf("  --> Important thing is to remember that list contains only 'human-use' passwords only, not any\n");
    printf("      type that is similar to generated passwords.\n");
    printf("  --> Like previously, to test again simply answer yes(y), for return, answer no(n).\n");

}

void credits(){
    ChangeColor('g');
    printf("\t\t\t\t   ----> PasswordWizz_Credits <----\n\n");
    ChangeColor(' ');
    printf("----------------------------------------------------------------------------------------------------\n");
    sleep(2);
    printf("\n\t\t\t\t\t   -> Created by <-\n\n");
    sleep(2);
    printf("\t\t\t\t\t     Samuel Scipa\n\n");
    sleep(2);
    printf("\t\t\t\t\t    -> VUT FEKT <-\n\n");
    sleep(2);
    printf("\t\t\t\t\t     MET-3 - 2019\n\n");

}



