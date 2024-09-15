/*
9) Escreva um algoritmo que leia as idades de 2 homens e 2 mulheres (considere que as 
idades dos homens serão sempre diferentes, bem como as das mulheres). Calcule e escreva 
a soma das idades do homem mais velho com a mulher mais nova, e o produto das idades 
do homem mais novo com a mulher mais velha.
*/

#include <stdio.h>

int main( ) {
    int m_age1, m_age2;
    int w_age1, w_age2;

    do {    
        printf("Digite a idade do primeiro homem: \n");
        scanf("%d", &m_age1);

        printf("Digite a idade do segundo homem: \n");
        scanf("%d", &m_age2);

        printf("Digite a idade da primeira mulher: \n");
        scanf("%d", &w_age1);

        printf("Digite a idade da segunda mulher: \n");
        scanf("%d", &w_age2);
    } while (m_age1 == m_age2 || w_age1 == w_age2);

    int older_man, young_man;
    int older_woman, young_woman;

    young_man = m_age1 < m_age2 ? m_age1 : m_age2;    
    older_man = m_age1 > m_age2 ? m_age1 : m_age2;

    young_woman = w_age1 < w_age2 ? w_age1 : w_age2;
    older_woman = w_age1 > w_age2 ? w_age1 : w_age2;

    printf("\nA soma da idade do homem mais velho com a mulher mais nova corresponde a: \n");
    printf("%d", older_man + young_woman);

    printf("\nO produto da idade do homem mais novo com a idade da mulher mais velha corresponde a: \n");
    printf("%d", young_man * older_woman);    
    return 0;
}