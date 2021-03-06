#include "my.h"
#include <stddef.h>
#include <limits.h>
#include <stdio.h>
int main()
{
	char *null = NULL;
	char a[] = "string";
 	char b[] = "";
	char c[] = "catch";
/*	my_str("Testing my_str:\n");
	my_str("test");
	my_str("\n");
	my_str("\0");
	my_str("\n");
	my_str(null);
	my_str("\n");
	
	my_str("Testing my_int\n");
	my_int(12345);
	my_str("\n");
	my_int(999);
        my_str("\n");
	my_int(-100);
	my_str("\n");
	my_int(-99999);
        my_str("\n");
	my_int(0);
	my_str("\n");
	my_int(INT_MAX);
	my_str("\n");
	my_int(INT_MIN);
	my_str("\n");
	
	my_str("Testing my_num_base\n");
	my_num_base(INT_MIN, "0123456789");
	my_str("\n");
	my_num_base(INT_MAX, "0123456789");
	my_str("\n");
	my_num_base(0, "0123456789");
	my_str("\n");
	my_num_base(16826, "0123456789ABCDEF");
	my_str("\n");
	my_num_base(12345678, "01234567");
	my_str("\n");
	my_num_base(9, "RTFM");
	my_str("\n");
	my_num_base(INT_MIN, "01");
	my_str("\n");
	my_num_base(5, "5");
	my_str("\n");
	my_num_base(10, "");
	my_str("\n");
	my_num_base(10, null);
	my_str("\n");
	
	my_str("Testing my_alpha\n");
	my_alpha();
	my_str("\n");
	
	my_str("Testing my_digits\n");
	my_digits();
	my_str("\n");
	
	my_str("Testing my_find\n");
	my_int(my_find("Hello", 'l'));
	my_str("\n");
	my_int(my_find("Hello", 'p'));
	my_str("\n");
	my_int(my_find("Hello", 'h'));
        my_str("\n");
	my_int(my_find("Hello", 'H'));
        my_str("\n");
	my_int(my_find("Hello", '\0'));
	my_str("\n");
	my_int(my_find(null, 'l'));
	my_str("\n");
	
	my_str("Testing my_rfind\n");
	my_int(my_rfind("Hello", 'l'));
	my_str("\n");
	my_int(my_rfind("Hello", 'H'));
        my_str("\n");
	my_int(my_rfind("Hello", 'h'));
        my_str("\n");
	my_int(my_rfind("Hello", 'p'));
	my_str("\n");
	my_int(my_rfind("Hello", '\0'));
	my_str("\n");
	my_int(my_rfind(null, 'l'));
	my_str("\n");
	
	my_str("Testing my_strlen\n");
	my_int(my_strlen("test"));
	my_str("\n");
	my_int(my_strlen("\0"));
	my_str("\n");
	my_int(my_strlen(null));
	my_str("\n");
	
	my_str("Testing my_revstr\n");
	my_int(my_revstr(a));
	my_str("\n");
	my_str(a);
	my_str("\n");
	my_int(my_revstr(c));
        my_str("\n");
        my_str(c);
        my_str("\n");
	my_int(my_revstr(b));
	my_str("\n");
	my_int(my_revstr(null));
	my_str("\n");
	*/
	my_str("Testing my_strindex\n");
	my_str(my_strindex("hello", 'l'));
	my_char('\n');
	my_str(my_strindex(a, 's'));
	my_char('\n');
	my_str(my_strindex("hello", 'p'));
	my_char('\n');
	my_str(my_strindex("test", '\0'));
	my_char('\n');
	my_str(my_strindex(NULL, '0'));
	my_char('\n');
	my_str(my_strindex("\0", '1'));
	my_char('\n');

	my_str("Testing my_strrindex\n");
	my_str(my_strrindex("hello", 'l'));
	my_char('\n');
	my_str(my_strrindex("hello", 'h'));
	my_char('\n');
	my_str(my_strrindex("hello", 'p'));
	my_char('\n');
	my_str(my_strrindex("test", '\0'));
	my_char('\n');
	my_str(my_strrindex(NULL, '0'));
	my_char('\n');
	my_str(my_strrindex("\0", '1'));
	my_char('\n');
	
	my_str("Testing my_strcat\n");
	char one[20] = "hello";
	char two[] = "world";
	my_str(my_strcat(one, "world"));
	my_char('\n');
	my_str(my_strcat(null, two));
	my_char('\n');
	my_str(my_strcat("hello", null));
	my_char('\n');
	my_str(my_strcat(one, ""));
	my_char('\n');
	my_str(my_strcat(NULL, NULL));
	my_char('\n');
	
	my_str("Testing my_strcmp\n");
	my_int(my_strcmp("hello", "hello"));
	my_char('\n');
	my_int(my_strcmp("appple", "banana"));
	my_char('\n');
	my_int(my_strcmp("banana", "apple"));
	my_char('\n');
	my_int(my_strcmp("aaa", "g"));
	my_char('\n');
	my_int(my_strcmp("aaa", "\0"));
	my_char('\n');
	my_int(my_strcmp("\0", "\0"));
	my_char('\n');
	my_int(my_strcmp(null, "\0"));
	my_char('\n');
	my_int(my_strcmp("\0", NULL));
	my_char('\n');
	my_int(my_strcmp(NULL, NULL));
	my_char('\n');

	my_str("Testing my_strncmp\n");
        my_int(my_strncmp("hello", "hello", 100));
        my_char('\n');
        my_int(my_strncmp("appple", "banana", 100));
        my_char('\n');
        my_int(my_strncmp("banana", "apple", 100));
        my_char('\n');
        my_int(my_strncmp("aaa", "g", 100));
        my_char('\n');
        my_int(my_strncmp("aaa", "\0", 100));
        my_char('\n');
        my_int(my_strncmp("\0", "\0", 100));
        my_str("\n\n");
	my_int(my_strncmp("aaa", "aaaaabcd", 0));
        my_char('\n');
	my_int(my_strncmp("aaa", "aaaaabcd", 1));
        my_char('\n');
	my_int(my_strncmp("aaa", "aaaaabcd", 2));
        my_char('\n');
	my_int(my_strncmp("aaa", "aaaaabcd", 3));
        my_char('\n');
	my_int(my_strncmp("aaa", "aaaaabcd", 4));
        my_char('\n');
        my_int(my_strncmp("aaa", "baaabcd", 0));
        my_char('\n'); 
        my_int(my_strncmp(null, "\0", 10)); 
        my_char('\n'); 
        my_int(my_strncmp("\0", NULL, 10)); 
        my_char('\n'); 
        my_int(my_strncmp(NULL, NULL, 1)); 
        my_char('\n');

	my_str("Testing my_strcpy\n");
	char *cpy1 = malloc(20);
	char *cpy2 = "helloworld";
	my_str(my_strcpy(cpy1, cpy2));
	my_char('\n');
	my_str(my_strcpy(cpy1, null));
	my_char('\n');
	my_str(my_strcpy(cpy1, "\0"));
	my_char('\n');
	my_str(my_strcpy(NULL, cpy2));
	my_char('\n');
	my_str(my_strcpy(NULL, NULL));
	my_char('\n');
	
	my_str("Testing my_strdup\n");
	my_str(my_strdup("hello"));
	my_char('\n');
	my_str(my_strdup("\0"));
	my_char('\n');
	my_str(my_strdup(null));
	my_char('\n');
	
	my_str("Testing my_strconcat\n");
	char cattest1[] = "hello";
	char cattest2[] = "world";
	my_str(my_strconcat(cattest1, cattest2));
	my_char('\n');
	my_str(my_strconcat(cattest1, NULL));
	my_char('\n');
	my_str(my_strconcat(NULL, cattest2));
	my_char('\n');
	my_str(my_strconcat(NULL, NULL));
	my_char('\n');
	my_str(my_strconcat("\0", "\0"));
	my_char('\n');
	
	my_str("Testing my_strncpy\n");
	char *ncpy1 = malloc(20);
	char *ncpy2 = "helloworld";
	my_str(my_strncpy(ncpy1, ncpy2, -5));
	my_char('\n');
	my_str(my_strncpy(ncpy1, ncpy2, 2));
	my_char('\n');
	my_str(my_strncpy(ncpy1, ncpy2, 5));
	my_char('\n');
	my_str(my_strncpy(ncpy1, ncpy2, 20));
	my_char('\n');
	my_str(my_strncpy(ncpy1, null, 5));
	my_char('\n');
	my_str(my_strncpy(ncpy1, "\0", 5));
	my_char('\n');
	my_str(my_strncpy(NULL, ncpy2, 10));
	my_char('\n');
	my_str(my_strncpy(NULL, NULL, 10));
	my_char('\n');
	
	my_str("Testing my_strnconcat\n");
	my_str(my_strnconcat("hello", "world", -1));
	my_char('\n');
        my_str(my_strnconcat("hello", "world", 1));
	my_char('\n');
	my_str(my_strnconcat("hello", "world", 3));
	my_char('\n');
	my_str(my_strnconcat("hello", "world", 7));
	my_char('\n');
	my_str(my_strnconcat(NULL, NULL, 10));
	my_char('\n');
	my_str(my_strnconcat("just a", NULL, 10));
	my_char('\n');
	my_str(my_strnconcat(NULL, "n chars of b", 4));
	my_char('\n');
	my_str(my_strnconcat(NULL, "n chars of b", 100));
	my_char('\n');
	my_str(my_strnconcat("\0", "\0", 10));
	my_char('\n');
	
	my_str("Testing my_vect2str\n");
	char *x[] = {"this", "is", "a", "test", "vector", NULL};
	my_str(my_vect2str(x));
	my_char('\n');
	char *x1[] = {"\0", NULL};
	my_str(my_vect2str(x1));
	my_char('\n');
	char *emptySarr[] = {NULL};
	my_str(my_vect2str(emptySarr));
	my_char('\n');
	my_str(my_vect2str(NULL));
	my_char('\n');
	
	my_str("Testing my_atoi\n");
	my_int(my_atoi("abc42-abc"));
	my_char('\n');
	my_int(my_atoi("abc4-2abc"));
	my_char('\n');
	my_int(my_atoi("abc4ab-2c"));
	my_char('\n');
	my_int(my_atoi("kjbrea-klijabr42skjngw"));
	my_char('\n');
	my_int(my_atoi(" sdfj ks s a  -456jsd 43"));
	my_char('\n');
	my_int(my_atoi("-asdasdasd-asdasd-asdasd"));
	my_char('\n');
	my_int(my_atoi("jowbet0akjrhb---42lia"));
	my_char('\n');
	my_int(my_atoi("--2"));
	my_char('\n');
	my_int(my_atoi("-------asdkjaskdhaksj789asas0909090---asasd"));
	my_char('\n');
	my_int(my_atoi("-abc-def-42"));
	my_char('\n');
	my_int(my_atoi("\0"));
	my_char('\n');
	my_int(my_atoi(NULL));
	my_char('\n');
	my_int(INT_MIN);
	my_char('\t');
	my_int(my_atoi("-2147483648"));
	my_char('\n');
	my_int(INT_MAX);
	my_char('\t');
	my_int(my_atoi("2147483647"));
	my_char('\n');
	
	my_str("Testing my_str2vect\n");
	char **vect;
	char y[] = "to    be 	or not \n to be 			\n";
	vect = my_str2vect(y);
	int i = 0;
	while (vect[i] != NULL)
	{
		my_str(vect[i]);
		i++;
		my_char('\n');
	}
	my_char('\n');
	char y0[] = "that is the question?";
	vect = my_str2vect(y0);
	i = 0;
	while (vect[i] != NULL)
	{
		my_str(vect[i]);
		i++;
		my_char('\n');
	}
	my_char('\n');
	char y1[] = "\0";
	vect = my_str2vect(y1);
	i = 0;
	while (vect[i] != NULL)
	{
		my_str(vect[i]);
		i++;
		my_char('\n');
	}
	my_char('\n');
	
	char *y2 = NULL;
	vect = my_str2vect(y2);
	my_char('\n');
	
	return 0;
}
