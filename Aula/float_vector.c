// ARQUIVO DE IMPLEMENTACOES
#include "float_vector.h"
#include<stdio.h>
#include<stdlib.h>

struct float_vector
{
    int capacity;   // Numero maximo de elementos
    int size;       // Quantidade atual de elementos
    float *data;    // Vetor de floats
};

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