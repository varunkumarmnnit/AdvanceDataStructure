#ifndef _FibHeap_H_
#define _FibHeap_H_
#include<iostream>
#include<vector>
#define DEGREE_LMT 40  //We have taken the assumption the max degree of fib node will not exceed more that 40
using namespace std;
struct FibHeapNode
{
	int degree;//Degree present for this node
	int weight;//Weight present on this node 
	int vertxId;//Vertx Id for this node .This vertex id is same as graph vertex number.
	FibHeapNode *parent;//Parent pointer of this node .Required for doubly linked list 
	FibHeapNode *left;//left pointer for this node .Required for doubly linked list 
	FibHeapNode *right;//right pointer for this node 
	FibHeapNode *child;//child pointer for this node 
	bool ChildCut;//childCut Value for this node either true or false
};
class FibHeap
{
	FibHeapNode *minNode;//Points to the minimum node pointer in the current Min Heap
	int nodecount;//represents no of nodes in the current Fib Heap
	public:
	int getNodeCount()
	{
		return nodecount;
	}
	FibHeapNode *getRoot()
	{
		return minNode;
	}

	FibHeap()
	{
		minNode=NULL;
		nodecount=0;
	}
	void InsertNode(FibHeapNode*);
	FibHeapNode* removeMin();
	FibHeapNode *CreateHeapNode(int ,int );
	void decreaseKey(FibHeapNode *,int  );
	void pairwiseCombine();
	void cascadeCut(FibHeapNode*);
	void cutNode(FibHeapNode *,FibHeapNode *);
	void JoinFibHeap(FibHeapNode *,FibHeapNode *);


};
void AddInList(FibHeapNode **,FibHeapNode**);
#endif
