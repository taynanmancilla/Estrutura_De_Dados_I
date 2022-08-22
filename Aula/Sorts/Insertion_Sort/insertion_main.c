#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"insertion_sort.h"

void run(int *vetor, int size)
{
    
    double time_spent = 0.0;

    clock_t begin = clock();

    srand(time(NULL));
    for(int i=0;i<size; i++){
        vetor[i] = rand()%99;
    }

    for(int i=0; i<size; i++){
        printf(" %d |", vetor[i]);
    }
    printf("\n\n");

    insertion(vetor, size);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    recordInsertion(vetor, size);
}


int main(){
/*
    int size = 100;
    srand(time(NULL));
    for(int i=0;i<size; i++){
        vetor[i] = rand()%size;
    }

    for(int i=0; i<size; i++){
        printf(" %d |", vetor[i]);
    }
    printf("\n\n");*/

    int size = 5;
    int *vetor;

    vetor = (int *)malloc(size*sizeof(int));
    if(vetor == NULL){
        printf("Erro de Alocacao!");
        system("pause");
        exit(1);
    }


    run(vetor, size);
/*
    size = 500000;
    vetor = (int *)realloc(vetor, size*sizeof(int));
    run(vetor, size);

    size = 1000;
    vetor = (int *)realloc(vetor, size*sizeof(int));
    run(vetor, size);

    free(vetor);*/

return 0;
}