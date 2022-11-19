#include"tree.h"
#include<stdio.h>
#define TAM 6

int main(){

    int val[TAM] = {10, 8, 3, 9, 17, 16};

    Tree *t = create_tree();

    // insert(t, 10);
    // insert(t, 8);
    // insert(t, 3);
    // insert(t, 9);
    // insert(t, 17);
    // insert(t, 16);

    for(int i=0; i<TAM; i++){
        insert(t, val[i]);
    }

    pre_order(t);

    destroy_tree(t);

return 0;
}