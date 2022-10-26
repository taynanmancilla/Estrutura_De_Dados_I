#include"ex004.h"

typedef struct _subscriber{
    char *telefone;
    char *nome;
    char *rua;
    char *numero;
    char *cidade;
    struct _subscriber *next;
    
}Subscriber;
typedef struct _phoneBook{
    Subscriber *begin;
    Subscriber *end;
    int size;
}Book;

Subscriber *create_Subscriber(char *nome, char *telefone, char *rua, char *numero, char *cidade)
{
    Subscriber *subscriber = (Subscriber*)calloc(1, sizeof(Subscriber));
    subscriber->nome = nome;
    subscriber->telefone = telefone;
    subscriber->rua = rua;
    subscriber->numero = numero;
    subscriber->cidade = cidade;
    
    return subscriber;
}
Book *create_Book()
{
    Book *book = (Book*)calloc(1, sizeof(Book));
    book->begin = NULL;
    book->end = NULL;
    book->size = 0;

    return book;
}

bool is_Empty(const Book *book)
{
    return book->begin == NULL;
}

// FUNCAO DE INSERIR
void insert_Subscriber(Book *book, char *nome, char *telefone, char *rua, char *numero, char *cidade)
{
    Subscriber *new = create_Subscriber(nome, telefone, rua, numero, cidade);

    if(is_Empty(book)){
        book->begin = book->end = new;
    }else{
        book->end->next = new;
        book->end = new;
    }
    book->size++;
}

// FUNCAO DE LISTAR
void print_Book(const Book *book)
{
    Subscriber *p = book->begin;
    int i=0;
    printf("\n---------PhoneBook---------\n");
    //Enquanto P apontar para um no existente
    while(p != NULL){
        printf("%s (%s): %s, %s - %s",p->telefone, p->nome, p->rua, p->numero, p->cidade);
        p = p->next;
        printf("\n");
    }
    printf("\n");
    printf("Size: %d\n", book->size);
}