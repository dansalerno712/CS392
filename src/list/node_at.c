#include "mylist.h"

struct s_node *node_at(struct s_node *head, int n)
{
	assert(n >= 0);
	assert(head != NULL);
	if (head != NULL)
	{
		struct s_node *temp;
		if (n <= 0)
		{
			return head;
		}
		temp = head;
		while (n > 0) /* loop through list */
		{
			if (temp -> next == NULL) /*if we reach end of list, return last node */
			{
				return temp;
			}
			temp = temp -> next;
			n--;
		}
		return temp; /* else return node at index n */
	}
	else
	{
		return NULL;
	}
}
