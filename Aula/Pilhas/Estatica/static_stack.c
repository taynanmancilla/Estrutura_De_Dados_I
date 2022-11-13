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

void StaticStack_destroy(StaticStack **S_ref)
{
    StaticStack *S = *S_ref;
    free(S->data); // Free no Vetor
    free(S);
    S_ref = NULL; // Setando o conteudo da referencia pra nulo
}

bool StaticStack_isEmpty(const StaticStack *S){ return S->top == -1; }
bool StaticStack_isFull(const StaticStack *S){ return S->top == (S->capacity - 1); }

void StaticStack_push(StaticStack *S, int value)
{
    if(StaticStack_isFull(S)){
        fprintf(stderr, "Erro em push()\n");
        fprintf(stderr, "A Pilha esta cheia\n");
        exit(EXIT_FAILURE);
    }
    S->top++;
    S->data[S->top] = value;
    //S[++top] = value
}

int StaticStack_pop(StaticStack *S)
{
    if(StaticStack_isEmpty(S)){
        fprintf(stderr, "Erro em pop()\n");
        fprintf(stderr, "A Pilha esta vazia\n");
        exit(EXIT_FAILURE);
    }
    int aux = S->data[S->top];
    S->top--;

    return aux;
}

int StaticStack_peek(StaticStack *S)
{
    if(StaticStack_isEmpty(S)){
        fprintf(stderr, "Erro em peek()\n");
        fprintf(stderr, "A Pilha esta vazia\n");
        exit(EXIT_FAILURE);
    }
    return S->data[S->top];
}

void StaticStack_print(const StaticStack *S)
{
    printf("Capacity: %ld\n", S->capacity);
    printf("Top: %ld\n", S->top);

    for(long i=0; i<=S->top; i++){
        printf("|%d| - %d\n", i, S->data[i]);
    }
}

long StaticStack_size(const StaticStack *S){
    return S->top+1;
}