#include <stdio.h>
#include <stdlib.h>

int main()
{
    //EXERCICE 1
    //Declaration d'un tableau
    int tableau[10];
    int i;

    //Ecriture dans un tableau
    for (i = 0; i < 10; i++)
    {
        tableau[i] = 2*(i+1);
    }

    //Lecture dans un tableau
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", tableau[i]);
    }

    //Exercice 2
    //Declaration du tableau
    int tab[10][10];
    int nombre;
    int multiple;

    //Calcul
    for (nombre = 0; nombre < 10; nombre++)
    {
        for (multiple = 0; multiple < 10; multiple++)
        {
            tab[nombre][multiple] = (nombre+1) * (multiple+1);
        }
    }

    //Affichage
    for (nombre = 0; nombre < 10; nombre++)
    {
        for (multiple = 0; multiple < 10; multiple++)
        {
            printf("%d * %d = %d\n",
                   (nombre+1),
                   (multiple+1),
                   tab[nombre][multiple]);
        }
    }

    //Exercice 3
    int tab100[10][10];
    int icpt = 1;
    int x, y;

    for (y=0; y<10; y++)
    {
        for (x=0; x<10; x++)
        {
            tab100[x][y] = x+1 + y*10
        }
    }

    for (y=0; y<10; y++)
    {
        for (x=0; x<10; x++)
        {
            tab100[x][y] = icpt;
            icpt++;
        }
    }


    return 0;
}
