#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"

int main(){

    LinkedList *Lista = List_Create();
/*
    printf("Adicionando pelo Inicio:\n");
    Add_First(Lista, 2);
    print(Lista);
    Add_First(Lista, 0);
    print(Lista);
    Add_First(Lista, 0);
    print(Lista);
    Add_First(Lista, 2);
    print(Lista);

    printf("\n");
*/
    printf("Adicionando pelo Fim\n");
    add_Last(Lista, 2);
    print(Lista);
    add_Last(Lista, 0);
    print(Lista);
    add_Last(Lista, 2);
    print(Lista);
    add_Last(Lista, 2);
    print(Lista);

    return 0;
}