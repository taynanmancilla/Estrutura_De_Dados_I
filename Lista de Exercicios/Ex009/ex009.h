#include <stdbool.h>

typedef struct cad_inf Info;
typedef struct node_simples Node;
typedef struct linkedlist List;

bool isNull(List *lista);
Info *cadastro (char *tipo, char *nome, char *id, int vaga, char *placa);
Node *create_node(Info *p);
List *create_lista();
void destroy(List **ref_lista);
void insert_dados(List *lista, Info *p);
void separa_dados(List *lista, List *lista_est, List *lista_func, Info *p);
void estacionamento(List *est, List *fun, Info *pessoa);
int size(List *lista1, List *lista2);
void print_list(List *lista);
