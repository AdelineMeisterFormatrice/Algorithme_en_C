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
    int choixJ,  choixPc;

    while ((pvPc > 0) && (pvJ > 0))
    {
        //Le Pc choisit
        choixPc = rand()%3+1;

        //Le joueur choisit
        printf("1: Pierre\n2: Papier\n3: Ciseaux\nVotre choix:")
        scanf("%d , &choixJ);")

        //On compare les choix
        switch (choixJ)
        {
        case PIERRE:
            switch(choixPc)
            {
        case PIERRE:
            pvPc--;
            break;
        case PAPIER:
            break;
        case CISEAUX:
            break;
            }

        }

    }






    return 0;
}
