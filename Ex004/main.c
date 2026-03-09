#include <stdio.h>

void casoEstacionado();
void casoMovimento();

int main()
{
    int situacao;

    printf("Situacao do veiculo:\n");
    printf("1 - Estacionado\n");
    printf("2 - Em movimento\n");
    printf("Escolha: ");
    scanf("%d", &situacao);

    switch(situacao)
    {
        case 1:
            casoEstacionado();
            break;

        case 2:
            casoMovimento();
            break;

        default:
            printf("Opcao invalida\n");
    }

    return 0;
}

void casoEstacionado()
{
    int hora;

    printf("Digite a hora (apenas horas): ");
    scanf("%d", &hora);

    if(hora >= 8 && hora <= 17)
    {
        printf("Multa: R$ 500,00\n");
    }
    else if(hora >= 17 && hora <= 20)
    {
        printf("Multa: R$ 250,00\n");
    }
    else if(hora >= 6 && hora <= 8)
    {
        printf("Multa: R$ 250,00\n");
    }
    else
    {
        printf("Estacionamento permitido\n");
    }
}

void casoMovimento()
{
    float velocidade;

    printf("Digite a velocidade do veiculo (km/h): ");
    scanf("%f", &velocidade);

    if(velocidade <= 60)
    {
        printf("Velocidade permitida. Nao tem multa.\n");
    }
    else if(velocidade <= 66)
    {
        printf("Multa: R$ 200,00\n");
    }
    else if(velocidade <= 72)
    {
        printf("Multa: R$ 400,00\n");
    }
    else
    {
        printf("Multa: R$ 800,00\n");
    }
}