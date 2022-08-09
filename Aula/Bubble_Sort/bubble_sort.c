#include<stdio.h>
#include<stdlib.h>
#include"bubble_sort.h"

int cont_Varredura=0;
int cont_Troca = 0;
int cont_Compara = 0;

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble(int vector[], int size)
{

    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-1; j++){

            if(vector[j] > vector[j+1]){
                swap(&vector[j], &vector[j+1]);
                cont_Varredura = vector[j];
                if(cont_Varredura == vector[j-1]){
                    break;
                }
                cont_Troca += 1;
             }
            cont_Compara +=1;
        }
        cont_Varredura += 1;
    }
}

void RecordVector(double tempo){
    FILE *arquivo = fopen("arquivo.txt", "w");
    if(arquivo == NULL)printf("Erro ao criar o arquivo!");

    fprintf(arquivo, "\nVarredura: %d", cont_Varredura-1);
    fprintf(arquivo, "\nTroca: %d", cont_Troca);
    fprintf(arquivo, "\nComparacao: %d", cont_Compara);
    fprintf(arquivo, "\nTempo de execucao: %f", tempo);
    fclose(arquivo);
}
