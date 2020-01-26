bintree: mainb.o bintree.o graph.o
	gcc -Wall -o3 mainb.o bintree.o graph.o -o bintree

mainb.o: mainb.c
	gcc -c mainb.c

bintree.o: bintree.c bintree.h
	gcc -c bintree.c

graph.o: graph.c graph.h
	gcc -c graph.c

dot: bst.dot
	dot -Tpng bst.dot -o bst.png

clean:
	rm *.o bintree