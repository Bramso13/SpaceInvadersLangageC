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
  
  int fd = open("./txt/test", O_WRONLY | O_TRUNC | O_CREAT, 0600);
    int iwrite;
    
    	Joueur j1, j2;
    j1.nomJoueur = "joueur 1"; j1.scoreCourant = 0; j1.meilleurScore = 0;
	j2.nomJoueur = "joueur 2"; j2.scoreCourant = 0; j2.meilleurScore = 0;
        if (fd > 0) {
            iwrite = write(fd, &j1, sizeof(Joueur));
            if (iwrite < 0) {
                fprintf(stderr, "erreur d'ecriture de fichier");
                return 0;
            }
            iwrite = write(fd, &j2, sizeof(Joueur));
            if (iwrite < 0) {
                fprintf(stderr, "erreur d'ecriture de fichier");
                return 0;
            }
	    }else{
            fprintf(stderr, "erreur d'ouverture de fichier");
            return 0;
        }
    
    close(fd);
    
    
  
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
    case 5 :
        fiche_score();
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
