#include"Circular_List.h"
#include <stdio.h>


int main(){
    CircList *L = List_create();

    Add_First(L, 5);
    Add_First(L, 7);
    Add_First(L, 4);
    Add_First(L, 0);
    Add_First(L, 1);

    print_CircularList(L);

    List_Destroy(&L);

return 0;
}