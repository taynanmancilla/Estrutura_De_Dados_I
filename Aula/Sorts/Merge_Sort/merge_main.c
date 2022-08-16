#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"float_vector.h"
#include"merge_sort.h"

int main(){
    //int var;
    FloatVector *arr = create(10);
    for(int i; i<capacity(arr); i++){
        int var = rand()%10;
        append(arr, var);
    }
    print(arr);
return 0;
}