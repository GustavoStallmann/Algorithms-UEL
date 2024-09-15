/*
3)  Elabore  um  programa  que  leia  do  usuário  o  tamanho  de  um  vetor  a  ser 
lido. Em seguida, faça a alocação dinâmica desse vetor. Por fim, leia o vetor 
do usuário e o imprima.
*/

#include <stdio.h> 
#include <stdlib.h>


int main( ) {
    int vec_size; 

    printf("Insira o tamanho do vetor: \n");
    scanf("%d", &vec_size);

    int *vec = malloc(sizeof(int) * vec_size);

    for (int i = 0; i < vec_size; i++) {
        printf("Informe um valor [%d/%d]:\n", i+1, vec_size);
        scanf("%d", &vec[i]);
    }

    printf("\nO vetor lido corresponde a:\n");

    for (int i = 0; i < vec_size; i++) {
        printf("[%d]", vec[i]);
    }
    
    return 0;
}
