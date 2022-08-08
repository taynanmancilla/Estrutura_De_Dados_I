#include<stdio.h>
#include<stdlib.h>
#include"ordenacao.h"

int cont_Varredura=0;

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble(int vector[], int size)
{
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-1; j++){//Melhorar
            if(vector[j] > vector[j+1]){
                swap(&vector[j], &vector[j+1]);
            }
        }
        cont_Varredura += 1;
    }
}

int printVector(const int *vector, int size){
    for(int i=0; i<size; i++){
        printf("|%d", vector[i]);
    }
}

