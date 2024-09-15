/*
8) Faça uma função que recebe, por parâmetros, a hora de início e a hora de
término de um jogo, ambas subdivididas em 2 valores distintos: horas e
minutos. A função deve retornar a duração do jogo em minutos,
considerando que o tempo máximo de duração de um jogo é de 24 horas e
que o jogo pode começar em um dia e terminar no outro.
*/

#include <stdio.h>

typedef struct {
    int hour;
    int minutes;
} Time;

void read_time(Time time) {
    printf("Insira a hora: (hh)\n");
    scanf("%d", &time.hour);

    printf("Insira os minutos: (mm)\n");
    scanf("%d", &time.minutes);
}

int get_game_duration_minutes(Time start_time, Time end_time) {
    int minutes_count = 0;

    do {
        if (start_time.minutes < 60) {
            minutes_count++;
            start_time.minutes++;
        } else { 
            start_time.minutes = 0;
            start_time.hour++;
        };
    } while (
        start_time.hour != end_time.hour && start_time.minutes != end_time.minutes
    );    

    return minutes_count;
}

int main( ) {
    Time time1, time2;
    read_time(time1);
    read_time(time2);

    int result = get_game_duration_minutes(time1, time2);
    printf("Duração do jogo em minutos: \n");

    return 0;
}