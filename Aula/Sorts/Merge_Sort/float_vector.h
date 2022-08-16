//ARQUIVOS .h - ARQUIVO DE ESPECIFICACOES
/*
Disponibilizamos as funcoes
*/

typedef struct float_vector FloatVector; //TAD

FloatVector *create(int tam);
void destroy(FloatVector **ref_vector);
int size(const FloatVector *vector); //funcao q retorna o tamanho
int capacity(const FloatVector *vector);
float at(const FloatVector *vector, int pos); //retorna o valor dentro de uma posicao no vetor
float get(const FloatVector *vector, int index);
void append(FloatVector *vector, float n); //inserir algo dentro do vetor
void print(const FloatVector *vector);

// ----- PODERIA EXISTIR -----
/*
bool compare(FloatVector*, FloatVector*); //comparar duas TADS
void split(FloatVector*, FloatVector*); //separar duas TADS
void join(FloatVector*, FloatVector*); //concatenar duas TADS
bool isfull(FloatVector);
*/

