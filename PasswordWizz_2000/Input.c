#include "PasswordWizz.h"

t_akce choice()
{
    int ch1 = 0;
    fflush(stdin);
    ch1 = getch();
    if (ch1 != 0xE0) {
        switch (ch1) {
            case 'a': return A;
            case 'b': return B;
            case 'c': return C;
            case 'q': return Q;
            case 'h': return H;
            case 'k': return K;
            default:
                return ch1;
        }
    }
    return ch1;
}
