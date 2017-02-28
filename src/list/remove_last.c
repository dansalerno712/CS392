#include "mylist.h"

void *remove_last(struct s_node **head)
{
	void *ret;
	struct s_node *temp;
	assert(head != NULL);
	assert(*head != NULL);
	/*
	if (head == NULL || *head == NULL)
	{
		return NULL;
	}*/
	temp = *head;
	if (temp -> next == NULL) 
	{
		if (temp -> prev == NULL)
		{
			return remove_node(head);
		}
		else
		{
			ret = temp -> elem;
			/* if head is not the actual head, unlink from previous node */
			temp -> prev -> next = NULL;
			temp -> prev = NULL;
			free(temp);
			return ret;
		}
	}
	/* this else is only triggered if there is > 1 node in the list,
	 * ensuring that there is a prev to dereference */
	else
	{
		while (temp -> next != NULL) /*find last node */
		{
			temp = temp -> next;
		}
		ret = temp -> elem;
		temp -> prev -> next = NULL; /* unlinks previous node from deleted node */
		free(temp);
		return ret;
	}
}
