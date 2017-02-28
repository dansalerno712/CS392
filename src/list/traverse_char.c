#include "mylist.h"

void traverse_char(struct s_node *head)
{
	if (head != NULL)
	{
		struct s_node *temp = head;
		while (temp != NULL)
		{
			print_char(temp);
			my_str(" ");
			temp = temp -> next;
		}
	}
	else
	{
		my_str("Empty list");
	}
}
