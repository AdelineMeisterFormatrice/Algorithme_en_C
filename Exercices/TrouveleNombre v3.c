#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Deux manières de déclarer des nombres magiques
#define NB_ESSAIS_MAX 6
const int nbEssaisMax = 6;

#define BORNE_MIN 0
#define BORNE_MAX 100

/*
Fonction qui retourne un nombre aléatoire
entre les deux bornes
*/
int nbAleatoire(int min, int max)
{
    //On vérifie si il faut inverser les nombres
    if (max<min)
    {
        //Min est plus grand que max
        //Il faut les inverser
        int tmp;
        tmp = min;
        min = max;
        max = tmp;
    }

    //On renvoie le nombre généré au hasard
    return rand() %(max-min+1) + min;
}

int main()
{
    //Initialisation du random
    srand(time(NULL));

    //Déclaration des variables
    int nbRandom = nbAleatoire(BORNE_MIN, BORNE_MAX);
    int nbJoueur = -1;
    int nbEssais = 0;
    int joueurJoue = 1;
    char joueurRejoue;

    int borneMinOrdi = BORNE_MIN;
    int borneMaxOrdi = BORNE_MAX;
    int nbOrdi = -1;

    //Jouer au jeu tant qu'on veut y jouer
    while (joueurJoue)
    {
        //On joue une partie tant qu'on n'a ni gagné ni perdu
        while ((nbRandom != nbJoueur) && (nbRandom != nbOrdi) && (nbEssais < NB_ESSAIS_MAX))
        {
            //Le joueur saisis
            printf("Saisis le nombre a deviner : ");
            fseek(stdin, 0, SEEK_END); //On replace le curseur de saisie
            scanf("%d", &nbJoueur);

            //L'ordinateur saisis
            nbOrdi = nbAleatoire(borneMinOrdi, borneMaxOrdi);
            printf("L'ordinateur a saisi %d\n", nbOrdi);

            nbEssais++;

            //On teste si le joueur a gagné ou non
            if (nbJoueur == nbRandom)
            {
                printf("Tu as gagne en %d essais\n"
                       , nbEssais);
            }
            else
            {
                if (nbJoueur > nbRandom)
                {
                    printf("C'est trop grand\n");

                    //L'ordi apprend la nouvelle borne max
                    borneMaxOrdi = nbJoueur-1;
                }
                else
                {
                    printf("C'est trop petit\n");

                    //L'ordi apprend la nouvelle borne min
                    borneMinOrdi = nbJoueur+1;
                }
            }

            //On teste si l'ordi a gagné ou non
            if (nbOrdi == nbRandom)
            {
                printf("L'ordinateur a gagne !\n");
            }
            else
            {
                if (nbOrdi > nbRandom)
                {
                    printf("Nombre de l'ordi trop grand\n");
                    if (borneMaxOrdi > nbOrdi)
                    {
                        //Si la borne est plus grande que son nombre, on reduit
                        borneMaxOrdi = nbOrdi -1;
                    }
                }
                else
                {
                    printf("Nombre de l'ordi trop petit\n");
                    if (borneMinOrdi < nbOrdi)
                    {
                        borneMinOrdi = nbOrdi +1;
                    }
                }
            }

        }
        //Fin de boucle joue partie

        //Si on est au max d'essais, tester la défaite
        if (nbEssais == NB_ESSAIS_MAX)
        {
            //Test de défaite du joueur
            if (nbRandom != nbJoueur)
            {
                printf("Tu as perdu !\n");
            }

            //Test de défaite de l'ordi
            if (nbRandom != nbOrdi)
            {
                printf("L'ordi a perdu !\n");
            }
        }

        /*Fin de partie, on demande si on veut rejouer */
        printf("Voulez-vous rejouer ?\nO = Oui\nN = non\nVotre choix :");
        fseek(stdin, 0, SEEK_END); //On replace le curseur de saisie
        scanf("%c", &joueurRejoue);
        if ((joueurRejoue == 'O') || (joueurRejoue == 'o'))
        {
            joueurJoue = 1;
            //On reinitialise la partie
            nbEssais = 0;
            nbRandom = nbAleatoire(BORNE_MIN, BORNE_MAX);
            nbJoueur = -1;
            nbOrdi = -1;
            borneMinOrdi = BORNE_MIN;
            borneMaxOrdi = BORNE_MAX;
        }
        else
        {
            if ((joueurRejoue == 'N') || (joueurRejoue == 'n'))
            {
                joueurJoue = 0;
            }
        }
    }
    //Fin de boucle jouer

    return 0;
}
