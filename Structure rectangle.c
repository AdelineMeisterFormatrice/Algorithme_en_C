#include <stdio.h>
#include <stdlib.h>

//Declaration de la structure rectangle
struct Rectangle
{
    unsigned int longueur;
    unsigned int largeur;
};

//Fonction pour calculer le perimetre
int calcPerimetre(struct Rectangle rekt)
{
    //Longueur *2 + Largeur*2
    return rekt.longueur*2 + rekt.largeur*2;
}

//Fonction pour calculer l'aire
int calcAire(struct Rectangle rekt)
{
    //Longueur * Largeur
    return rekt.longueur*rekt.largeur;
}

int main()
{
    //Appel de la structure rectangle
    struct Rectangle rekt;
    rekt.longueur = 10;
    rekt.largeur = 8;

    //Appel de la fonction perimetre
    printf("Perimetre %d \n" , calcPerimetre(rekt));

    //Appel de la fonction aire
    printf("Aire %d \n" , calcAire(rekt));

    return 0;
}
