#include <stdio.h>
#include <stdlib.h>

int main()
{
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

    return 0;
}
