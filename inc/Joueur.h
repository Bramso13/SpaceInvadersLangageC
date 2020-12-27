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
char * getNomJoueur(Joueur j){return j.nomJoueur;};
int getMeilleurScore(Joueur j){return j.meilleurScore;};
int getScoreCourant(Joueur j){return j.scoreCourant;};


int setJoueur(Joueur j, Joueurs js);
int setJoueurs(Joueurs js);
int setMeilleurScore(Joueur j, int meilleur){ j.meilleurScore = meilleur;};