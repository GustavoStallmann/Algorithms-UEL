/*
4) Escreva um programa que contenha uma estrutura representando uma
data válida. Essa estrutura deve conter os campos dia, mês e ano. Em
seguida, leia duas datas e armazene nessa estrutura. Calcule e exiba o
número de dias que decorreram entre as duas datas.
*/

#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

int days_on_month(int month) {
    switch (month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
            break;
        case 4: case 6: case 9: case 11:
            return 30;
            break;
        case 2:
            return 28;
            break;
        default:
            return 0;
            break;
    }
}

int main( ) {
    Date date1, date2;

    printf("Insira a primeira data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &date1.day, &date1.month, &date1.year);

    printf("Insira a segunda data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &date2.day, &date2.month, &date2.year);

    int days = 0;
    do {
        days++;
        date1.day++;
        if (date1.day > days_on_month(date1.month)) {
            date1.day = 1;
            date1.month++;
            if (date1.month > 12) {
                date1.month = 1;
                date1.year++;
            }
        }
    } while( date1.day != date2.day || date1.month != date2.month || date1.year != date2.year );

    printf("Diferenca de dias entre as duas datas informadas: %d\n", days);

    return 0;
}