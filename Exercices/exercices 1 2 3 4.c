#include <stdio.h>
#include <stdlib.h>

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

int main()
{
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

    return 0;
}





