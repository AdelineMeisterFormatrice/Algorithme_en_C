#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define NB_ESSAIS_MAX 6
const int nbEssaisMax = 6;

#define BORNE_MIN 0
#define BORNE_MAX 100


int nbAleatoire(int min, int max)
{

    if (max<min)
    {

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


    int nbRandom = nbAleatoire(BORNE_MIN, BORNE_MAX);
    int nbJoueur = -1;
    int nbEssais = 0;
    int joueurJoue = 1;
    char joueurRejoue;

    int borneMinOrdi = BORNE_MIN;
    int borneMaxOrdi = BORNE_MAX;
    int nbOrdi = -1;


    while(joueurJoue)
    {

        while((nbRandom != nbJoueur) && (nbRandom != nbOrdi) && (nbEssais < NB_ESSAIS_MAX))
        {

            printf("Saisis un nombre entre 0 et 100:");
            fseek(stdin, 0, SEEK_END);
            scanf("%d", &nbJoueur);


            nbOrdi = nbAleatoire(borneMinOrdi, borneMaxOrdi);
            printf("L'ordinateur a saisi %d\n", nbOrdi);

            nbEssais++;


            if (nbJoueur == nbRandom)
            {
                printf("Tu as gagne en %d essais\n", nbEssais);
            }
            else
            {
                if (nbJoueur > nbRandom)
                {
                    printf("C'est trop grand\n");


                    borneMaxOrdi = nbJoueur-1;
                }
                else
                {
                    printf("C'est trop petit\n");


                    borneMinOrdi = nbJoueur+1;
                }
            }


            if (nbOrdi == nbRandom)
            {
                printf("L'ordinateur a gagner !\n");
            }
            else
            {
                if (nbOrdi > nbRandom)
                {
                    printf("Nombre de l'ordi trop grand\n");
                    if (borneMaxOrdi > nbOrdi)
                    {
                        borneMinOrdi = nbOrdi +1;
                    }
                }
            }
        }

        if (nbEssais == NB_ESSAIS_MAX)
        {


            if (nbRandom != nbJoueur)
            {
                printf("Tu as perdu !\n");
            }


            if (nbRandom != nbOrdi)
            {
                printf("L'ordi a perdu !\n");
            }
        }


        printf("Voulez-vous rejouer ?\nO = Oui\nN = Non\nVotre choix :");
        fseek(stdin, 0, SEEK_END);
        scanf("%c", &joueurRejoue);
        if ((joueurRejoue == 'O') || (joueurRejoue == 'o'))
        {
            joueurJoue = 1;

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

    return 0;
}
