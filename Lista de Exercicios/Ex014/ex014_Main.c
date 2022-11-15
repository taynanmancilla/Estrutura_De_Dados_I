/*14.
Escreva um programa que implemente uma fila circular utilizando uma lista linear. O
programa deve ser capaz de inserir, remover e informar o tamanho da fila em um dado
momento.
*/
#include<stdio.h>
#include<stdlib.h>
#include"ex014.h"

int main(){

    Queue *fila = create_Queue();


    printf("-------- ENQUEUE (10, 50, 30) --------\n");
    enqueue_Queue(fila, 10);
    enqueue_Queue(fila, 50);
    enqueue_Queue(fila, 30);
    enqueue_Queue(fila, 40);
    enqueue_Queue(fila, 60);
    print_Queue(fila);

    dequeue_Queue(fila);

    print_Queue(fila);

    destroy_Queue(&fila);

return 0;
}