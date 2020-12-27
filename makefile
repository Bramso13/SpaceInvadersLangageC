cc = gcc
opt1 = -Wall `pkg-config --cflags MLV`
opt2 = `pkg-config --libs-only-other --libs-only-L MLV`
opt3 = `pkg-config --libs-only-l MLV`

The_monster : menu.o affichage.o main.o score.o animation.o sauvegarde.o
	$(cc) $(opt2) menu.o affichage.o main.o score.o animation.o sauvegarde.o $(opt3) -o The_monster

main.o : ./fichier_h/menu.h ./fichier_h/animation.h ./fichier_h/score.h ./fichier_h/sauvegarde.h ./fichier_c/main.c
	$(cc) $(opt1) -c ./fichier_c/main.c 

affichage.o : ./fichier_h/affichage.h ./fichier_c/affichage.c
	$(cc) $(opt1) -c ./fichier_c/affichage.c

menu.o : ./fichier_h/animation.h ./fichier_h/menu.h ./fichier_h/sauvegarde.h ./fichier_c/menu.c
	$(cc) $(opt1) -c ./fichier_c/menu.c 


score.o : ./fichier_h/score.h ./fichier_c/score.c
	$(cc) $(opt1) -c ./fichier_c/score.c 

animation.o: ./fichier_h/animation.h ./fichier_h/affichage.h ./fichier_h/score.h ./fichier_h/menu.h ./fichier_c/animation.c
	$(cc) $(opt1) -c ./fichier_c/animation.c 

sauvegarde.o: ./fichier_h/menu.h ./fichier_h/sauvegarde.h ./fichier_h/animation.h ./fichier_c/sauvegarde.c
	$(cc) $(opt1) -c ./fichier_c/sauvegarde.c 

clean:
	rm -f *.o *~ The_monster
