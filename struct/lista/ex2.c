/*
2) Crie uma estrutura para representar as coordenadas de um ponto no
plano (posições X e Y). Em seguida, declare e leia do teclado dois pontos e
exiba a distância entre eles.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Coordinate {
    int x;
    int y;
} coordinates[2];

typedef struct Coordinate cord; 

double get_distance_between_coordinates(cord first_cord, cord sec_cord) {
    int x_dist = abs(first_cord.x - sec_cord.x); 
    int y_dist = abs(first_cord.y - sec_cord.y);

    int distance = pow(x_dist, 2) + pow(y_dist, 2);
   
    return sqrt(distance);
}

int main () {
    for (int i = 0; i < 2; i++){
        printf("Digite o ponto X da coordenada [%d/%d]: \n", i+1, 2);
        scanf("%d", &coordinates[i].x);

        printf("Digite o ponto Y da coordenada [%d/%d]: \n", i+1, 2);
        scanf("%d", &coordinates[i].y);
    }

    double distance = get_distance_between_coordinates(coordinates[0], coordinates[1]);
    printf("A distancia entre o ponto X e Y corresponde a: %0.2f", distance);
    return 0;
}