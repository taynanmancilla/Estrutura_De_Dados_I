
typedef struct _site Site;
typedef struct _list List;

Site *Site_create(char *nome, char *link);
List *List_create();

void add_site(List *lista, char *nome, char *link);
void print(const List *lista);