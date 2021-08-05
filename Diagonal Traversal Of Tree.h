// C++ program to check if all leaves 
// are at same level 
#include <bits/stdc++.h> 
using namespace std; 

// A binary tree node 
struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

// A utility function to allocate 
// a new tree node 
struct Node* newNode(int data) 
{ 
	struct Node* node = (struct Node*) malloc(sizeof(struct Node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return node; 
} 

/* Recursive function which checks whether 
all leaves are at same level */
int level(Node *head, Node *node, int lev)
{
	if (head == NULL)
	return 0;
	if (head == node)
	return lev;
	int l = level(head, node->left, lev+1);
	if (l!=0)
	return l;
	return level(head, node->right, lev+1);
}

bool checkLeaflevel(Node *head)
{
	
	Node *temp = head;
	static stack <int> st;
	if (temp == NULL)
		return true;
	else if(temp->left == NULL && temp->right == NULL)
		if (st.empty())
			st.push(level(head, temp, 1));
		else
		{
			if (st.top() == level(head, temp, 1))
				return true;
			else
				return false;
		}
	else if(temp->left == NULL)
		return checkLeaflevel(temp->right);
	else if(temp->right == NULL)
		return checkLeaflevel(temp->left);
	else
		return (checkLeaflevel(temp->left) && checkLeaflevel(temp->right));
}
// Driver Code 
int main() 
{ 
	// Let us create tree shown in third example 
	struct Node *root = newNode(12); 
	root->left = newNode(5); 
	root->left->left = newNode(3); 
	root->left->right = newNode(9); 
	root->left->left->left = newNode(1); 
	root->left->right->left = newNode(1); 
	if (checkLeaflevel(root)) 
		cout << "Leaves are at same level\n"; 
	else
		cout << "Leaves are not at same level\n"; 
	getchar(); 
	return 0; 
} 

// This code is contributed 
// by Akanksha Rai 

