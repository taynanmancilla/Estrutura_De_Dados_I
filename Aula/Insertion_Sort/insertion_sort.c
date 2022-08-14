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
        
        //Desloca os valores pra esquerda e insere:
        //atual = vetor[i];
        /*for(j=i; j>0; j--){
            if((atual < vetor[j-1])){
                vetor[j] = vetor[j-1];
            }
            soma_comparacao += 1;
        }
        if(vetor[j] != atual)soma_troca += 1;
        vetor[j] = atual;*/
        atual = vetor[i];
        j = i-1;
        while(j >= 0 && atual < vetor[j]){ //enquanto atual for menor q o anterior

            vetor[j+1] = vetor[j];
            soma_comparacao += 1;
            j--;
            if(j==0)break;
        }
        if(vetor[j] != atual)soma_troca += 1;
        vetor[j+1] = atual;

        soma_varredura += 1;
    }
}

void recordInsertion(int *vetor, int size)
{
    for(int i=0; i<size; i++){
        printf(" %d |", vetor[i]);
    }
    printf("\nQuantidade de Trocas: %d\n", soma_troca);
    printf("Quantidade de Varreduras: %d\n", soma_varredura);
    printf("Quantidade de Comparacoes: %d\n", soma_comparacao);

    /*FILE *file = fopen("insertion_data.txt", "a");
    if(file == NULL)printf("Erro ao criar o arquivo!");

    fprintf(file, "Vetor de %d posicoes:\n", size);
    fprintf(file, "Quantidade de Trocas: %d\n", soma_troca);
    fprintf(file, "Quantidade de Varreduras: %d\n", soma_varredura);
    fprintf(file, "Quantidade de Comparacoes: %d\n", soma_comparacao);
    //fprintf(file, "Tempo de Execucao: %.2f\n\n", time_spent);*/

    //fclose(file);

}