#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int contador = 0;
int funcao(int n);
int funcao_otimizada(int o, int *mem);
int main(int argc, char const *argv[])
{
    int n;
    int *mem;
    char resposta;
    do {
        printf("Digite um numero para ver sua posição:\n");
        scanf("%d", &n);
        mem = malloc((n + 1) * sizeof(int));
        for(int i = 0; i <= n; i++){
            mem[i] = -1;
        }
        contador = 0;
        printf("%d\n", funcao(n));
        printf("Chamadas não otimizadas: %d\n", contador);
        contador = 0;
        printf("%d\n", funcao_otimizada(n, mem));
        printf("Chamadas otimizadas: %d\n", contador);
        free(mem);
        printf("\nDeseja calcular de novo? (s/n): ");
        scanf(" %c", &resposta);
    } while(resposta == 's');
    return 0;
}
//verção não otimizada
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
int funcao_otimizada(int o, int *mem)
{
    contador++;
    if(mem[o] != -1)
        return mem[o];
    if(o == 0)
        return mem[o] = 0;
    if(o == 1)
        return mem[o] = 1;
    mem[o] = funcao_otimizada(o - 1, mem) + funcao_otimizada(o - 2, mem);
    return mem[o];
}