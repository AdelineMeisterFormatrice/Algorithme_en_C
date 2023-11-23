#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Deux maniéres de déclarer des nombres magiques
#define NB_ESSAIS_MAX 6
const int nbEssaisMax = 6;

//fonction qui retourne un nombre aleatoire entre les deux bornes

int nbaleatoire(int max,int min)
{
    //On vérifie si il faut inverser les nombres

    int nb;
    nb =rand()%(max-min+1)+min;
    return nb;
}

int main()
{
    //Declaration des variables
    int nbrand;
    int nbjoueur = -1;
    int nbessais = 0;
    int joueurjoue = 1;
    char joueurrejoue;

    int borneMinOrdi = 0;
    int borneMaxOrdi = 100;
    int nbOrdi = -1;

    //Initialisation du random
    srand(time(NULL));
    nbrand = nbaleatoire(100,0);

    //Jouer au jeu tant qu'on veut y jouer
    while(joueurjoue)
    {
        //On joue une tant qu'on a ni gagner ni perdu
         while((nbrand != nbjoueur) && (nbrand != nbOrdi) && (nbessais < NB_ESSAIS_MAX))
    {
        //le joueur saisis
        printf("Choisissez un nombre entre 0 et 100:\n");
        fseek(stdin, 0, SEEK_END);
        scanf("%d",&nbjoueur);

        //L'ordinateur saisi
        nbOrdi = nbaleatoire(borneMinOrdi, borneMaxOrdi);
        printf("L'ordinateur a saisi %d\n",nbOrdi);

        if(nbrand == nbjoueur)
        {
            printf("vous avez gagner en %d essais !\n",nbessais);

        }
        if(nbrand < nbjoueur)
        {
            printf("C'est moins\n");

            //L'ordi apprend la nouvelle borne max
            borneMaxOrdi = nbjoueur-1;
        }
        if(nbrand > nbjoueur)
        {
            printf("C'est plus\n");

            //L'ordi apprend la nouvelle borne min
            borneMinOrdi = nbjoueur+1;
        }

        //On teste si l'ordi a gagné ou non
        if (nbOrdi == nbrand)
        {
            printf("L'ordinateur a gagner !\n");

        }
        else
        {
            if (nbOrdi > nbrand)
                printf("Nombre de l'ordi trop grand\n");
                 if (borneMaxOrdi > nbOrdi)
            {
                //Si la borne est  plus grande que son nombre , on reduit
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

        nbessais++;


    if ((nbessais == NB_ESSAIS_MAX) &&(nbrand != nbjoueur))
    {
        printf("Vous avez perdu ! Vous etes null\n");
    }


        //Fin de partie, on demande si on veut rejouer
        //On replace le curseur de saisie
        fseek(stdin, 0, SEEK_END);
        printf("Voulez-vous rejouer ?\nO = Oui \nN = Non\nVotre choix ?");
        scanf(" %c", &joueurrejoue);

        if((joueurrejoue == 'O') || (joueurrejoue == 'o'))
        {
            joueurjoue = 1;
            //On réinitialise la partie
            nbessais = 0;
            nbrand = nbaleatoire(100,0);
            nbjoueur = -1;
            borneMinOrdi = 0;
            borneMaxOrdi = 100;
            nbOrdi = -1;
        }
        else
        {
            joueurjoue = 0;
        }
    }
    while((nbrand != nbjoueur) && (nbessais < NB_ESSAIS_MAX))
    {
        printf("Choisissez un nombre entre 0 et 100:\n");
        fseek(stdin, 0, SEEK_END);
        scanf("%d",&nbjoueur);

        if(nbrand == nbjoueur)
        {
            printf("vous avez gagner en %d essais !\n",nbessais);

        }
        if(nbrand < nbjoueur)
        {
            printf("C'est moins\n");
        }
        if(nbrand > nbjoueur)
        {
            printf("C'est plus\n");
        }
        nbessais++;

    }
    if ((nbessais == NB_ESSAIS_MAX) &&(nbrand != nbjoueur))
    {
        printf("Vous avez perdu ! Vous etes null");
    }

    return 0;
}
