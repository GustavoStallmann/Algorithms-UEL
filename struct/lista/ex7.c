/*
7) Escolha um jogo de cartas, baseado em um “baralho tradicional” (cada
carta tem seu naipe e seu valor) ou tipo “super trunfo” (cada carta possui um
conjunto de atributos). Implemente a parte de distribuição (sorteio) de
cartas para 2 jogadores, considerando que cada jogador irá receber 5 cartas.
Exiba na tela as cartas que cada um dos jogadores recebeu.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char suit[50];
    char value[50];
} Card;

typedef struct {
    Card cards[5];
} Player;

void print_card(Card card) {
    printf("Naipe: %s\n", card.suit);
    printf("Valor: %s\n", card.value);
}

void print_player(Player player) {
    for (int i = 0; i < 5; i++) {
        print_card(player.cards[i]);
    }
}

void create_deck(Card deck[]) {
    char suits[4][15] = {"Copas", "Ouros", "Paus", "Espadas"};
    char values[13][2] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

    int card_count = 0;

    for (int suit = 0; suit < 4; suit++) {
        for (int value = 0; value < 13; value++) {
            strcpy(deck[card_count].suit, suits[suit]);
            strcpy(deck[card_count].value, values[value]);
            card_count++;
        }
    }
}

void shuffle_deck(Card deck[]) {
    for (int i = 0; i < 52; i++) {
        int random_index = rand() % 52;

        Card temp = deck[i];
        deck[i] = deck[random_index];
        deck[random_index] = temp;
    }
}

int main( ) {
    Card deck[52];
    create_deck(deck);
    shuffle_deck(deck);

    Player player1, player2;

    int card_count = 0;

    for (int i = 0; i < 5; i++) {
        player1.cards[i] = deck[card_count];
        card_count++;
    }

    for (int i = 0; i < 5; i++) {
        player2.cards[i] = deck[card_count];
        card_count++;
    }

    printf("Cartas do primeiro jogador:\n");
    print_player(player1);

    printf("\nCartas do segundo jogador:\n");
    print_player(player2);


    return 0;
}