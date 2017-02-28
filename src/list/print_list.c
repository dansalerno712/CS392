#include "mylist.h"

void print_list(struct s_node *head)
{
	struct s_node *temp = head;
	while (temp != NULL)
	{
		my_str(temp -> elem);
		my_char('\n');
		temp = temp -> next;
	}
}
