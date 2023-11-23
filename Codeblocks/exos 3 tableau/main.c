#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int estPremier(int nb)

int main()
{
    int tab100 [10][10];
    //int icpt = 1;
    int x, y ;
    int res = 1;
    int i;

    for(y=0; y<10; y++)
    {
        for (x=0; x<10; x ++)
        {
            tab100[x][y] = x +1 + y*10;
        }
    }
     for(y=0; y<10; y++)
    {
        for (x=0; x<10; x ++)
        {
            printf("%d\n", tab100[x][y]);
        }

    }

    for(i = 2; i< nb*0.5; i++)
    {
        if(nb%i == 0)
        {
            res = 0;
            break;
        }
    }
    return 0;
}
