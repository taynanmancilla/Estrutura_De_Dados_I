#include<stdlib.h>
#include<stdio.h>
#include"static_stack.h"

typedef struct _static_stack{
    int *data;
    long capacity;
    long top;
}StaticStack;

StaticStack *StaticStack_create(long capacity)
{
    StaticStack *S = (StaticStack*)calloc(1, sizeof(StaticStack));
    S->capacity = capacity;
    S->top = -1; // Pilha Vazia (-1)
    S->data = (int*)calloc(S->capacity, sizeof(int));

    return S;
}

void StaticStack_destroy(StaticStack **s_stack)
{
    StaticStack *S = *s_stack;
    free(S->data); // Free no Vetor
    free(S);
    s_stack = NULL; // Retira o valor do ponteiro no programa Main
}

bool StaticStack_isEmpty(const StaticStack *S){ return S->top == -1; }
bool StaticStack_isFull(const StaticStack *S){ return S->top == S->capacity - 1; }

void StaticStack_push(StaticStack *S, long value)
{
    //Verficar se esta cheio printando msg de erro
    S->top++;
    S->data[S->top] = value;
}
void StaticStack_pop(StaticStack *S)
{
    //Verificar se esta vazio printando msg de erro
    int aux = S->data[S->top];
    S->top--;

    return aux;
}

void StaticStack_peek(StaticStack *S); //*

void StaticStack_print(StaticStack *S); //*

long StaticStack_size(const StaticStack *S); //*