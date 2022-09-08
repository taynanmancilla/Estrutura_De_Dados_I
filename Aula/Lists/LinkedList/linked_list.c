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
    lista->end = NULL; // Atribuindo Nulo ao ponteiro pro final de uma lista recem criada

    return lista;
}

bool is_Empty(const LinkedList *lista)
{
    return lista->size == 0;
}

void Add_First(LinkedList *lista, int val)
{
    Node *p = Node_Create(val); // Criando um No P que recebe o valor VAL
    p->next = lista->begin;

    if(is_Empty(lista)){
        lista->end = p;
    }
    lista->begin = p;

    lista->size++;
}

void add_Last(LinkedList *lista, int val)
{
    Node *p = Node_Create(val);
    //Se a lista estiver vazia
    if(is_Empty(lista)){
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

void add_Better_Last(LinkedList *lista, int val)
{
    Node *new = Node_Create(val);

    //Se a lista estiver vazia
    if(is_Empty(lista)){
        lista->begin = lista->end = new;
    }else{
        lista->end->next = new; // Proximo elemento do ultimo Node aponta pro novo
        lista->end = lista->end->next; // O novo Node passa a ser o End
    }
    lista->size++;
}

void add_in_Order(LinkedList *lista, int val)
{
    Node *new = Node_Create(val);
    //Node *aux = Node_Create(val);
    if(is_Empty(lista)){
        lista->begin = lista->end = new;
    }else{
        if(new->val < lista->begin->val){ // Se o New valor for menor que o primeiro elemento da lista
            new->next = lista->begin; // New aponta pro primeiro elemento
            lista->begin = new; // New passa a ser o Primeiro elemento
        }else{
            Node *aux = lista->begin; // Ponteiro auxiliar pra percorrer a lista
            while(aux->next && new->val > aux->next->val){ // Se existe um proximo E o Novo valor for maior q o proximo
                aux = aux->next; // Auxiliar pula pro proximo
            }
        // Achou um maior que o New
        new->next = aux->next; // New aponta para o maior que ele
        aux->next = new; // Anterior aponta pro New
        }
    }
    lista->size++;
}

void remove_Value(LinkedList *lista, int val)
{
    if(!is_Empty(lista)){ // Se a lista nao estiver vazia
        // Se for o primeiro elemento(begin)
        if(lista->begin->val == val){
            Node *aux = lista->begin; // Apontando pro primeiro elemento da lista pra nao perder a referencia
            
            // Se possui apenas um elemento:
            if(lista->begin == lista->end){
                lista->end == NULL;
            }
            lista->begin = lista->begin->next; // Primeiro elemento passa a ser o next do begin
            free(aux);
        }else{// Se o elemento estiver no meio da lista
            Node *prior = lista->begin;
            Node *aux = lista->begin->next;
            
            /* Enquanto a lista possuir elemento pra percorrer
               E o valor do Node for diferente do valor(val). Os auxiliares avancam */
            while(aux != NULL && aux->val != val){ 
                prior = prior->next;
                aux = aux->next;
            }
            // Node igual ao valor(val) foi encontrado e eh apontado pelo aux
            if(aux != NULL){
                prior->next = aux->next;

                if(aux->next != NULL){ // Se for o Ultimo Node da lista
                    lista->end = prior;
                }

                free(aux);
            }
        }
        lista->size--;
    }
}

void remove_Better(LinkedList *lista, int val)
{
    if(!is_Empty(lista)){
        Node *aux = lista->begin;
        Node *prior = NULL;

        while(aux != NULL && aux->val != val){
            prior = aux;
            aux = aux->next;
        }

        if(aux != NULL){
            if(lista->end == aux){ // Eh o ultimo Node?
                lista->end = prior; // Final passa a ser o anterior
            }
            if(lista->begin == aux){ // Eh o primeiro Node?
                lista->begin = aux->next; // Inicio passa a ser o proximo do Node
            }
            else{ // Corrige o encadeamento caso seja um Node no meio ou Ultimo
                prior->next = aux->next; // Anterior aponta pro proximo do Node
            }
            free(aux);
        }
    }
    lista->size--;
}

/*  void remove_all(LinkedList *lista, int val)
{
    if(!is_Empty(lista)){
        Node *aux = lista->begin;
        Node *prior = NULL;

        while(aux != NULL){
            if(aux->val == val){
                if(lista->end == aux){
                    lista->end = prior;
                }
                if(lista->begin == aux){
                    lista->begin = aux->next;
                }else{
                    prior->next = aux->next;
                }
                free(aux);
            }
            prior = aux;
            aux = aux->next;
        }
    }
}
*/

int size(LinkedList *lista)
{
    return lista->size;
}

int get(LinkedList *lista, int index)
{
    if(is_Empty(lista)){
        fprintf(stderr, "ERRO em 'get()'\n");
        fprintf(stderr, "Lista Vazia\n");
        exit(EXIT_FAILURE);
    }else if(index < 0 || index >= lista->size){
        fprintf(stderr, "ERRO em 'get()'\n");
        fprintf(stderr, "Indice Invalido; %d\n", index);
        exit(EXIT_FAILURE);
    }else{
        int i=0;
        Node *p = lista->begin;
        while(i != index){ // Percorrendo a lista ate achar o indice desejado
            p = p->next;
            i++;
        }
        return p->val;
    }
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

    printf("Size: %d\n", lista->size);
    printf("Begin: %d\n", lista->begin->val);
    printf("End: %d\n", lista->end->val);
}

void destroy(LinkedList **lista)
{
    LinkedList *L = *lista;
    Node *p = L->begin;
    Node *aux = NULL;
    while(p != NULL){
        aux = p;
        p = p->next;
        free(aux);
    }
    free(L);
    *lista = NULL;

    printf("Lista deletada com sucesso!");
}


