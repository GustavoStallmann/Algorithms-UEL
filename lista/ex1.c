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
    if (!list) alloc_error(); 

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

    for (p = list->first_node; p != NULL; p = p->next)
        printf("[%d]", p->info);
}

int lst_node_ammount(List *list) {
    Node *node; 
    
    int node_ammount = 0; 
    for (node = list->first_node; node != NULL; node = node->next, node_ammount++);

    return node_ammount; 
}

bool lst_free(List *list) {
    Node *node, *previous_node;

    for (node = list->first_node; node != NULL; node = node->next) {
        if (!node->next) {
            free(node); 
            break;
        }
        
        previous_node = node; 
        if (previous_node) free(previous_node);
    }

    list->first_node = NULL; 
    return true; 
}

Node* lst_search(List *list, key info) {
    Node *node; 
    for (node = list->first_node; node != NULL; node = node->next) 
        if (node->info == info) 
            return node; 

    return NULL; 
}

//TERMINAR
bool lst_remove_node(List *list, key info) {
    Node *actual_node, *previous_node; 

    while (actual_node != NULL && actual_node->info != info) {
        previous_node = actual_node; 
        actual_node = actual_node->next;
    }

    return true; 
}

int main( ) {
    List *list = lst_init( ); 
    lst_insert(10, list); 
    lst_insert(20, list);
    lst_insert(30, list);
    lst_remove_node(list, 30);
    lst_print(list);

    printf("\nQuantidade de elementos: %d\n", lst_node_ammount(list));

    return 0;
}
