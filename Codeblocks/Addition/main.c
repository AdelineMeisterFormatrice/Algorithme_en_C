#include <stdio.h>
#include <stdlib.h>

float Addition(int nbUn,float nbDeux)
{
    //float addition = nbUn +nbDeux;
    return nbUn + nbDeux;
}

int main()
{
    //Fonction qui additionne 2 paramétres ,entiers,reéls,un reél + un entier

    printf("Le resultat est %.2f",Addition (4 ,4.5));

    return 0;
}
