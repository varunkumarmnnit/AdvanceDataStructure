#include"Fibonacciheap.h"
/*


Wrapper function add any Fib Node in the circular Link List 
*/
void AddInList(FibHeapNode ** frst,FibHeapNode **scnd)
{
	(*frst)->left->right=(*scnd);
	(*scnd)->left=(*frst)->left;
	(*scnd)->right=(*frst);
	(*frst)->left=(*scnd);
	(*scnd)->parent=NULL;
	(*scnd)->ChildCut=false;  //Initial chilCut value is set to be false 
}
/*

This function inserts the created FibNode into the FibHeap in the top circular doubly linked list  .

*/

void FibHeap::InsertNode(FibHeapNode *node)
{
	if(minNode)  
	{
		AddInList( &minNode,&node);
		if(node->weight<minNode->weight)
			minNode=node;

	}
	else
	{
		minNode=node;//This is for the first time insertion in the FibHeap 

	}
	nodecount++;  //After insertion of node the nodecount value should be increased 
}

/*

This creates the FibHeapNode with the given input values  

*/
FibHeapNode *FibHeap::CreateHeapNode(int v,int data)
{
	FibHeapNode *tmp=new FibHeapNode;
	tmp->degree=0;
	tmp->weight=data;
	tmp->vertxId=v;
	tmp->parent=NULL;
	tmp->child=NULL;
	tmp->left=tmp;
	tmp->right=tmp;
	tmp->ChildCut=false;
	return tmp;
}

/*

 This Function extract Minimum node from Fibonacci Heap 
    When minimum node is removed from Fibonacci Heap, Pointer 
	    remaining in list are updated but pointers in extracted 
		    node left unchanged.Also use pairwise_combine procdure 
			    for paiwise combining of Min Tree of same degree


*/
FibHeapNode *FibHeap::removeMin()
{
	FibHeapNode *tmpmin=minNode;//Saving Pointer tmpmin to minimum node in Fibonacci Heap
	if(!nodecount)
	{

		cout<<"No elements present.Hence remove min cant be performed"<<endl;

		return NULL ;
	}
	if(nodecount==1)  //If there is only one node in the FibHeap
	{

		minNode=NULL;
		nodecount--;   //decreasing the node count value 
		return tmpmin;

	}
	else
	{
		FibHeapNode *first=minNode->child;
		if(first!=NULL){

           /* For the Minimum Node of the tree add all the children into the root list */
			FibHeapNode *scnd=first->right;
			while((first!=scnd)&&(first!=NULL))
			{
				FibHeapNode *tmp=scnd;
				scnd=scnd->right;
				AddInList(&minNode,&tmp);


			}
			AddInList(&minNode,&first);}
		tmpmin->left->right=tmpmin->right;
		tmpmin->right->left=tmpmin->left;
		minNode=tmpmin->right;
		pairwiseCombine();//Call pairwise combine after all the children of the node which is removed is aded in the main circular list 
		nodecount--;//Node count is decreased
		return tmpmin;//Minimum FibHeap Node is returned 

	};
}

