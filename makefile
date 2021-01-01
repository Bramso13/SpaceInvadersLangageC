gcc = gcc

p1 = -Wall `pkg-config --cflags MLV`
p2 = `pkg-config --libs-only-other --libs-only-L MLV`
p3 = `pkg-config --libs-only-l MLV`

Space :	 Joueur.o Monstre.o Plan.o menu.o Fusee.o main.o
	$(gcc) $(p2) Joueur.o menu.o Fusee.o main.o Monstre.o Plan.o $(p3) -o Space

Joueur.o : ./inc/Joueur.h ./src/Joueur.c
	$(gcc) $(p1) -c ./src/Joueur.c
	
main.o : ./inc/Menu.h ./inc/Fusee.h ./inc/Joueur.h ./inc/Monstre.h ./inc/Plan.h ./src/main.c
	$(gcc) $(p1) -c ./src/main.c 

menu.o : ./inc/Menu.h ./src/menu.c
	$(gcc) $(p1) -c ./src/menu.c 

Fusee.o : ./inc/Fusee.h ./inc/Joueur.h ./src/Fusee.c
	$(gcc) $(p1) -c ./src/Fusee.c

Monstre.o: ./inc/Monstre.h ./inc/Plan.h ./src/Monstre.c
	$(gcc) $(p1) -c ./src/Monstre.c   

Plan.o: ./inc/Monstre.h ./src/Plan.c
	$(gcc) $(p1) -c ./src/Plan.c 

clean:
	rm -f *.o *~ Space
