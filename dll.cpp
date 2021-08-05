#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
	node *prev;
};
//add at front
node *push(node **headref,int x )
{
	node *temp = (node*)malloc(sizeof(node));
	temp->data = x;
	temp->next = *headref;
	temp->prev = NULL;
	*headref = temp;
	
}

//add after the pointer to the given node
void addafter(node *ref, int x)
{
	if (ref == NULL)
	{
		cout << "cant add after a NULL node\n";
		return;
	}
	node *temp = (node*)malloc(sizeof(node));
	node *mem = ref->next;
	temp->data = x;
	ref->next = temp;
	temp->prev = ref;
	temp->next = mem;
	mem->prev = temp;
}

// To append at last of the linked list
void append(node **headref, int x)
{
	node *temp = (node*)malloc(sizeof(node));
	if (*headref == NULL)
	{
		temp->data = x;
		temp->prev = NULL;
		temp->next = NULL;
		*headref = temp;
		return;
	}
	node *mem = *headref;
	while (mem->next != NULL)
	{
		mem = mem->next;
	}
	temp->data = x;
	mem->next = temp;
	temp->next = NULL;
	temp->prev = mem;
	
}

//To add before a given ref node
void addBefore(node **headref, node *ref, int x)
{
	node *temp = (node*)malloc(sizeof(node));
	if (ref == NULL)
	{
		return;	
	}
	if (ref->prev == NULL)
	{
		temp->data = x;
		ref->prev = temp;
		temp->next = ref;
		temp->prev = NULL;
		*headref = temp;
		return;
	}
	temp->data = x;
	node *mem = ref->prev;
	temp->next = ref;
	ref->prev = temp;
	mem->next = temp;
	temp->prev = mem;
}
// Delete a particular node
void deleteNode(struct node** head_ref, struct node* del) 
{ 
    /* base case */
    if (*head_ref == NULL || del == NULL) 
        return; 
  
    /* If node to be deleted is head node */
    if (*head_ref == del) 
        *head_ref = del->next; 
  
    /* Change next only if node to be deleted is NOT the last node */
    if (del->next != NULL) 
        del->next->prev = del->prev; 
  
    /* Change prev only if node to be deleted is NOT the first node */
    if (del->prev != NULL) 
        del->prev->next = del->next; 
  
    /* Finally, free the memory occupied by del*/
    free(del); 
    return; 
} 

//Reverse a dll
void reverse(node **headref)
{
	node *curr = *headref, *before = (*headref)->prev, (*after) = (*headref)->next, *temp = NULL;
	if (*headref == NULL)
	return;
	while (curr != NULL)
	{
		curr->prev = after;
		curr->next = before;
		temp = curr;
		curr = after;
		if (curr != NULL)
		{
			before = after->prev;
			after = after->next;
		}
		
		
	}
	*headref = temp;
}
void printdll(node *head)
{
	node *temp = head;
	cout << "NULL->";
	while (temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL\n";
}

int main()
{
	node *head = NULL;
	push(&head, 3);
	push(&head, 1);
	addafter(head, 2);
	append(&head, 4);
	printdll(head);
	reverse(&head);
	
	printdll(head);
}
