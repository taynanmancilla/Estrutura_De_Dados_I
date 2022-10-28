typedef struct _aluno Aluno;
typedef struct _list List;
typedef struct _notas Notas;

Aluno *create_Aluno(int ra, char *nome, bool *cpl, bool *aproalg, float t1, float t2, float t3, float nsub);
List *List_create();
