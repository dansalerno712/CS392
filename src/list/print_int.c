#include "mylist.h"

void print_int(struct s_node *node)
{
	assert(node != NULL);
	if (node != NULL)
	{
		if (node -> elem == NULL)
		{
			my_str("NULL");
		}
		else
		{
			my_int(*((int*)(node -> elem)));
		}
	}
}
