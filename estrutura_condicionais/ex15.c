/*
15) As tarifas de certo parque de estacionamento são as seguintes: 
• 1ª e 2ª hora - R$ 1,00 cada 
• 3ª e 4ª hora - R$ 1,40 cada 
• 5ª hora e seguintes - R$ 2,00 cada 
 
O  número  de  horas  a  pagar  é  sempre  inteiro  e  arredondado  por  excesso.  Deste  modo, 
quem estacionar durante 61 minutos pagará por duas horas, que é o mesmo que pagaria 
se tivesse permanecido 120 minutos. Os momentos de chegada ao parque e partida deste 
são apresentados na forma de pares de inteiros, representando horas e minutos. 
Por  exemplo,  o  par  12  50  representará  "dez  para  a  uma  da  tarde".  Pretende-se  criar  um 
programa que, lidos pelo teclado os momentos de chegada e de partida, escreva na tela o 
preço  cobrado  pelo  estacionamento.  Admite-se  que  a  chegada  e  a  partida  se  dão  com 
intervalo não superior a 24 horas. Portanto, se uma dada hora de chegada for superior a 
da partida, isso não é uma situação de erro, antes significara que a partida ocorreu no dia 
seguinte ao da chegada.
*/

#include <stdio.h>

typedef struct {
    int hour;
    int minute;
} Time;

int calculatePrice(Time arrival, Time departure) {
    int price = 0;
    int totalMinutes = (departure.hour * 60 + departure.minute) - (arrival.hour * 60 + arrival.minute);

    if (totalMinutes <= 120) {
        price = 1;
    } else if (totalMinutes <= 240) {
        price = 2;
    } else {
        price = 2 + (totalMinutes - 240) / 60;
    }

    return price;
}

int main( ) {
    Time arrival, departure;

    printf("Insira a hora de chegada (hh:mm): \n");
    scanf("%d:%d", &arrival.hour, &arrival.minute);

    printf("Insira a hora de partida (hh:mm): \n");
    scanf("%d:%d", &departure.hour, &departure.minute);

    printf("Preço a pagar: R$%d,00\n", calculatePrice(arrival, departure));
   
    return 0;
}