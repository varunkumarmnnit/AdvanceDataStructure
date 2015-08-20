#ifndef _h_djkstra_
#define _h_djkstra_
#include "Fibonacciheap.h"
#include <unordered_map>
#include<climits>
#include "Graph.h"
/*

This structure stores the result of the dijkstra algorithm 

*/
typedef struct res
{
vector<int>Dis;// stores the shortest  distance from the source node to the destination node .The destination node is represented as index of the vector .
vector<int>Par;//stores the parent node of the shortest path from source node..The destination node is represented as index of the vector .
}SSP;
SSP DjkstraFibHeap(Graph *,int s);

#endif
