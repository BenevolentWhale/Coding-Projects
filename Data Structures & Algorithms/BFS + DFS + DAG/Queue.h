#include <iostream>
using namespace std;

#ifndef QUEUE_H_
#define QUEUE_H_

class Queue {

private:
	int maxQueueSize, front, currentSize;
	int *queue;

public:

	Queue(int maxQueueSize) {
		this->maxQueueSize = maxQueueSize;
		front = 0;
		currentSize = 0;
		queue = new int[maxQueueSize];
	}

	void enqueue(int val) {
		int rear = (front + currentSize) % maxQueueSize;
		queue[rear] = val;
		currentSize++;
	}

	int dequeue() {
		currentSize--;
		int x = queue[front++];
		if (front == maxQueueSize)
			front = 0;
		return x;
	}

	int size() {
		return currentSize;
	}
};

#endif /* QUEUE_H_ */
