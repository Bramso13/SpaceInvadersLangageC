#ifndef DEF_MENU
#define DEF_MENU
#include "../inc/Fusee.h"
#include "../inc/Plan.h"
#include "../inc/Monstre.h"



int menu_principal(int width, int height, Joueurs mesJoueurs);
int menu_pause(int width, int height);
int menuJeu(int width, int height, matrice mat, int partiePoint, int nbJoueur, Joueurs mesJ);
#endif
