#include"tree.h"
#include<stdio.h>

int main(){

    Tree *t = create_tree();

    insert(t, 10);
    insert(t, 8);
    insert(t, 3);
    insert(t, 9);
    insert(t, 17);
    insert(t, 16);

return 0;
}