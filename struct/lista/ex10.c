/*
10) Escreva um programa que receba dois structs do tipo dma, cada um
representando uma data válida, e calcule o número de dias que decorreram
entre as duas datas.
struct dma {
    int dia;
    int mes;
    int ano;
};
Lembre-se de considerar anos bissextos.
*/

#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

/*
O ano será bissexto se divisível por 400, ou por 4 mas não divisível por 100;
*/
int is_leap_year(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int days_on_month(int month, int year) {
    switch (month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
            break;
        case 4: case 6: case 9: case 11:
            return 30;
            break;
        case 2:
            if (is_leap_year(year)) {
                return 29;
            } else {
                return 28;
            }
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
        if (date1.day > days_on_month(date1.month, date1.year)) {
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