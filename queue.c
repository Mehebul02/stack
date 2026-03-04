/*
CSE2111 Data Structures.
Queue implementation using Array.
Features include:
Enqueue (insert element at rear)
Dequeue(remove element from front)
Display(print queue)
Peek(returns the value of the front of the queue)

LIMITATION: This implementation has a limitation. When dequeuing
it does not shift the contents of the queue unless the last
element is dequeued.
*/

#include <stdio.h>
#define MAX 5 // Changing this value will change length of queue

int queue[MAX];
int front = -1, rear = -1;

//--------------------------------------
//Enqueue (insert element at rear)
//--------------------------------------
void enqueue(int num)
{
	if(rear == MAX-1)	//stack has no more space
	{
		printf("\n QUEUE OVERFLOW");
		return;
	}
	else if(front == -1 && rear == -1)	//stack is empty
		front = rear = 0;
	else
		rear++;	//move rear to insert element

	queue[rear] = num; //insert element at rear.

}


//--------------------------------------
//Dequeue (remove element from front)
//--------------------------------------
int dequeue()
{
	int val;
	if(front == -1 || front>rear)
	{
		printf("\n QUEUE IS EMPTY");
		return -1;
	}
	else
	{
		val = queue[front];
		front++;
		if(front > rear) //This occurs when the last element is removed from the queue and the front is increased
			front = rear = -1;
		return val;
	}
}

//--------------------------------------
//Return value of queue front
//--------------------------------------
int peek()
{
	if(front==-1 || front>rear)
	{
		printf("\n QUEUE IS EMPTY");
		return -1;
	}
	else
	{
		return queue[front];
	}
}

//------------------------------------------
//Print the entire stack from front to rear
//------------------------------------------
void display()
{
	int i;
	printf("\n");
	if(front == -1 || front > rear)
		printf("\n QUEUE IS EMPTY");
	else
	{
		printf("\n QUEUE: ");
		for(i = front;i <= rear;i++)
		printf("%d ", queue[i]);
	}
}

//--------------------------------------
//     MAIN FUNCTION
//--------------------------------------
int main()
{
	display();		//trying to print an empty queue
	enqueue(33);	//enqueuing 33
	enqueue(47);	//enqueuing 47
	enqueue(2);		//enqueuing 2
	enqueue(68);	//enqueuing 68
	display();		//print entire queue
	dequeue();		//dequeuing
	dequeue();		//dequeuing
	enqueue(55);	//enqueuing 55
	display();		//print entire queue

	return 0;
}
