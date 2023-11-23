#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main()
{
    srand(time(NULL));

    int Des = rand()%6 + 1;

   switch (Des)
   {
   case 1 :
   case 3 :
   case 5 :
    //impair
    printf("%d est impair", Des);
    break;
   case 2 :
   case 4 :
   case 6 :
    //pair
    printf("%d est pair", Des);
    break;

   }
    return 0;
}
