#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int P;
} Camel; 

int main( ) {
    int N; 
    scanf("%d", &N);

    Camel camels[N];

    for (int i = 0; i < N; i++)
        scanf("%d", &camels[i].P);

    int average_p = 0;
    int p_sum = 0;
    for (int i = 0; i < N; i++)
        p_sum += camels[i].P;

    average_p = p_sum / N;

    for (int i = 0; i < N; i++) 
        printf("\n%d", average_p - camels[i].P);

    return 0;
}