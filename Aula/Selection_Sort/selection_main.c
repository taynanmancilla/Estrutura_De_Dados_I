#include<stdio.h>
#include<stdlib.h>
#include"selection_sort.h"


int main(){

    int data[] = {0, 2, 7, 0, 9, 3, 8, 0};

    selection(data);
    printSelection(data);

return 0;
}