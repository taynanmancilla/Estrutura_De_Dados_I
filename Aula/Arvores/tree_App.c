#include"tree.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int val, size, i=0, j=0, igual, vet[255];
    int vetor[7] = {40, 20, 60, 10, 30, 50, 70};
    Tree *t = create_tree();

/*
    int val[6] = {10, 8, 3, 9, 17, 16};

    
    for(int i=0; i<6; i++){
        insert(t, val[i]);
    }

    removeVal(t, 3);
    pre_order(t);

    printf("\nSearch (9):\n");
    search(t, 9);
    printf("\nSearch (3):\n");
    search(t, 3);

    // puts("Removendo...");
    // //removeVal(t, 10);
    // pre_order(t);
*/

    int op = 999;
    while(op != 0)
    {
        printf("\n\n");
        printf("1 - Inserir Elemento\n");
        printf("2 - Deletar Elemento\n");
        printf("3 - Consultar Elemento\n");
        printf("4 - Arvore Simetrica\n");
        printf("5 - Imprimir Pre_Order\n");
        printf("6 - Imprimir In_Order\n");
        printf("7 - Imprimir Pos_Order\n");
        printf("8 - Desenhar Arvore\n");
        printf("9 - DESTRUIR Arvore\n");
        printf("0 - Sair\n\n>: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("Arvore Aleatoria(1) ou Exemplo de Arvore Simetrica (2)? >: ");
                scanf("%d", &size);
                if(size == 1){
                    printf("Quantos elementos deseja gerar?\n>: ");
                    scanf("%d", &size);
                    do{
                        vet[i] = rand()%100;
                        igual = 0;
                        for(j=0;j<i; j++){
                            if(vet[j] == vet[i]) { igual = 1; }
                        }
                        if(igual == 0){ i++; }

                    }while(i<size);
                    for(i=0;i<size; i++){
                       insert(t, vet[i]);
                    }
                }else{
                    for(i=0;i<7; i++){
                        insert(t, vetor[i]);
                    }
                }
                
                break;
            case 2:
                printf("Qual valor deseja remover?\n>: ");
                scanf("%d", &size);
                removeVal(t, size);
                break;
            case 3:
                printf("Qual elemento deseja consultar?\n>: ");
                scanf("%d", &size);
                search(t, size);
                break;
            case 4:
                arvore_simetrica(t);
                break;
            case 5:
                printf("PRE-ORDER:\n");
                pre_order(t);
                break;
            case 6:
                printf("IN-ORDER:\n");
                in_order(t);
                break;
            case 7:
                printf("POS-ORDER:\n");
                pos_order(t);
                break;
            case 8:
                printf("DESENHO:\n");
                draw_tree(t);
                break;
            case 9:
                destroy_tree(t);
                printf("Arvore Destruida com Sucesso!\n");
                break;
        }
    }


return 0;
}