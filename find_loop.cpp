#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int data;
	node *next;
};
// To find length of loop -> (do memory.size() - i) ||
bool findloop(node *headref)
{
	node *temp = headref;
	vector <node*> memory;
	while(temp != NULL)
	{
		memory.push_back(temp);
		temp = temp->next;
		if (temp != NULL)
		for (int i = 0; i < memory.size() ; i++)
		if (temp->next ==(memory.at(i)))
		return 1;
	}
	return 0;
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
	
	//fifth->data = 5;
	//fifth->next = NULL;
	
	if(findloop(head))
	cout << "yes\n";
	else
	cout << "no\n";
	
	return 0;
}
