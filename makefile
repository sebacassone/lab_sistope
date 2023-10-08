FLAGS = -Wall -lm

main: main.c funciones.o
	gcc $(FLAGS) -o main main.c funciones.o

funciones.o: funciones.c funciones.h
	gcc $(FLAGS) -c funciones.c

clear:
	rm -f ejemplo *.o
