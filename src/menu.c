
#include "../inc/Menu.h"
#include "../inc/Fusee.h"
#include "../inc/Plan.h"
#include "../inc/Monstre.h"
#include <MLV/MLV_all.h>

int menu_principal(int width, int height, Joueurs mesJoueurs){
  int largeur_text, hauteur_text, x_clique, y_clique, image_menu_width=300, image_menu_height=150;
  char * text_1 = "Partie joueur 1";
  char * text_2 = "Partie joueur 2"; 
  char * text_3 = "Score"; 
  char * text_4 = "Exit";
  int x = 175;
  int y = 50;

  /*if(getNomJoueur(mesJoueurs.mesJoueurs[1]) != NULL && getNomJoueur(mesJoueurs.mesJoueurs[2]) != NULL){

    text_1 = getNomJoueur(mesJoueurs.mesJoueurs[1]);
    text_2 = getNomJoueur(mesJoueurs.mesJoueurs[2]);
  }*/ // Probleme ici
  

  MLV_Image* image_menu = MLV_load_image("/home/bramso/Desktop/SpaceInvadersLangageC/src/image_menu.png");

  /*erreur s'il n'y a pas l'image*/
  if( !image_menu ){
    fprintf(stderr, "Image manquante.\n");
    exit(EXIT_FAILURE);
  }
  /*recuperer les tailles*/
  MLV_resize_image_with_proportions( image_menu, image_menu_width, image_menu_height);
  /*appliquer les tailles au images*/
  MLV_get_image_size(image_menu, &image_menu_width, &image_menu_height);
  /*affichage*/
  MLV_draw_image(image_menu,55,20);

  /*rectangle bouton*/
  /*milieu de la fenêtre 175*/
  MLV_draw_filled_rectangle(55,200,240,50,MLV_COLOR_WHITE);
  MLV_get_size_of_text(text_1, &largeur_text, &hauteur_text);
  MLV_draw_text(175-largeur_text/2, 200+(25-hauteur_text/2), text_1,MLV_COLOR_BLACK);

  MLV_draw_filled_rectangle(55,265,240,50,MLV_COLOR_WHITE);
  MLV_get_size_of_text(text_2, &largeur_text, &hauteur_text);
  MLV_draw_text(175-largeur_text/2, 265+(25-hauteur_text/2), text_2, MLV_COLOR_BLACK);

  MLV_draw_filled_rectangle(55,330,240,50,MLV_COLOR_WHITE);
  MLV_get_size_of_text(text_3, &largeur_text, &hauteur_text);
  MLV_draw_text(175-largeur_text/2, 330+(25-hauteur_text/2), text_3, MLV_COLOR_BLACK);

  MLV_draw_filled_rectangle(55,395,240,50,MLV_COLOR_WHITE);
  MLV_get_size_of_text(text_4, &largeur_text, &hauteur_text);
  MLV_draw_text(175-largeur_text/2, 395+(25-hauteur_text/2), text_4, MLV_COLOR_BLACK);

  MLV_actualise_window();

  /*Attendre un clic de souris*/
  MLV_wait_mouse(&x_clique, &y_clique);
  /*joueur 1*/
  /*x_clique1 = x1, x_clique2 = x1+x2,y_clique1 = y1, y_clique2 = y1+y2*/
  if (x_clique>=55 && x_clique<=295 && y_clique>=200 && y_clique<=250){
    MLV_get_size_of_text(text_1, &largeur_text, &hauteur_text);
    MLV_draw_filled_rectangle(55,200,240,50,MLV_COLOR_BLACK);
    MLV_draw_rectangle(55,200,240,50,MLV_COLOR_WHITE);
    MLV_draw_text(x-largeur_text/2, y+150+(25-hauteur_text/2), text_1, MLV_COLOR_WHITE);
    MLV_actualise_window();
    MLV_wait_seconds(0.75);
    return 3;
  }
    /*joueur 2*/
  else if (x_clique>= 55 && x_clique<=295 && y_clique>=265 && y_clique<=315){
    fprintf(stdout,"%s\n", text_2);
    MLV_draw_filled_rectangle(55,265,240,50,MLV_COLOR_BLACK);
    MLV_draw_rectangle(55,265,240,50,MLV_COLOR_WHITE);
    MLV_get_size_of_text( text_2, &largeur_text, &hauteur_text );
    MLV_draw_text( x-largeur_text/2, y+215+(25-hauteur_text/2), text_2, MLV_COLOR_WHITE);
    MLV_actualise_window();
    MLV_wait_seconds(0.75);
    return 4;
  }
   /*score*/
  else if (x_clique>= 55 && x_clique<=295 && y_clique>=330 && y_clique<=380){ /*score*/
    fprintf(stdout,"%s\n", text_3);
    MLV_draw_filled_rectangle(55,330,240,50,MLV_COLOR_BLACK);
    MLV_draw_rectangle(55,330,240,50,MLV_COLOR_WHITE);
    MLV_get_size_of_text( text_3, &largeur_text, &hauteur_text );
    MLV_draw_text( x-largeur_text/2, y+280+(25-hauteur_text/2), text_3, MLV_COLOR_WHITE);
    MLV_actualise_window();
    MLV_wait_seconds(0.75);
    return 5;
  }
   /*exit*/
  else if (x_clique>= 55 && x_clique<=295 && y_clique>=395 && y_clique<=445){ /*exit*/
    fprintf(stdout,"%s\n", text_4);
    MLV_draw_filled_rectangle(55,395,240,50,MLV_COLOR_BLACK);
    MLV_draw_rectangle(55,395,240,50,MLV_COLOR_WHITE);
    MLV_get_size_of_text( text_4, &largeur_text, &hauteur_text );
    MLV_draw_text(x-largeur_text/2, y+345+(25-hauteur_text/2), text_4, MLV_COLOR_WHITE);
    MLV_actualise_window();
    MLV_wait_seconds(0.75);
    return 0;
  }

  else {
    return 1;
  }
}
int menuJeu(int width, int height, fusee maFusee, matrice mat, listeMonstre liste, int partiePoint, int nbJoueur, Joueurs mesJ){
	printf("je suis par la lafami");
  int perdu = 0, balle;
  constructeurFusee(maFusee, partiePoint);
  placeFusee(maFusee, mat);
  balle = maFusee->positionFX+longueurFusee+1;
  Joueur monJ = mesJ.mesJoueurs[nbJoueur];
  printf("je suis par ici: %d", maFusee->positionFX);
  
  do
  {
    planVide(mat);
    perdu = partiePoint == 0;
    printf("je suis vers perdu");
    if(!perdu){
      if(MLV_get_keyboard_state(SDLK_RIGHT) == MLV_PRESSED && !(MLV_get_keyboard_state(SDLK_LEFT) == MLV_PRESSED)) moveFusee(maFusee, mat, 1, 2); // bouger a droite
      if(MLV_get_keyboard_state(SDLK_LEFT) == MLV_PRESSED && !(MLV_get_keyboard_state(SDLK_RIGHT) == MLV_PRESSED)) moveFusee(maFusee, mat, 1, 1); // bouger a droite
      if(liste.nb == 0){
        ligneMonstre(1, liste, mat);
      }
      if(moveToutMonstre(liste, mat)){
         partiePoint--;
         maFusee->pointFVie--;
      }
      attaqueFusee(maFusee, mat, liste, &balle, monJ);
      balle++;
      monJ.scoreCourant++;
      MLV_wait_milliseconds(200);
    }
    printf("je suis a la fin du while");
  } while (perdu);
  printf("je suis la\n");
  return 1;
  
}
