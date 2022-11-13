#include<stdio.h>
#include"static_stack.h"

int main(){

    StaticStack *S = StaticStack_create(5);
    int Topo;

    // StaticStack_print(S);

    // Topo = StaticStack_peek(S);
    // printf("Topo: %d\n", Topo);

    StaticStack_push(S, 5);
    StaticStack_push(S, 10);
    StaticStack_push(S, 15);
    StaticStack_push(S, 20);

    StaticStack_print(S);

    Topo = StaticStack_peek(S);
    printf("Peek: %d\n", Topo);

    Topo = StaticStack_pop(S);
    printf("Pop: %d\n\n", Topo);
    StaticStack_print(S);

    Topo = StaticStack_peek(S);
    printf("Peek: %d\n", Topo);

    StaticStack_push(S, 25);
    StaticStack_push(S, 30);

    StaticStack_print(S);

    // StaticStack_push(S, 35);


return 0;
}