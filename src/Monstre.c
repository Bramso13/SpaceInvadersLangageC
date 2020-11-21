#include "inc/Monstre.h"
#include <stdio.h>
#include <stdlib.h>


int getPointVie(Monstre m){return m->pointVie;}
char * getLienImage(Monstre m){return m->lienImage;}
int getPositionX(Monstre m){return m->positionX;}
int getPositionY(Monstre m){return m->positionY;}

void setPointVie(Monstre m, int point){m->pointVie = point;}
void setLienImage(Monstre m, char * lien){m->lienImage = lien;}
void setPositionX(Monstre m, int position){m->positionX = position;}
void setPositionY(Monstre m, int position){m->positionY = position;}

int constructeurMonstreBase(Monstre m, int x, int y){
    setPointVie(m, 10);
    setLienImage(m, "./");
    setPositionX(m, x);
    setPositionY(m, y);
}
int estVivant(Monstre m){
    return getPointVie(m) <= 0;
}