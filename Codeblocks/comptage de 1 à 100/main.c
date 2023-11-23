#include <stdio.h>
#include <stdlib.h>

int main()
{
    //créer une boucle while qui compte de 1 à 100
    unsigned int compte = 1;
    while(compte<=100) {
        //On compte
        printf("%u\n",compte);
        compte++;
    }
    return 0;
}
