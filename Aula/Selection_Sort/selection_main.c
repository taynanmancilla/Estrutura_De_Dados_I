#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"selection_sort.h"

void run(int *vetor, int size)
{
    srand(time(NULL));
    for(int i=0;i<size; i++){
        vetor[i] = rand()%99;
    }
    selection(vetor, size);
    printSelection(vetor, size);
}

int main(){

    int size = 10;
    int *vetor;

    vetor = (int *)malloc(size*sizeof(int));
    if(vetor == NULL){
        printf("Erro de Alocacao!");
        system("pause");
        exit(1);
    }
    printf("Vetor de %d posicoes:", size);
    run(vetor, size);

    printf("\n\n");
    size = 50;
    vetor = (int *)realloc(vetor, size*sizeof(int));
    printf("Vetor de %d posicoes:", size);
    run(vetor, size);

    printf("\n\n");
    size = 100;
    vetor = (int *)realloc(vetor, size*sizeof(int));
    printf("Vetor de %d posicoes:", size);
    run(vetor, size);

    free(vetor);

return 0;
}
