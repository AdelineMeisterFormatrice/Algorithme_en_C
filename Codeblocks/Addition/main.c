#include <stdio.h>
#include <stdlib.h>

float Addition(int nbUn,float nbDeux)
{
    //float addition = nbUn +nbDeux;
    return nbUn + nbDeux;
}

int main()
{
    //Fonction qui additionne 2 param�tres ,entiers,re�ls,un re�l + un entier

    printf("Le resultat est %.2f",Addition (4 ,4.5));

    return 0;
}
