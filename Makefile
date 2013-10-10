

pi-dupbox:   main.o menu.o utility.o
	@echo making all files
	@gcc -I /usr/include/SDL -o pi-dupbox main.o menu.o utility.o -pthread -lSDL -lSDL_mixer 

main.o: main.c main.h
	@echo making main.o
	@gcc -I /usr/include/SDL -c -g main.c  -pthread -lSDL -lSDL_mixer

menu.o: menu.c
	@echo making menu.o
	@gcc -I /usr/include/SDL -c -g menu.c  -pthread -lSDL -lSDL_mixer

utility.o: utility.c
	@echo making utility.o
	@gcc -I /usr/include/SDL -c -g utility.c -pthread -lSDL -lSDL_mixer

clean:
	rm -f *.o main
