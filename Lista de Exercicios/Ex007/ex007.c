#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"ex007.h"

typedef struct _notas{
    float t1;
    float t2;
    float t3;
} Notas;

typedef struct _aluno{
    int ra;
    char *nome;
    bool cpl;
    bool aproalg;
    Notas *ntrab;
    float nsub;
    struct _aluno *next;
    struct _aluno *prev;
} Aluno;

typedef struct _list {
    Aluno *begin;
    Aluno *end;
    int size;
} List;

Aluno *create_Aluno(int ra)
//Aluno *create_Aluno(int ra, char *nome, bool cpl, bool aproalg, float t1, float t2, float t3, float nsub)
{
    Aluno *aluno = (Aluno*)calloc(1, sizeof(Aluno));
    aluno->ra = ra;
    aluno->next = NULL;
    aluno->prev = NULL;
    // aluno->nome = nome;
    // aluno->cpl = cpl;
    // aluno->aproalg = aproalg;
    // aluno->ntrab->t1 = t1;
    // aluno->ntrab->t2 = t2;
    // aluno->ntrab->t3 = t3;
    // aluno->nsub = nsub;

    return aluno;
}

List *List_create()
{
    List *lista = (List*)calloc(1, sizeof(List));
    lista->begin = NULL;
    lista->end = NULL;
    lista->size = 0;

    return lista;
}

bool is_Empty(const List *L)
{
    return L->size == 0;
}

void add_Aluno(List *L, int ra)
//void add_Aluno(List *L, int ra, char *nome, bool cpl, bool aproalg, float t1, float t2, float t3, float nsub)
{
    Aluno *new = create_Aluno(ra);
    //Aluno *new = create_Aluno(ra, nome, cpl, aproalg, t1, t2, t3, nsub);
    if(is_Empty(L)){
        L->begin = L->end = new;
    }else{
        if(new->ra < L->begin->ra){ // Se o New valor for menor que o primeiro elemento da Lista
            new->next = L->begin; // New aponta pro primeiro elemento
            L->begin->prev = new; 
            L->begin = new; // New passa a ser o Primeiro elemento
        }else{
            Aluno *aux = L->begin; // Ponteiro auxiliar pra percorrer a Lista
            while(aux->next && new->ra > aux->next->ra){ // Se existe um proximo E o Novo valor for maior q o proximo
                aux = aux->next; // Auxiliar pula pro proximo
            }
        // Achou um maior que o New
        new->next = aux; // New aponta para o maior que ele
        new->prev = aux->prev; // Prev do New aponta pro Prev do Maior
        aux->prev->next = new; // Anterior do Maior recebe o novo
        aux->prev = new; // Prev do Maior eh o New
        }
    }
    L->size++;
}

void listar_Alunos(const List *L)
{
    Aluno *p = L->begin;
    printf("\n--------- Estrutura de Dados - Lista de Alunos ---------\n\n");
    while(p != NULL){
        printf("%d\n", p->ra);
        p = p->next;
    }
    printf("\n");
    // printf("Size: %d\n", L->size);
    // printf("Begin: %d\n", L->begin->ra);
    // printf("End: %d\n", L->end->ra);
}