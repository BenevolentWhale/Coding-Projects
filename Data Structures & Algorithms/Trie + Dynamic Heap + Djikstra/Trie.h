#include <iostream>
#include <string>
#include "TrieNode.h"
using namespace std;

#ifndef TRIE_H_
#define TRIE_H_

class Trie {

	TrieNode *root;

public:

	Trie() {
		root = new TrieNode();
	}

	void insert(string &str) {
		TrieNode* tmp = root;
		for (size_t i = 0; i < str.length(); i++)
		{
			char c = str.at(i);
			if (tmp->getChild(c) != NULL)
			{
				tmp = tmp->getChild(c);
			}
			else
			{
				while (i < str.length())
				{
					tmp = tmp->insertChild(str.at(i));
					i++;
				}
			}

		}
	}

	bool match(string &str) {
		TrieNode* tmp = root;
		for (size_t i = 0; i < str.length(); i++)
		{
			char c = str.at(i);
			if (tmp->getChild(c) == NULL) {
				return false;
			}
			else
			{
				tmp = tmp->getChild(c);
			}
		}
		return true;
	}
};

#endif /* TRIE_H_ */
