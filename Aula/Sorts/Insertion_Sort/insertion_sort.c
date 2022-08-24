#include<stdio.h>
#include<stdlib.h>
#include"insertion_sort.h"

int soma_troca = 0;
int soma_varredura = 0;
int soma_comparacao = 0;

void insertion(int*vetor, int size)
{
    int i, j, atual;

    //comparando o valor de uma posicao com os antecessores
    for(i=1; i<size; i++){
        atual = vetor[i];
        for(j = i; (j>0)&&(atual<vetor[j-1]); j--){
            soma_comparacao += 1;
            vetor[j] = vetor[j-1];
        }
        if(vetor[j] != atual)soma_troca += 1;
        vetor[j] = atual;
        soma_varredura += 1;
    }
}

void recordInsertion(int *vetor, int size, double time_spent)
{

    FILE *file = fopen("insertion_data.txt", "a");
    if(file == NULL)printf("Erro ao criar o arquivo!");

    fprintf(file, "Vetor de %d posicoes:\n", size);
    fprintf(file, "Quantidade de Trocas: %d\n", soma_troca);
    fprintf(file, "Quantidade de Varreduras: %d\n", soma_varredura);
    fprintf(file, "Quantidade de Comparacoes: %d\n", soma_comparacao);
    fprintf(file, "Tempo de Execucao: %.6f\n\n", time_spent);

    fclose(file);

}