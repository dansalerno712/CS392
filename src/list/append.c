#include "mylist.h"

void append(struct s_node *node, struct s_node **head)
{
	struct s_node *temp;
	assert(node != NULL);
	assert(node -> elem != NULL);
	assert(head != NULL);
	
	/*
	if (node == NULL || node -> elem == NULL || head == NULL)
	{
		return;
	}*/
	if (*head == NULL)
	{
		*head = node;
		return;
	}
	temp = *head;
	while (temp -> next != NULL)
	{
		temp = temp  -> next;
	}
	temp -> next = node;
	node -> prev = temp;
}
