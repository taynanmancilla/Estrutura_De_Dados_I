#include<stdio.h>
#include<stdlib.h>
#include"insertion_sort.h"

void insertion(int*vetor, int size)
{
    int i, j, atual;
    //comparando o valor de uma posicao com os antecessores
    for(i=1; i<size; i++){ 
        //Desloca os valores pra esquerda e insere:
        atual = vetor[i];
        for(j=i; (j>0) && (atual < vetor[j-1]); j--){
            vetor[j] = vetor[j-1];
        }
        vetor[j] = atual;
    }
}

void printInsertion()