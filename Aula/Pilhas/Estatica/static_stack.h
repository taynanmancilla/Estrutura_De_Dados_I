#ifndef STATIC_STACK
#define STATIC_STACK

#include<stdbool.h>

typedef struct _static_stack StaticStack;

StaticStack *StaticStack_create(long capacity);     // Alocar o espaco da Pilha e iniciar os parametros

void StaticStack_destroy(StaticStack **S_ref);    // Destruir a Pilha

bool StaticStack_isEmpty(const StaticStack *S);     // Verifica se esta vazio
bool StaticStack_isFull(const StaticStack *S);      // Verifica se esta cheio

long StaticStack_size(const StaticStack *S);        // Retornar o tamanho

void StaticStack_push(StaticStack *S, int value);  // Insere valor no topo
int StaticStack_pop(StaticStack *S);               // Remove valor do topo
int StaticStack_peek(StaticStack *S);              // Retornar elemento que esta no topo
void StaticStack_print(const StaticStack *S);             // Printar

#endif