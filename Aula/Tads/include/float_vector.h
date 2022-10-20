//ARQUIVOS .h - ARQUIVO DE ESPECIFICACOES
/*
Disponibilizamos as funcoes
*/

#include<stdio.h>
#include<stdbool.h>

//Especificando a estrutura
typedef struct float_vector FloatVector; 

//Verfica se o vetor esta cheio
bool _isFull(const FloatVector *vector);

//cria uma estrutura FloatVector
FloatVector *create(int tam);

void destroy(FloatVector **ref_vector);

//funcao q retorna o tamanho (numero atual de elementos inseridos)
int size(const FloatVector *vector); 

//retorna a capacidade do vetor (numero maximo de elementos)
int capacity(const FloatVector *vector);

//retorna o elemento do indice(valor dentro de uma posicao no vetor) com bound-checked
//bound-checked = Confere se o indice eh valido (Se esta dentro do agrupamento de elementos disponiveis)
float at(const FloatVector *vector, int pos); 

//retorna o elemento do indice sem fazer a checagem, aceitando indice invalido
float get(const FloatVector *vector, int index); 

//insere o valor 'n' no final do vetor, retornando um erro se estiver cheio
void append(FloatVector *vector, float n); 

// Insere o valor 'n' no indice 'index' do vetor, retornando um erro se o indice for invalido
void set(const FloatVector *vector, int index, float n);

// Imprime todos os elementos do vetor
void print(const FloatVector *vector);

// ----- PODERIA EXISTIR -----
/*
bool compare(FloatVector*, FloatVector*); //comparar duas TADS
void split(FloatVector*, FloatVector*); //separar duas TADS
void join(FloatVector*, FloatVector*); //concatenar duas TADS
*/