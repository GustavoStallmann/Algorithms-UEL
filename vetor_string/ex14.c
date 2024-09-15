/*
14) Faça um programa que leia dois vetores de 10 elementos. Crie um vetor 
que seja a intersecção entre os 2 vetores anteriores, ou seja, que contém 
apenas  os  números  que  estão  em  ambos  os  vetores.  Não  deve  conter 
números repetidos.
*/

#include <stdio.h>
#define VEC_SIZE 2

void print_vector(int vec[], int vector_size) {
    for (int i = 0; i < vector_size; i++) {
        if (vec[i] == 0) return;

        printf("[%d]", vec[i]);
    }
    printf("\n");
}

void read_vec_values(int vec[], int vector_size) {
    for (int i = 0; i < vector_size; i++) {
        printf("Insira um valor inteiro: [%d/%d]\n", i+1, vector_size);
        scanf("%d", &vec[i]);
    }
}

int vec_include_value(int vec[], int value, int vector_size) {
    for (int i = 0; i < vector_size; i++) {
        if (vec[i] == value) return 1;
    }

    return 0;
}

void get_vector_intersection(int f_vec[], int s_vec[], int vec_intersection[], int vector_size) {
    int found_values = 0;

    for (int i = 0; i < vector_size; i++) {
        int include_value = vec_include_value(s_vec, f_vec[i], vector_size);
        
        if (include_value) {
            vec_intersection[found_values] = f_vec[i];
        }

        found_values++;
    }
} 

int main( ) {
    // int f_vec[VEC_SIZE], s_vec[VEC_SIZE];

    // read_vec_values(f_vec, VEC_SIZE);
    // read_vec_values(s_vec, VEC_SIZE);

    // int vec_intersection[VEC_SIZE];

    // get_vector_intersection(f_vec, s_vec, vec_intersection, VEC_SIZE);
    // print_vector(vec_intersection, VEC_SIZE);

    if ( 'A' < 'B') {
        printf("a e menor que b");
    }

    return 0;
}