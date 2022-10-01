#include "doubly_list.h"

int main(){

    DoubleLinkedList *lista = List_create();

    Add_First(lista, 1);
    Add_First(lista, 2);
    Add_First(lista, 3);
    Add_First(lista, 9);
    Add_First(lista, 10);

    print_List(lista);
    inverted_print(lista);


return 0;
}