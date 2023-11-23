#include <stdio.h>
#include <stdlib.h>

int main()
{
   int tables [10][10];
   int i;
   int j;

   for(i = 0; i < 10 ; i++)
   {

       for(j = 0; j < 10 ; j++)
       {
           tables[i][j] = (i+1) *(j+1);
       }
   }
   for(i = 0; i < 10 ; i++)
   {
       for(j = 0; j < 10; j++)
       {
          printf("%d * %d = %d\n",(i+1),(j+1),tables[i][j]);
       }

   }






    return 0;
}
