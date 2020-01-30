main: main.o thread.o graph.o
	gcc -Wall -o3 main.o thread.o graph.o -o main

main.o: main.c
	gcc -c main.c

thread.o: thread.c thread.h
	gcc -c thread.c

graph.o: graph.c graph.h
	gcc -c graph.c

dot: thread.dot
	dot -Tpng thread.dot -o thread.png

clean:
	rm *.o main

thread:
	rm thread.dot thread.png
