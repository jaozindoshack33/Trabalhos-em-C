#include <stdio.h>
#include <string.h>
int contador = 0;
int funcao(int n);
int main(int argc, char const *argv[])
{
    int n;
    char resposta;
    do{
    printf("Digite um numero para ver sua posição:\n");
    scanf("%d", &n);
    printf("%d\n", funcao(n));
    printf("Chamadas: %d\n", contador);
    contador = 0;
    printf("\nDeseja calcular de novo? (s/n): ");
    scanf(" %c", &resposta);
    }while(resposta == 's');
    return 0;
}
int funcao(int n)
{
    contador++;
    if(n == 0) {
        return 0;
    }
    else if(n == 1) {
        return 1;
    }
    else {
        return funcao(n - 1) + funcao(n - 2);
    }
}