#include "mylist.h"

int main()
{
	struct s_node *head;
	struct s_node *temp;
	void *stuff;
	head = new_node("test", NULL, NULL);
	my_str(head -> elem);
	my_char('\n');
	free(head);
	my_str("--------\n");
	
	struct s_node *n1 = new_node("a", NULL, NULL);
	head = new_node("test", NULL, NULL);
	add_node(n1, &head);
//	add_node(NULL, &head);
//	add_node(new_node(NULL, NULL, NULL), &head);
//	add_node(n1, NULL);
	struct s_node *null = NULL;
//	add_node(n1, &null);
	print_list(head);
	my_str("---------------\n");
	print_list_reverse(head);
	my_str("---------------\n");
	
	add_elem("not a", &head);
//	add_elem(NULL, &head);
//	add_elem("something", NULL);
//	add_elem("something", &null);
	print_list(head);
	my_str("--------------\n");
	print_list_reverse(head);
	my_str("---------------\n");
	
	append(new_node("b", NULL, NULL), &head);
//	append(NULL, &head);
//	append(new_node(NULL, NULL, NULL), &head);
//	append(n1, NULL);
//	append(n1, &null);
	print_list(head);
	my_str("---------------\n");
	print_list_reverse(head);
	my_str("---------------\n");
	
	add_node_at(new_node("first", NULL, NULL), &head, 0);
	add_node_at(new_node("second", NULL, NULL), &head, 1);
	add_node_at(new_node("before b", NULL, NULL), &head, 5);
	add_node_at(new_node("c", NULL, NULL), &head, 7);
//	add_node_at(new_node(NULL, NULL, NULL), &head, 100);
//	add_node_at(NULL, &head, 100);
//	add_node_at(n1, NULL, 100);
//	add_node_at(n1, &null, 100);
	print_list(head);
	my_str("---------------\n");
	print_list_reverse(head);
	my_str("---------------\n");

//	stuff = remove_node(NULL);
//	stuff = remove_node(&null);
	stuff = remove_node(&head);
	my_str((char*)stuff);
	my_str("\t <------ removed elem\n");
	print_list(head);
	my_str("-----------------------\n");
	print_list_reverse(head);
	my_str("-----------------------\n");
	
//	stuff = remove_last(NULL);
//	stuff = remove_last(&null);
	stuff = remove_last(&head);
	my_str((char*)stuff);
	my_str("\t <--------- removed elem\n");
	print_list(head);
	my_str("-------------------------\n");
	print_list_reverse(head);
	my_str("--------------------------\n");
	
	my_str("Number of nodes: ");
	my_int(count_s_nodes(head));
	my_str("\n--------------------------\n");
	
	struct s_node *asd = new_node("hi", NULL, NULL);
	struct s_node *testremove = new_node("test", NULL, NULL);
	struct s_node *n2 = new_node("hi", NULL, NULL);
	add_node(n2, &testremove);
	print_list(testremove);
	my_str("--------------------\n");
	empty_list(&testremove);
	empty_list(&asd);
	temp = testremove;
	if (temp == NULL && asd == NULL)
		my_str("testremove cleared\n");
	my_str("---------------------------\n");
//	empty_list(&null);
//	empty_list(NULL);
	my_str("----------------------------\n");
	
	temp = new_node("string", NULL, NULL);
	print_string(temp);
	char x;
	x = 'c';
	temp = new_node(&x, NULL, NULL);
	print_char(temp);
	int y;
	y = 10;
	temp = new_node(&y, NULL, NULL);
	print_int(temp);
	my_char('\n');
	temp = new_node(NULL, NULL, NULL);
	print_int(temp);
	print_char(temp);
	print_string(temp);
//	print_int(NULL);
//	print_char(NULL);
//	print_string(NULL);
	my_str("\n-----------------------------------\n");
	
	temp = new_node(&y, NULL, NULL);
	int z = 2;
	add_node(new_node(&z, NULL, NULL), &temp);
	traverse_int(temp);
	empty_list(&temp);
	my_char('\n');
	temp = new_node(&x, NULL, NULL);
	char a = 'a';
	add_node(new_node(&a, NULL, NULL), &temp);
	traverse_char(temp);
	empty_list(&temp);
	my_char('\n');
	traverse_string(head);
	my_char('\n');
	traverse_int(NULL);
	traverse_char(NULL);
	traverse_string(NULL);
	my_str("\n-----------------------\n");
	
//	print_string(node_at(head, -5));
	print_string(node_at(head, 0));
	print_string(node_at(head, 1));
	print_string(node_at(head, 4));
	print_string(node_at(head, 5));
	print_string(node_at(head, 6));
//	node_at(NULL, 10);
	my_str("\n-----------------------------\n");
	
//	my_str((char*)elem_at(head, -5));
	my_str((char*)elem_at(head, 0));
	my_str((char*)elem_at(head, 1));
	my_str((char*)elem_at(head, 4));
	my_str((char*)elem_at(head, 5));
	my_str((char*)elem_at(head, 6));
//	elem_at(NULL, 10);
	my_str("\n---------------------\n");
	
	my_str("TEST REMOVE NODE AT HERE\n");
	stuff = remove_node_at(&head, 0);
	my_str(stuff);
	print_list(head);
	my_char('\n');
	print_list_reverse(head);
	my_char('\n');
	
	remove_node_at(&head, 1);
	print_list(head);
        my_char('\n');
        print_list_reverse(head);
        my_char('\n');

	remove_node_at(&head, 2);
	print_list(head);
        my_char('\n');
        print_list_reverse(head);
        my_char('\n');

	remove_node_at(&head, 2);
	print_list(head);
        my_char('\n');
        print_list_reverse(head);
        my_char('\n');

	remove_node_at(&head, 100);
	print_list(head);
        my_char('\n');
        print_list_reverse(head);
        my_char('\n');
        
        remove_node_at(&head, 1);
        traverse_string(head);
        my_char('\n');
	print_list_reverse(head);
        my_char('\n');
	
//	remove_node_at(NULL, 100);
//	remove_node_at(&null, 100);
	my_str("-------------------------\n");
	/* test clear_list on a longer list (head) after all testing done */
	
/*	my_str("\n----------------------\n");
	temp = new_node("d", NULL, NULL);
	add_elem("c", &temp);
	add_elem("b", &temp);
	add_elem("a", &temp);
	struct s_node *h = node_at(temp, 3);
	add_node(new_node("1", NULL, NULL) ,&h);
	remove_last(&h);
	print_list(temp);
	my_int(count_s_nodes(temp));
	my_char('\n');
	print_list_reverse(temp);  */
	
	my_str("\n==================\n");
	empty_list(&temp);
	temp = NULL;
	add_node(new_node("a", NULL, NULL), &temp);
	traverse_string(temp);
	empty_list(&temp);
	temp = NULL;
	add_elem("a",&temp);
	traverse_string(temp);
	empty_list(&temp);
	temp = NULL;
	append(new_node("a", NULL, NULL), &temp);
	traverse_string(temp);
	empty_list(&temp);
	temp = NULL;
	add_node_at(new_node("a", NULL, NULL), &temp, 1);
	traverse_string(temp);
	empty_list(&temp);
	temp = NULL;
	my_str("\n------------------------------\n");  
	
	int d1 = 1;
	int d2 = 2;
	int d3 = 3;
	
	add_elem(&d1, &temp);
	add_elem(&d2, &temp);
	add_elem(&d3, &temp);
	debug_int(temp);
	my_str("\n");
	empty_list(&temp);
	
	char dc1 = 'a';
	char dc2 = 'b';
	add_elem(&dc1, &temp);
	add_elem(&dc2, &temp);
	debug_char(temp);
	my_char('\n');
	empty_list(&temp);
	
	add_elem("last", &temp);
	add_elem("second to last", &temp);
	add_elem("almost first", &temp);
	add_elem("first", &temp);
	debug_string(temp);
	my_char('\n');
	empty_list(&temp);
	
	add_elem("singular", &temp);
	debug_string(temp);
	my_char('\n');
	empty_list(&temp);
	
	debug_int(temp);
	debug_char(temp);
	debug_string(temp);
	return 0;
}
