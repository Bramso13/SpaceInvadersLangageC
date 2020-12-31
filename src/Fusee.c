#include "../inc/Fusee.h"


int constructeurFusee(fusee f, int point){

    f->positionFX = WIDTH/2;
    f->positionFY = HEIGHT-2-longueurFusee;
    f->pointFVie = point;
    return 1;
}

void setX(fusee f, int x){
    if((x+largeurFusee) < WIDTH && (x-largeurFusee) > 0){
        f->positionFX = x;
    }
}
void setY(fusee f, int y){
    if((y+longueurFusee) < HEIGHT && (y-longueurFusee) > 0){
        f->positionFY = y;
    }
}

void placeFusee(fusee f, matrice mat){
    int x = f->positionFX, y=f->positionFY;
    mat[x][y] = 15;mat[x+1][y] = 15;mat[x-1][y] = 15;
    mat[x][y-1] = 15;mat[x+1][y-1] = 15;mat[x-1][y-1] = 15;
    mat[x][y-2] = 15;mat[x+1][y-2] = 15;mat[x-1][y-2] = 15;
    mat[x][y+1] = 15;mat[x+1][y+1] = 15;mat[x-1][y+1] = 15;
    mat[x][y+2] = 15;mat[x+1][y+2] = 15;mat[x-1][y+2] = 15;
    mat[x][y+3] = 15;
}

void moveFusee(fusee f, matrice m, int intensite, int direction){


    switch (direction)
    {
    case 1:
        setX(f, f->positionFX-intensite);
        placeFusee(f, m);
        break;
    case 2:
        setX(f, f->positionFX+intensite);
        placeFusee(f, m);
        break;
    
    default:
        break;
    }
}

void attaqueFusee(fusee f, matrice mat, listeMonstre l, int * i, Joueur monJ){

    Monstre m;

    if(*i < HEIGHT && *i > 0){
            if (mat[*i][f->positionFY] != 0)
            {
                m = identificationMonstre(*i, f->positionFY, l);
                degat(m, l);

                *i = f->positionFX+longueurFusee+1;
                monJ.scoreCourant = monJ.scoreCourant+20;
            }

            if(*i == f->positionFX+longueurFusee+1) mat[*i][f->positionFY] = 1;
            else{
                mat[*i][f->positionFY] = 1;
                mat[*i-1][f->positionFY] = 0;
            }
    }else{
        *i = f->positionFX+longueurFusee+1;
    }
    affichePlan(mat);

}
int estMorte(fusee f){
    return f->pointFVie <= 0;
}
