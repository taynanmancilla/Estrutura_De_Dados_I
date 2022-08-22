#include<stdlib.h>
#include<stdio.h>

int particiona(int *vetor, int inicio, int final)
{
    int left, right, pivo, auxiliar;
    left = inicio;
    right = final;
    pivo = vetor[inicio];
    while(left < right){
        while(vetor[left] <= pivo){
            left++;
        }
        while(vetor[right] > pivo){
            right--;
        }
        if(left < right){  
            auxiliar = vetor[left];
            vetor[left] = vetor[right];
            vetor[right] = auxiliar;
        }
    }
    vetor[inicio] = vetor[right];
    vetor[right] = pivo;
    return right;
}

void quickSort(int *vetor, int inicio, int fim)
{
    int pivo;
    if(fim > inicio){
        pivo = particiona(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo-1);
        quickSort(vetor, pivo+1, fim);
    }
}