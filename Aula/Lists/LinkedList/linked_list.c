#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"

typedef struct _node{
    int val;
    struct _node *next;
} Node;

typedef struct _Linked_list{
    Node *begin;
} LinkedList;

Node *Node_Create(int val)
{
    Node *node = (Node *)calloc(1, sizeof(Node)); //Alocando o No dinamicamente
    node->val = val; // Atribuindo o parametro passado 
    node->next = NULL; // Atribuindo nulo ao proximo elemento de um No recem criado

    return node;
}

LinkedList *create()
{
    LinkedList *lista = (LinkedList*)calloc(1, sizeof(LinkedList)); // Alocando a lista dinamicamente
    lista->begin = NULL; // Atribuindo Nulo ao ponteiro pro inicio de uma lista recem criada

    return lista;
}

void Add_First(LinkedList *lista, int val)
{
        Node *p = Node_Create(val); // Criando um No P que recebe o valor VAL
        p->next = lista->begin; // No P aponta onde o Inicio da lista esta apontando
        lista->begin = p; // Inicio aponta pro P
}
