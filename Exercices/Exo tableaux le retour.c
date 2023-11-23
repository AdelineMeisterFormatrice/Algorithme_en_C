#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void afficheTab(int ptab[10])
{
    int i;
    for (i=0; i<10; i++)
    {
        printf("[%d] : %d\n", i, ptab[i]);
    }
}

int main()
{
    srand(time(NULL));

    int tab[10];
    int i;
    int somme=0;

    //Remplissage du tableau avec des entiers entre 0 et 20
    for (i=0; i<10; i++)
    {
        tab[i] = rand()%21;
    }

    //Affichage du tableau
    afficheTab(tab);

    //Calcul de la moyenne
    for (i=0; i<10; i++)
    {
        somme += tab[i];
    }
    printf("Moyenne des elements du tableau: %f\n", somme/10.);

    //Tri du tableau
    int ilYAPermutation = 1;
    int cptnbper = 0;
    while (ilYAPermutation)
    {
        ilYAPermutation = 0;
        for (i=0; i<10-1; i++)
        {
            if (tab[i]>tab[i+1])
            {
                //Le i+1 ième est plus grand que le ième, on les permute
                int tmp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = tmp;
                ilYAPermutation = 1;
                cptnbper++;
            }
        }
    }

    //Affichage du tableau trié
    afficheTab(tab);

    //Médian
    printf("La mediane est %d", tab[(10/2)-1]);


    return 0;
}
