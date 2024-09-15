/*
11) Faça um programa para armazenar um livro de receitas e:
 Crie um vetor de 5 receitas, que deve ter nome (máximo 25 letras),
quantidade de ingredientes e ingredientes.
 Para cada receita, leia seu nome e a quantidade de ingredientes. Então
crie e leia o vetor de ingredientes, sendo que cada ingrediente contém
nome e quantidade.
 Procure receita por nome, mostrando seus ingredientes se encontrar.
Se não encontrar, informe ao usuário. Repita o processo até digitar
uma string vazia.
*/

#include <stdio.h>
#include <string.h>

#define RECIPES 5

typedef struct {
    char name[25];
    int quantity;
} Ingredient;

typedef struct {
    char name[25];
    int quantity;
    Ingredient ingredients[10];
} Recipe;

int searchRecipe(Recipe recipes[], char name[], int size) {
    for (int i = 0; i < size; i++) {
        if (strstr(recipes[i].name, name) != NULL) {
            return i;
        }
    }

    return -1;
}

int main( ) {
    Recipe recipes[RECIPES];

    for (int i = 0; i < RECIPES; i++) {
        printf("Insira o nome da receita [%d/%d]: \n", i + 1, RECIPES);
        setbuf(stdin, NULL);
        gets(recipes[i].name);

        printf("Insira a quantidade de ingredientes da receita [%d/%d]: \n", i + 1, RECIPES);
        scanf("%d", &recipes[i].quantity);

        for (int j = 0; j < recipes[i].quantity; j++) {
            printf("Insira o nome do ingrediente [%d/%d]: \n", j + 1, recipes[i].quantity);
            setbuf(stdin, NULL);
            gets(recipes[i].ingredients[j].name);

            printf("Insira a quantidade do ingrediente [%d/%d]: \n", j + 1, recipes[i].quantity);
            scanf("%d", &recipes[i].ingredients[j].quantity);
        }
    }

    char search[25];
    int index;

    do {
        printf("Insira o nome da receita que deseja buscar: \n");
        setbuf(stdin, NULL);
        gets(search);

        index = searchRecipe(recipes, search, RECIPES);

        if (index != -1) {
            printf("\nReceita encontrada!\n");
            printf("\t|Nome: %s\n", recipes[index].name);
            printf("\t|Ingredientes:\n");

            for (int i = 0; i < recipes[index].quantity; i++) {
                printf("\t\t|Nome: %s\n", recipes[index].ingredients[i].name);
                printf("\t\t|Quantidade: %d\n", recipes[index].ingredients[i].quantity);
            }
        } else {
            printf("Receita não encontrada!\n");
        }
    } while (strlen(search) > 0);

    return 0;
}