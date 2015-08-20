#ifndef _H_ROUTNG_
#define _H_ROUTNG_
#include "Graph.h"
#include "Trie.h"
#include "DijFib.h"
#include<string>
#include<vector>
using namespace std;
/*
typedef struct Trie_Result
{
string IpPrefix;
int nextHop;
}TrieResult;
*/
void routing_table(Graph *,int ,int);

#endif
