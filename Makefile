CC = g++ -g -Wno-deprecated -std=c++11

all:ssp routing

ssp: Graph.o driver.o Fibonacciheap.o DijFib.o
	$(CC) -o ssp Graph.o driver.o Fibonacciheap.o DijFib.o

routing: Graph.o driver_routing.o Routing.o Trie.o Fibonacciheap.o DijFib.o 
	$(CC) -o routing Graph.o Trie.o Routing.o driver_routing.o  Fibonacciheap.o DijFib.o
	
Graph.o: Graph.cpp Graph.h
	$(CC) -g -c Graph.cpp

driver.o: driver.cpp
	$(CC) -g -c driver.cpp

driver_routing.o: driver_routing.cpp
	$(CC) -g -c  driver_routing.cpp

Fibonacciheap.o: Fibonacciheap.cpp
	$(CC) -g -c Fibonacciheap.cpp

DijFib.o: DijFib.cpp
	$(CC) -g -c DijFib.cpp

Trie.o: Trie.cpp
	$(CC) -g -c Trie.cpp

Routing.o: Routing.cpp
	$(CC) -g -c Routing.cpp

clean:
	rm -f ssp 
	rm -f routing
	rm -f *.o
