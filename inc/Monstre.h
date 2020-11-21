// Définition du type Monstre

typedef struct Monstre * Monstre;

struct Monstre
{
    int pointVie;
    char * lienImage;
    int positionX;
    int positionY;
};

int getPointVie(Monstre m);
char * getLienImage(Monstre m);
int getPositionX(Monstre m);
int getPositionY(Monstre m);

void setPointVie(Monstre m, int point);
void setLienImage(Monstre m, char * lien);
void setPositionX(Monstre m, int position);
void setPositionY(Monstre m, int position);

int constructeurMonstreBase(Monstre m, int x, int y);

int estVivant(Monstre m);

