#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int jetD = 0;
int lanceD(int facesD)
{
    return rand()%facesD+1;
}

void lancepD(int facesD)
{
    jetD=  rand()%facesD+1;
}

int main()
{
    srand(time(NULL));
    //Jet de dé à 6 faces

    int facesD;
    int rejouer = 1;

    while(rejouer)
    {
        //initialiser
        jetD = 0;

        //On joue

        printf("Combien de face possede le de ?");
        scanf("%d", &facesD );

        //Tant qu'on n'est pas au score max
        while (jetD < facesD)
        {
            lancepD(facesD);
            printf("jet de de : %d\n",jetD);
        }

        //Veut on rejouer ?
        printf("Souhaiter vous rejouer ?\n1=oui\n0=Non\nChoix:");
        scanf("%d", &rejouer);
    }

    return 0;
}
