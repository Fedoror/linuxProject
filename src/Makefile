all: program


program: main.o mainFunctions.o List.o Expense.o
	gcc -o program main.c mainFunctions.h List.h Expense.h

main.o: main.c
	gcc -c main.c

mainFunctions.o: mainFunctions.h
	gcc -c mainFunctions.h

List.o: List.h
	gcc -c List.h

Expense.o: Expense.h
	gcc -c Expense.h


test.o: test.c List.h; gcc -c test.c
test: test.o list.o; gcc -otest test.o List.o ../Unity/src/unity.c
runtests: test ./test



clean:
	rm --force *.o giveCreditPleaseS

