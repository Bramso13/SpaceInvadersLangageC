#include "../inc/Monstre.h"
#include "../inc/Plan.h"
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

int placeMonstre(int x,int y,int pointVie,int type, matrice mat){
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


int longueurListe(matrice l){
	int i, k=0;
	for(i=0;i<MAXMONSTRE;i++){
		if(l[i][2] > 0) k++;
	}
	return k;
}


void listeVide(matrice l){

	int i, j;
	
	for(i=0;i<MAXMONSTRE;i++){
		for(j=0;j<4;j++)
            l[i][j] = 0;
		
	}
}

int identificationMonstre(int x, int y, matrice l){
  int i;
  for(i=0;i<MAXMONSTRE;i++){
      if((x > l[i][0]-largeurMonstre && x < l[i][0]+largeurMonstre) &&
      (y > l[i][1]-hauteurMonstre && y < l[i][1]+hauteurMonstre)){
          return i;
      }
    
    }
   return -1;

  
}
void ligneMonstre(int nbDeLigne, matrice l, matrice mat){
    int i,j, nb = WIDTH/(largeurMonstre*2+1), indexMonstre=0;
    for(j = 1;j<=nbDeLigne;j++){
    	for(i=1;i<nb;i++){
    		l[indexMonstre][0] = (largeurMonstre*2*i)+1;
    		l[indexMonstre][1] = (hauteurMonstre*j*2)+1;
    		l[indexMonstre][2] = 3;
    		l[indexMonstre][3] = 0;
    		indexMonstre++;
    	}
            
    }
    
}
void degat(int m, matrice liste){
	if(m>=0) liste[m][2] = liste[m][2]-1;
    if(liste[m][2] <= 0) kill(m, liste);
    
}
void kill(int i, matrice liste){

	liste[i][0] = 0;
	liste[i][1] = 0;
	liste[i][2] = 0;
	liste[i][3] = 0;
}
int moveToutMonstre(matrice liste, matrice mat){
    int i, test=0, x, y, j, k;

    for(i=0;i<MAXMONSTRE;i++){
        if(liste[i][2] > 0){
            liste[i][1]++;
            x = liste[i][0]; y = liste[i][1];
            for(j=0;j<largeurMonstre+1;j++){
                for(k=0;k<hauteurMonstre+1;k++){
                    if(mat[y+k][x+j] == 12 || mat[y+k][x+j] == 8 || mat[y+k][x+j] == 4){ test=1; kill(i,liste);}
                }
            }
            if(y+hauteurMonstre+1 >= HEIGHT) kill(i, liste);
	    }
    }
    return test;
}
void placeTouteListe(matrice l, matrice mat){

	int i;
	for(i=0;i<MAXMONSTRE;i++) 
        	placeMonstre(l[i][0],l[i][1],l[i][2],l[i][3], mat);

}

