#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PIERRE 1
#define PAPIER 2
#define CISEAUX 3

int main()
{
    srand(time(NULL));

    int pvPc = 3;
    int pvJ = 3;
    int choixJ, choixPc;

    while ((pvPc > 0) && (pvJ > 0))
    {
        //Le Pc choisit
        choixPc = rand()%3+1;

        //Le joueur choisit
        printf("1: Pierre\n2: Papier\n3: Ciseaux\nVotre choix:");
        scanf("%d", &choixJ);

        //On compare les choix
        switch (choixJ)
        {
        case PIERRE:
            switch (choixPc)
            {
            case PIERRE:
                pvPc--;
                pvJ--;
                break;
            case PAPIER:
                pvJ--;
                break;
            case CISEAUX:
                pvPc--;
                break;
            }
            break;
        case PAPIER:
            switch (choixPc)
            {
            case PIERRE:
                pvPc--;
                break;
            case PAPIER:
                pvPc--;
                pvJ--;
                break;
            case CISEAUX:
                pvJ--;
                break;
            }
            break;
        case CISEAUX:
            switch (choixPc)
            {
            case PIERRE:
                pvJ--;
                break;
            case PAPIER:
                pvPc--;
                break;
            case CISEAUX:
                pvPc--;
                pvJ--;
                break;
            }
            break;
        }
    }

    printf("La partie est terminée\nPV Pc: %d\nPv Joueur %d",pvPc, pvJ);

    return 0;
}
