/*13.
Escreva um programa que tenha uma fila cujos elementos possuem um campo inteiro
representando sua prioridade. Quanto menor o valor deste campo, maior a prioridade
do elemento. Insira n elementos com prioridades diversas na fila e depois divida a fila
em duas, uma com elementos cuja prioridade e menor ou igual ao valor p fornecido pelo
usuario e outra com os elementos restantes.
*/

#include"ex013.h"
#include<stdio.h>
#include<stdlib.h>

int main(){

    Queue *fila = create_Queue();

    enqueue_Queue(fila, 10, 1);
    enqueue_Queue(fila, 50, 5);
    enqueue_Queue(fila, 70, 7);
    enqueue_Queue(fila, 30, 3);
    enqueue_Queue(fila, 20, 2);
    enqueue_Queue(fila, 90, 9);
    enqueue_Queue(fila, 40, 4);
    enqueue_Queue(fila, 80, 8);
    enqueue_Queue(fila, 60, 6);
    print_Queue(fila);

    destroy_Queue(&fila);

return 0;
}
