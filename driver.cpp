#include<iostream>
#include"Graph.h"
#include"DijFib.h"
using namespace std;
int main(int argc ,char  *argv[])
{
	int s,d;
	SSP res;
	vector<int>ans;
	/*check for wrong number of arguments */
	if(argc!=4)
	{
		cout<<"Wrong no of arguments "<<endl;
		return 0;
	}
	int tmpd=stoi(argv[3]);  //convert destination node from string to integer
	int tmps=stoi(argv[2]);  //convert source node from string to integer
	Graph g(argv[1]);
    res=DjkstraFibHeap(&g,tmps);

	cout<<" "<<(int)res.Dis[tmpd]<<" "<<endl;  //prints the shortest path value from source to destination
	ans.push_back(tmpd);
    while(tmpd!=tmps)
	{
      ans.push_back(res.Par[tmpd]);//putting the answer of parent in vector .
		tmpd=res.Par[tmpd];

	}

	for(vector<int>::reverse_iterator it=ans.rbegin();it!=ans.rend();it++)
	{
		cout<<(*it)<<" "; //printing the shortest path  from source to destination 
	}

	return 0;
}
