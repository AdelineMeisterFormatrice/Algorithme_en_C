#include <stdio.h>
#include <stdlib.h>

int nbaleatoire(int max,int min)
{
    int nb;
    nb =rand()%(max-min+1)+min;
    return nb;
}


int main()
{
    printf("%d",nbaleatoire(100,0));
    //fonction qui g�n�re un nombre al�atoire entre min et max
    return 0;
}
