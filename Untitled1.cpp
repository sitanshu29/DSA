#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
		int data;
		node *left, *right;
	
};
node *newnode(int data);

void levelOrderTransverse(node *root)
{
	queue <node *> q;
	q.push(root);
	while (!q.empty())
	{
		node *temp  = q.front();
		q.pop();
		cout << temp->data;
		if (temp->left)
		q.push(temp->left);
		if(temp->right)
		q.push(temp->right);
	}
}
void printTree(node *root)
{
	if (!root)
	return;
	printTree(root->left);
	cout << (root->data)<< " ";
	printTree(root->right);
}

void insertTree(node *root, int data)
{
	queue <node *> q;
	q.push(root);
	while(!q.empty())
	{
		node * temp = q.front();
		q.pop();
		if (!temp->left)
		{
			temp->left = newnode(data);
			return;
		}
		else
		q.push(temp->left);
		if(!temp->right)
		{
			temp->right = newnode(data);
			return;
		}
		else
		q.push(temp->right);
	}
}

node *newnode(int data)
{
	
		
			node * newnode = new node;
			newnode->data = data;
			newnode->left = NULL;
			newnode->right = NULL;
			return newnode;
		
}
int flag = 0;
void checkContinuous(node *root)
{
	if (!root)
	return;
	if (root->left != NULL && ((root->left->data - root->data != 1)&&(root->left->data - root->data != -1)))
	{
		flag = 1;
		
	}
	if (root->right != NULL && ((root->right->data - root->data != 1)&&(root->right->data - root->data != -1)))
	{
		flag = 1;
	}
	checkContinuous(root->left);
	checkContinuous(root->right);
	
}
void deletenode(node* root, node* last)
{
	queue <node*> q;
	q.push(root);
	while (!q.empty())
	{
		node * temp = q.front();
		q.pop();
		if (temp->right)
		{
			if(temp->right == last)
			{
				temp->right == NULL;
				delete(last);
				return;
			}
			else
			q.push(temp->right);
		}
		if (temp->left)
		{
			if(temp->left == last)
			{
				temp->left == NULL;
				delete(last);
				return;
			}
			else
			q.push(temp->left);
		}		
	}
}

void deleteTree(node *root, int data)
{
	
	queue <node *> q;
	node *delnode= NULL;
	node * temp;
	q.push(root);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if (temp->data == data)
		delnode = temp;
		if (temp->left)
		q.push(temp->left);
		if (temp->right)
		q.push(temp->right);
		
	}
	int x = temp->data;
	deletenode(root,temp);
	delnode->data = x;
	
}

bool foldUtil(node *n1, node *n2)
{
	if (n1 == NULL && n2 == NULL)
	return true;
	if (n1 == NULL || n2 == NULL)
	return false;
	return foldUtil(n1->left, n2->right) && (n1->right, n2->left);
}
bool checkFoldable(node *root)
{
	if (root == NULL)
	return true;
	foldUtil(root->left, root->right);	
}
int flagm = 0;
bool mirrorUtil(node *n1, node *n2)
{
	if (n1 == NULL && n2 == NULL)
	return true;
	if (n1 == NULL || n2 == NULL)
	return false;
	if (n1->data != n2->data)
	flagm = 1;
	return foldUtil(n1->left, n2->right) && (n1->right, n2->left);
}
bool checkMirror(node *root)
{
	if (root == NULL)
	return true;
	mirrorUtil(root->left, root->right);	
}


int main()
{
	node *root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->right->right = newnode(7);
	levelOrderTransverse(root);
	cout << endl;
	printTree(root);
	
	checkContinuous(root);
	if (flag==1)
	cout << "NO\n";
	else
	cout << "YES\n";
	checkMirror(root);
	if (flagm == 1)
	cout << "Not mirror.\n";
	else if (checkMirror && flagm == 0)
	cout << "Yes it is mirror\n";
	else
	cout << "NOt mirror";
	return 0;
}

