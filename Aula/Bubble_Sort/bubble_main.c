#include<stdio.h>
#include<stdlib.h>
#include <time.h> // for clock_t, clock(), CLOCKS_PER_SEC
#include"bubble_sort.h"
#define C 100000
#define Q 500000
#define M 1000000

int main(int argc, char const *argv[]){

    double tempo_gasto = 0.0;

    clock_t begin = clock();

    
    int vetor[C];
    for(int i=0;i<C; i++){
        vetor[i] = rand()%C;
    }

    bubble(vetor, C);
    printVector(vetor, C);

    clock_t end = clock();

    tempo_gasto += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nTempo total gasto: %fs", tempo_gasto);

return 0;
}