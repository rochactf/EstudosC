#include <stdio.h>
#include <stdlib.h>

#define TAM1 300
#define TAM2 50

void lerVetor1(int v[], int *n);
void mostrarVetor1(int v[], int n);
void maiorSequencia(int v[], int n);

void lerVetor2(int v[], int *n);
void mostrarVetor2(int v[], int n);
void maiorDiferenca(int v[], int n);

int main()
{
    int opcao;

    do
    {
        printf("\nMENU DE OPCOES\n");
        printf("================\n");
        printf("1 - maior sequencia de numeros iguais consecutivos\n");
        printf("2 - maior diferenca entre dois numeros consecutivos\n");
        printf("3 - sair\n");
        printf("Escolha o numero de uma das opcoes acima...: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
            {
                int v[TAM1];
                int n = 0;
                lerVetor1(v, &n);
                mostrarVetor1(v, n);
                maiorSequencia(v, n);
                break;
            }
            case 2:
            {
                int v[TAM2];
                int n = 0;
                lerVetor2(v, &n);
                mostrarVetor2(v, n);
                maiorDiferenca(v, n);
                break;
            }
            case 3:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 3);

    return 0;
}

void lerVetor1(int v[], int *n)
{
    int val;
    *n = 0;
    printf("Digite numeros de 1 a 9 (0 para encerrar):\n");
    scanf("%d", &val);
    while (val != 0 && *n < TAM1)
    {
        if (val < 1 || val > 9)
            printf("Valor invalido. Digite entre 1 e 9 (0 para encerrar): ");
        else
        {
            v[*n] = val;
            (*n)++;
        }
        if (val != 0)
            scanf("%d", &val);
    }
}

void mostrarVetor1(int v[], int n)
{
    printf("\nVetor informado:\n");
    if (n <= 5)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", v[i]);
        printf("\n");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", v[i]);
            if ((i + 1) % 5 == 0)
                printf("\n");
        }
        if (n % 5 != 0)
            printf("\n");
    }
}

void maiorSequencia(int v[], int n)
{
    int melhorInicio = 0, melhorTam = 1;
    int atualInicio = 0, atualTam = 1;

    for (int i = 1; i < n; i++)
    {
        if (v[i] == v[i - 1])
        {
            atualTam++;
            if (atualTam > melhorTam)
            {
                melhorTam = atualTam;
                melhorInicio = atualInicio;
            }
        }
        else
        {
            atualInicio = i;
            atualTam = 1;
        }
    }

    if (melhorTam < 2)
    {
        printf("Nao ha sequencia de numeros iguais consecutivos.\n");
        return;
    }

    printf("\nMaior sequencia de numeros iguais consecutivos: ");
    for (int i = melhorInicio; i < melhorInicio + melhorTam; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void lerVetor2(int v[], int *n)
{
    int val;
    *n = 0;
    printf("Digite %d numeros maiores que zero e sem repeticao:\n", TAM2);
    while (*n < TAM2)
    {
        printf("v[%d]: ", *n);
        scanf("%d", &val);

        if (val <= 0)
        {
            printf("Valor invalido. Digite um numero maior que zero.\n");
        }
        else
        {
            int repetido = 0;
            for (int i = 0; i < *n; i++)
            {
                if (v[i] == val)
                {
                    repetido = 1;
                    break;
                }
            }
            if (repetido)
                printf("Numero ja informado. Digite um valor diferente.\n");
            else
            {
                v[*n] = val;
                (*n)++;
            }
        }
    }
}

void mostrarVetor2(int v[], int n)
{
    printf("\nVetor informado:\n");
    if (n <= 5)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", v[i]);
        printf("\n");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", v[i]);
            if ((i + 1) % 5 == 0)
                printf("\n");
        }
        if (n % 5 != 0)
            printf("\n");
    }
}

void maiorDiferenca(int v[], int n)
{
    int maior = 0, idxA = 0, idxB = 1;

    for (int i = 0; i < n - 1; i++)
    {
        int diff = v[i + 1] - v[i];
        if (diff < 0)
            diff = -diff;
        if (diff > maior)
        {
            maior = diff;
            idxA = i;
            idxB = i + 1;
        }
    }

    printf("\nMaior diferenca entre dois elementos consecutivos: %d\n", maior);
    printf("Entre v[%d] = %d e v[%d] = %d\n", idxA, v[idxA], idxB, v[idxB]);
}