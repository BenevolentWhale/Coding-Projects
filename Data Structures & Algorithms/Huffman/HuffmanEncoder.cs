using System;
using System.Collections;
namespace _PA2
{
    public class HuffmanEncoder
    {

        private char[] alphabet;
        private int[] frequencies;
        private int sigma;
        private int encodingLength, tableSize;
        private Hashtable charToEncodingMapping;

        public HuffmanEncoder(char[] alphabet, int[] frequencies, int sigma)
        {
            this.alphabet = alphabet;
            this.sigma = sigma;
            this.frequencies = frequencies;
            encodingLength = tableSize = 0;
            charToEncodingMapping = new Hashtable();
            encode();
        }

        private void encode()
        {   // complete this function
            BinaryTreeNode root = buildTree();
            createTable(root, "");
            for (int i = 0; i < sigma-1; i++)
            {
                char c = alphabet[i];
                string str = getEncoding(c);
                encodingLength = encodingLength + frequencies[i] * str.Length;
                tableSize = tableSize + str.Length + 8;
            }
        }

        private BinaryTreeNode buildTree()
        {   // complete this function
            PriorityQueue<BinaryTreeNode> PQ = new PriorityQueue<BinaryTreeNode>();
            for (int i = 0; i <  sigma-1;  i++)
            {
                BinaryTreeNode x = new BinaryTreeNode(alphabet[i], frequencies[i]);
                PQ.setPriority(x, frequencies[i]);
            }
            while (PQ.getSize() > 1)
            {
                BinaryTreeNode min = PQ.getMinimumItem();
                PQ.deleteMinimum();
                BinaryTreeNode secondMin = PQ.getMinimumItem();
                PQ.deleteMinimum();
               

                BinaryTreeNode y = new BinaryTreeNode('\0', (min.value + secondMin.value));

                min = y.left; secondMin = y.right;
                PQ.setPriority(y, y.value);
            }
            return PQ.getMinimumItem();
        }

        private void createTable(BinaryTreeNode node, String encoding)
        {   // complete this function
            if (node.left == null && node.right == null)
            {
                charToEncodingMapping.Add(node.character, encoding);
            }
            else
            {
                if (node.left != null)
                {
                    createTable(node.left, encoding + "0");
                }
                if (node.right != null)
                {
                    createTable(node.right, encoding + "1");
                }
            }
        }

        public string getEncoding(char c)
        {
            return charToEncodingMapping[c].ToString();
        }

        public int getSigma()
        {
            return sigma;
        }

        public int[] getFrequencies()
        {
            return frequencies;
        }

        public char[] getAlphabet()
        {
            return alphabet;
        }

        public int getTableSize()
        {
            return tableSize;
        }

        public int getEncodingLength()
        {
            return encodingLength;
        }
    }
}