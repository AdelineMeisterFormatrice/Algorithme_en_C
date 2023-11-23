#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void afficheTableau(int tab[8])
{
    int i;
    for (i=0; i<8; i++)
    {
        printf("[%d] : %d\n", i, tab[i]);
    }
}

int posLePlusPetit(int tab[8])
{
    int i;
    int lePlusPetit = tab[0];
    int posPlusPetit = 0;

    for (i=1; i<8; i++)
    {
        if (lePlusPetit>tab[i])
        {
            lePlusPetit = tab[i];
            posPlusPetit = i;
        }
    }
    return posPlusPetit;
}

int main()
{
    srand(time(NULL));
    //Déclaration des variables
    int tab[8];
    int i;
    //Initialise le tableau
    for (i=0; i<8; i++)
    {
        tab[i] = rand()%20+1;
    }

    //Affichage du tableau
    afficheTableau(tab);

    //Tri par sélection
    /*
    int tabTrie[8];
    for (i=0; i<8; i++)
    {
        //On cherche le plus petit pour le mettre dans le tableau trie
        int positionDuPlusPetitDuTableauNonTrie = posLePlusPetit(tab);
        tabTrie[i] = tab[positionDuPlusPetitDuTableauNonTrie];

        //On l'efface du tableau non trie en le remplacant par un grand nombre
        tab[positionDuPlusPetitDuTableauNonTrie] = 100;
    }

    //Affichage du tableau trié
    afficheTableau(tabTrie);
    */

    //Tri par permutation
    /*
    int ilYAPermutation = 1;
    int cptnbper = 0;
    while (ilYAPermutation)
    {
        ilYAPermutation = 0;
        for (i=0; i<8-1; i++)
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
    printf("%d permutations\n", cptnbper);
    afficheTableau(tab);
    */

    //Tri à bulles
    int tailleATraiter = 8-1;
    int k, j;

    //Boucle pour le nombre de permutations
    for (k=0; k<(8-1); k++)
    {
        //Boucle dégressive des permutations
        for (j=0; j<tailleATraiter; j++)
        {
            if (tab[j] > tab[j+1])
            {
                //Il faut permuter
                int tmp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tmp;
            }
        }
        tailleATraiter--;
    }
    afficheTableau(tab);


    return 0;
}
