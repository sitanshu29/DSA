// Given numbers in order ... Construct their binary tree

#include <iostream>
#include <vector>
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

vector <int> getLeaf(node *n)
{
	 vector <int> a;
	queue <node *> t;
	t.push(n);
	while(t.empty())
	{
		node *temp = t.front();
		t.pop();
		if (temp->left)
		{
			t.push(temp->left);
			if (temp->left->left == NULL && temp->left->right == NULL)
			a.push_back(temp->left->data);
		}
		if (temp->right)
		{
			t.push(temp->right);
			if (temp->right->left == NULL && temp->right->right == NULL)
			a.push_back(temp->right->data);
		}
	}
	cout << a.size();
	return a;
}
void checkLeafTransversal(node *n1, node *n2)
{
	 vector <int> arr1, arr2;
	 arr1 = getLeaf(n1);
	 arr2 = getLeaf(n2);
	 
	 bool flag = 0;
	 if (arr1.size() == arr2.size())
	{
	 	for (int i = 0 ; i < arr2.size(); i++)
	 	if (arr1[i] != arr2[i])
	 	{
	 		flag = 1;
	 		break;
	 	}
	}
	else
	{
		cout << "NO";
		return;
	}
	 if (flag)
	 cout << "NO";
	 else 
	 cout << "YES";
	 
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
	node *root1 = newNode(1); 
    root1->left = newNode(2); 
    root1->right = newNode(3); 
    root1->left->left = newNode(4); 
    root1->right->left = newNode(6); 
    root1->right->right = newNode(7); 
  
    node *root2 = newNode(0); 
    root2->left = newNode(1); 
    root2->right = newNode(5); 
    root2->left->right = newNode(4); 
    root2->right->left = newNode(6); 
    root2->right->right = newNode(8); 
  
    checkLeafTransversal(root1, root2);

	return 0;
}
