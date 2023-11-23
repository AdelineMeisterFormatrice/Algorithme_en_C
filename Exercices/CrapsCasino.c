#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lanceD()
{
    int D1, D2;
    D1 = rand()%6+1;
    D2 = rand()%6+1;
    printf("Vous obtenez %d + %d = %d\n", D1, D2, (D1 + D2));
    return (D1 + D2);
}

int main()
{
    srand(time(NULL));

    //Déclarations de variables
    int sommeD;
    int pointD;
    int partieGagnee = 0;

    //Début de partie, premier jet de dé
    sommeD = lanceD();

    switch(sommeD)
    {
    case 2:
    case 3:
    case 12:
        //Cas perdant
        printf("Perdu");
        break;
    case 7:
    case 11:
        //Cas gagnant
        printf("Gagne");
        break;
    default:
        //Mettre en mémoire le résultat du 1er jet
        pointD = sommeD;

        while (sommeD != 7)
        {
            //Tant que le jet est différent de 7, on rejoue
            sommeD = lanceD();

            if (sommeD == pointD)
            {
                //On valide le point
                partieGagnee = 1;
            }
        }

        if (partieGagnee)
        {
            printf("Gagne");
        }
        else
        {
            printf("Perdu");
        }
    } // fin switch

    return 0;
}
