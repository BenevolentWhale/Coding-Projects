#include <iostream>
#include <climits>
#include "Graph.h"
#include "Queue.h"
using namespace std;

#ifndef DFS_H_
#define DFS_H_

class DFS: public Graph {

private:

	bool *closed;

public:

	int *level;

	DFS(string fileName) {
		readUnweightedGraph(fileName);
		level = new int[numVertices];
		closed = new bool[numVertices];
	}

	~DFS() {
		delete[] level;
		delete[] closed;
	}

	void executeDFS(int s) {
		for (int i = 0; i < numVertices; i++)
		{
			closed[i] = false;
			level[i] = INT_MAX;
		}
		level[s] = 0;
		helpDFS(s);
	}

private:

	void helpDFS(int v) {
		closed[v] = true;
		for (int i = 0; i < outDegree[v]; i++)
		{
			Edge& adjEdge = adjList.at(v).at(i);
			int w = adjEdge.dest;

			if (closed[w]==false)
			{
				level[w] = level[v] + 1;
				helpDFS(w);
			}

		}
	}
};

#endif /* DFS_H_ */
