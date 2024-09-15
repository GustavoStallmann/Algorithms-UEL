#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year; 
    //int day, month, year; *os dois jeitos estão corretos*
} Date;

int calc_date_distance(Date f_date, Date s_date) {
    int day_count = 0; 

    while (f_date.day != s_date.day || f_date.month != s_date.month || f_date.year != s_date.year) {
        f_date.day++; 
        day_count++; 

        if (f_date.day > 30) {
            f_date.day = 1; 
            f_date.month++; 
        }

        if (f_date.month > 12) {
            f_date.month = 1; 
            f_date.year++; 
        }
    }

    return day_count; 
}

int main( ) {
    Date f_date, s_date; 

    printf("Insira uma data valida: \n");
    scanf("%d %d %d", &f_date);

    printf("Insira uma data valida: \n");
    scanf("%d %d %d", &s_date);

    printf("A diferença entre as datas é de %d dias.\n", calc_date_distance(f_date, s_date));

    return 0;
}