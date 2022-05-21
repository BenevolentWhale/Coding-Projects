using System;
namespace _PA5
{
    public class UnionFind
    {

        LinkedList[] representatives;

        public UnionFind(int initialNumSets)
        {
            representatives = new LinkedList[initialNumSets];
            for (int x = 0; x < initialNumSets; x++)
                makeSet(x);
        }

        public void makeSet(int x)
        { 
           LinkedList LL = new LinkedList();
            LL.insertAtEnd(x);
            representatives[x] = LL;
        }

        public LinkedList find(int x)
        {
            return representatives[x];
        }

        private void append(LinkedList arg1, LinkedList arg2)
        {
            arg1.tail.next = arg2.head;
            arg1.tail = arg2.tail;
            arg1.size += arg2.size;
            ListNode tmp = arg2.head;
            for (int i = 0; i < arg2.size; i++)
            {
                representatives[tmp.value] = arg1;
                tmp = tmp.next;
            }
            arg2.head = null;
            arg2.tail = null;
        }

        public void doUnion(int x, int y)
        {
            LinkedList LLx = find(x);
            LinkedList LLy = find(y);
           if(LLx != LLy)
            {
                if (LLx.size >= LLy.size)
                {
                    append(LLx, LLy);
                }
                else
                {
                    append(LLy, LLx);
                }
            }
        }
    }
}
