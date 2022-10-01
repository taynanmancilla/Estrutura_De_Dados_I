#include "doubly_list.h"

int main(){

    DoubleLinkedList *lista = List_create();

    Add_First(lista, 9);
    print_List(lista);
    Add_First(lista, 8);
    print_List(lista);
    Add_First(lista, 6);
    print_List(lista);
    Add_First(lista, 9);
    print_List(lista);
    Add_First(lista, 15);
    print_List(lista);


return 0;
}