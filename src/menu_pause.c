int menu_pause(int width, int heighauteur_text){
  int largeur_text, hauteur_text, x_clique, y_clique;
  int image_menu_width=300, image_menu_height=150;
  char * text_1 = "Partie joueur 1";
  char * text_2 = "Partie joueur 2";
  
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

  MLV_actualise_window();

  /*Attendre un clic de souris*/
  MLV_wait_mouse(&x_clique, &y_clique);
  /*Reprendre*/
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
  /*Exit*/
  else if (x_clique>= 55 && x_clique<=295 && y_clique>=265 && y_clique<=315){
    fprintf(stdout,"%s\n", text_2);
    MLV_draw_filled_rectangle(55,265,240,50,MLV_COLOR_BLACK);
    MLV_draw_rectangle(55,265,240,50,MLV_COLOR_WHITE);
    MLV_get_size_of_text( text_2, &largeur_text, &hauteur_text );
    MLV_draw_text( x-largeur_text/2, y+215+(25-hauteur_text/2), text_2, MLV_COLOR_WHITE);
    MLV_actualise_window();
    MLV_wait_seconds(0.75);
    return 0;
  }

  else {
    return 1;
  }
}