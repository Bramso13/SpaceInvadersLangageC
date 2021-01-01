#include "../inc/Monstre.h"
#include "../inc/Plan.h"
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
    setPointVie(m, 3);
    m->type = 0;
    setPositionX(m, x);
    setPositionY(m, y);

    addMonstre(m, l, index);
    return 1;

}

int placeMonstre(Monstre m, matrice mat){


    if(m == NULL) return 0;

    switch (m->type)
    {
    case 0: // monstre de type de base
        mat[m -> positionX][m -> positionY]= getPointVie(m);
         mat[m -> positionX-1][m -> positionY]= getPointVie(m);
         mat[m -> positionX-3][m -> positionY]= getPointVie(m);
         mat[m -> positionX-4][m -> positionY]= getPointVie(m);
         mat[m -> positionX+1][m -> positionY]= getPointVie(m);
         mat[m -> positionX+3][m -> positionY]= getPointVie(m);
         mat[m -> positionX+4][m -> positionY]= getPointVie(m);

         mat[m -> positionX][m -> positionY+1]= getPointVie(m);
         mat[m -> positionX-1][m -> positionY+1]= getPointVie(m);
         mat[m -> positionX-2][m -> positionY+1]= getPointVie(m);
         mat[m -> positionX-3][m -> positionY+1] = getPointVie(m);
         mat[m -> positionX+1][m -> positionY+1]= getPointVie(m);
         mat[m -> positionX+2][m -> positionY+1]= getPointVie(m);
         mat[m -> positionX+3][m -> positionY+1]= getPointVie(m);

         mat[m -> positionX-2][m -> positionY+2]= getPointVie(m);
         mat[m -> positionX+2][m -> positionY+2]= getPointVie(m);

         mat[m -> positionX-3][m -> positionY+3]= getPointVie(m);
         mat[m -> positionX+3][m -> positionY+3]= getPointVie(m);

         mat[m -> positionX][m -> positionY-1]= getPointVie(m);
         mat[m -> positionX-1][m -> positionY-1]= getPointVie(m);
         mat[m -> positionX-2][m -> positionY-1]= getPointVie(m);
         mat[m -> positionX-3][m -> positionY-1]= getPointVie(m);
         mat[m -> positionX-4][m -> positionY-1]= getPointVie(m);
         mat[m -> positionX-5][m -> positionY-1]= getPointVie(m);
         mat[m -> positionX+1][m -> positionY-1]= getPointVie(m);
         mat[m -> positionX+2][m -> positionY-1]= getPointVie(m);
         mat[m -> positionX+3][m -> positionY-1]= getPointVie(m);
         mat[m -> positionX+4][m -> positionY-1]= getPointVie(m);
         mat[m -> positionX+5][m -> positionY-1]= getPointVie(m);

         mat[m -> positionX][m -> positionY-2]= getPointVie(m);
         mat[m -> positionX-1][m -> positionY-2]= getPointVie(m);
         mat[m -> positionX-2][m -> positionY-2]= getPointVie(m);
         mat[m -> positionX-3][m -> positionY-2]= getPointVie(m);
         mat[m -> positionX-5][m -> positionY-2]= getPointVie(m);
         mat[m -> positionX+1][m -> positionY-2]= getPointVie(m);
         mat[m -> positionX+2][m -> positionY-2]= getPointVie(m);
         mat[m -> positionX+3][m -> positionY-2]= getPointVie(m);
         mat[m -> positionX+5][m -> positionY-2]= getPointVie(m);

         mat[m -> positionX-3][m -> positionY-3]= getPointVie(m);
         mat[m -> positionX-5][m -> positionY-3]= getPointVie(m);
         mat[m -> positionX+3][m -> positionY-3]= getPointVie(m);
         mat[m -> positionX+5][m -> positionY-3]= getPointVie(m);

         mat[m -> positionX-1][m -> positionY-4]= getPointVie(m);
         mat[m -> positionX-2][m -> positionY-4]= getPointVie(m);
         mat[m -> positionX+1][m -> positionY-4]= getPointVie(m);
         mat[m -> positionX+2][m -> positionY-4]= getPointVie(m);
        break;

    default:
        break;
    }

    return 1;
}

int moveMonstre(Monstre m, matrice mat, int intensite){

    setPositionY(m, m->positionY+intensite);
    placeMonstre(m, mat);
    if(mat[m->positionX][m->positionY-hauteurMonstre-1] == 15){
        return 1;
    }else{
        return 0;
    }
}

int estVivant(Monstre m){
    return getPointVie(m) <= 0;
}

void addMonstre(Monstre m, listeMonstre l, int index){

    if(estVivant(m)){
         l.listeMonstre[index] = m;
    }
}

Monstre identificationMonstre(int x, int y, listeMonstre l){
  int i;
  Monstre m=malloc(sizeof(*m));
  for(i=0;i!=MAXMONSTRE;i++){
      if((x > l.listeMonstre[i]->positionX-largeurMonstre && x < l.listeMonstre[i]->positionX+largeurMonstre) &&
      (y > l.listeMonstre[i]->positionY-hauteurMonstre && y < l.listeMonstre[i]->positionY+hauteurMonstre)){
          return l.listeMonstre[i];
      }
    
    }
   return m;

  
}
void ligneMonstre(int nbDeLigne, listeMonstre l, matrice mat){
    Monstre m=malloc(sizeof(*m));
    int i,j, nb = WIDTH/(largeurMonstre*2), indexMonstre=0;
    for(j = 0;j<nbDeLigne;j++){
        for(i=0;i<nb;i++){
            constructeurMonstreBase(m, largeurMonstre*i+1, hauteurMonstre*j+1,indexMonstre,l);
            placeMonstre(m, mat);
            indexMonstre++;
        }
    }
    
}
void degat(Monstre m, listeMonstre liste){
    setPointVie(m, m->pointVie-1);
    if(!estVivant(m)){
        actualiseListe(liste);
    }
}
void actualiseListe(listeMonstre liste){

    int i, j;
    for(i=0;i<MAXMONSTRE;i++){
        if(liste.listeMonstre[i]->pointVie == 0){
        	free(liste.listeMonstre[i]);
            liste.nb--;
            for(j=i-1; j<MAXMONSTRE-1; j++)
            {
                liste.listeMonstre[i] = liste.listeMonstre[j + 1];
            }
        }
    }
}
int moveToutMonstre(listeMonstre liste, matrice mat){
    int i, test=0;

    for(i=0;i<liste.nb;i++){
        if(moveMonstre(liste.listeMonstre[i], mat, 1)) test=1;
    }
    return test;
}

