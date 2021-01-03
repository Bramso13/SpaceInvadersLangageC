#include "../inc/Plan.h"
#include <MLV/MLV_all.h>



void planVide(matrice matri){

    int i,j;

    for(i=0;i<HEIGHT;i++){
        for(j=0;j<WIDTH;j++){
            matri[i][j] = 0;
        }
    }
}

void affichePlan(matrice mat){

    int i,j, vraiJ;
    MLV_Color couleur = MLV_rgba(0, 0, 0, 0);

    for(i=0;i<HEIGHT;i++){
        vraiJ = gHEIGHT/80*i;
        for(j=0;j<WIDTH;j++){
            if(mat[i][j] == 1) couleur = MLV_COLOR_RED;
            if(mat[i][j] == 2) couleur = MLV_COLOR_BLUE;
            if(mat[i][j] == 3) couleur = MLV_COLOR_WHITE;
            if(mat[i][j] == 4) couleur = MLV_COLOR_RED;
            if(mat[i][j] == 8) couleur = MLV_COLOR_BLUE;
            if(mat[i][j] == 12) couleur = MLV_COLOR_WHITE;
            if(mat[i][j] == 5) couleur = MLV_COLOR_WHITE;
            if(mat[i][j] == 15) couleur = MLV_COLOR_WHITE;
            if(mat[i][j] == 0) couleur = MLV_COLOR_BLACK;
            MLV_draw_filled_rectangle(gWIDTH/40*j, vraiJ, gHEIGHT/80,gWIDTH/40, couleur);

        }
    }
}
