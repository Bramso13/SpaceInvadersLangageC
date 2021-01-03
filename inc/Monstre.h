#ifndef DEF_MONSTRE
#define DEF_MONSTRE

// Définition du type Monstre
#include "../inc/Plan.h"


#define largeurMonstre 6
#define hauteurMonstre 4
#define MAXMONSTRE 10


void placeTouteListe(matrice l, matrice mat);
int longueurListe(matrice l);
int placeMonstre(int x,int y,int pointVie,int type, matrice mat);
int constructeurMonstreBase(int x, int y, int index, matrice l);
int identificationMonstre(int x, int y, matrice l);
void degat(int m, matrice liste);
void kill(int i, matrice liste);
void ligneMonstre(int nbDeLigne, matrice l, matrice mat);
int moveToutMonstre(matrice liste, matrice mat);

#endif
