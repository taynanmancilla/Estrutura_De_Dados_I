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

void print_sites(const List *lista)
{
    Site *p = lista->begin;
    int i=0;
    printf("\n---------Sites---------\n");
    //Enquanto P apontar para um no existente
    while(p != NULL){
        printf("|%s|->",p->nome);
        p = p->next;
    }
    printf("NULL\n");
    printf("Begin: %s\n", lista->begin->nome);
    printf("End: %s\n", lista->end->nome);
}

void get_site(List *lista, char *nome)
{
    if(is_Empty(lista)){
        fprintf(stderr, "ERRO em 'get()'\n");
        fprintf(stderr, "Lista Vazia\n");
        exit(EXIT_FAILURE);
    }else{
        Site *p = lista->begin;
        Site *ant = NULL;
        while(p->nome != nome){
            ant = p;
            p = p->next;
        }
        if(lista->begin->nome == p->nome){                      // No Inicio
            printf("\nBusca: %s\nLink: %s\n", p->nome, p->link);
        }else if(lista->end->nome == p->nome){                  // No Fim
            p->next = lista->begin;
            lista->begin = p;
            lista->end = ant;
            ant->next = NULL;
            printf("\nBusca: %s\nLink: %s\n", p->nome, p->link);
        }else{                                                  // No Meio
            ant->next = p->next;
            p->next = lista->begin;
            lista->begin = p;
            printf("\nBusca: %s\nLink: %s\n", p->nome, p->link);
        }
    }
}
