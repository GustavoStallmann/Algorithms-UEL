/*
6) Faça um programa que gerencie o estoque de um mercado e:
    * Crie e leia um vetor de 5 produtos, com os dados: código (inteiro),
    nome (máximo 15 letras), preço e quantidade.

    * Leia um pedido, composto por um código de produto e a quantidade.
    Localize este código no vetor e, se houver quantidade suficiente para
    atender ao pedido integralmente, atualize o estoque e informe o
    usuário. Repita este processo até ler um código igual a zero.
*/

#include <stdio.h>

#define PRODUCT_AMOUNT 5

struct Product {
    int barcode;
    char name[15];
    float price;
    int amount;
} product_list[PRODUCT_AMOUNT], order_product;

void insert_products( ) {
    printf("Insira os produtos no estoque do sistema: \n\n");
    for (int i = 0; i < PRODUCT_AMOUNT; i++) {
        printf("Codigo do produto: \n");
        scanf("%d", &product_list[i].barcode);

        printf("Nome do produto: \n");
        setbuf(stdin, NULL);
        gets(product_list[i].name);

        printf("Preco do produto: \n");
        scanf("%f", &product_list[i].price);

        printf("Quantidade do produto em estoque: \n");
        scanf("%d", &product_list[i].amount);
    }
}

int create_product_order(struct Product product) {
    for (int i = 0; i < PRODUCT_AMOUNT; i++) {
        if (product_list[i].barcode != product.barcode) continue;

        if (product_list[i].amount < product.amount) {
            return -1;
        }

        product_list[i].amount -= product.amount;
        return i;
    }

    return -1;
}

int main () {
    insert_products( );

    while(1) {
        printf("Digite o codigo para buscar o produto: \n");
        scanf("%d", &order_product.barcode);

        printf("Digite a quantidade desejada do produto: \n");
        scanf("%d", &order_product.amount);

        int prod_index = create_product_order(order_product);
        if (prod_index == -1) {
            printf("O produto solicitado nao tem quantidade em estoque suficiente.\n");
            continue;
        };  

        printf("Nova quantidade do produto [%s] em estoque: %dun.\n", product_list[prod_index].name, product_list[prod_index].amount);
    }
    
    return 0;
}