#ifndef _GraphNode_
#define _GraphNode_
#include<iostream>
#include<list>
#include<string>
#include<vector>
using namespace std;
struct GraphNode
{
	int des;  //vertex number 
	int weight;  //Weight present on this node .This weight is used during Dijkstra algorithm.Initially it contains the edge weight 
	int parent;   //Parent vertex  of this node 
	GraphNode(int d,int w,int p)  //Initialisation of this node
	{
		des=d;
		weight=w;
		parent=p;
	}
};

/*****************Graph Class **********************/
class Graph
{
	int V;         //No of vertices in the node 
	list<GraphNode> *adjlst; //Array of lists used for adjacency list
	public:
	int getVertex();
	list<GraphNode>* getList();

	vector<string>Ip;//vector containing  Ip addresses of each  vertex
	Graph(string);
	~Graph();
    bool EdgePresent(int s,int d);
	void addEdge(int ,GraphNode);

};
int DFS(Graph,int);
#endif



