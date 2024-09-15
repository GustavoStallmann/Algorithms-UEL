#include <stdio.h>

typedef struct {
    int min, max;
} MinMax;

void get_vector_min_max(int vec[], int vec_size, MinMax *mm) {
    mm->min = vec[0];
    mm->max = vec[0];

    for (int i = 0; i < vec_size; i++) {
        if (vec[i] > mm->max) mm->max = vec[i];
        if (vec[i] < mm->min) mm->min = vec[i];
    }
}

void print_vector(int vec[], int vec_size) {
    for (int i = 0; i < vec_size; i++)
        printf("[%d]", vec[i]);

    printf("\n");
}

void fill_vector(int vec[], int vec_size) {
    for (int i = 0; i < vec_size; i++) {
        printf("Informe o valor para a posição [%d] do vetor:\n", i);
        scanf("%d", &vec[i]);
    }
}

int main() {
    const int VEC_SIZE = 5;
    int vec[VEC_SIZE];

    fill_vector(vec, VEC_SIZE);
    print_vector(vec, VEC_SIZE);

    MinMax mm_res; 
    get_vector_min_max(vec, VEC_SIZE, &mm_res);
    printf("O valor minimo corresponde a: %d\n", mm_res.min);
    printf("O valor maximo corresponde a: %d\n", mm_res.max);

    return 0;
}
