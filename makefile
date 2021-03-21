exe: main.o
	gcc -O2 -Wall -pedantic -lm -lnsl -o exe main.o

main.o: main.c
	gcc -O2 -Wall -pedantic -c main.c

clean:
	rm -f exe *.o
