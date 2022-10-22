#ifndef LINKED_LIST_H
#define LISKED_LIST_H

#include<stdbool.h>

typedef struct _node Node;
typedef struct _Linked_list LinkedList;

Node *Node_Create(int val); 
LinkedList *List_Create(); 

bool is_Empty(const LinkedList *lista);

void add_Last(LinkedList *lista, int val);



#endif