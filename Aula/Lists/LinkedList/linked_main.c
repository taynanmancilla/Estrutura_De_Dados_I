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
    add_Last(Lista, 5);
    print(Lista);
    add_Last(Lista, 26);
    print(Lista);
    add_Last(Lista, 67);
    print(Lista);
    add_Last(Lista, 0);
    print(Lista);

/*
    printf("Adicionando pelo Fim (Melhorado)\n");
    add_Better_Last(Lista, 7);
    print(Lista);
    add_Better_Last(Lista, 15);
    print(Lista);
    add_Better_Last(Lista, 8);
    print(Lista);
    add_Better_Last(Lista, 17);
    print(Lista);
*/
    return 0;
}