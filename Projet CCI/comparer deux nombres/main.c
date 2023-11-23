#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int b;

    printf("Ce programme compare 2 nombres\n");

    printf("Entrer le nombre a :");
    scanf("%d", &a);

    printf("Entrer le nombre b :");
    scanf("%d", &b);

    if(a<b)
    {
        printf("a est plus petit que b");
    }
    else if(a>b)
    {
        printf("a est plus grand que b");
    }
    else
    {
        printf("a est egal a b");
    }



    return 0;
}
