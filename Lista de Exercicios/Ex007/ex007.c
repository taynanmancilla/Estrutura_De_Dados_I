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
    int *ra;
    char *nome;
    bool *cpl;
    bool *aproalg;
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

Aluno *create_Aluno(int ra, char *nome, bool *cpl, bool *aproalg, float t1, float t2, float t3, float nsub)
{
    Aluno *aluno = ( Aluno*)calloc(1, sizeof(Aluno));
    aluno->ra = ra;
    aluno->nome = nome;
    aluno->cpl = cpl;
    aluno->aproalg = aproalg;
    aluno->ntrab->t1 = t1;
    aluno->ntrab->t2 = t2;
    aluno->ntrab->t3 = t3;
    aluno->nsub = nsub;

    return aluno;
}

List *List_create()
{
    List *lista = (List*)calloc(1, sizeof(List));
    lista->begin = NULL;
    lista->end = NULL;
    lista->size = 0;
}
