#include "../inc/Plan.h"
#include <MLV/MLV_all.h>



void planVide(matrice mat){

    int i,j;

    for(i=0;i<HEIGHT;i++){
        for(j=0;j<WIDTH;j++){
            mat[i][j] = 0;
        }
    }
}

void affichePlan(matrice mat){

    int i,j, vraiJ;
    MLV_Color couleur = MLV_rgba(0, 0, 0, 0);

    for(i=0;i<HEIGHT;i++){
        vraiJ = gHEIGHT/80*i;
        for(j=0;j<WIDTH;j++){
            if(mat[i][j] == 1) couleur = MLV_COLOR_WHITE;
            if(mat[i][j] == 2) couleur = MLV_rgba(0, 1, 0, 1);
            if(mat[i][j] == 3) couleur = MLV_COLOR_WHITE;
            if(mat[i][j] == 15) couleur = MLV_COLOR_WHITE;
            if(mat[i][j] == 0) couleur = MLV_COLOR_BLACK;
            MLV_draw_filled_rectangle(gWIDTH/40*j, vraiJ, gHEIGHT/80,gWIDTH/40, couleur);

        }
    }
}
