#include<stdio.h>
#include<stdlib.h>
//#include "../MLV/MLV_all.h"

#include "../inc/Joueur.h"
#include "../inc/Menu.h"
#include "../inc/Fusee.h"
#include "../inc/Monstre.h"
#include "../inc/Plan.h"

int main(){
  int fenetre = 1;
  int width = 350, height = 500;
  int image_width= 100, image_height= 100;
  int x, y, score = 0, partiePoint = 3, avance = 30, vitesse=0;

  /*créé et afficher la fenetre */
  MLV_create_window("Space invaders", "space invaders", width, height);

  /*couleur de la fenetre*/
  MLV_clear_window(MLV_COLOR_BLACK);


  y = height-(image_height+10);
  x = width/2-(image_width/2);

  fusee maFusee = malloc(sizeof(maFusee));
  matrice mat;
  planVide(mat);

    listeMonstre liste;
    Joueurs mesJoueurs = getMesJoueurs();

  while (fenetre != 0){
    MLV_clear_window(MLV_COLOR_BLACK);
    switch (fenetre){
    case 1 : fenetre = menu_principal(width,height,mesJoueurs);
      break;
    case 3 : fenetre = menuJeu(width,height,maFusee,mat,liste,partiePoint,1, mesJoueurs);
      break;
    case 4 : fenetre = menuJeu(width,height,maFusee,mat,liste,partiePoint,2, mesJoueurs);
      break;
    case 5 : fenetre = fiche_score();
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
