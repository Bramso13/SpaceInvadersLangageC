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

    int i,j, vraiJ;
    MLV_Color couleur = MLV_rgba(0, 0, 0, 0);

    for(i=0;i<WIDTH;i++){
        vraiJ = gHEIGHT/40*i;
        for(j=0;j<HEIGHT;j++){
            if(mat[i][j] == 1){
                couleur = MLV_rgba(1, 1, 1, 1);
            }
            if(mat[i][j] == 0) couleur = MLV_rgba(0, 0, 0, 0);
            MLV_draw_rectangle(gWIDTH/80*j, vraiJ, gWIDTH/80, gHEIGHT/40, couleur);

        }
    }
}
