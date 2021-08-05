#include <iostream>
using namespace std;
 struct node
 {
 	int data;
 	node *next;
 };
 
 void printCircularList(node *head)
 {
 	if (head == NULL)
 	return;
	node *temp = head->next;			
 	cout << head->data << "->";
 	while (temp !=head)
 	{
 		cout << temp->data << "->";
 		temp = temp->next;
	}
	cout << "Repeat";
	
 }
 
 //Split linked list in 2 parts
 node *splitInTwo(node *head)
 {
 	node *fast = head, *slow = head;
 	while(fast!= NULL || slow != NULL)
 	{
 		if (fast->next ==head)
 		{
 			node *temp = slow->next;
 			fast->next = temp;
 			slow->next = head;
 			return temp;
		 }
		 else if(fast->next->next ==head)
		 {
		 	node *temp = slow->next;
		 	fast->next->next = temp;
		 	slow->next = head;
		 	return temp;
		 }
		 fast = fast->next->next;
		 slow = slow->next;
	 }
 }
 //function to insert a node at the beginning of a circilarly linked list
 void pushfront(node **head, int x)
 {
 	node *temp = *head, *ptr;
 	ptr->data = x;
 	ptr->next = *head;
 	if (*head != NULL)
	{
		while (temp->next != *head)
 		temp = temp->next;
 		temp->next = ptr;
 	}
 	else
 	ptr->next = ptr;
 	*head = ptr;
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
	fifth->next = head;
	printCircularList(head);
	
	node *headb = splitInTwo(head);
	printCircularList(head);
	printCircularList(headb);
	
	return 0;
}
