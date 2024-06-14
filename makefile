
AULAPILHA: main.o pilhas.o
	gcc main.o pilhas.o -o AULAPILHA

main.o: main.c
	gcc -c main.c

listas.o: pilhas.c pilhas.h
	gcc -c pilhas.c
