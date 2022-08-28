#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"float_vector.h"

int main() { 

   int size=10;
   FloatVector *vector = create(size);

   printf("\nList before sorting\n");
   srand(time(NULL));
   for(int i=0; i<size; i++){
        float v = rand()%size;
        append(vector, v);
   }
   print(vector);

   mergesort(vector, 0, size);

   printf("\nList after sorting\n");
   print(vector);

return 0;
}