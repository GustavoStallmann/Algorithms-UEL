#include <stdio.h>
#include <stdbool.h>

void print_vector(float vec[]) {
    for (int i = 0; i < 10; i++) {
        printf("[%0.2f]", vec[i]);
    }
}

int main () {
    float vec[10];

    for (int i = 0; i < 10; i++) {
        printf("Insira um valor [%d/%d]\n", i+1, 10);
        scanf("%f", &vec[i]);
    }

    int index = 0, passes = 0;
    while (true) {
        if (index == 9) index = 0;
        
        if (vec[index] > vec[index+1]) {
            float temp = vec[index];
            vec[index] = vec[index+1];
            vec[index + 1] = temp;
            passes = 0;
        } else {
            index++;
            passes++;
        }

        if (passes >= 9) break; 
    }

    print_vector(vec);

    return 0;
}