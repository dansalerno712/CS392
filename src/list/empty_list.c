#include "mylist.h"

void empty_list(struct s_node **head)
{
	assert(head != NULL);
	
	while (head != NULL && *head != NULL)
	{
		remove_node(head);
	}
}
