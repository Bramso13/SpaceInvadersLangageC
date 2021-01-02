#ifndef DEF_MONSTRE
#define DEF_MONSTRE

// Définition du type Monstre
#include "../inc/Plan.h"


#define largeurMonstre 6
#define hauteurMonstre 4
#define xUn 13
#define xDeux 25
#define MAXMONSTRE 10

typedef struct Monstre * Monstre;
typedef Monstre listeMonstre[MAXMONSTRE];


struct Monstre
{
    int pointVie;
    int type;
    int positionX;
    int positionY;
    int idMonstre;
};



int getPointVie(Monstre m);
void addMonstre(Monstre m, listeMonstre l, int index);
void placeTouteListe(listeMonstre l, matrice mat);
int getPositionX(Monstre m);
int getPositionY(Monstre m);
void listeVide(listeMonstre l);
void setPointVie(Monstre m, int point);
int longueurListe(listeMonstre l);
void setPositionX(Monstre m, int position);
void setPositionY(Monstre m, int position);

int constructeurMonstreBase(Monstre m, int x, int y, int index, listeMonstre l);
int identificationMonstre(int x, int y, listeMonstre l);
void degat(int m, listeMonstre liste);

int estVivant(Monstre m);
void ligneMonstre(int nbDeLigne, listeMonstre l, matrice mat);
void actualiseListe(listeMonstre liste);
int moveToutMonstre(listeMonstre liste, matrice mat);
#endif
