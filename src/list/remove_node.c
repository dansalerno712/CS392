#include "mylist.h"

void *remove_node(struct s_node **head)
{
	void *ret;
	struct s_node *temp;
	
	assert(head != NULL);
	assert(*head != NULL);
	/*
	if (head == NULL || *head == NULL)
	{
		return NULL;
	} */
	if ((*head) -> prev != NULL)
	{
		temp = *head;
		ret = temp -> elem;
		temp -> prev -> next = temp -> next; 
		if (temp -> next != NULL)
		{
			ret = temp -> elem;
			temp -> prev -> next = temp -> next;
			temp -> next -> prev = temp -> prev;
			*head = temp -> next;
			free(temp);
			return ret;
		}
		else
		{
			ret = temp -> elem;
			temp -> prev -> next = NULL;
			*head = temp -> next;
			free(temp);
			return ret;
		}
/*		free(temp);
		return ret; */
	}
	else
	{
	/*	my_str("else triggered");*/
		temp = *head;
		*head = temp -> next; /* sets the new head to be next node */
		ret = temp -> elem;
		if (*head != NULL) /*if head is now now null(i.e list w/ only 1 node), skip this step */
		{
			(*head) -> prev = NULL; /* unlinks new head from deleted node */
		}
		free(temp);
		return ret;
	}
}
