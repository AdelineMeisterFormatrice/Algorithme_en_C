#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Exercice 1
/*int addition(int nb1, int nb2)
{
    return nb1+nb2;
}

float addition(float nb1, float nb2)
{
    return nb1+nb2;
}*/

float addition(int nb1, float nb2)
{
    return nb1+nb2;
}

//Exercice 2
void afficheAddition(int nb1, float nb2)
{
    printf("%d + %.2f = %.2f", nb1, nb2, addition(nb1,nb2));
}

//Exercice 5
int nbAleatoire(int min, int max)
{
    if (max<min)
    {
        //Min est plus grand que max
        //Il faut les inverser
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

    //Exercice 3
    unsigned int i=1;
    while (i<=100)
    {
        printf("%u\n", i);
        i++;
    }

    //Exercice 4
    for (int j=99; j>=0; j--)
    {
        printf("%d\n", j);
    }

    //Exercice 6
    int nb1;
    int nb2;
    int res = 0;

    printf("Entrez le premier nombre a multiplier: ");
    scanf("%d", &nb1);
    printf("Entrez le second nombre a multiplier: ");
    scanf("%d", &nb2);

    for (int k=0; k<nb1; k++)
    {
        res += nb2;
    }
    printf("%d * %d = %d",nb1, nb2, res);

    return 0;
}





