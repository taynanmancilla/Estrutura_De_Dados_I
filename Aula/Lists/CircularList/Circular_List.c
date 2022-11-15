#include"Circular_List.h"
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

typedef struct _circ_node{
    int val;
    struct _circ_node *prev;
    struct _circ_node *next;
}CircNode, Node;

typedef struct _circ_list{
    Node *begin;
    Node *end;
    size_t size;
}CircList, List;

Node *Node_create(int val)
{
    CircNode *cnode = (CircNode*)calloc(1, sizeof(CircNode));
    cnode->val = val;
    cnode->next = cnode;
    cnode->prev = cnode;

    return cnode;
}
void Node_Destroy(CircNode **Ref_node)
{
    free(*Ref_node);
    *Ref_node = NULL;
}

CircList *List_create()
{
    CircList *L = (CircList*)calloc(1, sizeof(CircList));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}
void List_Destroy(CircList **Ref_list)
{
    CircList *L = *Ref_list;
    CircNode *aux = NULL;
    CircNode *p = L->begin;

    for(int i=0; i< L->size; i++){
        aux = p;
        p = p->next;
        Node_Destroy(&aux);
    }
    free(L);
    *Ref_list = NULL;
}


bool is_Empty(const CircList *lista)
{
    return lista->size == 0;
}

void Add_First(CircList *L, int val)
{
    CircNode *p = Node_create(val);

    if(is_Empty(L)){
        L->end = p;
    }else{
        p->next = L->begin;
        L->begin->prev = p;
        p->prev = L->end;
        L->end->next = p;
    }
    L->begin = p;
    L->size++;
}

void Add_Last(CircList *L, int val)
{
    CircNode *p = Node_create(val);
    if(is_Empty(L)){
        L->begin = L->end = p;
    }else{
        L->end->next = p;
        p->prev = L->end;
        L->end = p;
        //Circular:
        L->begin->prev = p;
        p->next = L->begin;
    }
    L->size++;
}

void print_CircularList(const CircList *L)
{
    if(is_Empty(L)){
        fprintf(stderr, "Erro em print_CircularList()\n");
        fprintf(stderr, "Lista Vazia!\n");
        exit(EXIT_FAILURE);
    }else{
        CircNode *p = L->begin;
        printf("Lista -> ");
        do{
            printf("|%d|->", p->val);
            p = p->next;
        }while(p != L->begin);

        printf("\nL->End: |%d|\n", L->end->val);
    }
    printf("Size: %lu\n", L->size);
}

void remove_CircularList(CircList *L, int val)
{
    if(!is_Empty(L)){
        CircNode *p = L->begin;
        if(L->begin->val == val){ // Na cabeca da lista
            if(L->begin == L->end){ // Lista de 1 elemento
                L->begin = L->end = NULL;
            }else{  // Mais de 1 elemento
                L->begin = p->next;
                L->begin->prev = L->end;
                L->end->next = L->begin;
            }
            Node_Destroy(&p);
            L->size--;
        }else{ // No meio/final da lista
            p = p->next;
            while(p != L->begin){
                if(p->val == val){
                    if(L->end == p){ // Final
                        L->end = p->prev;
                    }          
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                    
                    Node_Destroy(&p);
                    L->size--;
                    break;      // Forcar a saida do while
                }else{
                    p = p->next;
                }
            }
        }
    }
}