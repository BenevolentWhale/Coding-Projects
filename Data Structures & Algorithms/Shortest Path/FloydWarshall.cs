using System;
namespace _PA4
{
	public class FloydWarshall : Graph
	{

		public FloydWarshall(Graph graph) : base(graph) { }

		public int[][] execute()
		{
			int[][] allPairMatrix = new int[numVertices][];
			for (int i = 0; i < numVertices; i++) {
				allPairMatrix[i] = new int[numVertices];
			}
			

			for (int i = 0; i < numVertices; i++)
			{
				for (int j = 0; j < adjList[i].Count; j++)
				{
						allPairMatrix[i][j] = Int32.MaxValue;

					//set major diagonal
					if (i==j)
					{
						allPairMatrix[i][j] = 0;
					}
				}
			}


			for (int i = 0; i < numVertices; i++)
			{
				for (int j = 0; j < adjList[i].Count; j++)
				{
					allPairMatrix[adjList[i][j].src][adjList[i][j].dest] =  adjList[i][j].weight;
					
				}
			}

			for (int k = 0; k < numVertices; k++)
			{
				for (int i = 0; i < numVertices; i++)
				{
					for (int j = 0; j < numVertices; j++)
					{
						if (allPairMatrix[i][k] == Int32.MaxValue || allPairMatrix[k][j] == Int32.MaxValue)
						{
							continue;
						}
							int tempDist = allPairMatrix[i][k] + allPairMatrix[k][j];
							if (allPairMatrix[i][j] > tempDist)
							{
								allPairMatrix[i][j] = tempDist;
							}
						
					}
				}
			}

			
			for (int i = 0; i < numVertices; i++)
			{
				for (int j = 0; j < adjList[i].Count; j++)
				{
					//major diagonal
					if (i == j && allPairMatrix[i][j] < 0)
					{
						return null;
					}				
				}
			}


			return allPairMatrix;

		}
	}
}
