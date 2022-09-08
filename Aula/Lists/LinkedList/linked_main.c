#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"

int main(){

    LinkedList *Lista = List_Create();

    printf("Adicionando pelo Inicio:\n");
    Add_First(Lista, 6);
    print(Lista);
    Add_First(Lista, 5);
    print(Lista);
    Add_First(Lista, 4);
    print(Lista);

    printf("\n");

    printf("Adicionando pelo Fim \n");
    add_Better_Last(Lista, 7);
    print(Lista);
    add_Better_Last(Lista, 8);
    print(Lista);
    add_Better_Last(Lista, 9);
    print(Lista);

    printf("\n");

    printf("Adicionando em ordem\n");
    add_in_Order(Lista, 2);
    print(Lista);
    add_in_Order(Lista, 1);
    print(Lista);
    add_in_Order(Lista, 3);
    print(Lista);
    add_in_Order(Lista, 0);
    print(Lista);

    printf("\n");

    printf("Removendo a cabeca da lista\n");
    remove_Better(Lista, 0);
    print(Lista);

    printf("\n");

    printf("Removendo o ultimo elemento\n");
    remove_Better(Lista, 9);
    print(Lista);

    printf("\n");

    printf("Removendo elemento no meio da lista\n");
    remove_Better(Lista, 5);
    print(Lista);

    printf("\n");

/*    printf("Removendo elemento repetido da lista\n");
    add_in_Order(Lista, 4);
    print(Lista);
    remove_all(Lista, 4);
    print(Lista);
*/

    printf("\n");

    printf("Retornando um indice da lista:\n");
    print(Lista);
    printf("Indice[4] = %d\n", get(Lista, 4));

    printf("\n");

    destroy(&Lista);

return 0;
}