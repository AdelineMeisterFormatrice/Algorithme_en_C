#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nb1;
    int nb2;
    int res = 0;

    printf("Entrez le premier nombre a multiplier:");
    scanf("%d",&nb1);
    printf("Entrez le second nombre a multiplier:");
    scanf("%d",&nb2);

    for (int i=0; i<nb1; i++)
    {
        res += nb2;
    }
    printf("%d * %d = %d",nb1, nb2, res);

    return 0;
}
