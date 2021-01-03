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

    int fd = open("./txt/score", O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "probleme d'ouverture de fichier");

    }

	int iread = read(fd, &monJoueur, sizeof(Joueur));
	if (iread < 0) {
        fprintf(stderr, "probleme de lecture de fichier");

    }
	close(fd);
	return(monJoueur);
}

Joueurs getMesJoueurs(){


    Joueurs mesJoueurs;
    int i = 0;
	for(i=0;i<2;i++){
		Joueur monJoueur = getJoueur();
    		mesJoueurs.mesJoueurs[i] = monJoueur;
    		
	}
    mesJoueurs.nbJoueur = i+1;
    return mesJoueurs;
}

int setJoueur(Joueur j, Joueurs js){

    js.mesJoueurs[js.nbJoueur] = j;
    return 1;
}

int setJoueurs(Joueurs js){

    int i, fd = open("./txt/score", O_WRONLY | O_TRUNC | O_CREAT, 0600);
    for(i=0;i<2;i++) printf("nomJoueur : %s, meilleur : %d, score : %d\n", js.mesJoueurs[i].nomJoueur, js.mesJoueurs[i].meilleurScore,js.mesJoueurs[i].scoreCourant);
    for(i=0;i<2;i++){

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
    close(fd);
    return 1;
}
char * getNomJoueur(Joueur j){return j.nomJoueur;};
int getMeilleurScore(Joueur j){return j.meilleurScore;};
int getScoreCourant(Joueur j){return j.scoreCourant;};
void setMeilleurScore(Joueur j, int meilleur){ j.meilleurScore = meilleur;};

