#include <iostream>
#include <climits>
#include "Graph.h"
#include "Queue.h"
using namespace std;

#ifndef BFS_H_
#define BFS_H_

class BFS: public Graph {

public:

	int *level;

	BFS(string fileName) {
		readUnweightedGraph(fileName);
		level = new int[numVertices];
	}

	~BFS() {
		delete[] level;
	}

	void executeBFS(int s) {
		for (int i = 0; i < numVertices; i++)
		{
			level[i] = INT_MAX;
		}

		Queue vertexQ(numVertices);
		vertexQ.enqueue(s);
		level[s] = 0;
		while (vertexQ.size()>0)
		{
			int v = vertexQ.dequeue();
			for (int i = 0; i < outDegree[v]; i++)
			{
				Edge& adjEdge = adjList.at(v).at(i);
				int w = adjEdge.dest;

				if (level[w] == INT_MAX)
				{
					level[w] = level[v] + 1;
					vertexQ.enqueue(w);
				}

			}
		}
	}
};

#endif /* BFS_H_ */
