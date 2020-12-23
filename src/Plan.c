#include "inc/Plan.h"



void planVide(matrice mat){

    int i,j;

    for(i=0;i<WIDTH;i++){
        for(j=0;j<HEIGHT;j++){
            mat[i][j] = 0;
        }
    }
}

void affichePlan(matrice mat){

    int i,j;

    for(i=0;i<WIDTH;i++){
        for(j=0;j<HEIGHT;j++){
            if(mat[i][j] > 0){
                // mettre le rectangle de la bonne couleur
            }
        }
    }
}
