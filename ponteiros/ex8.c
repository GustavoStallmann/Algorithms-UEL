/*8) Crie uma função que receba dois parâmetros: um vetor e um valor do
mesmo tipo do vetor. A função deverá preencher os elementos de vetor com
esse valor. Não utilize índices para percorrer o vetor, apenas aritmética de
ponteiros.*/

#include <stdio.h>

const int VEC_SIZE = 5;

void fillVector(int vec[], int value) {
	for (int i = 0; i < VEC_SIZE; i++)
		*(vec + i) = value;
}

void printVector(int vec[]) {
	for (int i = 0; i < VEC_SIZE; i++)
		printf("[%d]", *(vec + i));
}

int main() {
	int vector[VEC_SIZE], value; 

	printf("Insira o valor ao qual o vetor sera preenchido: \n");
	scanf("%d", &value);

	fillVector(vector, value);
	printVector(vector);

	return 0;
}
