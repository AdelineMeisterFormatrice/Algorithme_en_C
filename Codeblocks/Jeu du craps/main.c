#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
 srand(time(NULL));

 //d�claration de variables

 int Des = rand()%12 + 1;

 switch(Des)
 {
 case 2:
 case 3:
 case 12:
    //Perdu
    printf("Vous avez perdu avec un %d",Des);
    break;
 case 7:
 case 11:
    //Gagn�
    printf("Vous avez gagner avec un %d",Des);
    break;
 case 4:
 case 5:
 case 6:
 case 8:
 case 9:
 case 10:
    //On relance les d�s
    printf("Vous avez fait un %d on relance les des",Des);
    while(Des != 7)
    {
        switch(Des)
        {
        case 4:
        case 5:
        case 6:
        case 8:
        case 9:
        case 10:
            //Gagn�
            printf("Vous avez gagn�");
            break;

        }
    }
    break;

 }

    return 0;
}
