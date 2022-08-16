#include<stdio.h>
#include<stdlib.h>
#include <time.h> // for clock_t, clock(), CLOCKS_PER_SEC
#include"bubble_sort.h"

void run(int *vetor, int size)
{
    
    double time_spent = 0.0;

    clock_t begin = clock();

    srand(time(NULL));
    for(int i=0;i<size; i++){
        vetor[i] = rand()%size;
    }
    bubble(vetor, size);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    RecordBubble(time_spent, size);
}

int main(int argc, char const *argv[]){

    int size = 100000;
    int *vetor;

    vetor = (int *)malloc(size*sizeof(int));
    if(vetor == NULL){
        printf("Erro de Alocacao!");
        system("pause");
        exit(1);
    }
    run(vetor, size);

    size = 500000;
    vetor = (int *)realloc(vetor, size*sizeof(int));
    run(vetor, size);

    size = 1000000;
    vetor = (int *)realloc(vetor, size*sizeof(int));
    run(vetor, size);
    
    free(vetor);

return 0;
}
