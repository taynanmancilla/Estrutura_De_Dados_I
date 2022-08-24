#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"float_vector.h"
#include"merge_sort.h"


void merge(FloatVector *arr, int inicio, int meio, int fim)
{
    /*int n1 = meio - inicio + 1; //tamanho do primeiro subvetor

    int n2 = fim - meio;

    int L[n1];
    int R[n2];

    for(int i =0; i<n1; i++){
        //L[i] = arr[inicio+1];
        L[i] = at(arr, inicio+1);
    } 
    for(int i =0; i<n2; i++){
        //R[i] = arr[meio+1]; //Pensar...
        R[i] = at(arr, meio+1);
    }

    int i=0, j=0, k=0, var;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            //arr[k] = L[i];
            var = at(arr, k);
            var = L[i];
            i++;
        }else{
            //arr[k] = R[j];
            var = at(arr, k);
            var = R[j];
            j++;
        }
        k++;
    }
    while(j < n2){
        //arr[k] = R[j];
        var = at(arr, k);
        var = R[j];
        j++;
        k++;
    }
    while(j < n1){
        //arr[k] = L[i];
        var = at(arr, k);
        var = L[i];
        i++;
        k++;
    }*/

    int *aux, left, right, tam, k;
    int fimL=0, fimR=0;

    tam = fim - inicio + 1;
    left = inicio;
    right = meio+1;
    aux = (int*)malloc(tam*sizeof(int));

    if(aux != NULL){
        for(int i=0; i<tam; i++){
            if(!left && !right){
                //Combina ordenando
                if(at(arr, left) < at(arr, right)){
                    aux[i] = at(arr, left++);
                }else{
                    aux[i] = at(arr, right++);
                }
                //Vetor acabou?
                if(left>meio) fimL=1;
                if(right>fim) fimR=1;
            }else{
                //Copia o que sobra
                if(!fimL){
                    aux[i] = at(arr, left++);
                }else{
                    aux[i] = at(arr, right++);
                }
            }
        }
        for(int j=0, k=inicio; j<tam; j++, k++){
            int n = aux[j];
            inserejossa(arr, k, n);
        }
    }
    free(aux);
}


int mergesort(FloatVector *arr, int inicio, int fim)
{
    if(inicio < fim){

        int meio = inicio + (fim - inicio) / 2;
        //int meio = (fim + inicio) / 2;

        mergesort(arr, inicio, meio);
        mergesort(arr, meio+1, fim);
        merge(arr, inicio, meio, fim);

    }
}  