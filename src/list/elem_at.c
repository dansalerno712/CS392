#include "mylist.h"

void *elem_at(struct s_node *head, int n)
{
	assert(head != NULL);
	assert(n >= 0);
	if (head != NULL)
	{
		struct s_node *temp = node_at(head, n); /* get node at n */
		return temp -> elem;
	}
	else
	{
		return NULL;
	}
}
