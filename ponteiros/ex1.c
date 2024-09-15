/*
1)  Escreva  um  programa  que  declare  um  inteiro,  um  real  e  um  char,  e 
ponteiros  para  inteiro,  real  e  char.  Associe  as  variáveis  aos  ponteiros. 
Modifique  os  valores  de  cada  variável  usando  os  ponteiros.  Imprima  os 
valores das variáveis antes e apo ́s a modificação.
*/
#include <stdio.h>

int main( ) {
    int integer = 10, *integer_p = &integer; 
    float real = 5.5, *real_p = &real; 
    char character = 'a', *character_p = &character;
    printf("Valores antes da modificação:\n");
    printf("Inteiro %d\n", *integer_p);
    printf("Float %f\n", *real_p);
    printf("Char %c\n", *character_p);

    *integer_p = 20;
    *real_p = 10.5;
    *character_p = 'b';

    printf("Valores antes da modificação:\n ");
    printf("Inteiro %d\n", *integer_p);
    printf("Float %f\n", *real_p);
    printf("Char %c\n", *character_p);
    return 0;
}
