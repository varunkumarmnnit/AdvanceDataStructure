#include"DijFib.h"
/*Header Files */

/*
Input Parameter : Graph and source vertex 
Ouput : Returns the single source shortest past from source to every other vertices 
This function  implements the Dijkstra algorithm using fibonacci heap 


*/
SSP DjkstraFibHeap(Graph *g,int s)
{
	unordered_map<int ,FibHeapNode *>fmap; //This map is required to get the Fib Node corresponding to the given vertex .
	int cost=0,it=s+1,V;
    SSP	tmp_path;

	V=g->getVertex();
	tmp_path.Dis.reserve(V);
	tmp_path.Par.reserve(V);
	bool visited[V];
	for(int i=0;i<V;i++)
		{
tmp_path.Dis[i]=0;//Initialisation of Dis vector 
tmp_path.Par[i]=0;//Initialisation of Par vector 
visited[i]=false; //Initialisation of visited node to false 
		}

	vector<int >parent(V,0);
	vector<int>res;
	int i=1;

	FibHeap fheap; 
	list<GraphNode> *adjList=g->getList();  //Getting the adjcency list of the graph
	FibHeapNode *tmp=fheap.CreateHeapNode(s,0);//source node weight is set 0 so that this will be extracted first in extract min operation.
	fheap.InsertNode(tmp);
	fmap[s]=tmp; 
	
	while(i<V)
	{   if(it<V){

	
		tmp=fheap.CreateHeapNode(it,INT_MAX);// apart from source node all other nodes will have value infinity(INT_MAX)
		fheap.InsertNode(tmp);
		fmap[it]=tmp;
		it++;
		i++;
	}
     
	 /*   the logic of if and else here if source vertex does not start from 0 .*/
	else
	{
		tmp=fheap.CreateHeapNode(it-V,INT_MAX);
		fheap.InsertNode(tmp);
		fmap[it-V]=tmp;
		it++;
		i++;

	}


	}
	while(fheap.getNodeCount())
	{
       tmp=fheap.removeMin();

	   int vrtxid=tmp->vertxId;
	   visited[vrtxid]=true;  //once any node comes we mark the corresponding vertex as visited so that we dont check this node again during relaxing of edges
	   
	   
	  // vertex[i++]=vrtxid;
	   for(list<GraphNode>::iterator it=adjList[vrtxid].begin();it!=adjList[vrtxid].end();it++)
	   {
            FibHeapNode *tmp_nbr=fmap[it->des];
			if(tmp_nbr!=NULL){

			
			if((tmp_nbr->weight>(it->weight+tmp->weight))&&(!visited[it->des]))
			{
				tmp_path.Par[it->des]=tmp->vertxId;  //updation of Parent value for this node 
				tmp_path.Dis[it->des]=it->weight+tmp->weight; //updation of weight value for this node
				fheap.decreaseKey(tmp_nbr,(it->weight+tmp->weight));  //decrease  key operation 
			}

	   }}


	}
	return tmp_path;
}
