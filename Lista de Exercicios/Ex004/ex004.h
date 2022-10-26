#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct _subscriber Subscriber;
typedef struct _phoneBook Book;

Subscriber *create_Subscriber(char *nome, char *telefone, char *rua, char *numero, char *cidade);
Book *create_Book();
bool is_Empty(const Book *book);

void insert_Subscriber(Book *book, char *nome, char *telefone, char *rua, char *numero, char *cidade);
void print_Book(const Book *book);