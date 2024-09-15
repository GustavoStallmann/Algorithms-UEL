/*
8) O IMC (índice de massa corporal) é um critério da OMS (Organização Mundial de Saúde) 
que fornece uma indicação sobre o peso corporal de uma pessoa adulta. A fórmula do IMC 
é calculada dividindo o peso pela altura ao quadrado. Escreva um algoritmo para que seja 
possível fornecer o peso e a altura de um adulto, e, assim, mostrar sua condição de acordo 
com a tabela a seguir: 
 
IMC em adultos: 
• Abaixo de 18,5: Abaixo do peso  
• Entre 18,5 e 25: Peso normal  
• Entre 25 e 30: Acima do peso  
• Acima de 30 obeso
*/

#include <stdio.h>
#include <math.h>

float calc_imc(float height, float weight) {
    return weight / pow(height, 2);
}

void classify_imc(float imc) {
    if (imc < 18.5) {
        printf("A pessoa está abaixo do peso.\n"); 
    } else if (imc < 25) {
        printf("A pessoa está no peso ideal.\n");
    } else if ( imc < 30) {
        printf("A pessoa está acima do peso.\n");
    } else {
        printf("A pessoa está obesa.\n");
    }
}

int main( ) {
    float height, weight;

    printf("Calcule o IMC de uma pessoa: \n\n");
    printf("Digite a altura (cm):\n");
    scanf("%f", &height);

    printf("Digite o peso (kg):\n");
    scanf("%f", &weight);

    int imc = calc_imc(height, weight);
    classify_imc(imc);

    return 0;
}