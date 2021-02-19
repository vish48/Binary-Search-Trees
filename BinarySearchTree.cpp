////Added function levelWidth in BinaryTree.h 

#include <iostream>
#include <cstdlib>

#include "NodeTypes.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"

using namespace std;

// write code for functions here 

BTNode * ceiling (BTNode * root, string key) 
{
    if (root->left == NULL && root->right == NULL   && root->data < key) //leaf node is smaller than key
        return NULL; 
  
    // if node value is greater than or equal to key and left of node is NULL or smaller then return the node value then return node
    if ( (root->data >= key && root->left == NULL)  || (root->data >= key && root->left->data < key) ) 
        return root; 
  
    if (root->data < key) 					 // if node value is smaller than key search the right subtree 
        return ceiling(root->right, key); 
    else									//search left subtree
        return ceiling(root->left, key); 
}


BTNode * deleteNode (BTNode * root, string key) 
{
	if (root == NULL) 		//empty tree
		return root; 
  
    if (key < root->data)   //if key is less than root, search left subtree
        root->left = deleteNode(root->left, key); 

    if (key > root->data) 	//if key is greater than root, search right subtree
        root->right = deleteNode(root->right, key); 
  
    else   //if node=key then delete this node
    { 
        if (root->left == NULL) 			//node with 1 or no child
        { 
            struct BTNode *temp = root->right; 
            free(root); 
            return temp; 
        }
		else
		{
	        if (root->right == NULL) 
	        { 
	            struct BTNode *temp = root->left; 
	            free(root); 
	            return temp; 
	        } 
	    }
  						
        BTNode* temp = treeMinimum(root->right); 		//node with 2 children, get inorder successor
        root->data = temp->data;    //put inorder successor content in node to delete
        root->right = deleteNode(root->right, temp->data);  //delete inorder sucessor node
    } 
    return root; 
}



BTNode * floor (BTNode * root, string key) 
{
	if (root == NULL) 	//empty tree
        return NULL; 
    
	if (root->data == key) //if root is equal to key, return root
        return root; 
  
    //if root is smaller than key, search right subtree
	if (root->data < key) 
	{ 
        BTNode* x = floor(root->right, key); 
       	if (x == NULL) 
           	return root; 
       	else
           	return x;
	}
  
    else 
	{
		if (root->data > key) 			//if root is greater than key, return left subtree value 
        	return floor(root->left, key);  
	}
}



BTNode * inOrderPredecessor (BTNode * node) 
{
	if(node==NULL)		
		return NULL;
	
	if(node->left != NULL)
	{
		return treeMaximum(node->left);					
	}
	else
	{
		BTNode *parent= node->parent;
		while(parent !=NULL && node==parent->left)
		{
			node=parent;
			parent=parent->parent;
		}
		return parent;
	}

}

BTNode *insert (BTNode * root, string key) 
{
	
	if (root == NULL)
	{
		root = createBTNode(NULL, key);
		return root;
	}
	
	BTNode *curr = root;
	BTNode *parent = new BTNode;
	parent = root;
	
	while (curr !=NULL)
	{
		
		if (key > curr->data)
			curr = curr->right;
		else if (key < curr->data)
			curr = curr->left;
		else
		{
			curr->count = curr->count + 1;
			return root;
		}
		
		if (curr != NULL)
			parent = curr;
	}
	
	if(key > parent->data)
		parent->right = createBTNode(parent, key);
	else
		parent->left = createBTNode(parent, key);
	
	return root;
}




BTNode * inOrderSuccessor (BTNode * node) 
{

	if (node == NULL)
		return NULL;
		
	if (node->right != NULL)
		return treeMinimum (node->right);
		
	BTNode * parent;
	parent = node->parent;
	
	while (parent != NULL && node == parent->right) 
	{
		node = parent;
		parent = parent->parent;
	}
	
	return parent;	
}



BTNode * recTreeSearch (BTNode * root, string key) {

	if (root == NULL)
		return NULL;
		
	if (root->data == key)
		return root;
		
	if (key < root->data)
		return (recTreeSearch (root->left, key));
	else
		return (recTreeSearch (root->right, key));
}



BTNode * treeMinimum (BTNode * root) {
	if (root == NULL)
		return NULL;
		
	while (root->left != NULL)
		root = root->left;
	
	return root;
}



BTNode * treeMaximum (BTNode * root) {
	if (root == NULL)
		return NULL;
		
	while (root->right != NULL)
		root = root->right;
	
	return root;
}
