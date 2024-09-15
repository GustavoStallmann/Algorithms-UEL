/*
17) Uma empresa decide dar um aumento aos seus funcionários de acordo com uma tabela 
que  considera  o  salário  atual  e  o  tempo  de  serviço  de  cada  funcionário.  Os  funcionários 
com  menor  salário  terão  um  aumento  proporcionalmente  maior  do  que  os  funcionários 
com  um  salário  maior,  e  conforme  o  tempo  de  serviço  na  empresa,  cada  funcionário  irá 
receber um bônus de salário. Faça um programa que leia: 
• o valor do salário atual do funcionário; 
• o tempo de serviço desse funcionário na empresa (número de anos de trabalho na 
empresa). 
 
Use as tabelas abaixo para calcular o salário reajustado deste funcionário e imprima o valor 
do  salário  final  reajustado,  ou  uma  mensagem  caso  o  funcionário  não  tenha  direito  a 
nenhum aumento
*/

#include <stdio.h>

float add_percentage(float value, float percentage) {
    return value+(value*percentage);
}

float calc_new_salary(int work_years, float current_salary) {
    if (current_salary < 500 || work_years < 1) 
        return add_percentage(current_salary, 0.25);

    if (current_salary < 1000 || work_years < 3)
        return add_percentage(current_salary, 0.20) + 100;

    if (current_salary < 1500 || work_years < 6) 
        return add_percentage(current_salary, 0.15) + 200;

    if (current_salary < 2000 || work_years < 10)
        return add_percentage(current_salary, 0.10) + 300;

    return current_salary + 500;
}


int main () {
    int work_years;
    float actual_salary;

    printf("Insira o atual salário do funcionário: \n");
    scanf("%f", &actual_salary);

    printf("Insira os anos de trabalho: \n");
    scanf("%f", &work_years);

    float result = calc_new_salary(work_years, actual_salary);
    printf("O salário do funcionario corresponde a: %0.2f", result);

    return 0;
}