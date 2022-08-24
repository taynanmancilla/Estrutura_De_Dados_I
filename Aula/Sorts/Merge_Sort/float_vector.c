// ARQUIVO DE IMPLEMENTACOES
#include "float_vector.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

/*void print(const FloatVector *vector)
{
    for(int i=0; i < vector->size; i++){
        printf("%.2f|", vector->data[i]);
    }
}*/

void print(const FloatVector *vector)
{

    for(int i = 0; i  < vector->size; i++)
    {
        printf("| %.0f |", vector->data[i]);
    }
}

void inserejossa(const FloatVector *vector, int index, float n)
{
    vector->data[index] = n;
}