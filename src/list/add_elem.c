#include "mylist.h"

void add_elem(void *elem, struct s_node **head)
{
	assert(elem != NULL);
	assert(head != NULL);
	/*
	if (elem == NULL)
	{
		return;
	}*
	if(head == NULL)
	{
		return;
	}*/
	add_node(new_node(elem, NULL, NULL), head);
}
