#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 0

struct ResultatPions
{
    unsigned int bienPlace;
    unsigned int malPlace;
};

struct Jeu
{
    int combinaison[4];
    int combinaisonJoueur[4];
    struct ResultatPions comparaison;
    unsigned int essais;
    unsigned int gagne;
    unsigned int perdu;
};

struct ResultatPions compareCombinaisons(struct Jeu mastermind)
{
    //On déclare des tableaux pour savoir si il faut tester les pions ou non
    unsigned int aTester[4] = {1, 1, 1, 1};
    unsigned int aTesterJoueur[4] = {1, 1, 1, 1};
    int i, j;

    mastermind.comparaison.bienPlace = 0;
    mastermind.comparaison.malPlace = 0;

    //On teste d'abord les bien placés
    for (i=0; i<4; i++)
    {
        if (mastermind.combinaison[i] == mastermind.combinaisonJoueur[i])
        {
            //Bien placé
            aTester[i] = 0;
            aTesterJoueur[i] = 0;
            mastermind.comparaison.bienPlace++;
        }
    }

    //Puis les mal placés
    for (i=0; i<4; i++)
    {
        if (aTesterJoueur[i])
        {
            //Il faut tester ce pion joueur
            for (j=0; j<4; j++)
            {
                if (aTester[j])
                {
                    if (mastermind.combinaisonJoueur[i] == mastermind.combinaison[j])
                    {
                        mastermind.comparaison.malPlace++;
                        //On ne teste plus ce pion de la combinaison secrète
                        aTester[j] = 0;
                        break;
                    }
                }
            }
        }
    }

    return mastermind.comparaison;
};

int main()
{
    unsigned int rejouer;
    int i;

    struct Jeu mastermind;
    mastermind.gagne = 0;
    mastermind.perdu = 0;

    do
    {
        //Initialisation des essais
        mastermind.essais = 10;
        //combinaison
        if (DEBUG)
        {
            mastermind.combinaison[0] = 1;
            mastermind.combinaison[1] = 1;
            mastermind.combinaison[2] = 2;
            mastermind.combinaison[3] = 3;
        }
        else
        {
            for (i=0; i<4; i++)
            {
                mastermind.combinaison[i] = rand()%10;
            }
        }


        while (mastermind.essais>0)
        {
            printf("Il vous reste %d essais\n", mastermind.essais);

            //Saisie de la combinaison du joueur
            for (i=0; i<4; i++)
            {
                printf("Saisir le chiffre %d :", i+1);
                scanf("%d", &mastermind.combinaisonJoueur[i]);
            }

            //Comparaison des combinaisons
            mastermind.comparaison = compareCombinaisons(mastermind);

            //Affichage des bien et mal placés
            printf("Votre combinaison %d %d %d %d\n", mastermind.combinaisonJoueur[0], mastermind.combinaisonJoueur[1], mastermind.combinaisonJoueur[2], mastermind.combinaisonJoueur[3]);
            if (DEBUG)
            {
                printf("La combinaison a trouver %d %d %d %d\n", mastermind.combinaison[0], mastermind.combinaison[1], mastermind.combinaison[2], mastermind.combinaison[3]);
            }
            printf("Bien places : %d - Mal places : %d\n", mastermind.comparaison.bienPlace, mastermind.comparaison.malPlace);

            //Test de victoire
            if (mastermind.comparaison.bienPlace==4)
            {
                break;
            }

            //On retire un essai
            mastermind.essais--;
        }

        //Test victoire/défaite
        if (mastermind.essais>0)
        {
            mastermind.gagne++;
            printf("Partie gagnee !\n");
        }
        else
        {
            mastermind.perdu++;
            printf("Partie perdue !\n");
        }

        //Gagnées et perdues
        printf("Parties gagnees : %d\nParties perdues : %d\n", mastermind.gagne, mastermind.perdu);

        //Demander de rejouer
        printf("Souhaitez-vous rejouer ?\n0 = NON, 1 = OUI\nChoix:");
        scanf("%d", &rejouer);
    }
    while (rejouer);

    return 0;
}
