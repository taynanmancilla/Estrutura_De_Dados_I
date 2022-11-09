#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include<stdbool.h>

typedef struct _static_queue StaticQueue;

StaticQueue *create_StaticQueue(long capacity);
void *destroy__StaticQueue(StaticQueue **Q_Ref);

bool is_empty_StaticQueue(const StaticQueue *Q);
bool is_full_StaticQueue(const StaticQueue *Q);
long size_StaticQueue(const StaticQueue *Q);
void print_StaticQueue(const StaticQueue *Q);

void enqueue_StaticQueue(int info, StaticQueue *Q);
int denqueue_StaticQueue(StaticQueue *Q);
void peek_StaticQueue(StaticQueue *Q);

#endif
