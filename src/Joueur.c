#include "../inc/Joueur.h"
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

    int fd = open("./txt/score", O_RDONLY, 0600);
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
    mesJoueurs.nbJoueur = i;
    return mesJoueurs;
}

int setJoueur(Joueur j, Joueurs js){

    js.mesJoueurs[js.nbJoueur] = j;
    return 1;
}

int setJoueurs(Joueurs js){

    int i, fd = open("./txt/score", O_WRONLY | O_TRUNC | O_CREAT, 0600);
    for(i=0;i<js.nbJoueur;i++){

        if (fd > 0) {
            int iwrite = write(fd, &js.mesJoueurs[i], sizeof(Joueur));
            if (iwrite < 0) {
                fprintf(stderr, "erreur d'ecriture de fichier");
                return 0;
            }
	    }else{
            fprintf(stderr, "erreur d'ouverture de fichier");
            return 0;
        }
    }
    return 1;
}
char * getNomJoueur(Joueur j){return j.nomJoueur;};
int getMeilleurScore(Joueur j){return j.meilleurScore;};
int getScoreCourant(Joueur j){return j.scoreCourant;};
void setMeilleurScore(Joueur j, int meilleur){ j.meilleurScore = meilleur;};

