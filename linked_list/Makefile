listtest: listtest.o list.o
	gcc -o listtest -g listtest.o list.o

listtest.o: listtest.c list.h
	gcc -g -c -Wall listtest.c

list.o: list.c list.h
	gcc -g -c -Wall list.c

clean:
	rm -f *.o listtest
