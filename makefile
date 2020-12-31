gcc = gcc

p1 = -Wall `pkg-config --cflags MLV`
p2 = `pkg-config --libs-only-other --libs-only-L MLV`
p3 = `pkg-config --libs-only-l MLV`

Space :	 Fusee.o Joueur.o main.o Monstre.o Plan.o menu.o
	$(gcc) $(p2) Fusee.o Joueur.o main.o menu.o Monstre.o Plan.o $(p3) -o Space

main.o : ./inc/Fusee.h ./inc/Joueur.h ./inc/Menu.h ./inc/Monstre.h ./inc/Plan.h ./src/main.c
	$(gcc) $(p1) -c ./src/main.c 

Fusee.o : ./inc/Fusee.h ./inc/Joueur.h ./src/Fusee.c
	$(gcc) $(p1) -c ./src/Fusee.c

Joueur.o : ./inc/Joueur.h ./src/Joueur.c
	$(gcc) $(p1) -c ./src/Joueur.c

Monstre.o: ./inc/Monstre.h ./inc/Plan.h ./src/Monstre.c
	$(gcc) $(p1) -c ./src/Monstre.c   

Plan.o: ./inc/Monstre.h ./src/Plan.c
	$(gcc) $(p1) -c ./src/Plan.c 

menu.o : ./inc/Menu.h ./src/menu.c
	$(gcc) $(p1) -c ./src/menu.c      

clean:
	rm -f *.o *~ Space
