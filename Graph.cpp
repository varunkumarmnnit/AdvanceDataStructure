#include<iostream>
#include<fstream>
#include<cstring>
#include<stack>
#include"Graph.h"
using namespace std;

/*******   Destructor for Graph Class *******************/
Graph::~Graph()
{	delete [] adjlst;
}

/*
Parameter : input file   mentioned in the first argument 
This fucntion creates graph from the input file  in adjacency list format 


*/
Graph::Graph(string inputfile)
{
	ifstream in;
	int vertex[3];
	int nlines=0;
	string line;
	char input[3];
	in.open(inputfile.c_str());
	while(getline(in,line))
	{
		nlines++;
		char *tmp=strtok(&line[0]," ");
		if(nlines==1)       //first line check 
		{
			this->V=stoi(tmp);
			this->adjlst= new list<GraphNode>[this->V];  //intilises number of lists based on vertices 
			continue ;
		}
		if(tmp==NULL)
			continue;
		else
		{ int i=0;
			vertex[i++]=stoi(tmp);
			while(tmp!=NULL)
			{
				tmp=strtok(NULL," ");
				if(tmp!=NULL)
				vertex[i++]=stoi(tmp);
			}
		}
        if(!EdgePresent(vertex[0],vertex[1]))    //edge will be added only when it does not exist before in adjacency list 
		{
        GraphNode node(vertex[1],vertex[2],-1);
		addEdge(vertex[0],node);
        }

	}

	in.close();  //cloing of input graph file 

};

/*

This function add the graphnode into the adjacency list 

*/
void Graph::addEdge(int s,GraphNode node)
{
	adjlst[s].push_back(node);
	GraphNode  rev_node(s,node.weight,node.parent);  //Since we assume the graph is not directed we have add edgein reverse direction also 
	adjlst[node.des].push_back(rev_node);
}
/*

Since the class variable V is private this is required to return private vriable 
*/
int Graph::getVertex()
{
	return this->V;
}

/*
Since the class variable adjacency list is private this is required to returen adjacency list pointer to outside class
*/
list<GraphNode >*  Graph::getList()
{
  return adjlst;
}


/*

This function checks that if there is an edge already added in the adjancy list then this return false to avoid redundancy 

*/

bool Graph::EdgePresent(int s,int d)
{
	for(list<GraphNode>::iterator it=adjlst[s].begin();it != adjlst[s].end();it++)
	{
		if(it->des==d)
			return true;
	}
	return false;
}


/*
int DFS(Graph obj,int s)
{
	bool v[obj.getVertex()];
	int count=0;
	list<GraphNode > *adjlst=obj.getList();

	v[s]=true;
	count++;
	stack<int>stck;
	stck.push(s);
	while(!stck.empty())
	{
		int top=stck.top();
		stck.pop();
		for(list<GraphNode>:: iterator it=adjlst[top].begin();it!=adjlst[top].end();it++)
		{
			if(!v[it->des])
			{
				v[it->des]=true;
				stck.push(it->des);
				count++;

			}
			else
				continue;

		}


	}
return count ;

}

*/
