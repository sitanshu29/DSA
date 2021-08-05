#include <iostream>
using namespace std;

struct node 
{
	int data;
	node *next;
};

//iterative method
void reverselist(node **headref)
{
	node *nex = NULL, *prev = NULL, *curr = *headref;
	while(curr != NULL)
	{
		nex = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nex;
	}
	*headref = prev;
	
}

//recursive method


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
	//node *fifth = (node*)malloc(sizeof(node));
	
	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;
	
	third->data = 3;
	third->next = fourth;
	
	fourth->data = 4;
	fourth->next = NULL;
	printlist(head);
	reverselist(&head);
	printlist(head);
	
	//fifth->data = 5;
	//fifth->next = NULL;
}
