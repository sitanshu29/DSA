#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

void printlist(node *head)
{
	while (head!= NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

void middlenode(node *head)
{
	node *lower = head, *upper = head;
	if (head !=NULL)
	{
		while(  upper!=NULL && upper->next !=NULL )
		{
			upper = upper->next->next;
			lower = lower->next;
		}
		cout<< "The data in the middle node is" << lower->data << endl;
	}
}
/*
void findmiddle(node *head, int j)
{
	node *temp = head;
	int k = (j-1)/2 +1;
	int i = 0;
	while(i!=k)
	{
		temp = temp->next;
		i++;}
	cout << endl << temp->data;
	
}												
int length(node*head)
{
	node *temp = head;
	
	if (temp->next == NULL)
	return 0;
	else
	return 1+ length(temp->next);
}
*/
int main()
{
	node *head = (node*)malloc(sizeof(node));
	node *second =(node*)malloc(sizeof(node));
	node *third = (node*)malloc(sizeof(node));
	node *fourth = (node*)malloc(sizeof(node));
	//node *fifth = (node*)malloc(sizeof(node));
	
	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;
	
	third->data = 3;
	third->next = fourth;
	
	fourth->data = 4;
	fourth->next = NULL;
	
	//fifth->data = 5;
	//fifth->next = NULL;
	
	printlist(head);
	
	middlenode(head);
	
	
	return 0;
}
