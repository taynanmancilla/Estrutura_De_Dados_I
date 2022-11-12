#include <stdbool.h>
#include"tree.h"
#include<stdio.h>
#include<stdlib.h>

void add(Node *node, int val);
void pre(Node *node);
void in(Node *node);

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
void destroy_tree(Tree *T);
bool tree_is_empty(Tree *T)
{
    T->root == NULL;
}

void insert(Tree *T, int val)
{
    if(tree_is_empty(T)){
        T->root = create_node(val);
        puts("creating tree...");
        return;
    }
    add(T->root, val);
}

void add(Node *node, int val)
{
    if(node->val > val){
        if(node->left == NULL){
            node->left = create_node(val);
            return;
        }
        add(node->left, val);
    
    }else{
        if(node->right == NULL){
            node->right = create_node(val);
            return;
        }
        add(node->right, val);
        
    }
}

void pre_order(Tree *T)
{
    if(tree_is_empty(T)){
        puts("tree is empty");
        return;
    }
    pre(T->root);
}

void pre(Node *node)
{
    if(node != NULL){
        printf("%d ", node->val);
        pre(node->left);
        pre(node->right);
    }
}

void in_order(Tree *T)
{
    
}
