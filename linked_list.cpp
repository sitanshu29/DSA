//Practicing linked list
#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};
// To insert ath the beginning
void push(node **head, int new_data)
{
	node *new_node = (node*)malloc(sizeof(node));
	new_node->data = new_data;
	new_node->next = *head;
	*head = new_node;
}

//To insert after a particular node
void insertAfter(node *prev_node, int new_data)
{
	if (prev_node == NULL)
	{
		cout << "The given node is null" << endl;
		return ;
	}
	node *new_node = (node*)malloc(sizeof(node));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
	
}
//To insert after the last(append)
void append(node **head, int new_data)
{
	node *new_node = (node*)malloc(sizeof(node));
	new_node->data = new_data;
	node *temp = *head;
	if(*head == NULL)
	{
		*head = new_node;
		return;
	}
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->next = NULL;
	return;
}

//To delete a particular node with the given data(key)
void deletenode_key(node **headref, int key)
{
	node *temp = *headref, *prev;
	if (temp->data == key && temp !=NULL)
	{
		*headref = temp->next;
		 free(temp);
		 return;
	}
	
	while (temp->data != key && temp !=NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	
	if(temp == NULL)
	{
		cout << "The given key is not present in the linked list\n";
		return;
	}
	
	prev->next = temp->next;
	free(temp);
	
}

//To delete a node with given position (0 - n-1)
void deletenode_pos(node **headref, int pos)
{
	node *temp = *headref, *prev;
	if (pos = 0 && temp!= NULL)
		{
			*headref = temp->next;
			free(temp);
			return;
		}
	for(int i = 1; i != pos; i++)
	{
		if (temp!= NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		else
		{
			cout << "The node previous to the pos given became null.. error 404\n";
			return;
		}
	}
	prev->next = temp->next;
	free(temp);
	
	
}


//To delete a complete linked list
void deletelist(node **headref)
{
	cout << "Deleting\n";
	node *temp = *headref, *prev;
	while (temp !=NULL)
	{
		prev = temp;
		temp = temp->next;
		free(prev);
	}
	*headref = NULL;
	cout << "All deleted\n";
}
//To find the lenght of linked list using iterative function
void findlengthitr(node **headref)
{
	int i = 0;
	node *temp = *headref;
	while(temp!= NULL)
	{
		i++;
		temp = temp->next;
	}
	cout << "The lenth of the list using iterative function is " << i << endl;
}

//To find thte lenght of linked list using recursive function
int findlengthrec(node *head)
{
	if (head == NULL)
	return 0;
	return 1+findlengthrec(head->next);
}
// To print the linked list
void printlist(node *n )
{
	while(n!= NULL)
	{
		cout << n->data << " ";
		n = n->next;
	}	
}

int main()
{
	node* head = NULL;
	node* second = NULL;
	node * third = NULL;
	
	head = (node*)malloc(sizeof(node));
	second = (node*)malloc(sizeof(node));
	third = (node*)malloc(sizeof(node));
	
	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;
	
	third->data = 4;
	third->next = NULL;
	
	push(&head, 0);
	printlist(head);
	
	insertAfter(second, 3);
	printlist(head);
	
	append(&head, 5);
	printlist(head);
	
	deletenode_key(&head, 3);
	printlist(head);
	
	insertAfter(second, 3);
	printlist(head);
	
	findlengthitr(&head);
	int j = findlengthrec(head);
	cout << j << endl;
	//deletenode_pos(&head, 3);
	
	//deletelist(&head);
	
	printlist(head);
	return 0;
}
