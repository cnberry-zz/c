graphtest: graph_test.o graph.o
	gcc -o graphtest -g graph_test.o graph.o

graph_test.o: graph_test.c graph.h
	gcc -g -c -Wall graph_test.c

graph.o: graph.c graph.h
	gcc -g -c -Wall graph.c

clean:
	rm -f *.o graphtest
