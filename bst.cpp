//Added function levelWidth in BinaryTree.h 

#include <iostream>
#include <fstream>
#include <cstring>

#include "NodeTypes.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"

using namespace std;

void menu()
{
	cout<<endl<<endl<<endl<<"Binary Search Tree (BST) \n ---------------------------------------------- \n\n";
	cout<<"1. Create BST from File \n";
	cout<<"2. Add Word to BST \n";
	cout<<"3. Delete Word from BST \n";
	cout<<"4. Search for Word in BST \n";
	cout<<"5. Traverse BST \n";
	cout<<"6. What Comes Before Word in BST? \n";
	cout<<"7. What Comes After Word in BST? \n";
	cout<<"8. Compare BSTs \n";
	cout<<"9. Statistics \n";
	cout<<"Q. Quit \n";
	cout<<"\nPlease enter an option: ";
}

int main() 
{
  	// write code to generate menu and implement Options 1-9 and 'Q'.
	string choice, opt,word;
	bool created=false, equal;
	char fname[50],name[50],s[50],b[50];
	BTNode * root=NULL, *root1=NULL,*found=NULL, *pre=NULL, *suc=NULL, *smallest=NULL, *biggest=NULL;
	int w=0,h=0,wth=0,m=0,x=0;
	
	ifstream fin;	
	menu();
	cin>>choice;
	
	while(choice != "Q" && choice !="q")			//while user has not chosen to quit
	{
	
		if(choice== "1")							//if option 1 is selected
		{
			if (created==true)			//if BST already created
				cout<<"\nBST was previously created";
			else
			{		
				cout<<"\nPlease enter the name of the file or M (Menu): ";
				cin>>fname;
			
				if( (strcmp(fname,"M")==0) || (strcmp(fname,"m")==0) )				//go to menu
				{
					menu();
					cin>>choice;
				}
				
				else if(created==false && ((strcmp(fname,"M")==1) || (strcmp(fname,"m")==1)) )			//if BST doesn't exist, open file
				{
					fin.open(fname);
					if(!fin.is_open())
						cout<<"\n The file "<<fname<<" was not found.";
						
					else															//input values from file into BST and set created to true
					{
						created=true;
						while(!fin.eof())				//read from file and insert into BST
						{
							fin>>word;
							root=insert(root,word);
						}
					}
				}
				fin.close();				//close file
			}
			menu();
			cin>>choice;
		}//endif for option1
		
		if(choice=="2")
		{
			cout<<"\nPlease enter the word to insert in the BST or M (Menu): ";
			cin>>word;
			
			if (word=="M" || word=="m")				//go to menu
			{
				menu();
				cin>>choice;
			}
			else
			{
				root=insert(root,word);			//call insert function
			}
			menu();
			cin>>choice;
		}
		
		if(choice=="3")
		{
			cout<<"\nPlease enter the word to delete from the BST or M (Menu): ";
			cin>>word;
			
			if (word=="M" || word=="m")				//go to menu
			{
				menu();
				cin>>choice;
			}
			else
			{
				found=recTreeSearch(root,word);		//check if word exists
				if(found==NULL)
					cout<<"\n"<<word<<" doesn't exist to delete";
				else
					root=deleteNode(root,word);				//if it does call delete function
			}
			menu();
			cin>>choice;
		}
		
		if(choice=="4")
		{
			cout<<"\nPlease enter a word to search for or M (Menu): ";
			cin>>word;
			
				if (word=="M" || word=="m")				//go to menu
			{
				menu();
				cin>>choice;
			}
			else
			{
				found=recTreeSearch(root,word);							//check if word exists and display appropriate message
				if(found==NULL)
				{
					cout<<"\nSorry, "<<word<<" was not found in the BST";
				}
				else
				{
					cout<<"\n"<<word<<" has occurred "<<found->count<<" time(s) in the file";
				}
			}
			menu();
			cin>>choice;
		}
		
		if(choice=="5")				//call pre and inorder traversal functions
		{
			cout<<"\nPreorder Traversal: \n";
			preOrder(root);
			cout<<"\n\nInorder Traversal: \n";
			inOrder(root);
			cout<<endl;
			menu();
			cin>>choice;
		}
		
		if(choice=="6")						
		{
			cout<<"\nEnter word: ";
			cin>>word;
			found=recTreeSearch(root,word);					//check if word exists
				
			if(found==NULL)
			{
				cout<<"\nSorry, "<<word<<" does not exist in the BST";
			}
			else
			{
				//cout<<"PRE EXISTS";
				pre=inOrderPredecessor(found);			//if word exists, call predecessor function and output it
				if(pre==NULL)
					cout<<"\n"<<word<<" has no predecessor";
				else
					cout<<"\nThe predecessor of "<<word<<" is "<<pre->data;
			}
			menu();
			cin>>choice;
		}
		
		if(choice=="7")
		{
			cout<<"\nEnter word: ";
			cin>>word;
			found=recTreeSearch(root,word);					//checj if word exists
			
			if(found==NULL)
			{
				cout<<"\nSorry, "<<word<<" does not exist in the BST";
			}
			else
			{	
				suc=inOrderSuccessor(found);					//if word exists, call sucessor function and output it
				if(suc==NULL)
					cout<<"\n"<<word<<" has no successor";
				else
					cout<<"\nThe successor of "<<word<<" is "<<suc->data;
			}
			menu();
			cin>>choice;
		}
		
		if(choice=="8")
		{
			cout<<"\nPlease enter name of file to create BST or M (Menu): ";
			cin>>name;
			
			if( (strcmp(name,"M")==0) || (strcmp(name,"m")==0) )				//go to menu
			{
				menu();
				cin>>choice;
			}
			
			else 
			{
				fin.open(name);
				if(!fin.is_open())						//check if file is found
					cout<<"\n The file "<<name<<" was not found.";
					
				else														
				{
					while(!fin.eof())
					{
						fin>>word;								///read words from file and insert in BST referenced by another root
						//cout<<word<<endl;
						root1=insert(root1,word);
					}
					equal=isEqual(root,root1);				//call the equal function and display appropriate message
					if(equal==true)
						cout<<"\nThe two BSTs are equal.";
					else if(equal==false)
						cout<<"\nThe two BSTs are not equal.";
				}
			}
			fin.close();
			menu();
			cin>>choice;
		}
		
		if(choice=="9")
		{
			m=moment(root);												//call moment, height, widtth, weight. treeMin and treeMx functions
			cout<<"\n(1) Number of nodes in the tree: "<<m;
			
			h=height(root);
			cout<<"\n(2) Height of the tree: "<<h;
			
			wth=width(root);
			cout<<"\n(3) Width of the tree: "<<wth;
			
			w=weight(root);
			cout<<"\n(4) Weight of the tree: "<<w;
			
			smallest=treeMinimum(root);
			biggest=treeMaximum(root);
			
			strcpy(s,smallest->data.c_str());
			strcpy(b,biggest->data.c_str());
			
			x=strcmp(s,b);
			if(x==-1)
			{
				cout<<"\n(5) Smallest word and biggest word in tree in alphabetical order: "<<s<<" "<<b;
			}
			else
			{
				cout<<"\n(5) Smallest word and biggest word in tree in alphabetical order: "<<b<<" "<<s;
			}
			menu();
			cin>>choice;
		}
	}//endwhile
	
	cout<<"\nEnd of program";
	return 0;
}
