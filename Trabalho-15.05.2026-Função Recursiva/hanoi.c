#include <stdio.h>

int contador = 0;

void hanoi(int n, char origem, char destino, char auxiliar);

int main()
{
    int n;
    char resposta;

    do {
        contador = 0;

        printf("Digite o numero de discos:\n");
        scanf("%d", &n);

        hanoi(n, 'A', 'C', 'B');

        printf("\nTotal de movimentos: %d\n", contador);

        printf("\nDeseja calcular de novo? (s/n): ");
        scanf(" %c", &resposta);

    } while(resposta == 's');

    return 0;
}

void hanoi(int n, char origem, char destino, char auxiliar)
{
    if(n == 1)
    {
        printf("Mover disco de %c para %c\n", origem, destino);
        contador++;
        return;
    }

    hanoi(n - 1, origem, auxiliar, destino);

    printf("Mover disco de %c para %c\n", origem, destino);
    contador++;

    hanoi(n - 1, auxiliar, destino, origem);
}