#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "ex003.h"

typedef struct _site{
    char *nome;
    char *link;
    struct _site *next;
    
}Site;

typedef struct _list{
    Site *begin;
    Site *end;
}List;

Site *Site_create(char *nome, char *link)
{
    Site *site = (Site*)calloc(1, sizeof(Site));
    site->nome = nome;
    site->link = link;
    return site;
}

List *List_create()
{
    List *lista = (List*)calloc(1, sizeof(List));
    lista->begin = NULL;
    lista->end = NULL;

    return lista;
}

bool is_Empty(const List *lista)
{
    return lista->begin == NULL;
}

void add_site(List *lista, char *nome, char *link)
{
    Site *new = Site_create(nome, link);

    //Se a lista estiver vazia
    if(is_Empty(lista)){
        lista->begin = lista->end = new;
    }else{
        lista->end->next = new; // Proximo elemento do ultimo Node aponta pro novo
        lista->end = lista->end->next; // O novo Node passa a ser o End
    }
    //lista->size++;
}

void print(const List *lista)
{
    Site *p = lista->begin;
    int i=0;
    printf("\tSites:\n");
    //Enquanto P apontar para um no existente
    while(p != NULL){
        printf("Site: %s hospedado em %s",p->nome, p->link);
        printf("\n");
        p = p->next;
    }
}
