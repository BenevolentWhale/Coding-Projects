#include <iostream>
#include <unordered_map>
using namespace std;

#ifndef TRIENODE_H_
#define TRIENODE_H_

class TrieNode {

public:

	unordered_map<char, TrieNode *> edges;

	TrieNode() {
	}

	TrieNode *insertChild(char c) {
		TrieNode *child = new TrieNode();
		edges[c] = child;
		return child;
	}

	TrieNode *getChild(char c) {
		return edges[c];
	}
};



#endif /* TRIENODE_H_ */
