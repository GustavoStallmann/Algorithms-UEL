/*
2) Elabore uma função que receba três números inteiros como parâmetro,
representando horas, minutos e segundos. A função deve retornar esse
horário convertido em segundos.
*/

#include <stdio.h>

int convert_to_seconds(int hours, int minutes, int seconds) {
    int hour_sec = hours * 60 * 60;
    int minutes_sec = minutes * 60; 

    return hour_sec + minutes_sec + seconds;
}

int main( ) {
    int hours, minutes, seconds; 
    printf("Informe o horario para converter em segundos: (HH:MM:SS)\n");
    scanf("%d:%d:%d", &hours, &minutes, &seconds);

    int sec_result = convert_to_seconds(hours, minutes, seconds);
    printf("O horario convertido em segundos corresponde a: %d", sec_result);
    return 0;
}