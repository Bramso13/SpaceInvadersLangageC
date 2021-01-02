#include "../inc/Monstre.h"
#include "../inc/Plan.h"
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

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
    	
        mat[m -> positionY][m -> positionX]= getPointVie(m);
         mat[m -> positionY][m -> positionX-1]= getPointVie(m);
         mat[m -> positionY][m -> positionX-3]= getPointVie(m);
         mat[m -> positionY][m -> positionX-4]= getPointVie(m);
         mat[m -> positionY][m -> positionX+1]= getPointVie(m);
         mat[m -> positionY][m -> positionX+3]= getPointVie(m);
         mat[m -> positionY][m -> positionX+4]= getPointVie(m);

         mat[m -> positionY+1][m -> positionX]= getPointVie(m);
         mat[m -> positionY+1][m -> positionX-1]= getPointVie(m);
         mat[m -> positionY+1][m -> positionX-2]= getPointVie(m);
         mat[m -> positionY+1][m -> positionX-3] = getPointVie(m);
         mat[m -> positionY+1][m -> positionX+1]= getPointVie(m);
         mat[m -> positionY+1][m -> positionX+2]= getPointVie(m);
         mat[m -> positionY+1][m -> positionX+3]= getPointVie(m);

         mat[m -> positionY+2][m -> positionX-2]= getPointVie(m);
         mat[m -> positionY+2][m -> positionX+2]= getPointVie(m);

         mat[m -> positionY+3][m -> positionX-3]= getPointVie(m);
         mat[m -> positionY+3][m -> positionX+3]= getPointVie(m);

         mat[m -> positionY-1][m -> positionX]= getPointVie(m);
         mat[m -> positionY-1][m -> positionX-1]= getPointVie(m);
         mat[m -> positionY-1][m -> positionX-2]= getPointVie(m);
         mat[m -> positionY-1][m -> positionX-3]= getPointVie(m);
         mat[m -> positionY-1][m -> positionX-4]= getPointVie(m);
         mat[m -> positionY-1][m -> positionX-5]= getPointVie(m);
         mat[m -> positionY-1][m -> positionX+1]= getPointVie(m);
         mat[m -> positionY-1][m -> positionX+2]= getPointVie(m);
         mat[m -> positionY-1][m -> positionX+3]= getPointVie(m);
         mat[m -> positionY-1][m -> positionX+4]= getPointVie(m);
         mat[m -> positionY-1][m -> positionX+5]= getPointVie(m);

         mat[m -> positionY-2][m -> positionX]= getPointVie(m);
         mat[m -> positionY-2][m -> positionX-1]= getPointVie(m);
         mat[m -> positionY-2][m -> positionX-2]= getPointVie(m);
         mat[m -> positionY-2][m -> positionX-3]= getPointVie(m);
         mat[m -> positionY-2][m -> positionX-5]= getPointVie(m);
         mat[m -> positionY-2][m -> positionX+1]= getPointVie(m);
         mat[m -> positionY-2][m -> positionX+2]= getPointVie(m);
         mat[m -> positionY-2][m -> positionX+3]= getPointVie(m);
         mat[m -> positionY-2][m -> positionX+5]= getPointVie(m);

         mat[m -> positionY-3][m -> positionX-3]= getPointVie(m);
         mat[m -> positionY-3][m -> positionX-5]= getPointVie(m);
         mat[m -> positionY-3][m -> positionX+3]= getPointVie(m);
         mat[m -> positionY-3][m -> positionX+5]= getPointVie(m);

         mat[m -> positionY-4][m -> positionX-1]= getPointVie(m);
         mat[m -> positionY-4][m -> positionX-2]= getPointVie(m);
         mat[m -> positionY-4][m -> positionX+1]= getPointVie(m);
         mat[m -> positionY-4][m -> positionX+2]= getPointVie(m);
        break;

    default:
        break;
    }

    return 1;
}

int moveMonstre(Monstre m, matrice mat, int intensite){

    if(estVivant(m)){
    	
    	setPositionY(m, m->positionY+intensite);
	    placeMonstre(m, mat);
	    if(mat[m->positionY+hauteurMonstre+1][m->positionX] == 15 || mat[m->positionY][m->positionX+largeurMonstre+1]){
		return 1;
	    }else{
		return 0;
	    }
    }
    
    return 0;
}
int longueurListe(listeMonstre l){
	int i, k=0;
	for(i=0;i<MAXMONSTRE;i++){
		if(estVivant(l[i])) k++;
	}
	return k;
}

int estVivant(Monstre m){
    return getPointVie(m) > 0;
}
void listeVide(listeMonstre l){

	int i;
	Monstre m = malloc(sizeof(m));
	m->pointVie = 0;
	m->type = 0;
	m->positionX = 0;
	m->positionY = 0;
	for(i=0;i<MAXMONSTRE;i++){
		l[i] = m;
		
	}
}
void addMonstre(Monstre m, listeMonstre l, int index){

	int i;
    if(estVivant(m)){
         for(i=0;i<MAXMONSTRE;i++){
         	if(!estVivant(l[i])){
         		l[i]->pointVie = m->pointVie;
         		l[i]->type = m->type;
         		l[i]->positionX = m->positionX;
         		l[i]->positionY = m->positionY;
         		l[i]->idMonstre = i;
         	}
         }
    }
}

int identificationMonstre(int x, int y, listeMonstre l){
  int i;
  for(i=0;i<MAXMONSTRE;i++){
      if((y > l[i]->positionX-largeurMonstre && y < l[i]->positionX+largeurMonstre) &&
      (x > l[i]->positionY-hauteurMonstre && x < l[i]->positionY+hauteurMonstre)){
          return i;
      }
    
    }
   return -1;

  
}
void ligneMonstre(int nbDeLigne, listeMonstre l, matrice mat){
    Monstre m=malloc(sizeof(*m));
    int i,j, nb = WIDTH/(largeurMonstre*2), indexMonstre=0;
    for(j = 1;j<=nbDeLigne;j++){
            constructeurMonstreBase(m, xUn, (hauteurMonstre*j)+1,indexMonstre,l);
            placeMonstre(m, mat);
            constructeurMonstreBase(m, xDeux, (hauteurMonstre*j)+1,indexMonstre,l);
            placeMonstre(m, mat);
            printf("x = %d et y = %d\n", m->positionX, m->positionY);
            indexMonstre++;
    }
    
}
void degat(int m, listeMonstre liste){
    liste[m]->pointVie = liste[m]->pointVie-1;
    printf("\npoint de vie = %d\n", liste[m]->pointVie);
    
}

int moveToutMonstre(listeMonstre liste, matrice mat){
    int i, test=0;

    for(i=0;i<MAXMONSTRE;i++){
        if(estVivant(liste[i])){
    	
    	setPositionY(liste[i], liste[i]->positionY+1);
		    placeMonstre(liste[i], mat);
		    if(mat[liste[i]->positionY+hauteurMonstre+1][liste[i]->positionX] == 15 || mat[liste[i]->positionY][liste[i]->positionX+largeurMonstre+1]){
			return 1;
		    }else{
			return 0;
		    }
	    }
	    
	    return 0;
    }
    return test;
}
void placeTouteListe(listeMonstre l, matrice mat){

	int i;
	for(i=0;i<MAXMONSTRE;i++) 
		placeMonstre(l[i], mat);
}

