graphtest: graph_test.o graph.o list.o
	gcc -o graphtest -g graph_test.o graph.o list.o

graph_test.o: graph_test.c graph.h
	gcc -g -c -Wall graph_test.c

graph.o: graph.c graph.h
	gcc -g -c -Wall graph.c

list.o: list.c graph.h
	gcc -g -c -Wall list.c

clean:
	rm -f *.o graphtest
