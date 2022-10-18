#include"Circular_List.h"
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

typedef struct _circ_node{
    int val;
    struct _circ_node *prev;
    struct _circ_node *next;
}CircNode, Node;

typedef struct _circ_list{
    Node *begin;
    Node *end;
    size_t size;
}CircList, List;

Node *Node_create(int val)
{
    CircNode *cnode = (CircNode*)calloc(1, sizeof(CircNode));
    cnode->val = val;
    cnode->next = cnode;
    cnode->prev = cnode;

    return cnode;
}
void Node_Destroy(CircNode **Ref_node)
{
    free(*Ref_node);
    *Ref_node = NULL;
}

CircList *List_create()
{
    CircList *L = (CircList*)calloc(1, sizeof(CircList));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}
void List_Destroy(CircList **Ref_list)
{
    CircList *L = *Ref_list;
    CircNode *aux = NULL;
    CircNode *p = L->begin;

    for(int i=0; i< L->size; i++){
        aux = p;
        p = p->next;
        Node_Destroy(&aux);
    }
    free(L);
    *Ref_list = NULL;
}


bool is_Empty(const CircList *lista)
{
    return lista->size == 0;
}

void Add_First(CircList *L, int val)
{
    CircNode *p = Node_create(val);

    if(is_Empty(L)){
        L->end = p;
    }else{
        p->next = L->begin;
        L->begin->prev = p;
        p->prev = L->end;
        L->end->next = p;
    }
    L->begin = p;
    L->size++;
}