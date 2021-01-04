
#include "../inc/Menu.h"
#include "../inc/Fusee.h"
#include "../inc/Plan.h"
#include "../inc/Monstre.h"
#include <string.h>
#include <MLV/MLV_all.h>

int menu_principal(int width, int height){
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
int menu_pause(int width, int height){
  int largeur_text, hauteur_text, x_clique, y_clique;
  char * text_1 = "Reprendre";
  char * text_2 = "Menu principal";
  
  

  /*rectangle bouton*/
  /*milieu de la fenêtre 175*/
  MLV_draw_filled_rectangle(55,200,240,50,MLV_COLOR_WHITE);
  MLV_get_size_of_text(text_1, &largeur_text, &hauteur_text);
  MLV_draw_text(175-largeur_text/2, 200+(25-hauteur_text/2), text_1,MLV_COLOR_BLACK);

  MLV_draw_filled_rectangle(55,265,240,50,MLV_COLOR_WHITE);
  MLV_get_size_of_text(text_2, &largeur_text, &hauteur_text);
  MLV_draw_text(175-largeur_text/2, 265+(25-hauteur_text/2), text_2, MLV_COLOR_BLACK);

  MLV_actualise_window();

  /*Attendre un clic de souris*/
  MLV_wait_mouse(&x_clique, &y_clique);
  /*Reprendre*/
  /*x_clique1 = x1, x_clique2 = x1+x2,y_clique1 = y1, y_clique2 = y1+y2*/
  if (x_clique>=55 && x_clique<=295 && y_clique>=200 && y_clique<=250){
    MLV_get_size_of_text(text_1, &largeur_text, &hauteur_text);
    MLV_draw_filled_rectangle(55,200,240,50,MLV_COLOR_BLACK);
    MLV_draw_rectangle(55,200,240,50,MLV_COLOR_WHITE);
    MLV_draw_text(x_clique-largeur_text/2, y_clique+150+(25-hauteur_text/2), text_1, MLV_COLOR_WHITE);
    MLV_actualise_window();
    MLV_wait_seconds(0.75);
    return 3;
  }
  /*Exit*/
  else if (x_clique>= 55 && x_clique<=295 && y_clique>=265 && y_clique<=315){
    fprintf(stdout,"%s\n", text_2);
    MLV_draw_filled_rectangle(55,265,240,50,MLV_COLOR_BLACK);
    MLV_draw_rectangle(55,265,240,50,MLV_COLOR_WHITE);
    MLV_get_size_of_text( text_2, &largeur_text, &hauteur_text );
    MLV_draw_text( x_clique-largeur_text/2, y_clique+215+(25-hauteur_text/2), text_2, MLV_COLOR_WHITE);
    MLV_actualise_window();
    MLV_wait_seconds(0.75);
    return 0;
  }

  else {
    return 1;
  }
  return 5;
}
int fiche_score(){
  int i=0, x=175, y=50, largeur_text, hauteur_text, x_clique, y_clique;
  int scoreint;
  char score[500];
  char nom[50];
  char * text_score = "Tableau des scores";
  char * text_retour = "Retour";
  FILE* fichier = NULL;
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_actualise_window();
/*fermer si erreur*/
  fichier=fopen("./txt/score.txt", "r");
  if (fichier==NULL){
    fprintf (stderr, "erreur fichier\n");
    exit(EXIT_FAILURE);
  }
   
/*Tableau des scores*/
  MLV_get_size_of_text(text_score, &largeur_text, &hauteur_text);
  MLV_draw_text(110, 10, text_score, MLV_COLOR_WHITE);
  while((fscanf(fichier,"%s %d", nom, &scoreint))==2 && i<10){
    sprintf(score, "%d", scoreint);
    MLV_draw_text(55, 50+30*i, nom, MLV_COLOR_WHITE);
    MLV_draw_text(275, 50+30*i, score, MLV_COLOR_WHITE);
    i++;
  }
 fclose(fichier);

  /*Bouton retour*/
  MLV_draw_filled_rectangle(55,395,240,50,MLV_COLOR_WHITE);
  MLV_get_size_of_text(text_retour, &largeur_text, &hauteur_text );
  MLV_draw_text(175-largeur_text/2, 395+(25-hauteur_text/2), text_retour, MLV_COLOR_BLACK);
  MLV_actualise_window();

 /*Clique sur le bouton*/
  MLV_wait_mouse(&x_clique, &y_clique);
  if (x_clique>= 55 && x_clique<=295 && y_clique>=395 && y_clique<=445){ 
    fprintf(stdout,"%s\n", text_retour);
     MLV_draw_filled_rectangle(55,395,240,50,MLV_COLOR_BLACK);
     MLV_draw_rectangle(55,395,240,50,MLV_COLOR_WHITE);
     MLV_get_size_of_text( text_retour, &largeur_text, &hauteur_text );
     MLV_draw_text(x-largeur_text/2, y+345+(25-hauteur_text/2), text_retour, MLV_COLOR_WHITE);
     MLV_actualise_window();
     MLV_wait_seconds(0.75);
     return 1;
  }
  else {
    return 7;
  }
}

void gameover(){
  
  int image_width=500, image_height=400;
 

  MLV_Image* image= MLV_load_image("./src/gameover.png");

  /*erreur s'il n'y a pas l'image*/
  if( !image){
    fprintf(stderr, "Image manquante.\n");
    exit(EXIT_FAILURE);
  }
  /*recuperer les tailles*/
  MLV_resize_image_with_proportions( image, image_width, image_height);
  /*appliquer les tailles au images*/
  MLV_get_image_size(image, &image_width, &image_height);
  /*affichage*/
  MLV_draw_image(image,-75,50);

  MLV_actualise_window();
}

int save_score(int score, Joueurs *Joueurs){
  int i,j;
  char name[100];          /* Pour le trie, taille de chaine de caractère*/
  int k=0;
  char* nom;                
  FILE* fichier = NULL;    /*initialiser le fichier */
  i=0;
 
  fichier = fopen("./txt/score.txt", "r"); 
  if (fichier == NULL){printf("-->Vous tentez d’acceder a un fichier inexistant\n");
    return 0;
  }
    
  /*On prend les nom et les scores*/
  while((fscanf(fichier,"%s %d",Joueurs->mesJoueurs[i].nomJoueur,&Joueurs->mesJoueurs[i].meilleurScore))==2 && i<=10){
    i++;
  }
  fclose(fichier);
  
/*Si le score est inférieur à la dernière ligne*/
/*Game Over + retour au menu*/
  if(score < Joueurs->mesJoueurs[9].meilleurScore){
  gameover();
  MLV_wait_seconds(3);
  return 1;
  }
/* Si le score est suppérieur à la dernière ligne*/
/*On remplace la dernière ligne par le score et on retrie */
  if (score > Joueurs->mesJoueurs[9].meilleurScore){
    Joueurs->mesJoueurs[9].meilleurScore = score;
/*L'utilisateur saisi son nom*/
    MLV_wait_input_box(55,200, 240, 80, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_COLOR_WHITE,"Entrez votre nom :  ", &nom);
    strcpy(Joueurs->mesJoueurs[9].nomJoueur, nom);   
    
    for(i=0;i<9;i++){
      for(j=i+1;j<10;j++){
        if (Joueurs->mesJoueurs[i].meilleurScore < Joueurs->mesJoueurs[j].meilleurScore){
          k = Joueurs->mesJoueurs[i].meilleurScore;
          Joueurs->mesJoueurs[i].meilleurScore = Joueurs->mesJoueurs[j].meilleurScore;
          Joueurs->mesJoueurs[j].meilleurScore = k;

          strcpy(name,Joueurs->mesJoueurs[i].nomJoueur);
          strcpy(Joueurs->mesJoueurs[i].nomJoueur,Joueurs->mesJoueurs[j].nomJoueur);
          strcpy(Joueurs->mesJoueurs[i].nomJoueur, name);
        }
      }
    }
  }
/*Maj fichier*/
  fichier = fopen("./txt/score.txt", "w+");
  for(i=0;i<10;i++){
    fprintf(fichier,"%s %d\n",Joueurs-> mesJoueurs[i].nomJoueur, Joueurs-> mesJoueurs[i].meilleurScore);
  }
  fclose(fichier);
  
  gameover();
  MLV_wait_seconds(3);
  return 1;
}
int menuJeu(int width, int height, matrice mat, int partiePoint, int nbJoueur){
	
  int perdu = 0, balle, vitesse =0, xBalle, level = 5, nbLigne = 1, menu;
  int largeur_text, hauteur_text, y_clique, x_clique;
  char * scoreAffichage = "score : ";
  char scoreA[10];
  fusee maFusee = malloc(sizeof(maFusee));
  Joueurs mesJ = getMesJoueurs();
  
  printf("nom : %s, meilleur : %d, score : %d\n",mesJ.mesJoueurs[nbJoueur-1].nomJoueur, mesJ.mesJoueurs[nbJoueur-1].meilleurScore, mesJ.mesJoueurs[nbJoueur-1].scoreCourant);
  matrice liste;
  constructeurFusee(maFusee, partiePoint);
  placeFusee(maFusee, mat);
  balle = maFusee->positionFY-longueurFusee-1;
  xBalle = maFusee->positionFX;
  planVide(liste);
  
  
  while(!perdu){
  	perdu = partiePoint == 0;
    
    if(!perdu){
      placeFusee(maFusee, mat);
      placeTouteListe(liste, mat);
      if(MLV_get_keyboard_state(SDLK_RIGHT) == MLV_PRESSED && !(MLV_get_keyboard_state(SDLK_LEFT) == MLV_PRESSED)) moveFusee(maFusee, mat, 1, 2); // bouger a droite
      if(MLV_get_keyboard_state(SDLK_LEFT) == MLV_PRESSED && !(MLV_get_keyboard_state(SDLK_RIGHT) == MLV_PRESSED)) moveFusee(maFusee, mat, 1, 1); // bouger a droite
      if(longueurListe(liste) == 0){
        ligneMonstre(nbLigne, liste, mat);
      }
      if(vitesse >= level){
          vitesse = 0;
          if(moveToutMonstre(liste, mat) == 1){
              partiePoint--;
              maFusee->pointFVie--;
          }         
      }
      if(mesJ.mesJoueurs[nbJoueur-1].scoreCourant > 1000) level = 3;
      if(level <= 3) nbLigne = 2;
      attaqueFusee(maFusee, mat, liste, &balle, &mesJ.mesJoueurs[nbJoueur-1], &xBalle);
      vitesse++;
      balle--;
      //monJ.scoreCourant++;
      
      MLV_draw_filled_rectangle(290,0,260,20,MLV_COLOR_WHITE);
      MLV_get_size_of_text("pause", &largeur_text, &hauteur_text);
      MLV_draw_text(300,0,"pause",MLV_COLOR_BLACK);
      sprintf(scoreA, "%d", mesJ.mesJoueurs[nbJoueur-1].scoreCourant);
      //strcat(scoreAffichage, scoreA);
      
      
      MLV_draw_filled_rectangle(200,480,260,20,MLV_COLOR_WHITE);
      MLV_get_size_of_text(scoreAffichage, &largeur_text, &hauteur_text);
      MLV_draw_text(200,480,scoreAffichage,MLV_COLOR_BLACK);
      MLV_draw_filled_rectangle(290,480,260,20,MLV_COLOR_WHITE);
      MLV_get_size_of_text(scoreA, &largeur_text, &hauteur_text);
      MLV_draw_text(300,480,scoreA,MLV_COLOR_BLACK);
      
      /*clique (je fais un return 1 dans le clique)*/
      if(MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED){
      		MLV_get_mouse_position(&x_clique, &y_clique);
      		if (x_clique>=290 && x_clique<=550 && y_clique>=0 && y_clique<=20){
      		setJoueurs(mesJ);
		  menu = menu_pause(WIDTH, HEIGHT);
		  if(menu == 5) menu = menu_pause(WIDTH, HEIGHT);
		  if(menu == 0) return 1;
		}
		MLV_clear_window(MLV_COLOR_BLACK);
      }
      if(MLV_get_keyboard_state(SDLK_SPACE) == MLV_PRESSED){
		menu = menu_pause(WIDTH, HEIGHT);
	  	if(menu == 5) menu = menu_pause(WIDTH, HEIGHT);
		if(menu == 0) return 1;
      
      }
      
      MLV_actualise_window();
      
      planVide(mat);
      MLV_wait_milliseconds(20);
    }
    
  }
  if(mesJ.mesJoueurs[nbJoueur-1].scoreCourant > mesJ.mesJoueurs[nbJoueur-1].meilleurScore){
  	mesJ.mesJoueurs[nbJoueur-1].meilleurScore = mesJ.mesJoueurs[nbJoueur-1].scoreCourant;
  }
  setJoueurs(mesJ);
  save_score(mesJ.mesJoueurs[nbJoueur-1].scoreCourant, &mesJ);
  perdu = 0;
  return 1;
  
}
