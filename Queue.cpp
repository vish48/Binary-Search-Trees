#include <iostream>

#include "NodeTypes.h"
#include "Queue.h"

using namespace std;

//Returns a pointer to a Queue Object
//Instantiates a Queue Object variable
Queue * initQueue () {
	Queue * q = new Queue;
	q->top = NULL;
	q->last = NULL;
	return q;
}

//Returns a boolean value, True or False if the Queue is Empty
//Parameters:
//* q -> a Queue pointer
bool isEmptyQueue (Queue * q) {
	if (q->top == NULL)
		return true;
	else
		return false;		
}

//Returns an integer, indicating the size of the Queue 
//Parameters:
//* q -> a Queue pointer
int sizeQueue (Queue * q) {

	Node * curr;
	int size;

	curr = q->top;	
	size = 0;
	
	while (curr != NULL) {
		curr = curr->next;
		size = size + 1;
	}
	
	return size;
}

//Adds a data to a Queue
//Parameters:
//Queue * q -> a pointer to a Queue
//BTNode * data -> a pointer to the data to add
void enqueue (Queue * q, BTNode * data) {
	Node * newElement = new Node;
	newElement->data = data;
	newElement->next = NULL;
	
	if (isEmptyQueue(q)) {
		q->top = newElement;
		q->last = newElement;
	}
	else {
		q->last->next = newElement;
		q->last = newElement;
	}
}

//Removes data from an existing Queue and returns the data
//Parameters:
//Queue * q -> a pointer to a Queue
BTNode * dequeue (Queue * q) {
	if (isEmptyQueue(q))
		return NULL; 				// to indicate error if dequeuing from an empty queue
	
	Node * toRemove;
	BTNode * data;
	
	toRemove = q->top;	//Assigns the top of the Queue to toRemove pointer
	data = toRemove->data;	//Assigns the data to remove to a temporary variable
	q->top = toRemove->next;
	if (q->top == NULL)
		q->last = NULL;
		
	delete (toRemove);
	
	return data;
}
