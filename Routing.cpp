#include "Routing.h"
/*
This function finds the next immediate vertex from a source to destination 


*/
int getNextHop(vector<int> &P,int s,int d)
{
	while(P[d]!=s)
	{
		d=P[d];
	}

	return  d;
}
/*
Parameter :Graph in adjacency list form have IP address also present for each vertices ,source and destination vertices for which routing scheme to be generated .This function builds tries for each vertices of the graph using Dijkstra single source shortest past implemented in part 1 .After that this function call the Search function of Trie to search  the IP address of the destination node and updates the result in TrieResult structure
*/

void routing_table(Graph *gg,int s,int d)
{
	SSP res=DjkstraFibHeap(gg,s);
	int it=d;
	int V=gg->getVertex();
	vector<Trie>Rtable(V);
	int itr=0;
	/*The purpose here is to create Binary Trie for each vertex */
	while(itr<V)
	{
		//Trie tmp;
		SSP tmp_res=DjkstraFibHeap(gg,itr); //finds shortest path for each vertex using dijkstra impplemented in part 1

	//	   cout<<" * "<<it<<" * "<<endl;
		for (int _d=0;_d<V;_d++)
		{

		
			if(itr!=_d)
			{
				int nextHop=getNextHop(tmp_res.Par,itr,_d);//find next hop for the given destination 
				string Ip=gg->Ip[_d]; //Get the ip address of the given destination 
				Rtable[itr].InsertPair(Ip,nextHop); //Insertion of IP address and next node in the Trie 
			}
		}
		Rtable[itr].OptimizePath();//Optimize the given trie 
		/*
		if(it==s)
			break;
		else
			it=res.Par[it];
			*/
			itr++;
	}
	int next=s;
	cout<<res.Dis[d]<<endl;

	/*This while loop finds the routing scheme from source and destination metioned in argument by the user */
	while (1)
	{
		if(next==d)
			break;
		TrieResult Tres= Rtable[next].Search(gg->Ip[d]);
		cout<<" "<<Tres.IpPrefix<<" ";
		next=Tres.nextHop;
	}

}
