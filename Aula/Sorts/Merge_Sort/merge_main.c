#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"float_vector.h"

void run(FloatVector *vetor, int size)
{
    
    double time_spent = 0.0;

    clock_t begin = clock();

   srand(time(NULL));
   for(int i=0; i<size; i++){
        float v = rand()%size;
        append(vetor, v);
   }
   mergesort(vetor, 0, size);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
   recordMerge(size, time_spent);
}

int main() { 

   int size = 1000000;
   FloatVector *vector = create(size);
   run(vector, size);
   free(vector);
/*
   int size = 1000;
   FloatVector *vector = create(size);
   run(vector, size);
   free(vector);

   int size = 10000;
   FloatVector *vector = create(size);
   run(vector, size);
   free(vector);

   int size = 500000;
   FloatVector *vector = create(size);
   run(vector, size);
   free(vector);

   int size = 1000000;
   FloatVector *vector = create(size);
   run(vector, size);
   free(vector);
*/
return 0;
}