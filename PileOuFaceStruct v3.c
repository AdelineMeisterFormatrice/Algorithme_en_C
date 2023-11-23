#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Joueur
{
    int choix;
    int victoires;
};

int testVictoiresOrdi(struct Joueur ordi[4], int nbOrdis)
{
    int i;
    for (i=0; i<nbOrdis; i++)
    {
        if (ordi[i].victoires>=5)
        {
            return 0; //On sort de la boucle de jeu
        }
    }
    return 1; //On continue la boucle de jeu
}

int testEgaliteVictoires(struct Joueur humain, struct Joueur ordi[4], int nbOrdis)
{
    int plusHautScore;
    int cptPlusHautScore = 0;
    int i;

    /*
    plusHautScore = humain.victoires;
    cptPlusHautScore++;
    for (i=0; i<nbOrdis; i++)
    {
        if (ordi[i].victoires>plusHautScore)
        {
            //On a un nouveau gagnant, il remplace l ancien meilleur score
            plusHautScore = ordi[i].victoires;
            cptPlusHautScore = 1;
        }
        else if (ordi[i].victoires == plusHautScore)
        {
            cptPlusHautScore++;
        }
    }*/

    //Premier passage: on cherche le plus haut score
    plusHautScore = humain.victoires;
    for (i=0; i<nbOrdis; i++)
    {
        if (ordi[i].victoires>plusHautScore)
        {
            //Nouveau plus haut score
            plusHautScore = ordi[i].victoires;
        }
    }

    //Second passage: on compte le nombre de joueurs qui ont le plus haut score
    //Cas humain
    if (humain.victoires==plusHautScore)
    {
        cptPlusHautScore++;
    }
    //Cas ordis
    for (i=0; i<nbOrdis; i++)
    {
        if (ordi[i].victoires==plusHautScore)
        {
            cptPlusHautScore++;
        }
    }

    if (cptPlusHautScore>1)
    {
        //Il y a au moins 2 personnes avec le plus haut score
        return 1;
    }
    else
    {
        //Il y a une seule personne avec le plus haut score
        return 0;
    }
}

int main()
{
    struct Joueur humain = {0, 0};
    struct Joueur ordi[4];
    int nbOrdis;
    int i;
    int jetPiece;

    srand(time(NULL));

    //Demander le nombre d'ordis
    printf("Combien d adversaires voulez-vous ? (1 a 4)\nChoix:");
    scanf("%d", &nbOrdis);

    //Initialiser les struct
    for (i=0; i<nbOrdis; i++)
    {
        ordi[i].victoires = 0;
    }

    //while (((humain.victoires<5) && (ordi.victoires<5)) || (humain.victoires==ordi.victoires))
    while (((humain.victoires<5) && testVictoiresOrdi(ordi, nbOrdis)) || (testEgaliteVictoires(humain, ordi, nbOrdis)))
    {
        //Jet de piece
        jetPiece = rand()%2; //0 ou 1

        //Choix ordis
        for (i=0; i<nbOrdis; i++)
        {
            ordi[i].choix = rand()%2+1; //1 ou 2
        }

        //Choix humain
        printf("Pile (1) ou Face (2) ?\nChoix:");
        scanf("%d", &humain.choix);

        //Vérifier choix humain
        if (jetPiece == humain.choix%2)
        {
            humain.victoires++;
            printf("L'humain a trouve\n");
        }

        //Vérifier choix ordis
        for (i=0; i<nbOrdis; i++)
        {
            if (jetPiece == ordi[i].choix%2)
            {
                ordi[i].victoires++;
                printf("L'ordi %d a trouve\n", i+1);
            }
        }

        //printf("Humain: %d - Ordi: %d\n", humain.victoires, ordi.victoires);
    }

    //Vérifier les gagnants
    if (humain.victoires>=5)
    {
        printf("L'humain a gagne !\n");
    }
    for (i=0; i<nbOrdis; i++)
    {
        if (ordi[i].victoires>=5)
        {
            printf("L'ordi %d a gagne !\n", i+1);
        }
    }


    return 0;
}
