#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

// function prototypes for functions given

BTNode * recTreeSearch (BTNode * root, string key);
BTNode * treeMinimum (BTNode * root);
BTNode * treeMaximum (BTNode * root);
BTNode * inOrderSuccessor (BTNode * node);

// function prototypes for Assignment 2

BTNode * ceiling (BTNode * root, string key);
BTNode * deleteNode (BTNode * root, string key);
BTNode * floor (BTNode * root, string key);
BTNode * inOrderPredecessor (BTNode * node);
BTNode * insert (BTNode * root, string key);

#endif
