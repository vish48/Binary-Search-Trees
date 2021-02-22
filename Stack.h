#ifndef _STACK_H
#define _STACK_H


//Struct and function prototypes for Stacks
struct Stack {
	Node * top;
};

Stack * initStack ();
bool isEmptyStack (Stack * s);
void push (Stack * s, BTNode * data);
BTNode * pop (Stack * s);

#endif
