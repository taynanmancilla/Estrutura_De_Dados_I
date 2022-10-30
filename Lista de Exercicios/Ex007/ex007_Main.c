/*
7. Pretende-se implementar um programa para armazenar e gerir a informacao referente
aos alunos inscritos na disciplina de Estrutura de Dados, utilizando para tal uma lista
duplamente ligada.
Os alunos encontram-se ordenados na lista pelo RA. Pretende-se implementar as rotinas
para inserir/alterar, pesquisar, remover, listar, gravar e ler de arquivo.
*/

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"ex007.h"

int main(){

    List *EstruturaDeDados = List_create();

    add_Aluno(EstruturaDeDados, 288430913);
    add_Aluno(EstruturaDeDados, 282696989);
    add_Aluno(EstruturaDeDados, 282883363);
    add_Aluno(EstruturaDeDados, 280009615);
    add_Aluno(EstruturaDeDados, 284912565);
    //add_Aluno(EstruturaDeDados, 288430913, "Taynan", 1, 1, 6.0, 7.8, 10, 0);

    listar_Alunos(EstruturaDeDados);



return 0;
}