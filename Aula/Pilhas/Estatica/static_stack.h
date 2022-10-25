#ifndef STATIC_STACK
#define STATIC_STACK

#include<stdbool.h>

typedef struct _static_stack StaticStack;

StaticStack *StaticStack_create(long capacity);     // Alocar o espaco da Pilha e iniciar os parametros

void StaticStack_destroy(StaticStack **s_stack);    // Destruir a Pilha

bool StaticStack_isEmpty(const StaticStack *S);     // Verifica se esta vazio
bool StaticStack_isFull(const StaticStack *S);      // Verifica se esta cheio

long StaticStack_size(const StaticStack *S);        // Retornar o tamanho

void StaticStack_push(StaticStack *S, long value);  // Insere valor no topo
void StaticStack_pop(StaticStack *S);               // Remove valor do topo
void StaticStack_peek(StaticStack *S);              // Retornar elemento que esta no topo
void StaticStack_print(StaticStack *S);             // Printar

#endif