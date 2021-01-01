#ifndef DEF_JOUEUR
#define DEF_JOUEUR

// Définition du type Joueur

typedef struct Joueur Joueur;
typedef struct Joueurs Joueurs;



struct Joueur
{
    char * nomJoueur;
    int meilleurScore;
    int scoreCourant;
};

struct Joueurs
{
    Joueur mesJoueurs[10];
    int nbJoueur;
};



Joueur getJoueur();
Joueurs getMesJoueurs();
char * getNomJoueur(Joueur j);
int getMeilleurScore(Joueur j);
int getScoreCourant(Joueur j);


int setJoueur(Joueur j, Joueurs js);
int setJoueurs(Joueurs js);
void setMeilleurScore(Joueur j, int meilleur);
#endif
