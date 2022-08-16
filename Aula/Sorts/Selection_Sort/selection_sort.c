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

void recordSelection(int size, double time_spent){
    FILE *file = fopen("selection_data.txt", "a");
    if(file == NULL)printf("Erro ao criar arquivo!");

    fprintf(file, "Vetor de %d posicoes:\n", size);
    fprintf(file, "Quantidade de Trocas: %d\n", soma_troca);
    fprintf(file, "Quantidade de Varreduras: %d\n", soma_varredura-1);
    fprintf(file, "Quantidade de Comparacoes: %d\n", soma_comparacao);
    fprintf(file, "Tempo de execucao: %.2fs\n\n", time_spent);

    fclose(file);
}