

#ifndef STACKANDQUEUE_QUEUE_H_
#define STACKANDQUEUE_QUEUE_H_

#include <iostream>
#include <climits>
using namespace std;

class Queue {
    
    private:
    
    int maxQueueSize, front, rear, currentSize;
    int *queue;
    
    public:
    Queue(int maxQueueSize) {
        if (maxQueueSize <= 0)
        cout << "Queue size should be a positive integer.";
        else {
            this->maxQueueSize = maxQueueSize;
            front = rear = 0;
            currentSize = 0;
            queue = new int[maxQueueSize];
        }
    }
    
    ~Queue() {
        delete queue;
    }
    
    void enqueue(int val) { // complete this function
		if (currentSize == maxQueueSize) {
			cout << "Queue is full";
		} else {
				queue[rear] = val;
				rear++;
				currentSize++;
			}
		if(rear == maxQueueSize)
			{
			rear = 0;
			}
    }
    
    int dequeue() { // complete this function
		if (currentSize == 0) {
			cout << "Queue is empty";
			return -1;
		}
		else {
			int removedItem = queue[front];
			front++;
			currentSize--;
			if (front == maxQueueSize)
			{
				front = 0;
			}
			return removedItem;
		}
    }
    
    int getSize() {// complete this function
		return currentSize;
    }
    
    void print() {
        if (getSize() == 0)
        cout << "[]";
        else {
            cout << "[";
            if (rear > front) {
                for (long i = front; i < rear - 1; i++)
                cout << queue[i] << ", ";
                cout << queue[rear - 1] << "]";
            } else {
                for (long i = front; i < maxQueueSize - 1; i++)
                cout << queue[i] << ", ";
                cout << queue[maxQueueSize - 1];
                
                for (long i = 0; i < rear; i++)
                cout << ", " << queue[i];
                cout << "]";
            }
        }
    }
};

#endif /* STACKANDQUEUE_QUEUE_H_ */


