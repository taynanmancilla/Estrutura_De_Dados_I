#include <stdbool.h>
#include"tree.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define espaco 5

typedef struct _tree{
    Node *root;
    int depth;
}Tree;
typedef struct _node{
    int val;
    Node *left;
    Node *right;
}Node;

Tree *create_tree()
{
    Tree *T = (Tree*)malloc(sizeof(Tree));
    T->root = NULL;
    return T;
}
Node *create_node(int val)
{   
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
bool tree_is_empty(Tree *T)
{
    T->root == NULL;
}

void destroy_node(Node *node)
{
    if(node == NULL){
        return;
    }
    destroy_node(node->left);
    destroy_node(node->right);
    free(node);
    node = NULL;
}
void destroy_tree(Tree *T)
{
    if(T->root == NULL){
        fprintf(stderr, "Erro em DESTROY()\n");
        fprintf(stderr, "Arvore is Empty!\n");
        exit(EXIT_FAILURE);
    }
    destroy_node(T->root);
    free(T);
}


void add(Node *node, int val)
{
    Node *n = create_node(val);
    if(node->val > val){
        if(node->left == NULL){
            node->left = n;
            return;
        }
        add(node->left, val);
    
    }else if(node->val < val){
        if(node->right == NULL){
            node->right = n;
            return;
        }
        add(node->right, val);
    }else{
        fprintf(stderr, "Erro em ADD()\n");
        fprintf(stderr, "Nao eh Possivel Inserir (%d) Numeros Repetidos!\n", val);
    }
}
void insert(Tree *T, int val)
{
    if(T->root == NULL){
    //if(tree_is_empty(T)){
        T->root = create_node(val);
        puts("creating tree...");
        return;
    }else{
    add(T->root, val);
    }
}

void consult(Node *node, int val)
{
    if(node != NULL){
        if(node->val == val){
            printf("Valor Encontrado: %d\n", node->val);
        }else{
            if(val > node->val){
                return consult(node->right, val);
            }else{
                return consult(node->left, val);
            }
        }
    }else{
        printf("Valor (%d) Nao Existe!\n", val);
    }
}
void search(Tree *T, int val)
{
    if(T->root == NULL){
        puts("tree is empty!");
        return;
    }else{
        consult(T->root, val);
    }
}

Node *remover(Node *node, int val)
{
    if(node != NULL){
        if(node->val == val){
            if(node->left == NULL && node->right == NULL){ // Noh Folha
                free(node);
                printf("| %d | foi removido com sucesso\n", val);
                return NULL;
            }else{
                if(node->left != NULL && node->right != NULL){  // Possuem 2 filhos
                    Node *aux = node->left;
                    while(aux->right != NULL){
                        aux = aux->right;
                    }
                    node->val = aux->val;
                    aux->val = val;
                    printf("Elemento trocado |%d|\n", val);
                    node->left = remover(node->left, val);
                    return node;
                }else{                                          // Possuem 1 filho
                    Node *aux;
                    if(node->left != NULL){
                        aux = node->left;
                    }else{
                        aux = node->right;
                    }
                    free(node);
                    printf("| %d | foi removido com sucesso\n", val);
                    return aux;
                }
            }
        }else{
            if(val < node->val){
                node->left = remover(node->left, val);
            }else{
                node->right = remover(node->right, val);
            }
            return node;
        }
    }
}
void removeVal(Tree *T, int val)
{
    if(T->root == NULL){
    //if(!tree_is_empty(T)){
        puts("Valor nao encontrado!\n");
        return;
    }else{
        remover(T->root, val);
    }
}

void pre(Node *node)
{
    if(node != NULL){
        printf("%d ", node->val);
        pre(node->left);
        pre(node->right);
    }
}
void pre_order(Tree *T)
{
    if(T->root == NULL){
    //if(!tree_is_empty(T)){
        puts("tree is empty");
        return;
    }
    pre(T->root);
}

void in(Node *node)
{
    if(node != NULL){
        in(node->left);
        printf("%d ", node->val);
        in(node->right);
    }
}
void in_order(Tree *T)
{
    if(T->root == NULL){
        puts("tree is empty");
        return;
    }
    in(T->root);
}

void pos(Node *node)
{
    if(node != NULL){
        pos(node->left);
        pos(node->right);
        printf("%d ", node->val);
    }
}
void pos_order(Tree *T)
{
    if(T->root == NULL){
        puts("tree is empty");
        return;
    }
    pos(T->root);
}

void desenha_arvore_horiz(Node *node, int depth, char *path, int direita)
{
    // stopping conditiondepth
    if (node == NULL)
        return;

    // increase spacing
    depth++;

    // start with direita no
    desenha_arvore_horiz(node->right, depth, path, 1);

    // set | draw map
    path[depth-2] = 0;

    if(direita)
        path[depth-2] = 1;

    if(node->left)
        path[depth-1] = 1;

    // print root after spacing
    printf("\n");

    for(int i=0; i<depth-1; i++)
    {
      if(i == depth-2)
          printf("+");
      else if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<espaco; j++)
      if(i < depth-2)
          printf(" ");
      else
          printf("-");
    }

    printf("%d\n", node->val);

    // vertical espacors below
    for(int i=0; i<depth; i++)
    {
      if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<espaco; j++)
          printf(" ");
    }

    // go to esquerda no
    desenha_arvore_horiz(node->left, depth, path, 0);
}
void draw_tree(Tree *T)
{
    char path[255] = {};
    if(T->root == NULL){
    //if(!tree_is_empty(T)){
        puts("tree is empty");
        return;
    }
    //initial depth is 0
    desenha_arvore_horiz(T->root, 0, path, 0);
}

int altura(Node *node)
{
    if(node == NULL){
        return -1;
    }else{
        int esquerda = altura(node->left);
        int direita = altura(node->right);
        if(esquerda > direita){
            return esquerda + 1;
        }else{
            return direita + 1;
        }
    }
}
int quantidade_Noh(Node *node)
{
    if(node == NULL){
        return 0;
    }else{
        return 1 + quantidade_Noh(node->left) + quantidade_Noh(node->right);
    }
}

// Função para verificar se a subárvore enraizada em `X` e `Y` se espelham
bool isSymmetric(Node *X, Node *Y)
{
    // se ambas as árvores estiverem vazias
    if (X == NULL && Y == NULL) {
        return true;
    }
 
    // retorna verdadeiro se
    // 1. Ambas as árvores não são vazias e
    // 2. A subárvore esquerda é o espelho da subárvore direita e
    // 3. A subárvore direita é o espelho da subárvore esquerda
    return (X != NULL && Y != NULL) && isSymmetric(X->left, Y->right) && isSymmetric(X->right, Y->left);
}
bool Symmetric(Node* root)
{
    if (root == NULL) {
        return true;
    }
 
    return isSymmetric(root->left, root->right); // Retorna True se as subarvores da esquerda e direite sao espelhadas
}
void arvore_simetrica(Tree *T)
{
    bool v = Symmetric(T->root);
    printf("%s\n", v?"Arvore SIMETRICA":"Arvore NAO SIMETRICA");
}
