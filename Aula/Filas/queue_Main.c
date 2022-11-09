#include"static_queue.c"

int main(){

    StaticQueue *fila = create_StaticQueue(3);

    enqueue_StaticQueue(10, fila);
    enqueue_StaticQueue(50, fila);
    enqueue_StaticQueue(30, fila);

    print_StaticQueue(fila);


return 0;
}