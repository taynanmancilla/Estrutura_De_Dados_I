#include<stdio.h>
#include<stdlib.h>
#include"selection_sort.h"
#define TAM 8

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void selection(int vetor[])
{
    for(int i=0; i<TAM; i++){

        int menor = i; //armazenando apenas o indice
        for(int j=i; j<TAM; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
        }
        swap(&vetor[i], &vetor[menor]);
    }
}

void printSelection(const int *vetor){
    for(int i=0; i<TAM; i++){
        printf("|%d", vetor[i]);
    }
}