#include <stdio.h>
#include <stdlib.h>

#define JOE 0
#define JACK 1
#define WILLIAM 2
#define AVRELL 3

struct Dalton
{
    int butin;
    int partButin;
    int balles;
    int vaEnMission;
    int enVie;
};

struct Bank
{
    int butin;
    int gardes;
};

void vaEnMission(struct Dalton unDalton)
{
    if (unDalton.enVie)
    {
        if (unDalton.vaEnMission) {
            printf("va en mission.\n");
        }
        else
        {
            printf("reste a la maison.\n");
        }
    }
    else
    {
        printf("est mort.\n");
    }
}

void aDesBalles(struct Dalton unDalton)
{
    if (unDalton.enVie)
    {
        if (unDalton.balles>0)
        {
            printf("a %d balles.\n", unDalton.balles);
        }
        else
        {
            printf("n'a plus de balles.\n");
        }
    }
    else
    {
        printf("est mort.\n");
    }
}

int main()
{
    struct Dalton lesDalton[4];
    struct Bank lesBanques[5];
    int i, j;
    int choixJoueur;

    //On initialise les 4 dalton
    lesDalton[JOE].partButin = 40;
    lesDalton[JOE].balles = 6;
    lesDalton[JOE].vaEnMission = 1;
    lesDalton[JOE].enVie = 1;
    lesDalton[JOE].butin = 0;
    lesDalton[JACK].partButin = 25;
    lesDalton[JACK].balles = 6;
    lesDalton[JACK].vaEnMission = 1;
    lesDalton[JACK].enVie = 1;
    lesDalton[JACK].butin = 0;
    lesDalton[WILLIAM].partButin = 25;
    lesDalton[WILLIAM].balles = 6;
    lesDalton[WILLIAM].vaEnMission = 1;
    lesDalton[WILLIAM].enVie = 1;
    lesDalton[WILLIAM].butin = 0;
    lesDalton[AVRELL].partButin = 10;
    lesDalton[AVRELL].balles = 6;
    lesDalton[AVRELL].vaEnMission = 1;
    lesDalton[AVRELL].enVie = 1;
    lesDalton[AVRELL].butin = 0;

    //On initialise les 5 banques
    for (i=0; i<5; i++)
    {
        lesBanques[i].butin = rand()%9*500+1000;
        lesBanques[i].gardes = lesBanques[i].butin/1000;
    }

    //On commence la tourn�e des banques
    for (i=0; i<5; i++)
    {
        //Infos sur la banque
        printf("Banque n %d, Butin: %d, Gardes: %d\n", i+1, lesBanques[i].butin, lesBanques[i].gardes);

        do
        {
            //Demander qui on veut emmener
            printf("Joe ");
            vaEnMission(lesDalton[JOE]);
            printf("Jack ");
            vaEnMission(lesDalton[JACK]);
            printf("William ");
            vaEnMission(lesDalton[WILLIAM]);
            printf("Avrell ");
            vaEnMission(lesDalton[AVRELL]);

            printf("Entrer le numero du Dalton (1 a 4) pour changer son statut et 0 pour partir\nChoix:");
            scanf("%d", &choixJoueur);
            if ((choixJoueur>0) && (choixJoueur<5))
            {
                lesDalton[choixJoueur-1].vaEnMission = !lesDalton[choixJoueur-1].vaEnMission;
            }
        }
        while(choixJoueur!=0);

        //Demander si ils veulent tirer
        do
        {
            printf("Il y a %d gardes\n", lesBanques[i].gardes);

            //Demander qui tire
            if (lesDalton[JOE].vaEnMission)
            {
                printf("Joe ");
                aDesBalles(lesDalton[JOE]);
            }
            if (lesDalton[JACK].vaEnMission)
            {
                printf("Jack ");
                aDesBalles(lesDalton[JACK]);
            }

            if (lesDalton[WILLIAM].vaEnMission)
            {
                printf("William ");
                aDesBalles(lesDalton[WILLIAM]);
            }

            if (lesDalton[AVRELL].vaEnMission)
            {
                printf("Avrell ");
                aDesBalles(lesDalton[AVRELL]);
            }

            printf("Entrer le numero du Dalton (1 a 4) pour tirer et 0 pour arreter\nChoix:");
            scanf("%d", &choixJoueur);
            if ((choixJoueur>0) && (choixJoueur<5))
            {
                //Tester si le Dalton est en mission ou pas
                if ((!lesDalton[choixJoueur-1].vaEnMission) || (!lesDalton[choixJoueur-1].enVie))
                {
                    printf("Ce Dalton n'est pas en mission !\n");
                }
                else
                {
                    //Tester si le Dalton a des balles ou pas
                    if (lesDalton[choixJoueur-1].balles>0)
                    {
                        //Tirer la balle, tuer un garde ou pas
                        lesDalton[choixJoueur-1].balles--;
                        if (lesBanques[i].gardes>0)
                        {
                            if (rand()%2==0)
                            {
                                //On tue un garde
                                lesBanques[i].gardes--;
                                printf("Un garde est mort, il reste %d gardes !\n", lesBanques[i].gardes);
                            }
                            else
                            {
                                //On rate
                                printf("Rate !\n");
                            }
                        }
                        else
                        {
                            printf("Il n'y a plus de garde a descendre !\n");
                        }

                    }
                    else
                    {
                        printf("Ce Dalton n'a plus de balles !\n");
                    }
                }
            }
        }
        while(choixJoueur!=0);

        //Les gardes restants ripostent
        for (j=0; j<lesBanques[i].gardes; j++)
        {
            if (rand()%2==0)
            {
                //Le garde touche
                printf("Le garde %d tire et tue !\n", j+1);
                int numDalton;

                for (numDalton=0; numDalton<4; numDalton++)
                {
                    if ((lesDalton[numDalton].vaEnMission) && (lesDalton[numDalton].enVie))
                    {
                        lesDalton[numDalton].enVie = 0;
                        printf("Le dalton %d est mort !\n", numDalton+1);
                        break;
                    }
                }
            }
            else
            {
                printf("Le garde %d tire et rate !\n",j+1);
            }
        }

        //Ils emportent le butin
        for (j=0; j<4; j++)
        {
            if ((lesDalton[j].vaEnMission) && (lesDalton[j].enVie))
            {
                int partButin = lesBanques[i].butin*lesDalton[j].partButin/100;
                lesDalton[j].butin += partButin;

                //Infos sur le butin recup�r�
                printf("Le dalton %d a pris %d du butin !\n", j+1, partButin);
            }
        }
    }

    for (i=0; i<4; i++)
    {
        if (lesDalton[i].enVie)
        {
            printf("Le dalton %d a un butin de %d !\n", i+1, lesDalton[i].butin);
        }
        else
        {
            printf("Le dalton %d est mort.\n", i+1);
        }
    }

    return 0;
}














