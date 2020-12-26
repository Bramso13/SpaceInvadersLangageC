#include "inc/Joueur.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/types.h>


Joueur getJoueur()
{
	Joueur monJoueur;

    int fd = open("./txt/score", O_WRONLY | O_APPEND | O_CREAT, 0600);
    if (fd < 0) {
        fprintf(stderr, "probleme d'ouverture de fichier");
    }

	int iread = read(fd, &monJoueur, sizeof(Joueur));
	if (iread < 0) {
        fprintf(stderr, "probleme de lecture de fichier");
    }
	
	return(monJoueur);
}

Joueurs getMesJoueurs(){


    Joueurs mesJoueurs;
    int i = 0;

    while(getJoueur().nomJoueur != NULL){
        mesJoueurs.mesJoueurs[i] = getJoueur();
        i++;
    }

    return mesJoueurs;
}