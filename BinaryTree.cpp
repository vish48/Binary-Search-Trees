//Added function levelWidth in BinaryTree.h 

#include <iostream>
#include <cstdlib>

#include "NodeTypes.h"
#include "BinaryTree.h"
#include "Stack.h"
#include "Queue.h"


using namespace std;

// write code for Assignment 2 functions here


BTNode * createBTNode (BTNode * parent, string data) 
{
	BTNode * newnode;				//creating new node
	newnode= new BTNode;
	
	newnode->data=data;						//inputting data
	newnode->count=1;
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->parent=parent;
	
	return newnode;					//return new binary tree node
}



int height(BTNode * root) 
{
	if (root == NULL)  			//null root means empty tree so no height
        return 0;  
    else
    {  
        int lefth = height(root->left);  			//getting height of left side of tree recursively
        int righth = height(root->right);  			//getting height of right side of tree recursively
      
        if (lefth > righth)  					//returning the greater value + 1 to account for root
            return(lefth + 1);  
        else 
			return(righth + 1);  
    }  
}


bool isEmptyTree(BTNode * root) 
{
	if(root==NULL)				//null root means empty tree
		return true;
	return false;
}

bool isEqual(BTNode * root1, BTNode * root2) 
{
    if (root1 == NULL && root2 == NULL)  	//2 empty trees are equal
        return true;  

    if (root1 == NULL && root2!=NULL) //if one is empty and other is not then not equal
		return false; 
    if (root2 == NULL && root1!=NULL) 
		return false; 
	
	else
	{
		if( (root1->data==root2->data) && isEqual(root1->left,root2->left) && isEqual(root1->right, root2->right) )
			return true;
		else
			return false;
	}
}

void preOrder (BTNode * root) 
{
	Stack *s=initStack();
	BTNode * curr = root;
	bool end=false;
	
	while(!end)				//while true
	{
		while(curr!= NULL)
		{
			cout<< curr->data<<"  ";			//print data, push on stack and assign curr to left of node
			push(s,curr);
			curr=curr->left;
		}
		if(isEmptyStack(s))					//if empty change end to true to exit outer while loop
			end=true;
		else								//if not empty pop from stack and assign curr to right of node
		{
			curr=pop(s);
			curr=curr->right;
		}
	}
}

int weight(BTNode * root) 
{
	if(root == NULL) 			//empty tree so no leaves     
        return 0;  
    if(root->left == NULL && root->right == NULL)  //is node has no children then it is a leaf so return 1
        return 1;          
    else
        return weight(root->left)+ weight(root->right); 		//return weight of left and right child of node
}

int levelWidth(BTNode* root, int level) 
{ 
    if (root == NULL) 	//empty tree, no width
        return 0; 
  
    if (level == 1) 	//1st level is root so width is 1
        return 1; 
  
    else 			//if it's not root level then call function recursively for left and right of root at the level before
	{
		if (level > 1) 
        	return levelWidth(root->left, level - 1) + levelWidth(root->right, level - 1); 
	}
} 
  

int width(BTNode * root) 
{	
    int max= 0, w=0, x=0,h=0;
	h=height(root); 
  
    for (x = 1; x <= h; x++) 	//from root to the height or number of levels in binary tree
	{ 
        w= levelWidth(root, x); 		//getting width for the xth level of tree	
        if (w> max) 			//if it's greater than the current max width then it becomes the new max width of tree
            max=w; 
    } 
    return max; 				//returning max width of tree
}

// functions you are provided with

int moment (BTNode * root) {

	if (root == NULL)
		return 0;
		
	return (1 + moment (root->left) + moment (root->right));
}


void inOrder (BTNode * root) {

	Stack * s = initStack ();
	
	BTNode * curr;
	bool finished;
	
	curr = root;
	finished = false;
	
	while (!(finished)) {
		while (curr != NULL) {
			push (s, curr);
			curr = curr->left;
		}
		if (isEmptyStack(s))
			finished = true;
		else {
			curr = pop (s);
			cout << curr->data << " ";
			curr = curr->right;
		}
	}

}

void levelOrder (BTNode * root) {
	
	Queue * q;
	BTNode * temp;
	
	if (root == NULL)
		return;
		
	q = initQueue();
	enqueue(q, root);
	
	while (!isEmptyQueue (q)) {
		temp = dequeue(q);
		cout << temp->data << " ";

		if (temp->left != NULL)
			enqueue(q, temp->left);

		if (temp->right != NULL)
			enqueue(q, temp->right);			
	}
}

