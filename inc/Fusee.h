#include "inc/Plan.h"
#include "inc/Monstre.h"
#include "inc/Joueur.h"
#define longueurFusee 3
#define largeurFusee 2

typedef struct Fusee * fusee;

struct Fusee
{
    int positionX;
    int positionY;
    int pointVie;

};

int constructeurFusee(fusee);
void attaqueFusee(fusee f, matrice mat, listeMonstre l, int * i, Joueur monJ);
void moveFusee(fusee f, matrice m, int intensite, int direction);
void placeFusee(fusee f, matrice mat);
void setY(fusee f, int y);
void setX(fusee f, int x);
int estMorte(fusee f);
