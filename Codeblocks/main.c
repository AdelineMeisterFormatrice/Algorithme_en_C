#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Hellllloooo");

   unsigned int pvPC = 5; //pvPC est un entier = 5
   unsigned int pvHumain = 5.
   unsigned int resultatPileFace = 0;
   unsigned int choixjoueur = 0;

   srand(time(NULL));

   //La partie continue tant que les deux joueurs sont en vie
   While ((pvPC > 0) && (pvHumain > 0))
   {
       //On demande au joueur son choix
       printf("Pile ou Face ?/nPile = 1/nFace = 2/nVotre choix ?");
       scanf("%d", &choixjoueur);

       //On détermine le jet de la pièce
       //de 1 à 2
       resultatPileFace = rand() %2 + 1;

       //On compare le jet et le choix du joueur
       if (resultatPileFace == choixjoueur)
       {
           //on gagne > L'ordinateur perd une vie
           pvPC = pvPC -1;
       }
       else
       {
           //On perd > Le joueur perd une vie
           pvHumain--;
       }
       //L'un des deux est mort, on annonce le gagnant
       if (pvPC = 0)
       {

           //L'ordinateur est mort
           printf("L'ordinateur est mort");
       }
       if (pvHumain = 0)
       {
           //Le joueur est mort
           printf("Le joueuer est mort");
       }
   }

    return 0;
}
