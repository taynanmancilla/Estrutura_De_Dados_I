#include<stdio.h>
#include<stdlib.h>
#include"bubble_sort.h"

long int soma_varredura=0;
long int soma_troca = 0;
long int soma_comparacao = 0;

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble(int *vector, int size)
{
    int controle=0;
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-1; j++){
            if(vector[j] > vector[j+1]){
                swap(&vector[j], &vector[j+1]);
                controle = vector[j];
                if(controle == vector[j-1]){
                    break;
                }
                soma_troca += 1;
            }
            soma_comparacao +=1;
        }
        soma_varredura += 1;
    }
}

void RecordBubble(double time_spent, int size)
{

    FILE *file = fopen("bubble_data.txt", "a");
    if(file == NULL)printf("Erro ao criar o arquivo!");

    fprintf(file, "Vetor de %d posicoes:\n", size);
    fprintf(file, "Quantidade de Trocas: %ld\n", soma_troca);
    fprintf(file, "Quantidade de Varreduras: %ld\n", soma_varredura-1);
    fprintf(file, "Quantidade de Comparacoes: %ld\n", soma_comparacao);
    fprintf(file, "Tempo de execucao: %.4fs\n\n", time_spent);

    fclose(file);

}
