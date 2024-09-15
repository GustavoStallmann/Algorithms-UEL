#include <stdio.h>
#include <stdlib.h>

struct address {
    char street[20];
    int number;
};


struct Person {
    char name[20];
    int age;
    struct address addr;
};

int main() {
    struct Person person1;
    printf("Digite o nome da pessoa: \n");
    setbuf(stdin, NULL);
    gets(person1.name);

    printf("Digite a idade da pessoa: \n");
    scanf("%d", &person1.age);

    printf("Digite a rua do endereco dessa pessoa: \n");
    setbuf(stdin, NULL);
    gets(person1.addr.street);

    printf("Digite o numero do endereco dessa pessoa: \n");
    scanf("%d", &person1.addr.number);

    printf("%s %d %s %d", person1.name, person1.age, person1.addr.street, person1.addr.number);
    
    return 0;
}