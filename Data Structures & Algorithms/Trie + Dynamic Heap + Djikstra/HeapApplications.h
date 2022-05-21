#include <iostream>
#include <string>

#include "Heap.h"
using namespace std;

#ifndef HEAPAPPLICATIONS_H_
#define HEAPAPPLICATIONS_H_

class HeapApplications {

public:
    
    static void heapSort(string *array, int arrayLen) {
       Heap *h = new Heap();
        for (int i = 0; i < arrayLen; i++)
        {
           h->heapArray.push_back(array[i]);
        }
        for (int i = 0; i < arrayLen; i++)
        {
            array[i] = h->getMinimum();
            h->deleteMinimum();

        }
    }
    
	static string* topK(string *array, int arrayLen, int k) {
        if (k > arrayLen)
        {
            k = arrayLen;
        }
        Heap* h = new Heap();
        //insert elements into vector/array
        for (int i = 0; i < arrayLen; i++)
        {
           h->heapArray.push_back(array[i]);
        }
        for (int i = 0; i < arrayLen; i++)
        {
            string minString = h->getMinimum();
            if (minString == h->getMinimum())
            {
                h->deleteMinimum();
                h->heapArray.push_back(array[i]);
            }
        }
        string *topK = new string[k];
        unsigned int pos = 0;
        while (h->size() > 0)
        {
            topK[pos] = h->getMinimum();
            pos++;
            h->deleteMinimum();

        }
        return topK;
    }
};

#endif /* HEAPAPPLICATIONS_H_ */
