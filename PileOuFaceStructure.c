#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Joueur
{
    int choix;
    int victoires;
};

int testVictoiresOrdi(struct Joueur ordi[4], int nbOrdi)
{
    int i;
    for(i=0; i<nbOrdi;i++)
    {
        if (ordi[i].victoires>=5)
        {
            return 0; //On sort de la boucle
        }
    }
    return 1; //On continue la boucle
}

int testEgalite(struct Joueur ordi[4], int nbOrdi,struct Joueur humain)
{
    int plusHautScore;
    int cptPlusHautScore =0;
    int i;

    //Verifier pour le joueur
    plusHautScore = humain.victoires;
    cptPlusHautScore++;

    //Verifier pour les ordis
    for(i=0; i<nbOrdi; i++)
    {
        if (ordi[i].victoires>plusHautScore)
        {
            //On a un nouveau gagnant, il remplace l'ancien meilleur score
            plusHautScore = ordi[i].victoires;
            cptPlusHautScore = 1;
        }
        else if (ordi[i].victoires == plusHautScore)
        {
            cptPlusHautScore++;
        }
    }

    return cptPlusHautScore-1;

}

int main()
{
    struct Joueur humain = {0, 0};
    struct Joueur ordi [4];
    int jetPiece;
    int nbOrdi;
    int i;

    srand(time(NULL));

    //On demande à l'humain le nombre d'ordi
        printf("Choisissez le nombre d'ordi de 1 a 4\nVotre choix:");
        scanf("%d", &nbOrdi);


    //Initialiser les struct
    for(i=0; i<nbOrdi;i++)
    {
        ordi[i].victoires = 0;
    }

    //Tant que victoire humain et victoire ordi sont <5 on joue
    //while (((humain.victoires<5) && (ordi.victoires<5)) || ((humain.victoires == ordi.victoires)))
    while(((humain.victoires<5) && testVictoiresOrdi(ordi, nbOrdi) || testEgalite(ordi,nbOrdi, humain)))
    {
        //Jet de piece
        jetPiece = rand()%2; //0 ou 1

        //Choix ordi
        for(i=0; i<nbOrdi;i++)
        {
            ordi[i].choix = 1; //1 ou 2
        }


        //Choix humain
        printf("Pile (1) ou Face (2) ?\nChoix:");
        scanf("%d", &humain.choix);

        //Vérifier choix humain
        if (jetPiece == humain.choix%2)
        {
            humain.victoires++;
            printf("L'humain a trouve\n");
            printf("l'humain a %d victoire\n" ,humain.victoires);
        }

        //Vérifier choix ordi
        for(i=0;i<nbOrdi; i++)
        {
            if (jetPiece == ordi[i].choix%2)
        {
            ordi[i].victoires++;
            printf("L'ordi %d a trouve\n", i+1);
            printf("L'ordi %d a %d victoire\n", i+1,ordi[i].victoires);
        }
        }
    }
    //Vérifier les gagnants
    if (humain.victoires>=5)
    {
        printf("L'humain a gagne !\n");
    }
    for(i=0;i<nbOrdi;i++)
    {
        if (ordi[i].victoires>=5)
    {
        printf("L'ordi %d a gagne !\n", i+1);
    }
    }


    return 0;
}
