#include "mylist.h"

void print_list_reverse(struct s_node *head)
{
	struct s_node *temp = head;
	if (head == NULL)
	{
		return;
	}
	while (temp -> next != NULL)
	{
		temp = temp -> next;
	}
	while (temp  != NULL)
	{
		my_str(temp -> elem);
		my_char('\n');
		temp = temp -> prev;
	}
}
