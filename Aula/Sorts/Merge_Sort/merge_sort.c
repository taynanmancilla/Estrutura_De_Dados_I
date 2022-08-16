#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"float_vector.h"
#include"merge_sort.h"

int mergesort(FloatVector arr[], int inicio, int fim)
{
    if(inicio < fim){

        int meio = inicio + (fim - inicio) / 2;

        mergesort(arr, inicio, meio);
        mergesort(arr, meio+1, fim);
        merge(arr, inicio, meio, fim);

    }
}

void merge(FloatVector arr[], int inicio, int meio, int fim)
{
    int n1 = meio - inicio + 1; //tamanho do primeiro subvetor
    int n2 = fim - meio;

    int L[n1];
    int R[n2];

    for(int i =0; i<n1; i++){
        //L[i] = arr[inicio+1];
        L[i] = get(arr, inicio+1);
    } 
    for(int i =0; i<n2; i++){
        //R[i] = arr[meio+1]; //Pensar...
        R[i] = get(arr, meio+1);
    }

    int i=0, j=0, k=0, var;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            //arr[k] = L[i];
            var = get(arr, k);
            var = L[i];
            i++;
        }else{
            //arr[k] = R[j];
            var = get(arr, k);
            var = R[j];
            j++;
        }
        k++;
    }
    while(j < n2){
        //arr[k] = R[j];
        var = get(arr, k);
        var = R[j];
        j++;
        k++;
    }
    while(j < n1){
        //arr[k] = L[i];
        var = get(arr, k);
        var = L[i];
        i++;
        k++;
    }
}