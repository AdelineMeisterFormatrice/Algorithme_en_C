#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct resultatRouletteRusse
{
    int gainJetons;
    int enVie;
};

int roulette(int jetons)
{
    int gainJetons = 0;
    unsigned int choixCouleur;
    unsigned int choixMise;
    unsigned int tirageRoulette;

    printf("Vous jouez a la roulette !\n");

    //Choix de la couleur (rouge ou noir)
    printf("Choix de la couleur : 0 = Rouge, 1 = Noir\nVotre choix:");
    scanf("%d", &choixCouleur);

    //Choix de la mise (entre 1 et 25)
    if (jetons>=25)
    {
        printf("Combien de jetons voulez-vous miser entre 1 et 25 ?");
    }
    else
    {
        printf("Combien de jetons voulez-vous miser entre 1 et %d ?", jetons);
    }
    printf("\nVotre choix:");
    scanf("%d", &choixMise);

    //Vérifier la mise
    if ((choixMise>25) || (choixMise>jetons))
    {
        //Erreur: mise trop haute
        choixMise = jetons;
        if (choixMise>25)
        {
            choixMise = 25;
        }
    }

    //Rappel des choix
    printf("Vous misez %d jetons sur la couleur ", choixMise);
    if (choixCouleur != 0)
    {
        //Autre chose que 0 = Impair
        printf("Noir\n");
    }
    else
    {
        //0 = Pair
        printf("Rouge\n");
    }

    //Déterminer le résultat du jeu
    tirageRoulette = rand()%37;

    if (tirageRoulette == 0)
    {
        //Perdu
        gainJetons -= choixMise;

    }
    else
    {
        //Tester le resultat et le choix du joueur
        if ((choixCouleur != 0) && (tirageRoulette%2 != 0))
        {
            //Le joueur choisit impair et le tirage est impair
            gainJetons += choixMise;
        }
        else if ((choixCouleur == 0) && (tirageRoulette%2 == 0))
        {
            //Le joueur choisit pair et le tirage est pair
            gainJetons += choixMise;
        }
        else
        {
            //Le joueur perd
            gainJetons -= choixMise;
        }
    }

    if (gainJetons>0)
    {
        printf("Gagne !\n");
    }
    else
    {
        printf("Perdu !\n");
    }

    return gainJetons;
}

struct resultatRouletteRusse rouletteRusse()
{
    struct resultatRouletteRusse resultat;
    unsigned int barillet[6] = {0,0,0,0,0,0};
    unsigned int choixRejouer;
    unsigned int i;

    //Initialise la variable structure resultat
    resultat.enVie = 1;
    resultat.gainJetons = 0;

    printf("Vous jouez a la roulette russe !\n");

    /*for (int i = 0; i<6; i++)
    {
        barillet[i] = 0;
    }*/

    //On place la balle aléatoirement
    barillet[rand()%6] = 1;

    do
    {
        //On appuie sur la gachette
        if (barillet[0] == 1)
        {
            //La balle est tirée, le joueur meurt
            resultat.enVie = 0;
        }
        else
        {
            //Le barillet tourne
            for (i=0; i<5; i++)
            {
                barillet[i] = barillet[i+1];
            }

            //Le joueur gagne 20 jetons
            resultat.gainJetons += 20;

            //On demande si la personne souhaite rejouer
            printf("Souhaitez-vous rejouer ?\nVotre choix:");
            scanf("%d", &choixRejouer);
        }
    }
    while(choixRejouer && resultat.enVie);

    return resultat;
}

int main()
{
    unsigned int jetons = 10;
    unsigned int enVie = 1;
    struct resultatRouletteRusse resRR;

    //Initialiser le hasard
    srand(time(NULL));

    //Le jeu
    while ((enVie != 0) && (jetons<100))
    {
        if (jetons > 0)
        {
            //Roulette
            jetons += roulette(jetons);
        }
        else
        {
            //Roulette russe
            resRR = rouletteRusse();
            jetons += resRR.gainJetons;
            enVie = resRR.enVie;

            //Si il n'a pas gagné de jetons à la roulette russe, il est mort
            /*if (jetons == 0)
            {
                enVie = 0;
            }*/
        }
    }

    //Le jeu est fini
    if (enVie)
    {
        //Vivant
        if (jetons>=110)
        {
            //Vivant et montre
        }
        else
        {
            //Vivant
        }
    }
    else
    {
        //Mort
    }

    return 0;
}
