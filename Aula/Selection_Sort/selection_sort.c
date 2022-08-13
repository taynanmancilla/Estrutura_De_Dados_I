#include<stdio.h>
#include<stdlib.h>
#include"selection_sort.h"


int soma_troca;
int soma_varredura;
int soma_comparacao;

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}
 

void selection(int *vetor, int size)
{

    for(int i=0; i<size; i++){

        int menor = i; //armazenando apenas o indice
        for(int j=i; j<size; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
                /*if(menor == j || menor != j){
                    soma_comparacao += 1;
                }*/
            }
            soma_comparacao += 1;
        }
        if(i != menor){
            swap(&vetor[i], &vetor[menor]);
            soma_troca += 1;
        }
    soma_varredura += 1;
    }   
}

void printSelection(const int *vetor, int size){
    for(int i=0; i<size; i++){
        printf("|%d", vetor[i]);
    }
    printf("\nTroca: %d", soma_troca);
    printf("\nVarredura: %d", soma_varredura-1);
    printf("\nComparacoes: %d", soma_comparacao);
}