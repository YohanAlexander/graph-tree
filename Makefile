tree: main.o bintree.o graph.o
	gcc -Wall -o3 main.o bintree.o graph.o -o tree

main.o: main.c
	gcc -c main.c

bintree.o: bintree.c bintree.h
	gcc -c bintree.c

graph.o: graph.c graph.h
	gcc -c graph.c

clean:
	rm *.o tree