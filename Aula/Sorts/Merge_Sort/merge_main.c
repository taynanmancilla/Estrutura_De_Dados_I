#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"float_vector.h"
#include"merge_sort.h"

int main(){
    int var, tam=10;
    FloatVector *arr = create(tam);

    for(int i=0; i<capacity(arr); i++){
        var = rand()%10;
        append(arr, var);
    }
    print(arr);

    int inicio = at(arr, 0);

    int fim = at(arr, tam-1);
    printf("\nInicio: %d", inicio);
    printf("\nFim: %d", fim);

/*
mergesort(arr, inicio, fim);
*/
return 0;
}