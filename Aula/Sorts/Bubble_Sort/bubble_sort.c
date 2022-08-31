#include<stdio.h>
#include<stdlib.h>
#include"bubble_sort.h"

long int soma_varredura = 0;
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
soma_varredura = 0;
soma_troca = 0;
soma_comparacao = 0;
    int controle=0, c=0;
    for(int i=0; i<size; i++){
        do{
        c = 0;
        for(int j=0; j<size; j++){
            if(vector[j] > vector[j+1]){
                swap(&vector[j], &vector[j+1]);
                controle = vector[j];
                soma_troca += 1;
                c = 1;
            }
            soma_comparacao +=1;
        }
        }while(c==1);
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
