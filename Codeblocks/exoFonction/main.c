#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand(time(NULL));

    int des1 = rand()%6+1;
    int des2 = rand()%20+1;
    int partieGagner =0;

    while(des1 != 6)
    {
        printf("vous avez un %d on continue\n", des1 );
        if(des1 == 6)
        {
            printf("vous avez un %d on lance le deuxieme des\n", des1 );
            while (des2 != 20);
            {
            if (des2 == 20)
            {
                partieGagner = 1;
                printf("gagner");
            }
            }
        }

    }
    return 0;
}
