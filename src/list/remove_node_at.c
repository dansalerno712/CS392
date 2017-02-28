#include "mylist.h"

void *remove_node_at(struct s_node **head, int n)
{
	struct s_node *temp;
	void *ret;
	assert(head != NULL);
	assert(*head != NULL);
	assert(n >= 0);
	                
	/*
	if (head == NULL || *head == NULL)
	{
		return NULL;
	}*/
	if (n <= 0)
	{
		return remove_node(head);
	}
	temp = *head;
	while (n > 0) /* loops through list */
	{
		if (temp -> next == NULL) /*if end of list, break */
		{
			break;
		}
		temp = temp -> next;
		n--;
	}
	if (n > 0 || temp -> next == NULL) /* if n is longer than list or at end of list */
	{
		return remove_last(head);
	}
	/* this else is only triggered if the node to be removed is not first or last, 
	 * which guarantess that the node has a prev and next to dereference */
	else /* remove node at index n */
	{
		ret = temp -> elem;
		temp -> prev -> next = temp -> next;
		temp -> next -> prev = temp -> prev;
		free(temp);
		return ret;
	}
}
