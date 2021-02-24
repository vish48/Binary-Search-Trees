#include <iostream>

#include "NodeTypes.h"
#include "Stack.h"

using namespace std;

//Returns a pointer to a Stack Object
//Instantiates a Stack pointer variable s
Stack * initStack () {
	Stack * s = new Stack;
	s->top = NULL; //Sets top of the Stack to NULL
	return s;
}

//Returns either true or false
//Parameters: Stack * s
//if top of stack is pointing to a NULL value then it is empty
bool isEmptyStack (Stack * s) {
	if (s->top == NULL)
		return true;
	else
		return false;		
}

//Parameters: Stack * s, BTNode * data
//Creates a new Node variable to store data.
//Assigns the top of the stack to that variable 
void push (Stack * s, BTNode * data) {
	Node * newElement = new Node;
	newElement->data = data;
	newElement->next = s->top;
	s->top = newElement;
}

//Returns the value at the top of the stack
BTNode * pop (Stack * s) {
	if (isEmptyStack(s))
		return NULL; 				// to indicate error if popping from an empty stack
	
	Node * toRemove;
	BTNode * data;
	
	toRemove = s->top;
	data = toRemove->data;
	s->top = s->top->next;
	delete (toRemove);
	
	return data;
}
