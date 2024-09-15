/*
11) Escreva um programa que lê primeiro os 6 números gerados pela loteria 
na  noite  de  sábado  na  TV  e  depois  lê  seus  próprios  6  números.  Então,  o 
programa  compara  quantos  números  o  jogador  acertou.  Em  seguida,  ele 
aloca  espaço  para  um  vetor  de  tamanho  igual  a  quantidade  de  números 
corretos e guarda os números corretos nesse vetor. Finalmente, o programa 
exibe os números sorteados e os seus números corretos.
*/

#include <stdio.h>
#include <stdlib.h>

#define LOT_NUM 6

void print_lottery_numbers(int lottery_nums[], int vec_size) {
    for (int i = 0; i < vec_size; i++) {
        printf("[%d]", lottery_nums[i]);
    }
    printf("\n");
}

void read_lottery_numbers(int lottery_nums[], int vec_size) {
    printf("Insira os numeros gerados pela loteria no sabado: \n");
    for (int i = 0; i < vec_size; i++) {
        printf("Numero [%d/%d]: ", i+1, vec_size);
        scanf("%d", &lottery_nums[i]);
    }
}

int* verify_number_matches(int lottery_nums[], int player_nums[], int size) {
    int *result = NULL; 
    int matches = 0; 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (lottery_nums[i] != player_nums[j]) continue;

            matches++;
            result = (int *) realloc(result, matches * sizeof(int));
            *(result + matches) = player_nums[j];
        }
    }

    return result;
}

int main( ) {
    int lottery_nums[LOT_NUM];
    read_lottery_numbers(lottery_nums, LOT_NUM);
    printf("Numeros sorteados: \n");
    print_lottery_numbers(lottery_nums, LOT_NUM);

    int player_nums[LOT_NUM];
    read_lottery_numbers(player_nums, LOT_NUM);
    printf("Numeros do jogador: \n");
    print_lottery_numbers(player_nums, LOT_NUM);

    int *result = verify_number_matches(lottery_nums, player_nums, LOT_NUM);
    printf("Acertos do jogador: \n");
    print_lottery_numbers(result, LOT_NUM);


    return 0;
}