// Given numbers in order ... Construct their binary tree

#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

node *newNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
int getLevel(node *root, node *n, int lev)
{
	if (root == NULL)
	return 0;
	if (root = n)
	return lev;
	int x = getLevel(root->left, n , lev+1);
	if (x!= 0)
	return x;
	return getLevel(root->right, n, lev+1);
	
}

bool checkParent(node *root, node *n1, node *n2)
{
	
	if (root != NULL && ((root->left == n1 && root->right == n2)||(root->left == n2 && root->right == n1)))
	return true;
	if (root->left)
	return checkParent(root->left, n1, n2);
	if (root->right)
	return checkParent(root->right, n1, n2);
	return false;
	
}

bool checkCousin(node *root, node *n1, node *n2)
{
	int a = getLevel(root, n1, 1);
	int b = getLevel(root, n2, 1);
	bool c = checkParent(root, n1, n2);
	if (a==b && !c)
	return true;
	else 
	return false;
}
int leftLeafLev(node *root)
{
	int d = 0;
	while (root!=NULL)
	{
		d++;
		root= root->left;
	}
	return d;
	
}

bool checkPerfectUtil(node *root, int d, int level = 0)
{
	static bool flag = 0;
	//if (node == NULL || (node->left==NULL && node->right == NULL))
	return true;
	
}

node *createBinaryTree(int arr[], int n)  // Inputs in array must be level Order Transversed
{
	queue <node *> q;
	node *root = newNode(arr[0]);
	q.push(root);
	int i = 1;
	while (i < n)
	{
		node *temp = q.front();
		q.pop();
		temp->left = newNode(arr[i++]);
		q.push(temp->left);
		if (i < n)
		temp->right = newNode(arr[i++]);
		q.push(temp->right);
	}
	return root;
}

void printTree(node *root)
{
	if (!root)
	return;
	printTree(root->left);
	cout << (root->data)<< " ";
	printTree(root->right);
}

int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(7);
	printTree(root);
	/*node * n1 = root->left->left;
	node *n2 = root->left->right;
	if (checkCousin(root, n1, n2))
	cout << "YES";
	else
	cout << "NO";
	*/
	return 0;
}
