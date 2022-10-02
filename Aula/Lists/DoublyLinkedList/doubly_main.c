#include "doubly_list.h"

int main(){

    DoubleLinkedList *lista = List_create();

    printf("----------- Adicionando no inicio -----------\n");
    Add_First(lista, 5);
    Add_First(lista, 4);
    Add_First(lista, 3);
    Add_First(lista, 2);
    Add_First(lista, 1);
    print_List(lista);
    inverted_print(lista);

    printf("\n----------- Adicionando no fim -----------\n");
    Add_Last(lista, 6);
    Add_Last(lista, 7);
    Add_Last(lista, 8);
    Add_Last(lista, 9);
    Add_Last(lista, 10);

    print_List(lista);
    inverted_print(lista);

    printf("----------- Removendo Elementos -----------\n");
    print_List(lista);
    printf("Removendo o 5:\n");
    Remove(lista, 5);
    print_List(lista);
    printf("Removendo o 8:\n");
    Remove(lista, 8);
    print_List(lista);

return 0;
}