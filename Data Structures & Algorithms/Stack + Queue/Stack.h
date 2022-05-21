

#ifndef STACKANDQUEUE_STACK_H_
#define STACKANDQUEUE_STACK_H_

#include <iostream>
#include <climits>
using namespace std;

class Stack {

    private:
    int maxStackSize, topOfStack;
    int *stack;

    public:

    Stack(int maxStackSize) {
        if (maxStackSize <= 0)
        cout << "Stack size should be a positive integer.";
        else {
            this->maxStackSize = maxStackSize;
            topOfStack = -1;
            stack = new int[maxStackSize];
        }
    }

    ~Stack() {
        delete stack;
    }
    
    void push(int val) { // complete this function
      if (topOfStack < maxStackSize-1) {
		  topOfStack++;
		  stack[topOfStack] = val;
		
      } else  {
        cout << "Stack is full";
      }
    }

    int pop() { // complete this function
		if (topOfStack > -1)
		{
			int returnVal = stack[topOfStack];
			topOfStack--;
			return returnVal;
		}
		else { 
			cout << "stack is empty";
			return -1;
		}
		
    }

    int getSize() { // complete this function;
      return (topOfStack+1);
    }
};

#endif /* STACKANDQUEUE_STACK_H_ */
