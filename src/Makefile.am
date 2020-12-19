all: giveCreditPlease


giveCreditPlease: main.o logic.o list.o Record.o
	gcc -o giveCreditPlease main.c logic.h list.h Record.h

main.o: main.c
	gcc -c main.c

logic.o: logic.h
	gcc -c logic.h

list.o: list.h
	gcc -c list.h

Record.o: Record.h
	gcc -c Record.h


test.o: test.c list.h; gcc -c test.c
test: test.o list.o; gcc -otest test.o list.o Unity/src/unity.c
runtests: test ./testS



clean:
	rm --force *.o giveCreditPleaseS