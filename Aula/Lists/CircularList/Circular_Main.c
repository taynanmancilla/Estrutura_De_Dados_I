#include"Circular_List.h"
#include <stdio.h>


int main(){
    CircList *L = List_create();

    puts("Adiciona no Inicio:");
    Add_First(L, 5);
    Add_First(L, 4);
    Add_First(L, 3);
    Add_First(L, 2);
    Add_First(L, 1);
    print_CircularList(L);

    puts("\nAdiciona no Fim:");
    Add_Last(L, 6);
    Add_Last(L, 7);
    Add_Last(L, 8);
    Add_Last(L, 9);
    Add_Last(L, 10);
    print_CircularList(L);

    puts("\nRemovendo na Cabeca (1):");
    remove_CircularList(L, 1);
    print_CircularList(L);
    
    puts("\nRemovendo na Meio (5):");
    remove_CircularList(L, 5);
    print_CircularList(L);

    puts("\nRemovendo na Fim (10):");
    remove_CircularList(L, 10);
    print_CircularList(L);

    List_Destroy(&L);

return 0;
}