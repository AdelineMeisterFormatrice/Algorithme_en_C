#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Dalton
{
    int butin = 0;
    int balles = 6;
    int pourcentageGains;
    int enVie =1;

};

struct Banques
{
    int argent;
    int nbGardes;
};


int main()
{
    srand(time(NULL));

    struct Dalton famille[4];
    struct Banques goldbanque[5];

    //On genere l'argent et les gardes des 5 banques
    for(int i=0; i<5; i++)
    {
        goldbanque[i].argent = (rand()%8+2)*500;
        goldbanque[i].nbGardes = goldbanque[i].argent/1000;
    }

    //On genere les 4 daltons


    return 0;
}
