#include <iostream>
using namespace std;

struct node 
{
	int data;
	node *next;
};

void replaceLastToFirst(node **headref)
{
	node *temp = (*headref), *prev = NULL, *preprev = *headref;
	while (temp)
	{
		prev = temp;
		temp = temp->next;
	}
	while(preprev->next != prev)
	preprev = preprev->next;
	prev->next = *headref;
	*headref = prev;
	preprev->next = temp;
}

/*
void replace(node **a, node **b)
{
	node **tempa = a, **tempb = b;
	(*a)->next = (*b)->next;
	(*b)->next->next = (*a)->next->next;
	(*b)->next = (*tempa)->next;
	(*tempa)->next = (*tempb)->next->next;
}
void replacenode(node *head, int x, int y)
{
	node *temp = head;
	if (temp!=NULL && temp->data != x && temp->data != y)
	{
		node *arr[2];
		int num[2] = {x, y};
		for (int i = 0; i < 2; i++)
		{
			node *prev;
			while (temp->data != num[i] && temp!= NULL)
			{
				prev = temp;
				temp = temp->next;	
			}
			arr[i] = prev;		
		}
		replace(&(arr[0]), &(arr[1]));
	}
	
}

*/
//To print the list
void printlist(node *headref)
{
	node *temp = headref;
	while(temp !=NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL\n";
}
int main()
{
	node *head = (node*)malloc(sizeof(node));
	node *second =(node*)malloc(sizeof(node));
	node *third = (node*)malloc(sizeof(node));
	node *fourth = (node*)malloc(sizeof(node));
	node *fifth = (node*)malloc(sizeof(node));
	
	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;
	
	third->data = 3;
	third->next = fourth;
	
	fourth->data = 4;
	fourth->next = fifth;
	
	fifth->data = 5;
	fifth->next = NULL;
	
	printlist(head);
	
	replaceLastToFirst(&head);
	
	
	printlist(head);
	
	//fifth->data = 5;
	//fifth->next = NULL;
}
