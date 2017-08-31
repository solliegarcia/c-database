all: project1

project1: main.o UI_functions.o DB_functions.o record.h helpers.o
	gcc -o project1 main.o UI_functions.o DB_functions.o helpers.o

DB_functions.o: DB_functions.c record.h prototypes.h
	gcc -Wall -ansi -pedantic-errors -c DB_functions.c

UI_functions.o: UI_functions.c record.h prototypes.h helpers.c
	gcc -Wall -ansi -pedantic-errors -c UI_functions.c

helpers.o: helpers.c record.h prototypes.h
	gcc -Wall -ansi -pedantic-errors -c helpers.c

main.o: main.c record.h prototypes.h helpers.c
	gcc -Wall -ansi -pedantic-errors -c main.c

clean:
	rm *o project1
