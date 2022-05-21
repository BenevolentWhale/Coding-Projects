using System;
using System.Collections.Generic;

namespace _PA4
{
	public class Johnson : Graph
	{

		public Johnson(Graph graph) : base(graph) { }

		public int[][] execute()
		{
			adjList.Add(new List<Edge>());
			for (int i = 0; i < numVertices; i++)
			{
				Edge e = new Edge(numVertices, i, 0);
				adjList[numVertices].Add(e); ;
			}

			numEdges+= numVertices;
			numVertices++;

			BellmanFord bg = new BellmanFord(this);
			int[] phi = bg.execute(numVertices - 1);

			adjList.RemoveAt(numVertices-1);

			numVertices--;
			numEdges -= numVertices;

			if (phi == null)
			{
				return null;
			}

			for (int i = 0; i < numVertices; i++)
			{
				for (int j = 0; j < adjList[i].Count; j++)
				{
					adjList[i][j].weight += (phi[adjList[i][j].src] - phi[adjList[i][j].dest]);
				}
			}

			int[][] allPairMatrix = new int[numVertices][];
			for (int i = 0; i<numVertices; i++) {
				allPairMatrix[i] = new int[numVertices];
			}

			Dijkstra d = new Dijkstra(this);

			for (int i = 0; i < numVertices; i++)
			{
				allPairMatrix[i] = d.execute(i);
			}

			for (int i = 0; i < numVertices; i++)
			{
				for (int j = 0; j < numVertices; j++)
				{
					if (i!=j && allPairMatrix[i][j] != Int32.MaxValue)
					{
						allPairMatrix[i][j] = allPairMatrix[i][j] - phi[i] + phi[j];
					}
				}
			}

			for (int i = 0; i < numVertices; i++)
			{
				for (int j = 0; j < adjList[i].Count; j++)
				{
					adjList[i][j].weight = phi[i];
				}
			}

			//reverse
			for (int i = 0; i < numVertices; i++)
			{
				for (int j = 0; j < adjList[i].Count; j++)
				{
					adjList[i][j].weight -= (phi[adjList[i][j].src] - phi[adjList[i][j].dest]);
				}
			}



			return allPairMatrix;
		}
	}
}
