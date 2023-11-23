#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void affichetab(int ptab[10])
{
    int i;
    for(i=0; i<10; i++)
    {
        printf("[%d] : %d\n",i, ptab[i]);
    }
}

int main()
{

    srand(time(NULL));

    //Déclaration des variables
    int tableau[10];
    int i;
    int somme=0;

    //initialisation du tableau
    for(i=0; i<10; i++)
    {
        tableau[i] = rand()%21;

    }

    //Affichage du tableau
    affichetab(tableau);

    //Calcule de la moyenne
    for(i=0; i<10; i++)
    {
        somme += tableau[i];
    }
    printf("Moyenne des elements du tableau : %f\n",somme/10.);

    int ilYAPermutation = 1;
    int cptnbper = 0;
    while (ilYAPermutation)
    {
        ilYAPermutation = 0;
        for (i=0; i<10-1; i++)
        {
            if (tableau[i]>tableau[i+1])
            {
                //Le i+1 ième est plus grand que le ième, on les permute
                int tmp = tableau[i];
                tableau[i] = tableau[i+1];
                tableau[i+1] = tmp;
                ilYAPermutation = 1;
                cptnbper++;
            }
        }
    }
    affichetab(tableau);

    //Médian
    printf("La mediane est %d", tableau[(10/2)-1]);



    return 0;
}
