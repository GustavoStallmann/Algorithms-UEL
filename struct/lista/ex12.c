/*
12) Faça um programa que controle o fluxo de voos nos aeroportos de um
país. Com V = 5 (voos) e A = 5 (aeroportos) e:
• Crie e leia um vetor de voos, sendo que cada voo contém um código de
aeroporto de origem e um de destino.
• Crie um vetor de aeroportos, sendo que cada aeroporto contém seu
código, quantidade de voos que saem e quantidade de voos que chegam.
Nota: Cada aeroporto é identificado por um código inteiro entre 0 e (A-1).
Não aceite aeroportos de código inexistente.
*/

#include <stdio.h>

const int V = 5;
const int A = 5;

typedef struct {
    int origin;
    int destiny;
} Flight;

typedef struct {
    int code;
    int departures;
    int arrivals;
} Airport;

int verify_airport_code(int code, Airport airport_list[]) {
    for (int i = 0; i < A; i++) 
        if (airport_list[i].code == code) return 1;

    return 0;
}

int main() {
    Flight flights[V];
    Airport airports[A];

    for (int i = 0; i < A; i++) {
        airports[i].code = i;
        airports[i].departures = 0;
        airports[i].arrivals = 0;
    }

    for (int i = 0; i < V; i++) {
        int origin, destiny;
        do {
            printf("Digite o codigo do aeroporto de origem: \n");
            scanf("%d", &origin);

            printf("Digite o codigo do aeroporto de destino: \n");
            scanf("%d", &destiny);
        } while (!verify_airport_code(origin, airports) || !verify_airport_code(destiny, airports));

        flights[i].origin = origin;
        flights[i].destiny = destiny;

        airports[origin].departures++;
        airports[destiny].arrivals++;
    }

    for (int i = 0; i < A; i++) {
        printf("\nO aeroporto [%d] possui: \n", airports[i].code);
        printf("\t[%d]: voos de saida\n", airports[i].departures);
        printf("\t[%d]: voos de chegada\n", airports[i].arrivals);
    }

    return 0;
}