#include "mylist.h"

void debug_char(struct s_node *head)
{
	if (head != NULL)
	{
		struct s_node *temp = head;
		
		while (temp != NULL)
		{
			my_str("(");
			if (temp -> prev == NULL)
			{
				my_str("NULL");
			}
			else
			{
				print_char(temp -> prev);
			}
			my_str(" <- ");
			print_char(temp);
			my_str(" -> ");
			if (temp -> next == NULL)
			{
				my_str("NULL");
			}
			else
			{
				print_char(temp -> next);
			}
			my_str(") ");
			temp = temp -> next;
		}
	}
	else
	{
		my_str("Empty list");
	}
}
