#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include "Queue.h"
#include "Graph.h"
using namespace std;

#ifndef DAG_H_
#define DAG_H_

class DAG: public Graph {

private:

	int *inDegree;

public:

	int *topoOrder;
	int *distance;

	DAG(string filePath) {
		readWeightedGraph(filePath);
		topoOrder = new int[numVertices];
		distance = new int[numVertices];
		inDegree = new int[numVertices];
	}

	~DAG() {
		delete[] inDegree;
		delete[] topoOrder;
		delete[] distance;
	}

	void longestPaths(int s) {
		for (int i = 0; i < numVertices; i++)
		{
			inDegree[i] = 0;
			distance[i] = INT_MIN;
		}

		for (int i = 0; i < numVertices; i++)
		{
			for (int j = 0; j < outDegree[i]; i++) 
			{
				Edge& adjEdge = adjList.at(i).at(j);
				inDegree[adjEdge.dest] ++;
			}
		}

		Queue vertexQ(numVertices);
		for (int i = 0; i < numVertices; i++)
		{
			if (inDegree[i] == 0) 
			{
				vertexQ.enqueue(i);
			}
		}

		distance[s] = 0;
		int topoLevel = 0;

		while (vertexQ.size() > 0)
		{
			int v = vertexQ.dequeue();
			topoOrder[topoLevel] = v;
			topoLevel++;
			for (int j = 0; j < outDegree[v]; j++)
			{
				Edge& adjEdge = adjList.at(v).at(j);
				int adjVertex = adjEdge.dest;
				inDegree[adjVertex] --;
				if (inDegree[adjVertex] == 0)
				{
					vertexQ.enqueue(adjVertex);
				}
				if (distance[v] != INT_MIN)
				{
					int len = distance[v] + adjEdge.weight;
					if (len>distance[adjVertex])
					{
						distance[adjVertex] = len;
					}
				}
			}
		}
	}
};

#endif /* DAG_H_ */
