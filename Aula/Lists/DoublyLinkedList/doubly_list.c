#include "doubly_list.h"
#include "stddef.h"
#include "stdlib.h"

typedef struct _double_node{
    int val;
    struct _double_node *next;
    struct _double_node *prev;
}DoubleNode, Node;

typedef struct _double_linked_list{
    Node *begin;
    Node *end;
    size_t size;
} DoubleLinkedList, List;

Node *Node_create(int val)
{
    Node *node = (Node*)calloc(1, sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->val = val;

    return node;
}
List *List_create()
{
    List *L = (List*)calloc(1, sizeof(List));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}
void Destroy(DoubleLinkedList **Ref_list)
{
    List *L = *Ref_list;
    Node *p = L->begin;

    while(p != NULL){
        Node *aux = p;
        p = p->next;
        free(aux);
    }
    free(L);

    *Ref_list = NULL; // Setando o conteudo da referencia pra Nulo
}

bool is_Empty(const DoubleLinkedList *L)
{
    return L->size == 0;
}

void Add_First(DoubleLinkedList *L, int val)
{
    Node *new = Node_create(val);
    new->next = L->begin; // Novo Noh aponta pro Noh de inicio
    if(is_Empty(L)){
        L->end = new;
    }else{ 
        L->begin->prev = new; // O anterior do primeiro elemento aponta pro novo
    }
    L->begin = new; // Proximo da lista vira o novo Noh
    L->size++;
}

void Add_Last(DoubleLinkedList *L, int val)
{
    Node *new = Node_create(val);
    new->prev = L->end;
    if(is_Empty(L)){
        L->begin = new;
    }else{
        L->end->next = new;
    }
    L->end = new;
    L->size++;
}

void print_List(const DoubleLinkedList *L)
{
    Node *p = L->begin;
    printf("Lista = ");
    while(p != NULL){
        printf("|%d|->", p->val);
        p = p->next;
    }
    printf("NULL\n");
    printf("Size: %d\n", L->size);
    printf("Begin: %d\n", L->begin->val);
    printf("End: %d\n", L->end->val);
}

void inverted_print(const DoubleLinkedList *L)
{
    Node *p = L->end;
    printf("Lista Invertida = ");
    while(p != NULL){
        printf("|%d|->", p->val);
        p = p->prev;
    }
    printf("NULL\n");
    printf("Size: %d\n", L->size);
    printf("Begin: %d\n", L->begin->val);
    printf("End: %d\n", L->end->val);
}

void Remove(DoubleLinkedList *L, int val)
{
    if(!is_Empty(L)){ // Removendo se a lista nao for vazia
        if(L->begin->val == val){ // Elemento na cabeca da lista
            Node *p = L->begin;
            L->begin = L->begin->next; // Cabeca recebe o segundo elemento da lista
            if(L->size == 1){ // Lista de 1 elemento
                L->end = NULL;
            }else{
                L->begin->prev = NULL; // Nova Cabeca rebece Nulo no Anterior 
            }
        free(p); // desaloca o Noh que corresponde ao elemento
        L->size--; 
        }else{ // Elemento no meio ou no fim da lista
            Node *p = L->begin->next;
            while(p != NULL){
                if(p->val == val){
                    p->prev->next = p->next;    // O Next do Noh anterior passar a ser o Next de P
                    if(L->end == p){    // Elemento no fim
                        L->end = L->end->prev; // Fim de Lista passa a ser o penultimo
                        
                    }else{              //Elemento no meio
                        p->next->prev = p->prev; // Anterior do Next de P passa a ser o Noh anteior de P               
                    }
                    free(p);
                    p = NULL;
                    L->size--;
                }else{
                    p = p->next;
                }
            }
        }
    }
}

int get(DoubleLinkedList *L, int index)
{
    if(is_Empty(L)){
        fprintf(stderr, "Erro em get()\n");
        fprintf(stderr, "Lista Vazia!\n");
        exit(EXIT_FAILURE);
    }else if(index < 0 || index >= L->size){
        fprintf(stderr, "Erro em get()\n");
        fprintf(stderr, "Indice Invalido: %d\n", index);
        exit(EXIT_FAILURE);
    }else{
        Node *p = L->begin;
        int i=0;
        while(i != index){
            p = p->next;
            i++;
        }
        return p->val;
    }
}
