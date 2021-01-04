#include "../inc/Joueur.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/types.h>




Joueurs getMesJoueurs(){


    Joueurs mesJoueurs;
    int i;
    int fd = open("./txt/test", O_RDONLY);
    int iread;
	for(i=0;i<2;i++){
		
		    if (fd < 0) {
			fprintf(stderr, "probleme d'ouverture de fichier");

		    }

			iread = read(fd, &mesJoueurs.mesJoueurs[i], sizeof(Joueur));
			if (iread < 0) {
			fprintf(stderr, "probleme de lecture de fichier");

		    }
			
    		
	}
	close(fd);
    mesJoueurs.nbJoueur = i;
    return mesJoueurs;
}


int setJoueurs(Joueurs js){

    int i, fd = open("./txt/test", O_WRONLY | O_TRUNC | O_CREAT, 0600);
    int iwrite;
    for(i=0;i<js.nbJoueur;i++){
	printf("nomJoueur : %s, meilleur : %d, score : %d, nbJ : %d\n", js.mesJoueurs[i].nomJoueur, js.mesJoueurs[i].meilleurScore,js.mesJoueurs[i].scoreCourant, js.nbJoueur);
        if (fd > 0) {
            iwrite = write(fd, &js.mesJoueurs[i], sizeof(Joueur));
            if (iwrite < 0) {
                fprintf(stderr, "erreur d'ecriture de fichier");
                return 0;
            }
	    }else{
            fprintf(stderr, "erreur d'ouverture de fichier");
            return 0;
        }
    }
    close(fd);
    return 1;
}


