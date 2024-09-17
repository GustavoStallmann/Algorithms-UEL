#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void alloc_error( ) {
    printf("Erro: memoria insuficiente");
    exit(1);
}

typedef int key; 
typedef struct nd {
    key info; 
    struct nd *next;
} Node;

typedef struct {
    Node *first_node; 
} List; 

List* lst_init( ) {
    List *list = (List *) malloc(sizeof(List));
    list->first_node = NULL; 
    return list; 
};

Node* lst_insert(key info, List *list) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (!new_node) alloc_error();

    new_node->info = info; 
    new_node->next = list->first_node; 

    list->first_node = new_node;

    return new_node; 
}

void lst_print(List *list) {
    Node *p; 

    for (p=list->first_node; p != NULL; p = p->next)
        printf("[%d]", p->info);
}

int main( ) {
    List *list = lst_init( ); 
    lst_insert(10, list); 
    lst_insert(20, list);
    lst_print(list);

    for (int i, j; i<10 && j<10; i++, j++)
        printf("%d | %d\n", i, j);

    return 0;
}
