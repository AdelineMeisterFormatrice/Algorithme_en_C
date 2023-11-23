#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Joueur
{
    int nbVictoire;
    int choixJoueur;
};

int main()
{
    srand(time(NULL));

    struct Joueur joueurHumain;
    joueurHumain.nbVictoire = 0;
    joueurHumain.choixJoueur;

    struct Joueur joueurPC;
    joueurPC.nbVictoire = 0;
    joueurPC.choixJoueur = rand() %2+1;
    int lancerPieces = rand() %2+1;

    while ((joueurHumain.nbVictoire) < 5 && (joueurPC.nbVictoire < 5))
    {



        printf("Faites votre choix Pile = 1 Face = 2 \nVotre choix:");
        scanf("%d", &joueurHumain.choixJoueur);

        if(joueurHumain.choixJoueur == lancerPieces && joueurPC.choixJoueur==lancerPieces)
        {
            joueurHumain.nbVictoire++;
            joueurPC.nbVictoire++;
            printf("Les deux joueurs gagne\n");
            printf("Le joueur humain a %d victoires\n", joueurHumain.nbVictoire);
            printf("Le PC a %d victoires\n",joueurPC.nbVictoire);
        }

        if(joueurHumain.choixJoueur == lancerPieces && joueurPC.choixJoueur != lancerPieces)
        {
            joueurHumain.nbVictoire++;
            printf("Joueur Humain gagne et pc perd\n");
            printf("Le joueur humain a %d victoires\n", joueurHumain.nbVictoire);
        }

        if(joueurHumain.choixJoueur != lancerPieces && joueurPC.choixJoueur == lancerPieces)
        {
            joueurPC.nbVictoire++;
            printf("Joueur PC gagne et humain perd\n");
            printf("Le joueur PC a %d victoires\n", joueurPC.nbVictoire);
        }

    }


    return 0;
}
