#include <stdio.h>
#include <stdlib.h>

#define PIONJ1 o
#define PIONJ2 x

const char pionJ1 = 'o';
const char pionJ2 = 'x';

void afficheGrille(char grille[3][3])
{
    printf("-------\n");
    printf("|%c|%c|%c|\n", grille[0][0], grille[0][1], grille[0][2]);
    printf("--+-+--\n");
    printf("|%c|%c|%c|\n", grille[1][0], grille[1][1], grille[1][2]);
    printf("--+-+--\n");
    printf("|%c|%c|%c|\n", grille[2][0], grille[2][1], grille[2][2]);
    printf("-------\n");
}

int verifGagne(char grille[3][3])
{
    int i;
    //On vérifie en ligne
    for (i=0; i<3; i++)
    {
        if ((grille[i][0] == grille[i][1]) && (grille[i][0] == grille[i][2]) && (grille[i][0] != ' '))
        {
            return 1;
        }
    }

    //On vérifie en colonne
    for (i=0; i<3; i++)
    {
        if ((grille[0][i] == grille[1][i]) && (grille[0][i] == grille[2][i]) && (grille[0][i] != ' '))
        {
            return 1;
        }
    }

    //On vérifie en diagonale
    if ((grille[0][0] == grille[1][1]) && (grille[0][0] == grille[2][2]) && (grille[0][0] != ' '))
    {
        return 1;
    }
    if ((grille[2][0] == grille[1][1]) && (grille[2][0] == grille[0][2]) && (grille[2][0] != ' '))
    {
        return 1;
    }

    return 0;
}

int main()
{
    char grille[3][3];
    int i;
    int tourJoueur = 1;
    int coordX, coordY;

    //Debut de partie = initialisation
    for (i=0; i<9; i++)
    {
        grille[i/3][i%3] = ' ';
    }

    //On joue tant que personne n'a gagné
    while (!verifGagne(grille))
    {
        afficheGrille(grille);
        printf("Tour du joueur %d\n", tourJoueur);
        //Tour du joueur 1 puis tour du joueur 2...
        if (tourJoueur == 1)
        {
            //Tour joueur 1
            tourJoueur++;

            do
            {
                printf("Coordonnee X de votre choix: ");
                scanf("%d", &coordX);
                printf("Coordonnee Y de votre choix: ");
                scanf("%d", &coordY);
            }
            while (grille[coordX][coordY] != ' ');

            grille[coordX][coordY] = pionJ1;
        }
        else
        {
            //Tour joueur 2

            tourJoueur--;

            do
            {
                printf("Coordonnee X de votre choix: ");
                scanf("%d", &coordX);
                printf("Coordonnee Y de votre choix: ");
                scanf("%d", &coordY);
            }
            while (grille[coordX][coordY] != ' ');

            grille[coordX][coordY] = pionJ2;
        }
    }

    //On annonce le gagnant
    afficheGrille(grille);
    //Attention c'est buggé !
    printf("Joueur %d a gagne !", tourJoueur);

    return 0;
}
