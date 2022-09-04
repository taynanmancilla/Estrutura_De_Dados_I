#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"

int main(){

    LinkedList *Lista = List_Create();

    Add_First(Lista, 2);
    print(Lista);
    Add_First(Lista, 0);
    print(Lista);
    Add_First(Lista, 0);
    print(Lista);
    Add_First(Lista, 2);
    print(Lista);

    return 0;
}