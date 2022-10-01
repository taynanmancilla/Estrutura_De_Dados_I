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

Node *Node_create(int val)
{
    Node *node = (Node*)calloc(1, sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->val = val;

    return node;
}
List *List_create()
{
    List *L = (List*)calloc(1, sizeof(List));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}
void Destroy(DoubleLinkedList **Ref_list)
{
    List *L = *Ref_list;
    Node *p = L->begin;

    while(p != NULL){
        Node *aux = p;
        p = p->next;
        free(aux);
    }
    free(L);

    *Ref_list = NULL; // Setando o conteudo da referencia pra Nulo
}

bool is_Empty(const DoubleLinkedList *L)
{
    return L->size == 0;
}

void Add_First(DoubleLinkedList *L, int val)
{
    Node *p = Node_create(val);
    p->next = L->begin; // Novo Noh aponta pro Noh de inicio
    if(is_Empty(L)){
        L->end = p;
    }else{ 
        L->begin->prev = p; // O anterior do primeiro elemento aponta pro novo
    }
    L->begin = p; // Proximo da lista vira o novo Noh
    L->size++;
}

void print_List(const DoubleLinkedList *L)
{
    Node *p = L->begin;
    printf("Lista = ");
    while(p != NULL){
        printf("|%d|->", p->val);
        p = p->next;
    }
    printf("NULL\n");
}
