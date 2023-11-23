#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int iBeer = 99;
    while(iBeer>0) {
        //On chante
        printf("%u bouteille%c de biere sur un mur,\n"
                "%u bouteille%c de biere,\n"
                "Et on en descend une !,\n",
                iBeer, //Premier paramètre
                (iBeer==1) ? ' ' : 's', //Second paramètre
                iBeer,
               (iBeer==1) ? ' ' : 's');
        iBeer--;
    }
    return 0;
}
