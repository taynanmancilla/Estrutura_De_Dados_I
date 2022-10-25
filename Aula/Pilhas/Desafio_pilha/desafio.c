// Merge de duas pilhas dinamicas
    // Uma plha de size=7 e outra de size=4
#include"desafio.h"

typedef struct _node{
    int val;
    struct _double_node *next;
    struct _double_node *prev;
}Node;

typedef struct _static_stack{
    Node *begin;
    Node *end;
    size_t size;
} StaticStack;

Node *Node_create(int val)
{
    Node *node = (Node*)calloc(1, sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->val = val;

    return node;
}
StaticStack *List_create()
{
    StaticStack *L = (StaticStack*)calloc(1, sizeof(StaticStack));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}
bool is_Empty(const StaticStack *L)
{
    return L->size == 0;
}

void print_List(const StaticStack *L)
{
    Node *p = L->begin;
    printf("Pilha = ");
    while(p != NULL){
        printf("|%d|->", p->val);
        p = p->next;
    }
    printf("NULL\n");
    printf("Size: %d\n", L->size);
    printf("Begin: %d\n", L->begin->val);
    printf("End: %d\n", L->end->val);
}

void StaticStack_push(StaticStack *S, long value)
{
    Node *new = Node_create(value);
    new->prev = S->end;
    if(is_Empty(S)){
        S->begin = new;
    }else{
        S->end->next = new;
    }
    S->end = new;
    S->size++;
}

void StaticStack_Merge(StaticStack *S1, StaticStack *S2)
{
    S2->begin->prev = S1->end;
    S1->end->next = S2->begin;
    S1->end = S2->end;
    S1->size += S2->size;
}