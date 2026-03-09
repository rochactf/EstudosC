#include <stdio.h>
#include <stdlib.h>

float calcularGratificacao(float salB);
float calcularDeducao(float salB);

int main()
{
    float salB, grat, ded, valL;

    printf("Digite o valor do salario base: ");
    scanf("%f", &salB);

    if (salB < 0)
    {
        printf("Valor invalido!\n");
        return 0;
    }
    else if (salB == 0)
    {
        printf("Nao houve salario nesse mes!\n");
        return 0;
    }

    grat = calcularGratificacao(salB);
    ded = calcularDeducao(salB);

    valL = salB + grat - ded;

    printf("O salario base e de: R$%.2f\n", salB);
    printf("O valor da gratificacao e de: R$%.2f\n", grat);
    printf("O valor das deducoes e de: R$%.2f\n", ded);
    printf("O valor liquido a receber e de: R$%.2f\n", valL);

    return 0;
}

float calcularGratificacao(float salB)
{
    if (salB <= 300)
        return 100;
    else if (salB <= 500)
        return 75;
    else if (salB <= 1000)
        return 50;
    else
        return 30;
}

float calcularDeducao(float salB)
{
    if (salB <= 200)
        return 0;
    else if (salB <= 500)
        return salB * 0.03;
    else if (salB <= 700)
        return salB * 0.05;
    else if (salB <= 1000)
        return salB * 0.08;
    else
        return salB * 0.10;
}