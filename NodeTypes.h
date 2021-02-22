#ifndef _NODETYPES_H
#define _NODETYPES_H

#include <iostream>
using namespace std;

//Struct prototypes for Node Types
struct BTNode {
	string data;
	int count;
	BTNode * left;
	BTNode * right;
	BTNode * parent;
};

struct Node {
	BTNode * data;
	Node * next;	
};

#endif
