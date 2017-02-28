#include "mylist.h"

int count_s_nodes(struct s_node *head)
{
	int count;
	struct s_node *temp;
	if (head == NULL)
	{
		return 0;
	}
	count = 0;
	temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp -> next;
	}
	return count;
}
