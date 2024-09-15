/*
5) Faça um programa que leia um vetor com dados de 5 livros: título
(máximo 30 letras), autor (máximo 15 letras) e ano. Procure um livro por
título, perguntando ao usuário qual título deseja buscar. Mostre os dados de
todos os livros encontrados.
*/

#include <stdio.h>
#include <string.h>
#define BOOK_AMOUNT 5

struct book_struct {
    char title[30];
    char author[15];
    int year;
} books[BOOK_AMOUNT], search_book;

typedef struct book_struct Book;

void search_book_title(Book book_list[], Book searched_book){
    int found_index = 0;
    Book result_list[BOOK_AMOUNT];

    for (int i = 0; i < BOOK_AMOUNT; i++) {
        if (strstr(book_list[i].title, searched_book.title) != NULL) {
            result_list[found_index] = book_list[i];
            found_index++;
        }
    }

    printf("\nLivro(s) encontrado(s): \n\n");
    for (int i = 0; i < found_index; i++) {
        printf("\t|Titulo: %s\n", result_list[i].title);
        printf("\t|Autor: %s\n", result_list[i].author);
        printf("\t|Ano de publicacao: %d\n\n", result_list[i].year);
    }   
}

int main( ) {
    for (int i = 0; i < BOOK_AMOUNT; i++) {
        printf("Informe o nome do livro: \n");
        setbuf(stdin, NULL);
        gets(books[i].title);

        printf("Informe o nome do autor: \n");
        setbuf(stdin, NULL);
        gets(books[i].author);

        printf("Informe o ano de publicacao: \n");
        scanf("%d", &books[i].year);
    }

    printf("Busque um livro no catalogo: \n");
    setbuf(stdin, NULL);
    gets(search_book.title);

    search_book_title(books, search_book);     
    
    return 0;
}