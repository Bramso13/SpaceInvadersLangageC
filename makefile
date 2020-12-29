p1 = -Wall `pkg-config --cflags MLV`
p2 = `pkg-config --libs-only-other --libs-only-L MLV`
p3 = `pkg-config --libs-only-l MLV`

Space : Fusee.o Joueur.o main.o menu.o Monstre.o Plan.o
    $(gcc) $(p2) menu.o affichage.o main.o score.o animation.o sauvegarde.o $(p3) -o Space

main.o : ./inc/Fusee.h ./inc/Joueur.h ./inc/Menu.h ./inc/Monstre.h ./inc/Plan.h ./src/main.c
    $(gcc) $(p1) -c ./fichier_c/main.c 

Fusee.o : ./inc/Fusee.h ./inc/Joueur.h ./src/Fusee.c
    $(gcc) $(p1) -c ./fichier_c/affichage.c

Joueur.o : ./inc/Joueur.h ./src/Joueur.c
    $(gcc) $(p1) -c ./fichier_c/menu.c 

menu.o : ./inc/menu.h ./src/menu.c
    $(gcc) $(p1) -c ./fichier_c/score.c 

Monstre.o: ./inc/Monstre.h ./inc/Plan.h ./src/Monstre.c
    $(gcc) $(p1) -c ./fichier_c/animation.c 

Plan.o: ./inc/Monstre.h ./src/Plan.c
    $(gcc) $(p1) -c ./fichier_c/sauvegarde.c 

clean:
    rm -f *.o *~ Space