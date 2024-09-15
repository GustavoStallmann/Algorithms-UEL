/*
12)  Faça  um  programa  que  simule  ‘virtualmente’  a  memória  de  um 
computador: o usuário começa especificando o tamanho da memória (define 
quantos bytes tem a memória), e depois ele irá ter 2 opções: inserir um dado 
em  um  determinado  endereço,  ou  consultar  o  dado  contido  em  um 
determinado endereço. A memória deve iniciar com todos os dados zerados.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size; 
    int *storage;
} Memory;

Memory init_memory(int mem_size) {
    if (mem_size <= 0) printf("O tamanho da memoria deve ser maior que 0");
    Memory mem = {.size = mem_size};
    mem.storage = (int *) calloc(mem_size, sizeof(int));

    return mem;
}

void print_mem_values(Memory mem) {
    for (int i = 0; i < mem.size; i++) {
        printf("[%d]", mem.storage[i]);
    }
    printf("\n");
}

void print_mem_value_by_pos(Memory mem, int pos) {
    if (mem.size < pos || pos < 0) printf("Posição da memoria incorreta");
    printf("\t[%d]\n", mem.storage[pos]);
}

void include_value(Memory mem, int value, int position) {
    if (mem.size < position || position < 0) printf("Insercao impossivel.");

    mem.storage[position] = value;
}

int main( ) {
    int mem_size; 
    printf("Informe o tamanho da memoria:\n");
    scanf("%d", &mem_size);

    Memory mem = init_memory(mem_size);

    int opt; 
    do {
        printf("[0] - Sair\n");
        printf("[1] - Ver memoria\n");
        printf("[2] - Ver valor de uma posicao\n");
        printf("[3] - Inserir valor\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                print_mem_values(mem);
            case 2: 
                int pos; 
                printf("Insira a posição:\n");
                scanf("%d", &pos);

                print_mem_value_by_pos(mem, pos);
            case 3: 
                int value, position;

                printf("Insira a posição: \n ");
                scanf("%d", &position);
                
                printf("Insira o valor: \n");
                scanf("%d", &value);

                include_value(mem, value, position);
            default:
                break;
        }
    } while (opt != 0);

    return 0;
}