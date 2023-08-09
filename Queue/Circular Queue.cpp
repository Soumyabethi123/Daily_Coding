#include <bits/stdc++.h> 
class CircularQueue{
    public:
    // Initialize your data structure.
        int *arr;
		int front;
		int rear;
		int size;

    CircularQueue(int s){
        // Write your code here.
        this->size=s;
		arr = new int[s];
		front=-1;
		rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int data){
        // Write your code here.
        if(front==0 && rear==size-1){
		
		    return 0;
	    }
	    else if(rear==front-1){
		
		    return 0;
	    }
	    else if(front==-1 && rear==-1){
		
		    front++;
		    rear++;
		    arr[front]=data;
	    }
	    else if(rear==size-1 && front>0){
		
		    rear=0;
		    arr[rear]=data;
	    }
	    else{
		
		    rear++;
		    arr[rear]=data;
	    }

        return 1;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(front==-1){
		
		return -1;
	}
	
	int ans=arr[front];
	arr[front]=-1;
	
	if(front==rear){
		
		arr[front]=-1;
		front=-1;
		rear=-1;
	}
	else if(front==size-1){
		
		front=0;
	}
	else{
		
		front++;
	}

    return ans;
    }
};
