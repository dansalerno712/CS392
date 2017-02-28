#include "mylist.h"

void add_node_at(struct s_node *node, struct s_node **head, int n)
{
	struct s_node *temp;
	
	assert(node != NULL);
	assert(node -> elem != NULL);
	assert(head != NULL);
	assert(n >= 0);
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
	if (n <= 0)
	{
		add_node(node, head);
	}
	else
	{
		temp = *head;
		/* loop until reached n spot or end of list */
		while(n > 0)
		{
			if (temp -> next == NULL)
			{
				break;
			}
			temp = temp -> next;
			n--;
		}
		/* if n is too large, append */
		if (n > 0)
		{
			append(node, head);
		}
		/* if in middle, add  */
		else
		{
			temp -> prev -> next = node;
			node -> prev = temp -> prev;
			temp -> prev = node;
			node -> next = temp;
		}
	}
}
