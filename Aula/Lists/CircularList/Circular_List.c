#include"Circular_List.h"
#include<stddef.h>

typedef struct _circ_node{
    int val;
    struct _circ_node *prev;
    struct _circ_node *prev;
}CircNode, Node;

typedef struct _circ_list{
    Node *begin;
    Node *end;
    size_t size;
}CircList, List;