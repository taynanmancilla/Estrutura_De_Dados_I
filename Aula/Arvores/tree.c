#include <stdbool.h>
#include"tree.h"
#include<stdio.h>
#include<stdlib.h>


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
    if(tree_is_empty(T)){
        return;
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
    
    }else{
        if(node->right == NULL){
            node->right = n;
            return;
        }
        add(node->right, val);
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
// del(Node *node, int val)
// {
//     if(node->val < val){
//         node->right = del(node->right, val);
//     }else if(node->val > val){
//         node->left = del(node->left, val);
//     }else{ // Elemento encontrado
//         if(node->left == NULL && node->right == NULL){ // Nao possui nenhum filho
//             free(node);
//             return NULL; // Retornando nulo para o galho do Noh anterior
//         }else if(node->left == NULL && node->right != NULL){ // Apenas 1 filho na direita

//         }
//     }
// }
// void remove(Tree *T, int val)
// {
//     if(T->root == NULL){
//     //if(!tree_is_empty(T)){
//         puts("tree is empty");
//         return;
//     }else{
//         del(T->root, val);
//     }
// }

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
    if(tree_is_empty(T)){
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
    if(tree_is_empty(T)){
        puts("tree is empty");
        return;
    }
    pos(T->root);
}
