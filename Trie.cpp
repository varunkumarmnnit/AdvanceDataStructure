
#include "Trie.h"
/*Wrapper function to check the given Bnode is last LeafNode or Not  */
bool isLeafNode(BNode *p) {
	
	if(p == NULL) return false;
	if((p->l == NULL)&& (p->r == NULL))
		return true;
	return false;
	
}

Trie :: Trie() {
	head = NULL;
}
/*


Parameter : Ip address of the destination vertex . Next Vertex  present in the shortest path to reach that destination .
This function insert the ip value ,next hop value pair in the binary trie

*/
void Trie :: InsertPair(string Ip, int nextHop) {

	if(head == NULL) {
		head = new TNode(Ip, nextHop);
		return;
	}

	BNode *TPtr = head; 
	BNode *Parent = NULL;
	int currLevel = 0; //This is the current branch level 
	int dBit; //This is the branch at which node bit value differes 

	while (1) {

		if(TPtr == NULL) {
			if(Ip[currLevel-1] == '0') {
				Parent->l = new TNode(Ip, nextHop);
			} else {
				Parent->r = new TNode(Ip, nextHop);
			}
			break;
		}
		if(TPtr->l == NULL && TPtr->r == NULL) {  //This is the case when we arrived at Leaf Node 
			string trieIp = ((TNode *)TPtr)->key;
			for(int ii = 0; ii < Ip.size(); ii++) {
				if(trieIp[ii] != Ip[ii]) {
					dBit = ii;
					break;
				}
			}
			if(dBit == Ip.size()) { //If the IP is already present we dont need to add anything 
				return;
			}

			if(Parent == NULL) {
				head = new BNode();
				Parent = head;
			} else {
				if(Ip[currLevel-1] == '0') {
					Parent->l = new BNode();  //If the last level bit value is 0 then we need to go left in the trie 
					Parent = Parent->l;
				} else {
					Parent->r = new BNode();
					Parent = Parent->r;//If the last level bit value is 1 then we need to go right in the trie 
				}
			}

			for(int ii = currLevel; ii < dBit; ii++) {
				if(Ip[ii] == '0') {
					Parent->l = new BNode();
					Parent = Parent->l;
				} else {
				 Parent->r = new BNode();
					Parent = Parent->r;
				}
			}

			if(Ip[dBit] == '0') {
				Parent->l = new TNode(Ip, nextHop);
				Parent->r = TPtr;
			} else {
				Parent->r = new TNode(Ip, nextHop);
				Parent->l = TPtr;
			}
			break;
		}

		if(Ip[currLevel] == '0') {
			Parent = TPtr;
			TPtr = TPtr->l;
			currLevel++;
		} else {
			Parent = TPtr;
			TPtr = TPtr->r;
			currLevel++;
		}
	}
}

/*
Parameter :Ip address of the destination node which is to be searched in the Trie 
This function searches the input Ip in the corresponding trie and update  the longest matched prefix IP in the TrieResult
*/

TrieResult Trie :: Search(string destIp) {
TrieResult res;
	string prefixIp = "";
	BNode *tPtr = head; 
	int currLevel = 0;

	while(1) {
		if(tPtr == NULL) break; 
		if(isLeafNode(tPtr)) {
			res.IpPrefix = prefixIp;
		
			res.nextHop = ((TNode *)tPtr)->data;
			break;
		}
		if(destIp[currLevel] == '0') {  //When the current level bit is 0 then we add 0 bit in the prefix result 
			prefixIp += '0';
			tPtr = tPtr->l;
			currLevel++;
		} else {
			prefixIp += '1'; //When the current level bit is 1 then we add 1 1 in the prefix result 
			tPtr = tPtr->r;
			currLevel++;
		}
	}
	return res;

}

void Trie :: OptimizePath() {
	head = Optimize(head);
}

/*

Parameter :Takes BNode pointer as an argument .For the first call the BNode is the head pointer of the corresponding Trie .This function optimizes the trie based on post order traversal of the Trie .It removes the subTries whose Next Hop is same for all destination .


*/

BNode* Trie :: Optimize(BNode* root) {
	if(root == NULL) return NULL;
	if(root->l == NULL && root->r == NULL) { 
		return root;
	}
	BNode *l = Optimize(root->l);
	BNode *r = Optimize(root->r);
    if(l == NULL || r== NULL) { 
		if(l == NULL) {
			if(isLeafNode(r)) {
				return r;
			}
		} else {
			if(isLeafNode(l)) {
				return l;
			}
		}
	}

	if(isLeafNode(l) && isLeafNode(r)) {
		int leftData = ((TNode*)l)->data;
		int rightData = ((TNode*)r)->data;
		if(leftData == rightData) {  //When we arrived at tha Leaf Node and both the leaf nodes have same Neaxt Hop then we do trie shrinking 


			return r;
		}
	}
	root->l = l;
	root->r = r;
	return root;
}

