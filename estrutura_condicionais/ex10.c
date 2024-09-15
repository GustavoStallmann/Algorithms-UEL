/*
10) Escreva um algoritmo para calcular o valor a ser pago por um produto, considerando o 
preço original e a forma de pagamento escolhida. Consulte a tabela abaixo para identificar 
o código de pagamento escolhido e efetue o cálculo correspondente

Código Condição de pagamento  
                                                                                                                                       
1 - À vista em dinheiro ou cheque, recebe 10% de desconto 
2 - À vista no cartão de crédito, recebe 15% de desconto 
3 - Em duas vezes, preço normal de etiqueta sem juros 
4 - Em duas vezes, preço normal de etiqueta mais juros de 10%
*/

#include <stdio.h>

float calc_payment_value(int product_price, int payment_method) {
    float final_price;

    switch (payment_method)
    {
    case 1:
        final_price = product_price * 0.90;
        break;
    case 2: 
        final_price = product_price * 0.85;
        break;
    case 3: 
        final_price = product_price;
        break;
    case 4: 
        final_price = product_price * 1.10;
        break;
    default:
        break;
    } 

    return final_price;
}

int main( ) {
    int product_price, payment_method;

    printf("Insira o valor do produto que sera pago: \n");
    scanf("%f", &product_price);

    do {
        printf("Escolha um dos metodos de pagamentos abaixo: \n");
        printf("[1] - A vista em dinheiro ou cheque (10%% de desconto);\n");
        printf("[2] - A vista no cartao de credito (15%% de desconto);\n");
        printf("[3] - Em 2x (preco inicial);\n");
        printf("[4] - Em 4x (+10%% de juros).\n");
        scanf("%d", &payment_method);
    } while (payment_method > 5 || payment_method < 0 || &payment_method == NULL);
    
    float final_price = calc_payment_value(product_price, payment_method);
    printf("O valor final do produto de acordo com o metodo de pagamento selecionado corresponde a: \n");
    printf("%0.2f", final_price);
    return 0;
}