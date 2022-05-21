

#ifndef STACKANDQUEUE_QUEUEUSINGSTACK_H_
#define STACKANDQUEUE_QUEUEUSINGSTACK_H_

#include <iostream>
#include <climits>
#include "Stack.h"

using namespace std;

class QueueUsingStack {
    
    Stack *mainStack;
    int maxQueueSize;
	
    
    public:
    QueueUsingStack(int maxQueueSize) {
        this->maxQueueSize = maxQueueSize;
        mainStack = new Stack(maxQueueSize);

    }
    
    ~QueueUsingStack() {
        delete mainStack;
    }
    
    void enqueue(int val) { // complete this function
	Stack *tempStack;
		tempStack = new Stack(maxQueueSize);
		int loopCount = mainStack->getSize();
		for (int i = 0; i <loopCount; i++)
		{
			tempStack->push(mainStack->pop());
		}
		mainStack->push(val);
		for (int i = 0; i < loopCount; i++)
		{
			mainStack->push(tempStack->pop());
		}
		}
	
    
    int dequeue() { // complete this function
		return mainStack->pop();
    }
    
    int getSize() { // complete this function
		return mainStack->getSize();
    }
    
    void print() {
        if (getSize() == 0)
        cout << "[]";
        else {
            cout << "[";
            int n = getSize();
            for (int i = 0; i < n - 1; i++) {
                int x = dequeue();
                cout << x << ", ";
                enqueue(x);
            }
            int x = dequeue();
            cout << x << "]";
            enqueue(x);
        }
    }
};
#endif /* STACKANDQUEUE_QUEUEUSINGSTACK_H_ */

