#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		int height;
		Node *left, *right;
		Node(int x)
		{
			data = x;
			height = 1;
			left = right = NULL;
		}
};

Node *minNode(Node *root)
{
	if (root->left == NULL)
	return root;
	return minNode(root->left);
}

int height(Node *root)
{
	if(root == NULL)
	return 0;
	return root->height;
}

int getbalance(Node *root)
{
	if (root == NULL)
	return 0;
	return height(root->left) - height(root->right);
}

Node *LL(Node *root)
{
	Node *temp = root->left->right;
	root->left->right = root;
	Node *newroot = root->left;
	root->left = temp;
	
	root->height = max(height(root->left), height(root->right))+1;
	newroot->height = max(height(newroot->left), height(newroot->right))+1;
	
	return newroot;
}

Node *RR(Node *root)
{
	Node *temp = root->right->left;
	root->right->left = root;
	Node *newroot = root->right;
	root->right = temp;
	
	root->height = max(height(root->left), height(root->right))+1;
	newroot->height = max(height(newroot->left), height(newroot->right))+1;
	
	return newroot;
}

Node *LR(Node *root)
{
	root->left = RR(root->left);
	return LL(root);
}

Node *RL(Node *root)
{
	root->right = LL(root->right);
	return RR(root);
}

Node *insert(Node *root, int key)
{
	if (root == NULL)
	return new Node(key);
	if (key < root->data)
	root->left = insert(root->left, key);
	else if (key > root->data)
	root->right = insert(root->right, key);
	else
	return root;
	
	root->height = max(height(root->left), height(root->right))+1;
	int balance = getbalance(root);
	
	if (balance > 1 && getbalance(root->left) == 1)		//LL rotation
	root = LL(root);
	else if (balance > 1 && getbalance(root->left) == -1)	//LR rotation
	root = LR(root);
	else if (balance < -1 && getbalance(root->right) == -1)		//RR rotate
	root = RR(root);
	else if (balance < -1 && getbalance(root->right) == 1)		//RL rotate
	root = RL(root);
	
	return root;
	 
}

void preOrder(Node *root)
{
	if (root == NULL)
	return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

Node *deleteKey(Node *root, int key)
{
	if (root == NULL)
	return root;
	if (key < root->data)
	root->left = deleteKey(root->left, key);
	else if (key > root->data)
	root->right = deleteKey(root->right, key);
	else										//Node found
	{
		if (root->left == NULL || root->right == NULL)
		{
			Node *temp = root->left?root->left:root->right;
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
			{
				*root = *temp;
			}
			delete(temp);
		}
		else
		{
			Node *temp = minNode(root->right);
			root->data = temp->data;
			root->right = deleteKey(root->right, temp->data);
		}
	}
	//Now balancing Part
	if (root == NULL)
	return root;
	
	root->height = max(height(root->left), height(root->right))+1;
	int balance = getbalance(root);
	
	if (balance > 1 && getbalance(root->left) >= 0)		//LL rotation
	root = LL(root);
	else if (balance > 1 && getbalance(root->left) < 0)	//LR rotation
	root = LR(root);
	else if (balance < -1 && getbalance(root->right) <= 0)		//RR rotate
	root = RR(root);
	else if (balance < -1 && getbalance(root->right) > 0)		//RL rotate
	root = RL(root);
	
	return root;
}

int main()
{
	Node *root = NULL;
	root = insert(root, 20);
	root = insert(root, 15); root = insert(root, 10); root = insert(root, 13); root = insert(root, 12);
	preOrder(root); cout << endl;
	root = deleteKey(root, 15);
	preOrder(root);
}
