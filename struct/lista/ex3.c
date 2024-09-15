/*
3) Crie uma estrutura chamada Retângulo. Essa estrutura deverá conter o
ponto superior esquerdo e o ponto inferior direito do retângulo. Cada
ponto é definido por uma estrutura Ponto, a qual contém as posições X e Y.
Faça um programa que declare e leia uma estrutura Retângulo e exiba a
área e o comprimento da diagonal e o perímetro desse retângulo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Pos {
    int x;
    int y;
};

struct Rect {
    struct Pos position[2];
} rectangle;


double calc_rect_diagonal(struct Rect rect) {
    int x_dist = rect.position[0].x - rect.position[1].x;
    int y_dist = rect.position[0].y - rect.position[1].y;

    int diag = pow(x_dist, 2) + pow(y_dist, 2);

    return sqrt(diag);
}

int calc_rect_area(struct Rect rect) {
    int rect_width = abs(rect.position[0].x - rect.position[1].x);
    int rect_height = abs(rect.position[0].y - rect.position[1].y); 

    int area = rect_width * rect_height;

    return area;   
}

int calc_rect_perimeter(struct Rect rect) {
    int rect_width = abs(rect.position[0].x - rect.position[1].x);
    int rect_height = abs(rect.position[0].y - rect.position[1].y); 

    int perimeter = (rect_width * 2) + (rect_height * 2);

    return perimeter;
}

int main() {
    for (int i = 0; i < 2; i++){
        printf("Digite o ponto X do ponto [%d/%d] do retangulo: \n", i+1, 2);
        scanf("%d", &rectangle.position[i].x);

        printf("Digite o ponto Y do ponto [%d/%d] do retangulo: \n", i+1, 2);
        scanf("%d", &rectangle.position[i].y);
    }

    double diag = calc_rect_diagonal(rectangle);
    printf("A diagonal do retangulo corresponde a: %0.2f\n", diag);

    int area = calc_rect_area(rectangle);
    printf("A area do retangulo corresponde a: %d\n", area);

    int perimeter = calc_rect_perimeter(rectangle);
    printf("O perimetro do retangulo corresponde a: %d\n", perimeter);

    return 0;
}