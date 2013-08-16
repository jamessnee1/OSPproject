

main:   main.o menu.o utility.o
	@echo making all files
	@gcc -I /usr/include/SDL -o main main.o menu.o utility.o -lSDL -lSDL_mixer 

main.o: main.c main.h
	@echo making main.o
	@gcc -I /usr/include/SDL -c -g main.c -lSDL -lSDL_mixer

menu.o: menu.c
	@echo making menu.o
	@gcc -I /usr/include/SDL -c -g menu.c -lSDL -lSDL_mixer

utility.o: utility.c
	@echo making utility.o
	@gcc -I /usr/include/SDL -c -g utility.c -lSDL -lSDL_mixer

clean:
	rm -f *.o main
