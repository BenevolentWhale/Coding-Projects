using System;
using System.Collections.Generic;

namespace _PA5
{
    public class Kruskal : Graph
    {
        public Kruskal(String filePath, GraphType type) : base(filePath, type)
        {
        }

        private void sort()
        {
            edgeList.Sort();
        }

        public List<Edge> runKruskal()
        {
            sort();
            UnionFind objUF = new UnionFind(numVertices);
            List<Edge> edges = new List<Edge>();
            int numEdgesAdded = 0;

            for (int i = 0; i < edgeList.Count; i++)
            {
                int src = edgeList[i].src;
                int dest = edgeList[i].dest;
                if (objUF.find(src) != objUF.find(dest))
                {
                    objUF.doUnion(src, dest);
                    edges.Add(edgeList[i]);
                    numEdgesAdded++;
                    if (numEdgesAdded == numVertices-1)
                    {
                        
                        break;
                    }
                }
            }

            return edges;
        }
    }
}
