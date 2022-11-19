#include"tree.h"
#include<stdio.h>
#define TAM 6

int main(){

    int val[TAM] = {10, 8, 3, 9, 17, 16};

    Tree *t = create_tree();

    for(int i=0; i<TAM; i++){
        insert(t, val[i]);
    }

    pre_order(t);
    printf("\nSearch (9):\n");
    search(t, 9);
    printf("\nSearch (18):\n");
    search(t, 18);

    destroy_tree(t);

return 0;
}