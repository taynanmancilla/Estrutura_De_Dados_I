//ARQUIVO DE ESPECIFICACOES


typedef struct float_vector FloatVector;

FloatVector *create(int tam); // Criar um vetor do tipo FloatVector
void destroy(FloatVector **ref_vector); // Excluindo o vetor
int size(const FloatVector *vector); // Retornar a quantidade atual de elementos
int capacity(const FloatVector *vector); // Retornar a capacidade maxima de elementos
float at(const FloatVector *vector, int pos); // Retornar o valor dentro de um indice no vetor COM tratamento de erro
float get(const FloatVector *vector, int index); // Retornar o valor dentro de um indice no vetor SEM tratamento de erro
void append(FloatVector *vector, float n); // Inserir um valor no fim do vetor
void print(const FloatVector *vector); // Imprimir o vetor
void set(const FloatVector *vector, int index, float n); // Inserir um valor em um determinado indice


void mergesort(FloatVector *vector, int inicio, int fim);
void merge(FloatVector *vector, int inicio, int meio, int fim);
