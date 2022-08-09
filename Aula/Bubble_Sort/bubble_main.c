#include<stdio.h>
#include<stdlib.h>
#include <time.h> // for clock_t, clock(), CLOCKS_PER_SEC
#include"bubble_sort.h"

int main(int argc, char const *argv[]){

    double tempo_gasto = 0.0;

    clock_t begin = clock();

    int tecla, TAM;
    printf("Escolha o tamanho do vetor:\n");
    printf("DIGITE:\n(1) Vetor de 100k\n(2) Vetor de 500k\n(3) Vetor de 1M\n");
    scanf("%d", &tecla);

    switch (tecla)
    {
    case 1:
        TAM = 100000;
        break;
    case 2:
        TAM = 500000;
        break;
    case 3:
        TAM = 1000000;
        break;
    
    default:
        printf("Numero invalido!");
        break;
    }

    printf("Aguarde...");

    int vetor[TAM];
    for(int i=0;i<TAM; i++){
        vetor[i] = rand()%TAM;
    }

    bubble(vetor, TAM);
    

    clock_t end = clock();

    tempo_gasto += (double)(end - begin) / CLOCKS_PER_SEC;

    RecordVector(tempo_gasto);

return 0;
}