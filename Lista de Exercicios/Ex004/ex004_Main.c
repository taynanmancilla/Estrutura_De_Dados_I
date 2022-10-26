/*Pretende-se utilizar uma lista ligada simples para realizar a gestao de uma lista telefonica.
A lista devera armazenar a morada de cada assinante. O programa devera realizar as seguintes
funcoes: inserir, remover, listar, pesquisar, gravar em ficheiro, ler de ficheiro, e
contar o numero de elementos na lista.*/

#include"ex004.h"

int main(){
    Book *PhoneBook = create_Book();

    insert_Subscriber(PhoneBook, "Taynan", "18933009853", "Rua Descanso", "45", "Primavera");
    insert_Subscriber(PhoneBook, "Icaro", "18997032683", "Rua Zacarias", "1409", "Tres Lagoas");
    insert_Subscriber(PhoneBook, "Juliana", "6740048622", "Pirarucu", "1312", "Florianopolis");

    print_Book(PhoneBook);

return 0;
}