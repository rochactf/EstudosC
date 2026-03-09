#include <stdio.h>
#include <stdlib.h>

float maiorNumero(float a, float b, float c);
float menorNumero(float a, float b, float c);
float numeroDoMeio(float a, float b, float c);

int main()
{
    int i;
    float a, b, c;
    float menor, meio, maior;

    printf("Escolha entre 1(crescente), 2(decrescente) e 3(maior no meio): ");
    scanf("%d", &i);

    printf("Digite o 1 numero: ");
    scanf("%f", &a);

    printf("Digite o 2 numero: ");
    scanf("%f", &b);

    printf("Digite o 3 numero: ");
    scanf("%f", &c);

    maior = maiorNumero(a, b, c);
    menor = menorNumero(a, b, c);
    meio = numeroDoMeio(a, b, c);

    printf("\nResultado: ");

    if(i == 1)
    {

        printf("%.2f --> %.2f --> %.2f\n", menor, meio, maior);

    }
    else if(i == 2)
    {

        printf("%.2f --> %.2f --> %.2f\n", maior, meio, menor);

    }
    else if(i == 3)
    {

        printf("%.2f --> %.2f --> %.2f\n", meio, maior, menor);

    }
    else
    {
        printf("Opcao invalida\n");
    }

    return 0;
}

float maiorNumero(float a, float b, float c)
{
    if(a >= b && a >= c)
        return a;

    else if(b >= a && b >= c)
        return b;

    else
        return c;
}

float menorNumero(float a, float b, float c)
{
    if(a <= b && a <= c)
        return a;

    else if(b <= a && b <= c)
        return b;
        
    else
        return c;
}

float numeroDoMeio(float a, float b, float c)
{
    float maior = maiorNumero(a,b,c);
    float menor = menorNumero(a,b,c);

    return a + b + c - maior - menor;
}