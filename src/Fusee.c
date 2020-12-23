#include "inc/Fusee.h"


int constructeurFusee(fusee f){

    f->positionX = WIDTH/2;
    f->positionY = HEIGHT/2;
}

void setX(fusee f, int x){
    if((x+largeurFusee) < WIDTH && (x-largeurFusee) > 0){
        f->positionX = x;
    }
}
void setY(fusee f, int y){
    if((y+longueurFusee) < HEIGHT && (y-longueurFusee) > 0){
        f->positionY = y;
    }
}

void placeFusee(fusee f, matrice mat){


}

void moveFusee(fusee f, matrice m, int intensite, int direction){


    switch (direction)
    {
    case 1:
        setX(f, f->positionX-intensite);
        placeFusee(f, m);
        break;
    case 2:
        setX(f, f->positionX+intensite);
        placeFusee(f, m);
        break;
    
    default:
        break;
    }
}

void attaqueFusee(fusee f, matrice mat){

    int i = f->positionX+longueurFusee+1;
    Monstre m;
    int test = 1;

    while(i != HEIGHT && test){

        if (mat[i][f->positionY] != 0)
        {
            m = identificationMonstre(i, f->positionY);
            degat(m);
            test = 0;
        }

        if(i == f->positionX+longueurFusee+1) mat[i][f->positionY] = 1;
        else{
            mat[i][f->positionY] = 1;
            mat[i-1][f->positionY] = 1;
        }
        affichePlan(mat);
        // attendre 
        i++;

    }
    
    
    // attendre
}