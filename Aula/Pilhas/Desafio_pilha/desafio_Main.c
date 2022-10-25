#include"desafio.h"

int main(){

    StaticStack *pilha1 = List_create();
    StaticStack *pilha2 = List_create();

    StaticStack_push(pilha1, 4);
    StaticStack_push(pilha1, 0);
    StaticStack_push(pilha1, 0);
    StaticStack_push(pilha1, 2);
    print_List(pilha1);

    StaticStack_push(pilha2, 8);
    StaticStack_push(pilha2, 9);
    StaticStack_push(pilha2, 2);
    StaticStack_push(pilha2, 2);
    StaticStack_push(pilha2, 25);
    StaticStack_push(pilha2, 69);
    StaticStack_push(pilha2, 101);
    print_List(pilha2);

    StaticStack_Merge(pilha1, pilha2);
    print_List(pilha1);
    


return 0;
}