/*
 pairwise combining repeatdley merge the node of the same degree until
     all the Min tree in Fibonacci Heap has a distinct degree 

*/
void FibHeap::pairwiseCombine()
{
	vector<FibHeapNode *>degreeList(DEGREE_LMT,NULL);
	FibHeapNode *start=minNode;
	FibHeapNode  *it=minNode;
	//  For each root list node look for others node of  of the same degree.
	do
	{
		FibHeapNode *x=it;
		int d=x->degree;
		it=it->right;
		while(degreeList[d]!=NULL)
		{
			FibHeapNode *y=degreeList[d];
			/* Make Node y child of node x , as x is the node which contain smaller value */
			if(x->weight>y->weight)
			{
				FibHeapNode *tmp=x;
				x=y;
				y=tmp;
			}

                    // If we wrapped around we need to check for this case.
			if(y==it)
				it=it->right;
            // Because removeMin() arbitrarily assigned the min
			                    // reference, we have to ensure we do not miss the
								                    // end of the root node list.)
			if(y==start)
				start=start->right;
			JoinFibHeap(y,x);

			degreeList[d]=NULL;
			d++;
		}
		degreeList[d]=x; /* Save the MinFibnode in tha array,if later we found node with same Degree
		               we again need it to combine it */
	}while(it!=start);

	minNode=NULL;
	/* Now in the array we have all the Min tree with distict degree now by using these we would
	           construct New fibonacci heap */
	for(int i=0;i<DEGREE_LMT;i++)
	{
		if(degreeList[i]!=NULL)
		{
			degreeList[i]->right=degreeList[i];
			degreeList[i]->left=degreeList[i];
			if (minNode==NULL)
			{
				minNode=degreeList[i];
			}
			else
			{
				AddInList(&minNode,&degreeList[i]);
				if(minNode->weight>degreeList[i]->weight)
					minNode=degreeList[i];
			}
		}
	}
}
void FibHeap::JoinFibHeap(FibHeapNode *y,FibHeapNode *x)
{

	/*Remove y from the root list of Fibonacci Heap */
	y->left->right=y->right;
	y->right->left=y->left;
	y->parent=x;
	if(x->child!=NULL)  //If x has child node then we have add y in the x child circular list 
	{

		y->right=x->child;
		y->left=x->child->left;
		x->child->left->right=y;
		x->child->left=y;
	}
	else
	{

		y->right=y;
		y->left=y;
	}

	x->child=y;
	x->degree++; //Since y has been added in child  hence degree of x will increase 
	y->ChildCut=false;//Put ChildCut value to be false

}
/* This function decrease the value of fibonacci node x to value k */
void FibHeap::decreaseKey(FibHeapNode *node,int key)
{
	if(!node||!minNode||node->weight<key)//if node weight whose key to changed is already less than key then we wont perform decrease key operation 
	{
		cout<<"Decrease key operation could not be performed successfully "<<endl;
		return ;
	}
	else
	{
		node->weight=key;/* Assign new weight to node */
		FibHeapNode *parent=node->parent;
		/*If Heap order is violated call funtion cut and cascade_cut */
		if(parent!=NULL&&(parent->weight>node->weight))
		{
			cutNode(parent,node);
			cascadeCut(parent);
		}
		if(node->weight<minNode->weight)
		{
			minNode=node;

		}

	}

}
/* Remove c from the child list of p and then decrease 
    degree of p*/


void FibHeap::cutNode(FibHeapNode *p,FibHeapNode *c)
{

	/* if c is only child ,make child of p is NULL */
	if(c->right==c)
	{
		p->child=NULL;
		AddInList(&minNode,&c);
	}
	else
	{
		c->left->right=c->right;
		c->right->left=c->left;
		if(p->child==c)
			p->child=c->right;
		AddInList(&minNode,&c);/* Add c into the root List */
		p->degree=p->degree-1; /* Update the degree of the node p */
	}

}
/*
Parameter – It take 1 MinFibnode and do cascading.
If y is a root list no more cascading required, for y to be in root list it parent would
be NULL.
If child cut happens first time no more cut and cascading required
Just mark the node to indicate child cut is true
If y is marked y is just lost the second child, y is cut from here and added to the
root list and cascading cut is called to the parent of the node



*/
void FibHeap::cascadeCut(FibHeapNode *node)
{
	FibHeapNode *parent=node->parent;
	/* If parent  is a root list  no more cascading required */


	if(parent !=NULL)
	{
		/* If childcut happens first time no more cut and cascading required
		           just mark the node to indicate childcut is true */
		if(!node->ChildCut)
		{
			node->ChildCut=true;
		}

		/* if parent  is marked parent  is just lost the second child , parent  is cut from here 
		           and added to the root list and cascading cut is called to the parent 
				              of the node */
		else{
			cutNode(parent,node);
			cascadeCut(parent);
		}
	}


}

