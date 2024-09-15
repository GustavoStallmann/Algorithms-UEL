/*
6)  Crie  um  programa  que  contenha  um  array  de  inteiros  com  cinco 
elementos.  Utilizando  apenas  aritmética  de  ponteiros,  leia  esse  array  do 
teclado e imprima o dobro de cada valor lido.
*/

#include <stdio.h>
#define ARR_SIZE 5

void read_arr_values(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Digite o %do valor:\n", i+1);
        scanf("%d", &arr[i]);
    }
}

void double_arr_values(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * 2; 
    }
}

void print_arr(int arr[], int size) {
    for (int i = 0; i < size; i++) 
        printf("[%d]", arr[i]);
}

int main( ) {
    int arr[ARR_SIZE];

    read_arr_values(arr, ARR_SIZE);
    double_arr_values(arr, ARR_SIZE);
    print_arr(arr, ARR_SIZE);

    return 0;
}