//ARQUIVOS .h - ARQUIVO DE IMPLEMENTACOES
/*
Aplicacao das funcoes
*/

#include "float_vector.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//########## INTERFACE PRIVADA #############

struct float_vector
{
    int capacity;   // Numero maximo de elementos
    int size;       // Quantidade atual de elementos armazenados atualmente
    float *data;    // Vetor de floats
};

//Funcao Privada - Nao esta disponivel para os usuarios/programas,
//ou outros arquivos que usam o float_vector.h
bool _isFull(const FloatVector *vector)
{
    return vector->size == vector->capacity;
}

//########## IMPLEMENTACAO DA INTERFACE PUBLICA

/**
    * @brief Cria (aloca) um vetor de float com uma dada capacidade
    * 
    * @param tam Capacidade do vetor 
    * @return FloatVector* Um vetor de floats alocado/criado
*/

FloatVector *create(int tam)
{
    FloatVector *vet = (FloatVector *)calloc(1, sizeof(FloatVector)); //Criando uma estrutura de floatvector
    vet->capacity = tam;
    vet->size = 0; //Tamanho inicial eh zero(nenhum elemento inserido no vetor)
    vet->data = (float *)calloc(vet->capacity, sizeof(float)); //Alocando um vetor de float de tamanho 'tam'

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
        fprintf(stderr, "Index [%d] is out of bounds\n", pos);
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
        fprintf(stderr, "ERROR in 'append'\nVector is full!"); //STDERR = Saida padrao de erro
        exit(EXIT_FAILURE); //EXIT_FAILURE = Macro que indica que estamos saindo do programa com uma falha
    }
    vector->data[vector->size++] = n;
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

void print(const FloatVector *vector)
{
    printf("Size: %d\n", vector->size);
    printf("Capacity: %d\n", vector->capacity);
    printf("-----\n");
    for(int i=0; i < vector->size; i++){
        printf("|%d| - %.2f\n", i, vector->data[i]);
    }
}