// Binary Search Tree Operations
#include <iostream>
using namespace std;

class Node
{
	int data;
	Node *left, *right;
};

Node *insert(Node *head, int data)
{
	if (head == NULL)
		return newNode(data);
	if (head->data > data)
		head->left = newNode(data);
	else if (head->data < data)
		head->right = newNode(data);
	return head;
}
