// K-DTree

#include <iostream>
using namespace std;
const int k =2;
class Node
{
	public:
	int data[k];
	Node *left, *right;
};

Node *newnode(int x[])
{
	Node *temp = new Node();
	for (int i =0; i < k; i++)
	temp->data[i] = x[i];
	temp->left = temp->right = NULL;
	return temp;
}

Node *insert(Node *root, int x[], int lev = 0)
{
		if (root == NULL)
		return newnode(x);
	if (root->data[lev%k] > x[lev%k])
		root->left = insert(root->left, x, lev+1);
	else
		root->right = insert(root->right, x, lev+1);
	return root;
}

bool isEqualArray(int a[], int b[])
{
	for (int i = 0; i < k ; i++)
	if (a[i] != b[i])
	return false;
	return true;
}

bool search(Node *root, int x[], int lev = 0)
{
	if (root == NULL)
		return 0;
	if (isEqualArray(root->data, x))
		return 1;
	else if (root->data[lev%k] > x[lev%k])
		return search(root->left, x, lev+1);
	else
		return search(root->right, x, lev+1);
}
int minElement(int x, int y, int z)
{
	int w = min(x, y);
	return min(w, z);
}

int findMin(Node *root, int dim, int lev = 0) // dim -> dimension, lev-> level. Also assuming all the elements are positive
{
	if (root == NULL)
		return INT_MAX;
	if (dim == lev%k)
	{
		if (root->left)
			return findMin(root->left, dim, lev+1);
		else
			return root->data[dim];
	}
	else
	{
		int l = findMin(root->left, dim, lev+1);
		int r = findMin(root->right, dim, lev+1);
		return minElement(l, r, root->data[dim]);
	}
}

int main() 
{ 
    struct Node* root = NULL; 
    int points[][k] = { { 30, 40 }, { 5, 25 }, 
       { 70, 70 }, { 10, 12 }, { 50, 30 }, { 35, 45 } }; 
  
    int n = sizeof(points) / sizeof(points[0]); 
  
    for (int i = 0; i < n; i++) 
        root = insert(root, points[i]); 
  
    cout << "Minimum of 0'th dimension is " << findMin(root, 0) << endl; 
    cout << "Minimum of 1'th dimension is " << findMin(root, 1) << endl; 
  
    return 0; 
} 