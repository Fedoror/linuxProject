all: program


program: main.o Structs.o libList.a libmainFunctions.so
	gcc -o program main.c Structs.h -L. -lList -lmainFunctions -Wl,-rpath,.

main.o: main.c
	gcc -c main.c

Structs.o: Structs.h
	gcc -c Structs.h

listExpansion.o: listExpansion.c
	gcc -c listExpansion.c

libList.a: listExpansion.o
	ar cr libList.a listExpansion.o

libmainFunctions.so: mainFunctions_lib.o
	gcc -shared -o libmainFunctions.so mainFunctions_lib.o

mainFunctions_lib.o: mainFunctions_lib.c
	gcc -c -fPIC mainFunctions_lib.c




test.o: test.c List.h; gcc -c test.c
test: test.o list.o; gcc -otest test.o List.o ../Unity/src/unity.c
runtests: test ./test

clean:
	rm --force *.o *.a *.so program

