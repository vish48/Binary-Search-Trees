#ifndef _BINARYTREE_H
#define _BINARYTREE_H

// function prototypes for functions given

int moment (BTNode * root);
void inOrder (BTNode * root);
void levelOrder (BTNode * root);

// function prototypes for Assignment 2

BTNode * createBTNode (BTNode * parent, string data);
int height(BTNode * root);
bool isEmptyTree(BTNode * root);
bool isEqual(BTNode * root1, BTNode * root2);
void preOrder (BTNode * root);
int weight(BTNode * root);
int width(BTNode * root);
int levelWidth(BTNode* root, int level); 

#endif
