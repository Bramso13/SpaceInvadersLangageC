#ifndef DEF_MONSTRE
#define DEF_MONSTRE

// Définition du type Monstre
#include "../inc/Plan.h"


#define largeurMonstre 6
#define hauteurMonstre 4
#define MAXMONSTRE 4

typedef struct Monstre * Monstre;
typedef struct listeMonstre listeMonstre;


struct Monstre
{
    int pointVie;
    int type;
    int positionX;
    int positionY;
};
struct listeMonstre{
    Monstre listeMonstre[MAXMONSTRE];
    int nb;
};

int getPointVie(Monstre m);
void addMonstre(Monstre m, listeMonstre l, int index);

int getPositionX(Monstre m);
int getPositionY(Monstre m);

void setPointVie(Monstre m, int point);

void setPositionX(Monstre m, int position);
void setPositionY(Monstre m, int position);

int constructeurMonstreBase(Monstre m, int x, int y, int index, listeMonstre l);
Monstre identificationMonstre(int x, int y, listeMonstre l);
void degat(Monstre m, listeMonstre liste);

int estVivant(Monstre m);
void ligneMonstre(int nbDeLigne, listeMonstre l, matrice mat);
void actualiseListe(listeMonstre liste);
int moveToutMonstre(listeMonstre liste, matrice mat);
#endif
