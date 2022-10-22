#include<stdio.h>
#include<stdlib.h>
#include "ex001.h"

typedef struct _node{
    int val;
    struct _node *next;   
} Node;

typedef struct _Linked_list{
    Node *begin;
    Node *end;
    int size;
} LinkedList;

bool is_Empty(const LinkedList *L)
{
    return L->size == 0;
}

Node *Node_Create(int val)
{
    Node *node = (Node *)calloc(1, sizeof(Node)); 
    node->val = val; 
    node->next = NULL; 

    return node;
}

LinkedList *List_Create()
{
    LinkedList *lista = (LinkedList*)calloc(1, sizeof(LinkedList)); 
    lista->begin = NULL;
    lista->end = NULL; 

    return lista;
}

void Add_First(LinkedList *L, int val)
{
    Node *p = Node_Create(val);
    p->next = L->begin;

    if(is_Empty(L)){
        L->end = p;
    }
    L->begin = p;

    L->size++;
}

void imprime (LinkedList *L) {
   if (is_Empty(L)) {
      printf ("%d\n", L->conteudo);
      imprime (L->prox);
   }
}