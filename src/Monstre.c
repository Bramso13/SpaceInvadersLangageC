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
    free(m);
    return 1;

}

int placeMonstre(int x,int y,int pointVie,int type, matrice mat){


    if(m == NULL) return 0;

    switch (type)
    {
    case 0: // monstre de type de base
    	
        mat[y][x]= pointVie;
         mat[y][x-1]= pointVie;
         mat[y][x-3]= pointVie;
         mat[y][x-4]= pointVie;
         mat[y][x+1]= pointVie;
         mat[y][x+3]= pointVie;
         mat[y][x+4]= pointVie;

         mat[y+1][x]= pointVie;
         mat[y+1][x-1]= pointVie;
         mat[y+1][x-2]= pointVie;
         mat[y+1][x-3] = pointVie;
         mat[y+1][x+1]= pointVie;
         mat[y+1][x+2]= pointVie;
         mat[y+1][x+3]= pointVie;

         mat[y+2][x-2]= pointVie;
         mat[y+2][x+2]= pointVie;

         mat[y+3][x-3]= pointVie;
         mat[y+3][x+3]= pointVie;

         mat[y-1][x]= pointVie;
         mat[y-1][x-1]= pointVie;
         mat[y-1][x-2]= pointVie;
         mat[y-1][x-3]= pointVie;
         mat[y-1][x-4]= pointVie;
         mat[y-1][x-5]= pointVie;
         mat[y-1][x+1]= pointVie;
         mat[y-1][x+2]= pointVie;
         mat[y-1][x+3]= pointVie;
         mat[y-1][x+4]= pointVie;
         mat[y-1][x+5]= pointVie;

         mat[y-2][x]= pointVie;
         mat[y-2][x-1]= pointVie;
         mat[y-2][x-2]= pointVie;
         mat[y-2][x-3]= pointVie;
         mat[y-2][x-5]= pointVie;
         mat[y-2][x+1]= pointVie;
         mat[y-2][x+2]= pointVie;
         mat[y-2][x+3]= pointVie;
         mat[y-2][x+5]= pointVie;

         mat[y-3][x-3]= pointVie;
         mat[y-3][x-5]= pointVie;
         mat[y-3][x+3]= pointVie;
         mat[y-3][x+5]= pointVie;

         mat[y-4][x-1]= pointVie;
         mat[y-4][x-2]= pointVie;
         mat[y-4][x+1]= pointVie;
         mat[y-4][x+2]= pointVie;
        break;

    default:
        break;
    }

    return 1;
}

// int moveMonstre(Monstre m, matrice mat, int intensite){

//     if(estVivant(m)){
    	
//     	setPositionY(m, m->positionY+intensite);
// 	    placeMonstre(m, mat);
// 	    if(mat[m->positionY+hauteurMonstre+1][m->positionX] == 15 || mat[m->positionY][m->positionX+largeurMonstre+1]){
// 		return 1;
// 	    }else{
// 		return 0;
// 	    }
//     }
    
//     return 0;
// }
int longueurListe(listeMonstre l){
	int i, k=0;
	for(i=0;i<MAXMONSTRE;i++){
		if(l[i][2] > 0) k++;
	}
	return k;
}

int estVivant(Monstre m){
    return getPointVie(m) > 0;
}
void listeVide(listeMonstre l){

	int i, j;
	
	for(i=0;i<MAXMONSTRE;i++){
		for(j=0;j<4;j++)
            l[i][j] = 0;
		
	}
}
void addMonstre(Monstre m, listeMonstre l, int index){

	int i;
    if(estVivant(m)){
         for(i=0;i<MAXMONSTRE;i++){
         	if(!estVivant(l[i])){
         		l[i][2] = m->pointVie;
         		l[i][3] = m->type;
         		l[i][0] = m->positionX;
         		l[i][1] = m->positionY;
         	}
         }
    }
}

int identificationMonstre(int x, int y, listeMonstre l){
  int i;
  for(i=0;i<MAXMONSTRE;i++){
      if((y > l[i][0]-largeurMonstre && y < l[i][0]+largeurMonstre) &&
      (x > l[i][1]-hauteurMonstre && x < l[i][1]+hauteurMonstre)){
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
    liste[m][2] = liste[m][2]-1;
    printf("\npoint de vie = %d\n", liste[m][2]);
    
}

int moveToutMonstre(listeMonstre liste, matrice mat){
    int i, test=0;

    for(i=0;i<MAXMONSTRE;i++){
        if(liste[i][2] > 0){
    	    liste[i][1]++;
		    placeMonstre(liste[i][0],liste[i][1],liste[i][2],liste[i][3], mat);
		    if(mat[liste[i][1]+hauteurMonstre+1][liste[i][0] == 15 || mat[liste[i][1]][liste[i][0]+largeurMonstre+1]==15)
                test=1;
            else 
                test=0;
	    }
    }
    return test;
}
void placeTouteListe(listeMonstre l, matrice mat){

	int i;
	for(i=0;i<MAXMONSTRE;i++) 
        placeMonstre(liste[i][0],liste[i][1],liste[i][2],liste[i][3], mat);

}

