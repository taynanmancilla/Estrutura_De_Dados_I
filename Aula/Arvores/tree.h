#include <stdbool.h>

typedef struct _tree Tree;
typedef struct _node Node;

Tree *create_tree();            // Cria uma arvore
Node *create_node(int val);     // Cria um Noh

void destroy_node(Node *node);  // Destruir o Noh
void destroy_tree(Tree *T);     // Destruir a arvore
bool tree_is_empty(Tree *T);    // Retorna se esta vazio

void insert(Tree *T, int val);      // Insere um valor
void removeVal(Tree *T, int val);   // Remove Valor
void search(Tree *T, int val);      // Busca Valor
void arvore_simetrica(Tree *T);     // Verifica Simetria

void pre_order(Tree *T);            //Imprime PreOrder
void in_order(Tree *T);             //Imprime InOrder
void pos_order(Tree *T);            //Imprime PosOrder
void draw_tree(Tree *T);            //Desenha

// Buscar valor
// Dividir arvore apos 50 elementos (Quebrar a cada 50 e juntar, formando uma floresta)
// Criar Menu para:
    // Inserir ********
    // Deletar **********
    // Consultar **********
    // Se arvore eh simetrica 