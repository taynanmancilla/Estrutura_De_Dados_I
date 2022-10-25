#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct _node Node;
typedef struct _static_stack StaticStack;

Node *Node_create(int val);
StaticStack *List_create();

bool is_Empty(const StaticStack *lista);
void print_List(const StaticStack *lista);

void StaticStack_push(StaticStack *S, long value);  // Insere valor no topo
void StaticStack_pop(StaticStack *S);               // Remove valor do topo
void StaticStack_peek(StaticStack *S); 
void StaticStack_Merge(StaticStack *S1, StaticStack *S2);

