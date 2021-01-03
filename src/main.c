#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/types.h>
#include "../MLV/MLV_all.h"


#include "../inc/Menu.h"
#include "../inc/Joueur.h"

int main(){

  int fenetre = 1;
  int width = 350, height = 500;
  int partiePoint;

  /*créé et afficher la fenetre */
  MLV_create_window("Space invaders", "space invaders", width, height);

  /*couleur de la fenetre*/
  MLV_clear_window(MLV_COLOR_BLACK);
  matrice mat;
  planVide(mat);
  
  
  while (fenetre != 0){
    MLV_clear_window(MLV_COLOR_BLACK);
    switch (fenetre){
    case 1 : 
    fenetre = menu_principal(width,height);
      break;
    case 3 : 
        partiePoint = 3;
        
        fenetre = menuJeu(width,height,mat,partiePoint,1);
        break;
    case 4 : 
        partiePoint = 3;
        
        fenetre = menuJeu(width,height,mat,partiePoint,2);
        break;
    default : fenetre = 0;
    }
    printf("%d\n", fenetre);
    MLV_actualise_window();
  }
	

  
  /*mettre a jour la fenetre */
  MLV_actualise_window();

  
  /*ferme la fenetre */
  MLV_free_window();

  exit(EXIT_SUCCESS);
  /*return 1;*/
}
