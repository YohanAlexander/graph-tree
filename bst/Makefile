main: main.o bst.o graph.o
	gcc -Wall -o3 main.o bst.o graph.o -o main

main.o: main.c
	gcc -c main.c

bst.o: bst.c bst.h
	gcc -c bst.c

graph.o: graph.c graph.h
	gcc -c graph.c

dot: bst.dot
	dot -Tpng bst.dot -o bst.png

clean:
	rm *.o main

bst:
	rm bst.dot bst.png
