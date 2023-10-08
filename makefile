FLAGS = -Wall -lm

main: main.c
	gcc $(FLAGS) -o main main.c

clear:
	rm -f ejemplo *.o
