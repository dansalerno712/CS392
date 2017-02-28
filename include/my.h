#ifndef _LIBMY_H_
#define _LIBMY_H_
#include <stddef.h>
#include <stdlib.h>
/* I pledge my honor that I have abided by the Stevens Honor System
 * Daniel Salerno
 */

/*
 * libmy.h
 * A library to practice C string and character functions
 *
 * Author: Dan Salerno
 */
#define MAX_BUFFER_SIZE 1024

void my_char(char c);
void my_str(char*);
void my_int(int);
void my_num_base(int, char*);
void my_alpha();
void my_digits();
int my_find(char*, char);
int my_rfind(char*, char);
int my_strlen(char*);
int my_revstr(char*);
char *my_strindex(char *, char);
char *my_strrindex(char*, char);
char *my_strcat(char*, char*);
int my_strcmp(char*, char*);
int my_strncmp(char*, char*, int);
char *my_strconcat(char*, char*);
char *my_strnconcat(char*, char*, int);
char *my_strcpy(char*, char*);
char *my_strncpy(char*, char*, int);
char *my_strdup(char*);
char *my_vect2str(char**);
char **my_str2vect(char*);
int my_atoi(char*);
#endif /*_ LIBMY_H_ */
