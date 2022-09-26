#include "doubly_list.h"
#include "stddef.h"
#include "stdlib.h"

typedef struct _double_node{
    int val;
    struct _double_node *next;
    struct _double_node *prev;
}DoubleNode, Node;

typedef struct _double_linked_list{
    Node *begin;
    Node *end;
    size_t size;
} DoubleLinkedList, List;