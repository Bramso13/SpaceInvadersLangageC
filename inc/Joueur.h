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
    struct Joueur mesJoueurs[10];
};



Joueur getJoueur();
Joueurs getMesJoueurs();
char * getNomJoueur(Joueur);
int getMeilleurScore(Joueur j);
int getScoreCourant(Joueur j);


int setJoueur(Joueur j);
int setMeilleurScore(Joueur j, int meilleur);