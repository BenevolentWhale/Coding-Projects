#include <climits>
#include <iostream>
#include "Graph.h"
using namespace std;

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

class Dijkstra: public Graph {

private:
	bool *closed;

public:
	int *distance, *parent;

	Dijkstra(string &filePath) {

		readWeightedGraph(filePath);
		distance = new int[numVertices];
		parent = new int[numVertices];
		closed = new bool[numVertices];
	}

	~Dijkstra() {
		delete[] distance;
		delete[] parent;
		delete[] closed;
	}

	void executeDijkstra(int source) {
		for (int i = 0; i < numVertices; i++)
		{
			distance[i] = INT_MAX;
			parent[i] = -1;
			closed[i] = false;
		}
		distance[source] = 0;
		int numOpen = 1;
		while (numOpen >0)
		{
			int minDist = INT_MAX;
			int minVertex = -1;
			for (int i = 0; i < numVertices; i++)
			{
				if (closed[i]==false && distance[i] < minDist)
				{
					minDist = distance[i];
					minVertex = i;
				}
			}
			closed[minVertex] = true;
			numOpen--;
			for (int i = 0; i < outDegree[minVertex]; i++)
			{
				Edge& adjEdge = adjList.at(minVertex).at(i);
				//adjEdge.dest = adjVertex;
				int adjVertex = adjEdge.dest;
				if (closed[adjVertex]==false)
				{
					int newDist = distance[minVertex] + adjEdge.weight;
					if (distance[adjVertex]==INT_MAX)
					{
						numOpen++;
					}
					if (newDist<distance[adjVertex])
					{
						distance[adjVertex] = newDist;
						parent[adjVertex] = minVertex;
					}
				}
			}
		}
	}

	void printDistanceArray() {
		cout << "[";
		for (int i = 0; i < numVertices - 1; i++) {
			if (distance[i] == INT_MAX)
				cout << "infty, ";
			else
				cout << distance[i] << ", ";
		}
		if (distance[numVertices - 1] == INT_MAX)
			cout << "infty]";
		else
			cout << distance[numVertices - 1] << "]";
	}

	void printParentArray() {
		cout << "[";
		for (int i = 0; i < numVertices - 1; i++) {
			cout << parent[i] << ", ";
		}
		cout << parent[numVertices - 1] << "]";
	}
};

#endif

