#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"selection_sort.h"
#define size 8

int main(){

   // int data[] = {0, 2, 7, 0, 9, 3, 8, 0};
    int vetor[size];
    //vetor = (int*)calloc(size, sizeof(int));

    srand(time(NULL));
    for(int i=0;i<size; i++){
        vetor[i] = rand()%9;
    }

    for(int i=0; i<size; i++){
        printf("|%d", vetor[i]);
    }
    printf("\n");
    selection(vetor, size);
    printSelection(vetor, size);

    free(vetor);

return 0;
}