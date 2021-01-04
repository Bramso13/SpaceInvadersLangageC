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




Joueurs getMesJoueurs();




int setJoueurs(Joueurs js);

#endif
