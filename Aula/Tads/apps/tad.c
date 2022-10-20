#include<stdlib.h>
//#include<stdio.h> | ja incluida no arquivo de especificacoes
#include<string.h>
#include"float_vector.h"

int main(int argc, char const *argv[]){

    FloatVector *vetor = create(2);

    print(vetor);

    append(vetor, 2.0);
    append(vetor, 0.0);
    append(vetor, 0.0);
    append(vetor, 2.0);

    print(vetor);

    append(vetor, 2.0);


    destroy(&vetor);
return 0;
}

/*
COMPILACAO:

    gcc -c float_vector.c // Gerando arquivo objeto(.o)
    gcc tad.c float_vector.o -o tad // Gerando o executavel do programa
    .\tad // Rodando o programa

*/