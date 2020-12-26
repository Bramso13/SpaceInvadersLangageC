#include "inc/Monstre.h"
#include "inc/Plan.h"
#include <stdio.h>
#include <stdlib.h>


int getPointVie(Monstre m){return m->pointVie;}

int getPositionX(Monstre m){return m->positionX;}
int getPositionY(Monstre m){return m->positionY;}

void setPointVie(Monstre m, int point){m->pointVie = point;}

void setPositionX(Monstre m, int position){
    if((position+largeurMonstre) < WIDTH && (position-largeurMonstre) > 0){
        m->positionX = position;
    }
    
    }
void setPositionY(Monstre m, int position){

    if((position+hauteurMonstre) < HEIGHT && (position-hauteurMonstre) > 0){
        m->positionY = position;
    }
}

int constructeurMonstreBase(Monstre m, int x, int y, int index, listeMonstre l){
    setPointVie(m, 10);
    m->type = 0;
    setPositionX(m, x);
    setPositionY(m, y);

    addMonstre(m, l, index);

}

int placeMonstre(Monstre m, matrice mat){


    if(m == NULL) return 0;

    switch (m->type)
    {
    case 0: // monstre de type de base

        break;

    default:
        break;
    }

    return 1;
}

int moveMonstre(Monstre m, matrice mat, int intensite){

    setPositionY(m, m->positionY+intensite);
    placeMonstre(m, mat);
}

int estVivant(Monstre m){
    return getPointVie(m) <= 0;
}

void addMonstre(Monstre m, listeMonstre l, int index){

    l[index] = m;
}

Monstre identificationMonstre(int x, int y){
  int i;
  for(i=0;l[i]!=MAXMONSTRE;i++){
    if(l[i] -> positionX == x && l[i] -> positionY == y){
    return l[i];
    }
  return 0;
  }
}

void degat(Monstre m){
    setPointVie(m, m->pointVie-1);
}

