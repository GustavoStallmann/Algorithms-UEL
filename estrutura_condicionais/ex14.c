/*
14) Leia uma data e determine se ela é válida. Ou seja, verifique se o mês está entre 1 e 12, 
e se o dia existe naquele mês. Note que fevereiro tem 29 dias em anos bissextos, e 28 dias 
em anos não bissextos.
*/

#include <stdio.h>

//verifica se o ano é bissexto
int is_leap_year(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int main( ) {
    int days, month, year; 
    printf("Insira a data desejada: \n");
    scanf("%d %d %d", &days, &month, &year);

    int leap_year = is_leap_year(year);

    if (
        (leap_year && month == 2 && days > 29) ||
        (month < 0 || month > 12) ||
        (days > 31) 
    ) return printf("Data invalida");

    printf("A data informada é válida\n");
    return 0;
}