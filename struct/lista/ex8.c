/*
8) Fazer um programa para simular uma agenda de telefones. Para cada
pessoa devem-se ter os seguintes dados:
 Nome
 E-mail
 Endereço (contendo campos para Rua, número, complemento, bairro,
cep, cidade, estado, país).
 Telefone (contendo campo para DDD e número)
 Data de aniversário (contendo campo para dia, mês, ano).
 Observações: Uma linha (string) para alguma observação especial.
(a) Definir a estrutura acima.
(b) Declarar a variável agenda (vetor) com capacidade de agendar até 100
nomes.
(c) Definir um bloco de instruções busca por primeiro nome: Imprime os
dados da pessoa com esse nome (se tiver mais de uma pessoa, imprime para
todas).
(d) Definir um bloco de instruções busca por mês de aniversário: Imprime os
dados de todas as pessoas que fazem aniversário nesse mês.
(e) Definir um bloco de instruções busca por dia e mês de aniversário:
Imprime os dados de todas as pessoas que fazem aniversário nesse dia e
mês.
(f) Definir um bloco de instruções insere pessoa: Insere por ordem alfabética
de nome.
(g) Definir um bloco de instruções retira pessoa: Retira todos os dados dessa
pessoa e desloca todos os elementos seguintes do vetor para a posição
anterior.
(h) Definir um bloco de instruções imprime agenda com as opções:
• Imprime nome, telefone e e-mail.
• Imprime todos os dados.

(i) O programa deve ter um menu principal oferecendo as opções acima.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int CONTACT_SIZE = 100;

struct Adress {
    char street[50];
    int number;
    char complement[50];
    char neighborhood[50];
    int cep;
    char city[50];
    char state[50];
    char country[50];
};

struct Phone {
    int ddd;
    int number;
};

struct Birthday {
    int day;
    int month;
    int year;
};

typedef struct {
    char name[50];
    char email[50];
    struct Adress adress;
    struct Phone phone;    
    struct Birthday birthday;
    char observations[50];
} Person;

void print_person_data(Person person, int only_contact_info) {
    printf("\t |Nome: %s", person.name);
    printf("\t |Email: %s", person.email);
    printf("\t |Telefone: (%d) %d", person.phone.ddd, person.phone.number);
    if (!only_contact_info) {
        printf("\t |Aniversário: %d/%d/%d", person.birthday.day, person.birthday.month, person.birthday.year);
        printf("\t |Observações: %s", person.observations);
        printf("\t |Endereço: %s, %d, %s, %s, %d, %s, %s, %s", person.adress.street, person.adress.number, person.adress.complement, person.adress.neighborhood, person.adress.cep, person.adress.city, person.adress.state, person.adress.country);
    }
}

int search_person_by_name(Person contact_list[], char name[]) {
    Person* result_list = NULL;
    int found_count = 0;

    for (int i = 0; i < CONTACT_SIZE; i++) {
        if (strstr(name, contact_list[i].name) == NULL) continue;
            found_count++;

            result_list = realloc(result_list, (found_count * sizeof (Person)));
            result_list[found_count-1] = contact_list[i];
    }

    if (found_count <= 0) {
        printf("Nenhuma pessoa encontrada.\n");
        free(result_list);
        return -1;
    }
    
    printf("Resultado obtido da busca: ");
    for (int i = 0; i < found_count; i++) {
        print_person_data(result_list[i], 0);
    }

    free(result_list);
    return 0;
}

int search_person_by_aniversary_month(Person contact_list[], int month) {
    Person result_list[CONTACT_SIZE];
    int found_count = 0;

    for (int i = 0; i < CONTACT_SIZE; i++) {
        if (contact_list[i].birthday.month == month) {
            result_list[found_count] = contact_list[i];
            found_count++;
        }
    }

    if (found_count <= 0) {
        printf("Nenhuma pessoa encontrada.\n");
        return -1;
    }

    printf("Resultado obtido da busca: ");
    for (int i = 0; i < found_count; i++) {
        print_person_data(result_list[i], 0);
    }

    return 0;
}

int search_person_by_aniversary_month_day(Person contact_list[], int month, int day) {
    Person result_list[CONTACT_SIZE];
    int found_count = 0;

    for (int i = 0; i < CONTACT_SIZE; i++) {
        if (contact_list[i].birthday.month == month && contact_list[i].birthday.day == day) {
            result_list[found_count] = contact_list[i];
            found_count++;
        }
    }

    if (found_count <= 0) {
        printf("Nenhuma pessoa encontrada.\n");
        return -1;
    }

    printf("Resultado obtido da busca: ");
    for (int i = 0; i < found_count; i++) {
        print_person_data(result_list[i], 0);
    }

    return 0;
}

int add_new_contact(Person contact_list[]) {
    Person new_contact;
    printf("Digite o nome do contato: ");
    setbuf(stdin, NULL);
    fgets(new_contact.name, 50, stdin);

    printf("Digite o email do contato: ");
    fgets(new_contact.email, 50, stdin);

    printf("Digite o telefone do contato [ddd numero]: ");
    scanf("%d %d", &new_contact.phone.ddd, &new_contact.phone.number);

    printf("Digite o dia, mês e ano de aniversário do contato [dia mes ano]: ");
    scanf("%d %d %d", &new_contact.birthday.day, &new_contact.birthday.month, &new_contact.birthday.year);

    printf("Digite as observações do contato: ");
    scanf("%s", new_contact.observations);

    for (int i = 0; i < CONTACT_SIZE; i++) {
        if (contact_list[i].name == NULL) {
            contact_list[i] = new_contact;
            return 0;
        }
    }

    printf("Agenda cheia, não foi possível adicionar novo contato.\n");
    return -1;
}

void print_contact_list(Person contact_list[], int all_data) {
    for (int i  = 0; i < CONTACT_SIZE; i++) {
        if (contact_list[i].name == NULL) break;

        if (all_data) {
            print_person_data(contact_list[i], 0);
            return;
        }
        
        print_person_data(contact_list[i], 1);
    }    
}

int menu(Person contact_list[]) {
    while (1) {
        int option;
        printf("\n[Agenda eletrônica]: escolha uma das opções abaixo\n\n");
        printf("[1] - Adicionar novo contato\n");
        printf("[2] - Buscar contato pelo nome\n");
        printf("[3] - Buscar contato por mes de aniversario\n");
        printf("[4] - Buscar contato por mes e dia de aniversario\n");
        printf("[5] - Visualizar agenda\n");
        printf("[0] - Sair\n");
        scanf("%d", &option);

        int day, month;

        switch (option) {
            case 0: 
                return 1;
            case 1:
                add_new_contact(contact_list);
                break;
            case 2:
                char name[50];
                printf("Digite o nome do contato: ");
                setbuf(stdin, NULL);
                fgets(name, 50, stdin);

                search_person_by_name(contact_list, name);
                break;
            case 3: 
                printf("Digite o mês de aniversário\n");
                scanf("%d", &month);

                search_person_by_aniversary_month(contact_list, month);
                break;
            case 4: 
                printf("Digite o mês de dia do aniversário dd/mm\n");
                scanf("%d/%d", &day, &month);

                search_person_by_aniversary_month_day(contact_list, month, day);
                break;
            case 5:
                int option;
                printf("Selecione o modo de visualização: \n");
                printf("[1] - Apenas informações de contato.\n");
                printf("[2] - Todas informações.\n");
                scanf("%d", &option);

                print_contact_list(contact_list, option);
                break;
            default:
                printf("\t[Agenda eletrônica]: Opção inválida!\n");
                break;
        }
    }
}

int main( ) {
    Person contact_list[CONTACT_SIZE]; 

    return menu(contact_list);
}