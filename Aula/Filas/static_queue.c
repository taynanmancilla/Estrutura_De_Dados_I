#include"static_queue.h"

#include<stdio.h>
#include<stdlib.h>

typedef struct _static_queue{
    int *data;
    int size;
    long capacity;
    long begin;
    long end;

}StaticQueue;

StaticQueue *create_StaticQueue(long capacity)
{
    StaticQueue *Q = (StaticQueue*)calloc(1, sizeof(StaticQueue));
    Q->data = (int *)calloc(capacity, sizeof(int)); // Alocando o vetor
    Q->capacity = capacity;
    Q->begin = 0;
    Q->end = 0;
    Q->size = 0;
}

bool is_empty_StaticQueue(const StaticQueue *Q)
{
    return Q->size == 0;
}
bool is_full_StaticQueue(const StaticQueue *Q)
{
    return Q->size == Q->capacity;
}
long size_StaticQueue(const StaticQueue *Q)
{
    return Q->size;
}

void enqueue_StaticQueue(int info, StaticQueue *Q)
{
    if(is_full_StaticQueue(Q)){
        fprintf(stderr, "Erro em enqueue()\n");
        fprintf(stderr, "Vetor esta cheio\n");
        exit(EXIT_FAILURE);
    }
    Q->data[Q->end] = info;
    Q->end = (Q->end + 1) % Q->capacity; // Fila circular
    Q->size++;
}

int denqueue_StaticQueue(StaticQueue *Q)
{
    if(is_empty_StaticQueue(Q)){
        fprintf(stderr, "Erro em denqueue()\n");
        fprintf(stderr, "Vetor esta vazio\n");
        exit(EXIT_FAILURE);
    }
    int val = Q->data[Q->begin];
    Q->begin = (Q->begin + 1) % Q->capacity;
    Q->size--;
}

void print_StaticQueue(const StaticQueue *Q)
{
    int i, j;
    for(j = 0, i=Q->begin; j<Q->size; j++, i=(i+1)%Q->capacity){
        printf("| %d ", Q->data[i]);
    }
}