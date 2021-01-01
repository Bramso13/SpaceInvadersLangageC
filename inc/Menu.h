#ifndef DEF_MENU
#define DEF_MENU
#include "../inc/Fusee.h"
#include "../inc/Plan.h"
#include "../inc/Monstre.h"
#include "../inc/Joueur.h"


int menu_principal(int width, int height, Joueurs mesJoueurs);
int menuJeu(int width, int height, fusee maFusee, matrice mat, listeMonstre liste, int partiePoint, int nbJoueur, Joueurs mesJ);
#endif
