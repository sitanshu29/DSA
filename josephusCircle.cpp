#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

node *newnode(int i)
{
	node *temp = new node;
	temp->next = temp;
	temp->data = i;
	return temp;
}
void josephusCircle(int n, int m)
{
	node *head= newnode(1);
	node *temp =head;
	for (int i =2; i<=n; i++)
	{
		temp->next = newnode(i);
	
		temp = temp->next;
	}
	temp->next = head;
	
	node *ptr = head;
	node *tempdata, *prev;
	while(ptr->next != ptr)
	{
		
		tempdata = ptr;
		for (int i = 0; i < m; i++)
		{
			prev =tempdata;
			tempdata = tempdata->next;
		}
		ptr = tempdata->next;
			
		prev->next = ptr;
	}
	cout << ptr->data;
}

int main()
{
	int n, m;
	cin >> n >> m;
	josephusCircle(n, m);
}
