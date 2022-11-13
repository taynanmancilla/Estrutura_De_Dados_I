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

    Notas *trabalho;
    List *EstruturaDeDados = List_create();

    // add_Aluno(EstruturaDeDados, 288430913, "Taynan", true, true, 6.0, 7.8, 10.0, 0.0);
    // add_Aluno(EstruturaDeDados, 282696989, "Beatriz", false, true, 5.0, 8.0, 1.0, 7.0);
    // add_Aluno(EstruturaDeDados, 285696989, "Maria", false, false, 10.0, 9.8, 10.0, 0.0);
    // add_Aluno(EstruturaDeDados, 282883363, "Icaro", true, false, 3.0, 4.8, 7.0, 0.0);
    // add_Aluno(EstruturaDeDados, 280009615, "Tereza", false, true, 1.0, 2.8, 0.0, 6.5);
    // add_Aluno(EstruturaDeDados, 284912565, "Nathalia", false, false, 4.5, 8.8, 10.0, 6.0);
    // add_Aluno(EstruturaDeDados, 288430913, "Jose", true, true, 10.0, 1.0, 4.8, 8.6);

    // add_Aluno(EstruturaDeDados, 288430913, "Taynan", 1, 1, 6.0, 7.8, 10.0, 0.0);
    // add_Aluno(EstruturaDeDados, 282696989, "Beatriz", 0, 1, 5.0, 8.0, 1.0, 7.0);
    // add_Aluno(EstruturaDeDados, 285696989, "Maria", 0, 0, 10.0, 9.8, 10.0, 0.0);
    // add_Aluno(EstruturaDeDados, 282883363, "Icaro", 1, 0, 3.0, 4.8, 7.0, 0.0);
    // add_Aluno(EstruturaDeDados, 280009615, "Tereza", 0, 1, 1.0, 2.8, 0.0, 6.5);
    // add_Aluno(EstruturaDeDados, 284912565, "Nathalia", 0, 0, 4.5, 8.8, 10.0, 6.0);
    // add_Aluno(EstruturaDeDados, 288430913, "Jose", 1, 1, 10.0, 1.0, 4.8, 8.6);

    // add_Aluno(EstruturaDeDados, 288430913, "Taynan", 1, 1);
    // add_Aluno(EstruturaDeDados, 282696989, "Rafael", 0, 1);
    // add_Aluno(EstruturaDeDados, 285696989, "Thiago", 0, 0);
    // add_Aluno(EstruturaDeDados, 282883363, "Daniel", 1, 0);
    // add_Aluno(EstruturaDeDados, 280009615, "Tereza", 0, 1);
    // add_Aluno(EstruturaDeDados, 284912565, "Samuel", 0, 0);
    // add_Aluno(EstruturaDeDados, 288430913, "Wesley", 1, 1);

    // add_Aluno(EstruturaDeDados, 288430913, "Taynan", 1, 1, 6.0, 7.8, 10.0);
    // add_Aluno(EstruturaDeDados, 282696989, "Rafael", 0, 1, 5.0, 8.0, 1.0);
    // add_Aluno(EstruturaDeDados, 285696989, "Thiago", 0, 0, 10.0, 9.8, 10.0);
    // add_Aluno(EstruturaDeDados, 282883363, "Daniel", 1, 0, 3.0, 4.8, 7.0);
    // add_Aluno(EstruturaDeDados, 280009615, "Tereza", 0, 1, 1.0, 2.8, 0.0);
    // add_Aluno(EstruturaDeDados, 284912565, "Samuel", 0, 0, 4.5, 8.8, 10.0);
    // add_Aluno(EstruturaDeDados, 288430913, "Wesley", 1, 1, 10.0, 1.0, 4.8);
    
    add_Aluno(EstruturaDeDados, 288430913, "Taynan", 1, 1, {6.0, 7.8, 10.0});
    add_Aluno(EstruturaDeDados, 282696989, "Rafael", 0, 1, {5.0, 8.0, 1.0});
    add_Aluno(EstruturaDeDados, 285696989, "Thiago", 0, 0, {10.0, 9.8, 10.0});
    add_Aluno(EstruturaDeDados, 282883363, "Daniel", 1, 0, {3.0, 4.8, 7.0});
    add_Aluno(EstruturaDeDados, 280009615, "Tereza", 0, 1, {1.0, 2.8, 0.0});
    add_Aluno(EstruturaDeDados, 284912565, "Samuel", 0, 0, {4.5, 8.8, 10.0});
    add_Aluno(EstruturaDeDados, 288430913, "Wesley", 1, 1, {10.0, 1.0, 4.8});
        

    listar_Alunos(EstruturaDeDados);

return 0;
}