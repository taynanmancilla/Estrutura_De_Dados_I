#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"

typedef struct _node{
    int val;
    struct _node *next;
} Node;

typedef struct _Linked_list{
    Node *begin;
    Node *end;
    int size;
} LinkedList;

Node *Node_Create(int val)
{
    Node *node = (Node *)calloc(1, sizeof(Node)); //Alocando o No dinamicamente
    node->val = val; // Atribuindo o parametro passado 
    node->next = NULL; // Atribuindo nulo ao proximo elemento de um No recem criado

    return node;
}

LinkedList *List_Create()
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
        lista->size++;
}

void add_Last(LinkedList *lista, int val)
{
    Node *p = Node_Create(val);
    //Se a lista estiver vazia
    if(lista->begin == NULL){
        lista->begin = p;
    }else{
        Node *aux = lista->begin;
        //Enquanto houver um proximo No
        while(aux->next != NULL){
            aux = aux->next;
        }
        // Na saida do laco AUX sera o ultimo No, logo jogamos o apontamento para o novo ultimo no
        aux->next = p;
    }
    lista->size++;
}

void print(const LinkedList *lista)
{
    Node *p = lista->begin;
    printf("Lista -> ");
    //Enquanto P apontar para um no existente
    while(p != NULL){
        printf("|%d|-> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
}
