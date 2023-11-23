#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_ESSAIS_MAX 6
const int nbEssaisMax = 6; // Les 2 déclarations ci-dessus sont juste pour déclarer une constante

int nbAleatoire(int min, int max)
{
    if (max<min)
    {
        //Min est plus grand que max
        //Il faut les inverser
        int tmp;
        tmp = min;
        min = max;
        max = tmp;
    }

    return rand() %(max-min+1) + min;
}

int main()
{
    srand(time(NULL));

    int nbRandom = nbAleatoire(0, 100);
    int nbJoueur = -1;
    int nbEssais = 0;
    int joueurJoue = 1;
    char joueurRejoue;

    while (joueurJoue)
    {
        //On Joue
        while ((nbRandom != nbJoueur) && (nbEssais < NB_ESSAIS_MAX))
    {
        printf("Saisis le nombre a deviner : ");
        scanf("%d", &nbJoueur);
        nbEssais++;

        if (nbJoueur == nbRandom)
        {
            printf("Tu as gagne en %d essais"
                   , nbEssais);
        }
        else
        {
            if (nbJoueur > nbRandom)
            {
                printf("C'est trop grand\n");
            }
            else
            {
                printf("C'est trop petit\n");
            }
        }
    }
        //Fin de partie, on demande si on veut rejouer
        //On replace le curseur de saisie
        fseek(stdin, 0, SEEK_END);
        printf("Voulez-vous rejouer ?\nO = Oui\nN = Non\Votre choix :");
        scanf("%c, &joueurRejoue");
        if ((joueurRejoue == 'O') || (joueurRejoue == 'o'))
        {
            joueurJoue = 1;
            //On reinitialise la partie
            nbEssais = 0;
            int nbRandom = nbAleatoire(0, 100);
            int nbJoueur = -1;


        }
        else
        {
            joueurJoue = 0;
        }
    }


    if ((nbEssais == NB_ESSAIS_MAX) && (nbRandom != nbJoueur))
    {
        printf("Tu as perdu !");
    }
    return 0;
}
