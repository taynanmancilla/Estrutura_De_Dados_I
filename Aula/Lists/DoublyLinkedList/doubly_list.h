#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct _double_node DoubleNode, Node;
typedef struct _double_linked_list DoubleLinkedList, List;

Node *Node_create(int val);
DoubleLinkedList *List_create();

void Destroy(DoubleLinkedList **Ref_list);
bool is_Empty(const DoubleLinkedList *lista);
void Add_First(DoubleLinkedList *lista, int val); // Insercao no primeiro elemento
void Add_Last(DoubleLinkedList *lista, int val); // Insercao no fim da lista
void print_List(const DoubleLinkedList *lista); // Impressao dos elementos da lista
void inverted_print(const DoubleLinkedList *lista); // Impressao dos elementos da lista
void Remove(DoubleLinkedList *lista, int val); // Remove o primeiro valor(val) encontrado na lista


void add_in_Order(DoubleLinkedList *lista, int val); // Insercao ordenada na lista
int size(DoubleLinkedList *lista); // Retorna o tamanho da lista
int get(DoubleLinkedList *lista, int index); // Retorna o valor na posicao desejada

