main: main.o heap.o graph.o
	gcc -Wall -o3 main.o heap.o graph.o -o main

main.o: main.c
	gcc -c main.c

heap.o: heap.c heap.h
	gcc -c heap.c

graph.o: graph.c graph.h
	gcc -c graph.c

dot: heap.dot
	dot -Tpng heap.dot -o heap.png

clean:
	rm *.o main

heap:
	rm heap.dot heap.png
