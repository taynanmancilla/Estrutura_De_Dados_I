#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"

int main(){

    LinkedList *Lista = List_Create();

/* ADD NO INICIO FUNCIONANDO:
    Add_First(Lista, 2);
    print(Lista);
    Add_First(Lista, 0);
    print(Lista);
    Add_First(Lista, 0);
    print(Lista);
    Add_First(Lista, 2);
    print(Lista);
*/

    add(Lista, 2);
    print(Lista);
    add(Lista, 0);
    print(Lista);
    add(Lista, 2);
    print(Lista);
    add(Lista, 2);
    print(Lista);

    return 0;
}