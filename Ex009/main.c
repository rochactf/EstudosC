#include <stdio.h>
#include <stdlib.h>

float calcularCredito(float saldM);

int main()
{
    float saldM, cred;

    printf("Digite o saldo medio: ");
    scanf("%f", &saldM);

    if (saldM < 0)
    {

        printf("Saldo invalido!\n");
        return 0;
        
    }

    cred = calcularCredito(saldM);

    printf("O seu saldo medio e de: R$%.2f\n", saldM);
    printf("O valor de credito disponivel e de: R$%.2f\n", cred);

    return 0;
}

float calcularCredito(float saldM)
{
    float cred;

    if (saldM <= 1000)
    {

        cred = 0;

    }
    else if (saldM <= 2000)
    {

        cred = saldM * 0.2;

    }
    else if (saldM <= 3000)
    {

        cred = saldM * 0.3;

    }
    else if (saldM <= 4000)
    {

        cred = saldM * 0.4;

    }
    else
    {

        cred = saldM * 0.5;

    }

    return cred;
}