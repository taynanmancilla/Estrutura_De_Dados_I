#ifndef LINKED_LIST_H
#define LISKED_LIST_H


typedef struct _node Node;
typedef struct _Linked_list LinkedList;

Node *Node_Create(int val); // Criar um No da lista inserindo o valor(val)
LinkedList *List_Create(); // Criar uma Lista do tipo LinkedList

void Add_First(LinkedList *lista, int val); // Insercao no primeiro elemento
void add_Last(LinkedList *lista, int val); // Insercao no fim da lista
void print(const LinkedList *lista); // Impressao dos elementos da lista


#endif //!LINKED_LIST_H