#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int jetD;

int lanceD(int facesD)
{
    return rand()%facesD+1;
}

void planceD(int facesD)
{
    jetD = rand()%facesD+1;
}

int main()
{
    srand(time(NULL));

    //Jet de dé à 6 faces
    int facesD;
    int rejouer = 1;

    while (rejouer)
    {
        //On joue
        printf("Combien de faces possede le de ? ");
        scanf("%d", &facesD);

        //Tant qu'on n'est pas au score max

        //Réinitialiser
        /*jetD = 0;
        while (jetD < facesD)
        {
            planceD(facesD);
            printf("Jet de de : %d\n", jetD);
        }*/


        do
        {
            planceD(facesD);
            printf("Jet de de : %d\n", jetD);
        }
        while (jetD < facesD);

        //Veut-on rejouer ?
        printf("Souhaitez-vous rejouer ?\n0=Non\n1=Oui\nChoix: ");
        scanf("%d", &rejouer);
    }




    return 0;
}
