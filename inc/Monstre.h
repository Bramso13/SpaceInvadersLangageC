// Définition du type Monstre
#include "inc/Plan.h"

#define largeurMonstre 6
#define hauteurMonstre 4
#define MAXMONSTRE 4

typedef struct Monstre * Monstre;
typedef Monstre listeMonstre[MAXMONSTRE];


struct Monstre
{
    int pointVie;
    int type;
    int positionX;
    int positionY;
};


int getPointVie(Monstre m);

int getPositionX(Monstre m);
int getPositionY(Monstre m);

void setPointVie(Monstre m, int point);

void setPositionX(Monstre m, int position);
void setPositionY(Monstre m, int position);

int constructeurMonstreBase(Monstre m, int x, int y, int index, listeMonstre l);
Monstre identificationMonstre(int x, int y);
void degat(Monstre m);

int estVivant(Monstre m);

