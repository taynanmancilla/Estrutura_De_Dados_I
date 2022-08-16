#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"float_vector.h"
#include"merge_sort.h"

int main(){
    //int var;
    FloatVector *arr = create(10);
    for(int i=0; i<capacity(arr); i++){
        int var = rand()%10;
        append(arr, var);
    }
    print(arr);

int inicio = get(arr, 0);
int fim = get(arr, size(arr));

mergesort(*arr, inicio, fim);

return 0;
}