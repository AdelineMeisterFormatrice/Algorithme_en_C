#include <stdio.h>
#include <stdlib.h>

#define PIONJ1 o
#define PIONJ2 x

const char pionJ1 = 'o';
const char pionJ2 = 'x';

int verifGagne(char grille[3][3])
{
    int i;
    //On v�rifie en ligne
    for(i=0; i< 3; i++)
    {
        if((grille[i][1] == grille[i][2] &&grille[i][3] &&(grille[i][1] != ' ')))
        {
            return 0;
        }
    }

    //On v�rifie en cologne
    for(i=0; i< 3; i++)
    {
        if((grille[1][i] == grille[2][i] &&grille[1][i] &&(grille[3][i] != ' ')))
        {
            return 0;
        }
    }

    //On v�rifie en diagonale
     for(i=0; i< 3; i++)
    {
        if((grille[1][i] == grille[2][i] &&grille[1][i] &&(grille[3][i] != ' ')))
        {
            return 0;
        }
    }

    return 0;
}

int main()
{
    char grille[3][3];

    //Debut de partie = initialisation

    //On joue tant que personne n'a gagn�

    //Tour du joueur 1 puis tour du joueur 2..
    return 0;
}
