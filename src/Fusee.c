#include "../inc/Fusee.h"
#include "../inc/Joueur.h"



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
    mat[y][x] = f->pointFVie*4;mat[y][x+1] = f->pointFVie*4;mat[y][x-1] = f->pointFVie*4;
    mat[y-1][x] = f->pointFVie*4;mat[y-1][x+1] = f->pointFVie*4;mat[y-1][x-1] = f->pointFVie*4;
    mat[y-2][x] = f->pointFVie*4;mat[y-2][x+1] = f->pointFVie*4;mat[y-2][x-1] = f->pointFVie*4;
    mat[y+1][x] = f->pointFVie*4;mat[y+1][x+1] = f->pointFVie*4;mat[y+1][x-1] = f->pointFVie*4;
    mat[y+2][x] = f->pointFVie*4;mat[y+2][x+1] = f->pointFVie*4;mat[y+2][x-1] = f->pointFVie*4;
    mat[y+3][x] = f->pointFVie*4;
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

void attaqueFusee(fusee f, matrice mat, matrice l, int * i, Joueur monJ, int * xBalle){

    int m;

    if(*i < HEIGHT && *i > 0){
            if (mat[*i-1][*xBalle] != 0)
            {
                m = identificationMonstre(*xBalle,*i, l);
                degat(m, l);

                *i = f->positionFY-longueurFusee-1;
                monJ.scoreCourant = monJ.scoreCourant+20;
                *xBalle = f->positionFX;
            }

            if(*i == f->positionFY-longueurFusee-1) mat[*i][*xBalle] = 1;
            else{
                mat[*i][*xBalle] = 5;
                mat[*i+1][*xBalle] = 0;
            }
    }else{
        *i = f->positionFY-longueurFusee-1;
        *xBalle = f->positionFX;
    }
    affichePlan(mat);

}
int estMorte(fusee f){
    return f->pointFVie <= 0;
}
