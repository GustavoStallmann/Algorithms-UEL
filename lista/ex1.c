#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int KEY; 

typedef struct node_element { 
    KEY data;
    struct node_element *next; 
} Node; 

void alloc_error( ) {
    printf("Erro: memoria insuficiente");
    exit(1);
}

Node *init_list( ) {
    Node *list = (Node *) malloc(sizeof(Node));
    if (!list) alloc_error();
    list->next = NULL; 

    return list; 
}

Node *get_last_node(Node *first_node) {
    if (first_node->next == NULL) return first_node; 

    return get_last_node(first_node->next);
}

bool push_node(Node *first_node, KEY data) {
    Node *last_node = get_last_node(first_node);

    Node *new_node = (Node *) malloc(sizeof(Node));
    if (!new_node) alloc_error();

    last_node->next = new_node;
    return true; 
}

void print_nodes(Node *first_node) {
    if (!first_node->next) return; 

    printf("%d", first_node->data);
    return print_nodes(first_node->next);
}

int main( ) {
    Node *list = init_list(); 
    get_last_node(list);
    // push_node(list, 10);
    // print_nodes(list);
    return 0;
}
