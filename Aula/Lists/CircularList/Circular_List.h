#include<stdbool.h>

typedef struct _circ_node CircNode, Node;
typedef struct _circ_list CircList, List;

Node *Node_create(int val);
CircList *List_create();

void Node_Destroy(CircNode **Ref_node);
void List_Destroy(CircList **Ref_list);
bool is_Empty(const CircList *lista);

void Add_First(CircList *L, int val); // Insercao no primeiro elemento
void Add_Last(CircList *L, int val);
