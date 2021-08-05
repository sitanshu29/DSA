// M Way Tree

#include <bits/stdc++.h>
#define M 4
using namespace std;


class Node
{
	public:
	int data[M+1];   // first element will store the count of no. of elements prensent in the array
	Node* child[M+1];
	
	Node()
	{
		this->data[0] = 0;
	}
};

Node *newnode(int x)
{
	Node *temp = new Node();
	temp->data[0] = 1;
	temp->data[1] = x;
	for(int i = 0; i < M+1; i++)
		temp->child[i] = NULL;
	return temp;
}

int search(int x, int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (x <= arr[i])
			return i;
	}
	return size;
}

	
Node* insert(Node *head, int data)
{
	if (head == NULL)
		return newnode(data);
	if (head->data[0] < M)
	{
		head->data[head->data[0] +1] = data;
		head->data[0] += 1;
		sort(head->data+1, head->data+head->data[0]+1);
		return head;
	}
	else
	{
		int chIndex = search(data, head->data+1, M);
		head->child[chIndex] = insert(head->child[chIndex], data);
	}
	return head;
}

void printLevelOrder(Node *head)
{
	if (head == NULL)
		return;
	queue<Node *> q;
	q.push(head);
	Node *temp;
	while(!q.empty())
	{
		int cnt=q.size();
		while(cnt--)
		{
			temp=q.front();
			q.pop();
			for(int i=1;i<temp->data[0]+1;++i)
			cout<<temp->data[i]<<" ";
			if(temp->data[0]==M)
			{
				for(int i=0;i<=M;++i)
				if(temp->child[i])
				q.push(temp->child[i]);
			}
			cout<<"\t";
		}
		cout<<endl;
	}
}

int main()
{
	Node *head = NULL;
	bool flag = 1;
	int x;
	while(flag)
	{
		cin >> x;
		if (x == -1)
		flag = 0;
		else
		head = insert(head, x);
	}
	printLevelOrder(head);
}

