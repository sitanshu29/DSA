// AVL Trees
#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node *left, *right;
};

Node *newNode(int item) 
{ 
    struct Node *temp =  new Node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

Node *LL(Node *root)
{
	Node *temp = root->left->right;
	root->left->right = root;
	Node *temp2 = root->left;
	root->left = NULL;
	temp2->right->left = temp;
	return temp2;
}

Node *RR(Node *root)
{
	Node *temp = root->right->left;
	root->right->left = root;
	Node *temp2 = root->right;
	root->right = NULL;
	temp2->left->right = temp;
	return temp2;
}


Node *LR(Node *root)
{
	root->left = RR(root->left);
	root = LL(root);
	return root;
}

Node *RL(Node *root)
{
	root->right = LL(root->right);
	root = RR(root);
	return root;
}

	

int height(Node *root)
{
	if (root == NULL)
		return 0;
	int l = height(root->left);
	int r = height(root->right);
	if (l> r)
		return l+1;
	else
		return r+1;
}

void modifyAVL(Node* (&root))
{
	if (root == NULL)
		return;
	modifyAVL(root->left);
	if ((height(root->left) - height(root->right) >= 2))
	{
		if (height(root->left->left) - height(root->left->right) >= 0)
			root = LL(root);
		else if (height(root->left->left) - height(root->left->right) <= -1)
			root = LR(root);
	}
	else if ((height(root->left) - height(root->right) <= -2))
	{
		if (height(root->right->left) - height(root->right->right) <= 0)
			root = RR(root);
		else if (height(root->right->left) - height(root->right->right) >= 1)
			root = RL(root);
	}
	modifyAVL(root->right);
}

void printInorder(Node *root) 
{ 
    if (root == NULL) return; 
  
    printInorder(root->left); 
    cout << root->data << " "; 
    printInorder(root->right); 
}

void printLevelOrder(Node *root) 
{ 
    // Base Case 
    if (root == NULL)  return; 
  
    // Create an empty queue for level order tarversal 
    queue<Node *> q; 
  
    // Enqueue Root and initialize height 
    q.push(root); 
  
    while (q.empty() == false) 
    { 
        // Print front of queue and remove it from queue 
        Node *node = q.front(); 
        cout << node->data << " "; 
        q.pop(); 
  
        /* Enqueue left child */
        if (node->left != NULL) 
            q.push(node->left); 
  
        /*Enqueue right child */
        if (node->right != NULL) 
            q.push(node->right); 
    } 
} 

int main() 
{ 
    Node *root = newNode(40); 
    root->left = newNode(20); 
    root->right = newNode(50); 
    root->left->left = newNode(10); 
    root->left->right = newNode(30); 
    root->right->right = newNode(60); 
    root->left->left->left = newNode(5); 
    root->left->right->left = newNode(25); 
	root->left->right->right = newNode(36);
	root->left->right->left->right = newNode(27);  
    cout << "Level Traversal of given tree\n"; 
    printLevelOrder(root); 
  
    modifyAVL(root); 
  
    cout << "\n\nLevel Traversal of transformed tree\n"; 
    printLevelOrder(root); 
  
    return 0; 
} 

