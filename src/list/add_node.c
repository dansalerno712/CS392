#include "mylist.h"

void add_node(struct s_node *node, struct s_node **head)
{
	assert(node != NULL);
	assert(node -> elem != NULL);
	assert(head != NULL);
	/*
	if (node == NULL || node -> elem == NULL || head == NULL)
	{
		return;
	}*/
	/* return or assert */
	if (*head == NULL)
	{
		*head = node;
		return;
	}
	if ((*head) -> prev != NULL)
	{
		node -> prev = (*head) -> prev;
		node -> next = *head;
		(*head) -> prev -> next = node;
		(*head) -> prev = node;
	}
	else
	{
		node -> next = *head;
		node -> prev = (*head) -> prev;
		(*head) -> prev = node;
		*head = node;
	}
}
