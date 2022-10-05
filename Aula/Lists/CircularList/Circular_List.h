#include<stdbool.h>

typedef struct _circ_node CircNode, Node;
typedef struct _circ_list CircList, List;

Node *Node_create(int val);
CircList *List_create();

void Destroy(CircList **Ref_list);
bool is_Empty(const CircList *lista);

