#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand(time(NULL));

    int tableau[8];
    int i;
    int interne , externe, temp;

    for(i=0;i<8;i++)
    {
        int random = rand()%20 + 1 ;
        tableau[i] =random;
    }
    printf("Tableau avant le tri\n");
    printf("\n");
    for(i=0;i<8;i++)
    {

        printf("%d\n",tableau[i]);
    }
    for(externe=0;externe<8-1;externe++)
    {
        for(interne=externe+1; interne<8;interne++)
        {
            if(tableau[externe] > tableau[interne])
            {
                temp=tableau[externe];
                tableau[externe] = tableau[interne];
                tableau[interne] = temp;
            }
        }
    }
    printf("\n");
    printf("Tableau apres le tri\n");
    printf("\n");
    for(i=0; i<8; i++)
    {

        printf("%d\n",tableau[i]);
    }
    return 0;
}

