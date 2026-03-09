#include <stdio.h>

int soma(int a, int b);
int subtracao(int a, int b);
int multiplicacao(int a, int b);
int divisao(int a, int b);
void escolha(int v1, int v2);

int main()
{
    int v1, v2;

    printf("Digite o primeiro valor: ");
    scanf("%d", &v1);

    printf("Digite o segundo valor: ");
    scanf("%d", &v2);

    escolha(v1, v2);

    return 0;
}

void escolha(int v1, int v2)
{
    int esc;
    int resultado;

    printf("Digite [<1>] para somar, [<2>] para subtrair, [<3>] para multiplicar, [<4>] para dividir, [<0>] para sair: ");
    scanf("%d", &esc);

    while (esc != 0)
    {
        if (esc == 1)
        {
            resultado = soma(v1, v2);
            printf("O resultado da soma é: %d\n", resultado);
        }
        else if (esc == 2)
        {
            resultado = subtracao(v1, v2);
            printf("O resultado da subtração é: %d\n", resultado);
        }
        else if (esc == 3)
        {
            resultado = multiplicacao(v1, v2);
            printf("O resultado da multiplicação é: %d\n", resultado);
        }
        else if (esc == 4)
        {
            if (v2 == 0)
            {
                printf("Não é possível dividir por zero!\n");
            }
            else
            {
                resultado = divisao(v1, v2);
                printf("O resultado da divisão é: %d\n", resultado);
            }
        }
        else
        {
            printf("Opção inválida! Digite novamente.\n");
        }

        printf("Digite 1 para somar, 2 para subtrair, 3 para multiplicar, 4 para dividir ou 0 para sair: ");
        scanf("%d", &esc);
    }
}

int soma(int a, int b)
{
    return a + b;
}

int subtracao(int a, int b)
{
    return a - b;
}

int multiplicacao(int a, int b)
{
    return a * b;
}

int divisao(int a, int b)
{
    return a/b;
}