/*Considere uma colecao de nomes de sites da web e seus respectivos links na Internet 
armazenados atraves de uma lista simplesmente encadeada. Escreva uma classe que contenha
um metodo que, dado o nome de um site, busque o seu link correspondente na lista e ao
mesmo tempo mova o noh que contem o nome buscado para o inıcio da lista, de forma que
ele possa ser encontrado mais rapidamente na proxima vez que for buscado.*/

#include<stdio.h>
#include<stdlib.h>
#include "ex003.h"


int main(){

    List *Lista = List_create();

    add_site(Lista, "Facebook", "https://facebook.com");
    add_site(Lista, "Instagram", "https://instagram.com");
    add_site(Lista, "Xvideos", "https://xvideos.com");
    add_site(Lista, "Ifms", "https://ifms.edu.com.br");
    print(Lista);

return 0;
}