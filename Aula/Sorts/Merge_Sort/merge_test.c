#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Tentativa 1
/*void merge(float *vector, int inicio, int meio, int fim) {
   int l1, l2, i=0;

   for(l1 = inicio, l2 = meio + 1, i = inicio; l1 <= meio && l2 <= fim; i++) {
      if(vector[l1] <= vector[l2])
         aux[i] = vector[l1++];
      else
         aux[i] = vector[l2++];
   }
   
   while(l1 <= meio)    
      aux[i++] = vector[l1++];

   while(l2 <= fim)   
      aux[i++] = vector[l2++];

   for(i = inicio; i <= fim; i++)
      vector[i] = aux[i];
}*/

//Tentativa 2:
/*void merge(int *vector, int inicio, int meio, int fim)
{
   int *aux, p1, p2, tam;
   int fim1=0, fim2=0;
   tam = fim-inicio+1;
   p1 = inicio;
   p2 = meio+1;
   aux = (int*)malloc(tam*sizeof(int));

   if(aux != NULL){
      //Percorrendo o vetor auxiliar
      for(int i=0; i<tam; i++){
         if(!fim1 && !fim2){
            //Verificando quem eh o menor elemento pra cada posicao de p1 e p2 e coloca no vetor auxiliar
            if(vector[p1] < vector[p2]){
               aux[i] = vector[p1++];
            }else{
               aux[i] = vector[p2++];
            }
            //Chegando no final do vetor
            if(p1>meio)fim1=1;
            if(p2>fim)fim2=1;
         }else{
            //Quando um dos vetores acaba, nao precisamos continuar comparando
            //simplesmente copiamos o que sobrou pro final do auxiliar
            if(!fim1){
               aux[i] = vector[p1++];
            }else{
               aux[i] = vector[p2++];
            }
         }
      }
      int k;
      //jogando os dados ordenados no vetor
      for(int j=0, k=inicio; j<tam; j++, k++){
         vector[k] = aux[j];
      }
   }
   free(aux);
}*/

//Tentativa 3:
void merge(int *vector, int inicio, int meio, int fim)
{
   int i, j, k;
   //Inicio de cada vetor auxiliar
   int pL = meio - inicio + 1;
   int pR = fim - meio;
 
   int left[pL], right[pR];// Vetores auxiliares (esquerda e direita)
   //Atribundo os valores dos vetores auxiliares
   for(i = 0; i < pL; i++){
      left[i] = vector[inicio+i];
   }
   for(j = 0; j < pR; j++){
      right[j] = vector[meio+1+j];
   }

   //Atribuindo o menor dos dois auxiliares no vetor principal:
   i=0, j=0;
   k = inicio;
   while(i < pL && j < pR){
      if (left[i] <= right[j]) {
         vector[k] = left[i];
         i++;
      }else{
         vector[k] = right[j];
         j++;
      }
      k++;
   }

   //Quando um dos vetores acaba, nao precisamos continuar comparando
   //simplesmente copiamos o que sobrou pro final do auxiliar:
   while (i < pL) {
      vector[k] = left[i];
      i++;
      k++;
   }
   while (j < pR) {
      vector[k] = right[j];
      j++;
      k++;
   }
}

void mergesort(int *vector, int inicio, int fim)
{
   if(inicio < fim) {
      //Calculando a metade
      int meio = inicio+(fim - inicio) / 2;
      //Chamando a funcao pras duas metades
      mergesort(vector, inicio, meio);
      mergesort(vector, meio+1, fim);
      //Combinando 2 metades de forma ordenada
      merge(vector, inicio, meio, fim);
   }
}


//minha:
int main() { 

   int size=10, vector[size];

   printf("\nList before sorting\n");
   srand(time(NULL));
   for(int i=0; i<size; i++){
        vector[i] = rand()%10;
      printf("%d |", vector[i]);
   }

   mergesort(vector, 0, size-1);

   printf("\nList after sorting\n");
   for(int i=0; i < size; i++){
      printf(" %d |", vector[i]);
   }

return 0;
}