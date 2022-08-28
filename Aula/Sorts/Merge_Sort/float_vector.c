// ARQUIVO DE IMPLEMENTACOES
#include "float_vector.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

struct float_vector
{
    int capacity;   // Numero maximo de elementos
    int size;       // Quantidade atual de elementos
    float *data;    // Vetor de floats
};

bool _isFull(const FloatVector *vector)
{
    return vector->size == vector->capacity;
}

/**
    * @brief Cria (aloca) um vetor de float com uma dada capacidade
    * 
    * @param tam Capacidade do vetor 
    * @return FloatVector* ponteiro de um vetor de floats
*/

FloatVector *create(int tam)
{
    FloatVector *vet = (FloatVector *)calloc(1, sizeof(FloatVector));
    vet->capacity = tam;
    vet->size = 0;
    vet->data = (float *)calloc(vet->capacity, sizeof(float));

    return vet; //retornando poteiro de criacao da estrutura
}

void destroy(FloatVector **vet_ref)
{
    FloatVector *vet = *vet_ref;    
    free(vet->data);
    free(vet);
    *vet_ref = NULL; //setando NULL ao valor na funcao main
}

int size(const FloatVector *vector)
{
    return vector->size;
}

int capacity(const FloatVector *vector)
{
    return vector->capacity;
}

float at(const FloatVector *vector, int pos)
{
    if(pos < 0 || pos >= vector->size){
        fprintf(stderr, "Error: Invalid position\n");
        fprintf(stderr, "Index [%d] is out of bounds\n");
        exit(EXIT_FAILURE);
    }

    return vector->data[pos];
}

float get(const FloatVector *vector, int index)
{
    return vector->data[index];
}

void append(FloatVector *vector, float n)
{
    if(_isFull(vector)){
        fprintf(stderr, "Error in append\nVector is full!");
        exit(EXIT_FAILURE);
    }
    vector->data[vector->size++] = n;
}

void print(const FloatVector *vector)
{
    for(int i = 0; i  < vector->size; i++)
    {
        printf("| %.0f |", vector->data[i]);
    }
}

void set(const FloatVector *vector, int index, float n)
{
    if(index < 0 || index >= vector->size){
        fprintf(stderr, "ERROR in 'set'\n");
        fprintf(stderr, "Index [%d] is out of bounds: [0, %d]\n", index, vector->size-1);
        exit(EXIT_FAILURE);
    }
    vector->data[index] = n;
}


void merge(FloatVector *vector, int inicio, int meio, int fim)
{
   int i, j, k;
   //Inicio de cada vetor auxiliar
   int pL = meio - inicio + 1;
   int pR = fim - meio;
 
   int left[pL], right[pR];// Vetores auxiliares (esquerda e direita)
   //Atribundo os valores dos vetores auxiliares
   for(i = 0; i < pL; i++){
      //left[i] = vector[inicio+i];
      //left[i] = at(vector, inicio+1);
        left[i] = vector->data[inicio+1];
   }
   for(j = 0; j < pR; j++){
      //right[j] = vector[meio+1+j];
      //right[j] = at(vector, meio+1+j);
        right[j] = vector->data[meio+1+j];
   }

   //Atribuindo o menor dos dois auxiliares no vetor principal:
   i=0, j=0;
   k = inicio;
   while(i < pL && j < pR){
      if (left[i] <= right[j]) {
        //vector[k] = left[i];
        //set(vector, k, left[i]);
        vector->data[k] = left[i];
        i++;
      }else{
        //vector[k] = right[j];
        //set(vector, k, right[j]);
        vector->data[k] =right[j];
        j++;
      }
      k++;
   }

   //Quando um dos vetores acaba, nao precisamos continuar comparando
   //simplesmente copiamos o que sobrou pro final do auxiliar:
    while(i < pL){
        //vector[k] = left[i];
        //set(vector, k, left[i]);
        vector->data[k] = left[i];
        i++;
        k++;
    }
    while(j < pR){
        //vector[k] = right[j];
        //set(vector, k, right[j]);
        vector->data[k] = right[j];
        j++;
        k++;
   }
}

void mergesort(FloatVector *vector, int inicio, int fim)
{
   if(inicio < fim) {
      //Calculando a metade
      int meio = inicio+(fim - inicio) / 2;
      //Chamando a funcao pras duas metades
      mergesort(vector, inicio, meio);
      mergesort(vector, meio+1, fim);
      //Combinando 2 metades de forma ordenada
      merge(vector, inicio, meio, fim);
   }
}