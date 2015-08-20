
#ifndef _TRIE_H_
#define _TRIE_H_

//#include <stdlib.h>
#include <string>
using namespace std;

typedef struct BranchNode {
	BranchNode *l, *r;
	BranchNode() {
		l = r =  NULL;
	}
}BNode;
typedef struct TrieNodeTag : public BNode
{
	string key; //Contains Ip address of the node
	int data; //Contains the vertex id of the next Hop from the source vertex 
	TrieNodeTag();//Constructor of this structure 
//Creates of TrieNode Element with Ip and vertex number .
	TrieNodeTag(string dIp, int nextNode) {
		key = dIp;
		data = nextNode;
	}

}TNode;

typedef struct Trie_Result {
	string IpPrefix;
	int nextHop;
}TrieResult;

class Trie {
private :
	BNode *head;//Contains the root pointer of the trie 
public :
	Trie();
	void InsertPair(string destIp, int nextNode);
	TrieResult Search(string destIp);
	BNode* Optimize(BNode *p);
	void OptimizePath();

};
#endif /* TRIE_H_ */
