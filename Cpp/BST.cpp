#include <iostream>
#include <vector>
using namespace std;

struct tree_node
{
	float value;
	tree_node *left;
	tree_node *right;
};
typedef struct tree_node node; 

node* createnewnode(float value)
{
	node* newnode = new (node);
	newnode->value = value;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

void printinorder(node* root)
{
	if(root == NULL)
	{
		return;
	}
	printinorder(root->left);
	cout<< root->value << endl;
	printinorder(root->right);
}

node* buildbinarytree(vector<float> elements)
{
	vector<float>::iterator iter;
	iter = elements.begin();

	node* root;
	root = createnewnode(*iter);
	iter++;/* skip first element */
	node* current;
	current = root;

	/* assign */
	
	while(iter != elements.end())
	{
		if(*iter > current->value)
		{
			if(current->right == NULL)
			{
				current->right = createnewnode(*iter);
				iter++;/* next element */
				current = root;/* insert from top */
				continue;
			}
			else
			{
				current = current->right;
				continue;
			}	
		}
		else if(*iter <= current->value)
		{
			if(current->left == NULL)
			{
				current->left = createnewnode(*iter);
				iter++;
				current = root;/* insert from top */
				continue;
			}
			else
			{
				current = current->left;
				continue;					
			}
		}	

	}

	return root;
}

void findelement(node* root,float value)
{

	if(value == root->value)
	{
		cout<<"Value Found"<<endl;
	}
	else if(value <= root->value)
	{
		findelement(root->left,value);
	}
	else if(value > root->value)
	{
		findelement(root->right,value);
	}
		
	
}

int main()
{
	cout << "Hello world" << endl;
	vector<float> elements = {5,3,6,2,4,1,7,8};//{5,4.2,2,6,3,7,4.6,5,9,4.1,0};
	node* root = buildbinarytree(elements);
	printinorder(root);
	findelement(root,4);
	return 0;
} 
