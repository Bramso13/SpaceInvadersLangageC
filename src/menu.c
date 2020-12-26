
#include "inc/Menu.h"
#include "inc/Joueur.h"
#include "inc/Fusee.h"
#include "inc/Monstre.h"
#include "inc/Plan.h"


int menu_principal(int width, int height, Joueurs mesJoueurs){
  int largeur_text, hauteur_text, x_clique, y_clique, image_menu_width=300, image_menu_height=150;
  char * text_1 = "Partie joueur 1", text_2 = "Partie joueur 2", text_3 = "Score", text_4 = "Exit";



  
    text_1 = getNomJoueur(mesJoueurs.mesJoueurs[1]);
    text_2 = getNomJoueur(mesJoueurs.mesJoueurs[2]);

  MLV_Image* image_menu = MLV_load_image("./Images/image_menu.png");

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
int menuJeu(int width, int height, fusee maFusee, matrice mat, listeMonstre liste, int partiePoint, Joueur monJ){
  int perdu = 0;
  int balle = maFusee->positionX+longueurFusee+1;
  do
  {
    perdu = partiePoint == 0;
    
    if(!perdu){
      if(estMorte(maFusee)) partiePoint--;
      if(MLV_get_keyboard_state(MLV_KEYBOARD_RIGHT)) moveFusee(maFusee, mat, 1, 2); // bouger a droite
      if(MLV_get_keyboard_state(MLV_KEYBOARD_LEFT)) moveFusee(maFusee, mat, 1, 1); // bouger a droite
      if(liste.nb == 0){
        ligneMonstre(1, liste, mat);
      }
      moveToutMonstre(liste, mat);
      attaqueFusee(maFusee, mat, liste, &balle, monJ);
      balle++;
      monJ.scoreCourant++;
      MLV_wait_milliseconds(200);
    }
  } while (!perdu);
  if(perdu) return 6;
  
}