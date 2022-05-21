#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Edge.h"
using namespace std;

#ifndef GRAPH_H_
#define GRAPH_H_

class Graph {

public:

	int numVertices;
	int numEdges;
	int *outDegree;
	vector<vector<Edge> > adjList;

	Graph() {
		numVertices = 0;
		numEdges = 0;
		outDegree = nullptr;
	}

	~Graph() {
		delete[] outDegree;
	}

	void readWeightedGraph(string &filePath) {
		ifstream fileReader(filePath, ios::in);
		fileReader >> numVertices;
		fileReader >> numEdges;
		outDegree[numVertices];
		adjList.reserve(numEdges);
		for (int i = 0; i < numVertices; i++)
		{
			outDegree[i] = 0;
			adjList.resize(adjList.size()+1);
		}
		for (int i = 0; i < numEdges; i++)
		{
			int src, dest, weight;
			fileReader >> src;
			fileReader >> dest;
			fileReader >> weight;
			Edge e(src, dest, weight);
			adjList[src].push_back(e);
			outDegree[src]++;
		}
		fileReader.close();
	}
};

#endif /* GRAPH_H_ */
