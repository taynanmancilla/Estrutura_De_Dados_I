#include <stdbool.h>

typedef struct _tree Tree;
typedef struct _node Node;

Tree *create_tree();
Node *create_node(int val);

void destroy_tree(Tree *T); // Destruir
bool tree_is_empty(Tree *T);

void insert(Tree *T, int val);

void pre_order(Tree *T);
void in_order(Tree *T);

// Buscar valor
// Dividir arvore apos 50 elementos (Quebrar a cada 50 e juntar, formando uma floresta)
// Criar Menu para:
    // Inserir
    // Deletar
    // Consultar
    // Se arvore eh simetrica