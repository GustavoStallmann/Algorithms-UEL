/*
7) Suponha que um caixa tenha apenas notas de 1, 10 e 100 reais. Este algoritmo é
projetado para calcular o número mínimo de cada nota que o caixa deve fornecer como
troco, após uma compra ser realizada. O algoritmo receberá como entrada o valor da
compra e o valor do pagamento, ambos em números inteiros. Caso o valor do pagamento
seja menor que o valor da compra, o cálculo não será realizado e a seguinte mensagem
deverá ser exibida: "Pagamento Negado".
Por exemplo:
- Valor da compra: R$ 725
- Valor do pagamento: R$ 1000
- Troco: R$ 275
Neste caso, o resultado deve mostrar:
- 2 notas de R$ 100
- 7 notas de R$ 10
- 5 notas de R$ 1
*/

#include <stdio.h>

int main() {
    int purchaseValue, paymentValue;
    int change, notes100, notes10, notes1;

    printf("Valor da compra: R$ ");
    scanf("%d", &purchaseValue);

    printf("Valor do pagamento: R$ ");
    scanf("%d", &paymentValue);

    if (paymentValue < purchaseValue) {
        printf("Pagamento negado\n");
        return 1; 
    }
    
    change = paymentValue - purchaseValue;
    notes100 = change / 100;
    change = change % 100;
    notes10 = change / 10;
    change = change % 10;
    notes1 = change;

    printf("Troco: R$ %d\n", paymentValue - purchaseValue);
    printf("- %d notas de R$ 100\n", notes100);
    printf("- %d notas de R$ 10\n", notes10);
    printf("- %d notas de R$ 1\n", notes1);

    return 0;
}
