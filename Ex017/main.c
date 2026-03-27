#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIAS 30
#define MAX_DIA 3
#define MAX_TIPOS 4

typedef struct
{
    int codigo;
    char descricao[50];
} TipoServico;

typedef struct
{
    int numero;
    float valor;
    int codigoServico;
    int codigoCliente;
} Servico;

TipoServico tipos[MAX_TIPOS];
Servico matriz[DIAS][MAX_DIA];
int qtdPorDia[DIAS];
int tiposCadastrados = 0;

void cadastrarTipos();
void cadastrarServico();
void mostrarDia();
void mostrarIntervalo();
void relatorioGeral();
int buscarTipo(int codigo);

int main()
{
    int i, j;
    for (i = 0; i < DIAS; i++)
    {
        qtdPorDia[i] = 0;
        for (j = 0; j < MAX_DIA; j++)
        {
            matriz[i][j].numero = 0;
            matriz[i][j].valor = 0;
            matriz[i][j].codigoServico = 0;
            matriz[i][j].codigoCliente = 0;
        }
    }

    int opcao;
    do
    {
        printf("\n=== MENU ===\n");
        printf("1. Cadastrar os tipos de servicos\n");
        printf("2. Cadastrar os servicos prestados\n");
        printf("3. Mostrar os servicos prestados em determinado dia\n");
        printf("4. Mostrar os servicos prestados dentro de um intervalo de valor\n");
        printf("5. Mostrar relatorio geral\n");
        printf("6. Finalizar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                cadastrarTipos();
                break;
            case 2:
                cadastrarServico();
                break;
            case 3:
                mostrarDia();
                break;
            case 4:
                mostrarIntervalo();
                break;
            case 5:
                relatorioGeral();
                break;
            case 6:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}

int buscarTipo(int codigo)
{
    for (int i = 0; i < tiposCadastrados; i++)
        if (tipos[i].codigo == codigo)
            return i;
    return -1;
}

void cadastrarTipos()
{
    printf("\nCadastro de tipos de servico (%d posicoes disponiveis):\n", MAX_TIPOS);
    tiposCadastrados = 0;
    for (int i = 0; i < MAX_TIPOS; i++)
    {
        printf("Codigo do tipo %d: ", i + 1);
        scanf("%d", &tipos[i].codigo);
        printf("Descricao do tipo %d: ", i + 1);
        while (getchar() != '\n');
        fgets(tipos[i].descricao, 50, stdin);
        int len = strlen(tipos[i].descricao);
        if (tipos[i].descricao[len - 1] == '\n')
            tipos[i].descricao[len - 1] = '\0';
        tiposCadastrados++;
    }
    printf("Tipos de servico cadastrados com sucesso.\n");
}

void cadastrarServico()
{
    if (tiposCadastrados == 0)
    {
        printf("Cadastre os tipos de servico primeiro (opcao 1).\n");
        return;
    }

    int dia;
    printf("Dia do servico (1 a %d): ", DIAS);
    scanf("%d", &dia);
    if (dia < 1 || dia > DIAS)
    {
        printf("Dia invalido.\n");
        return;
    }
    dia--;

    if (qtdPorDia[dia] >= MAX_DIA)
    {
        printf("Limite de %d servicos por dia atingido.\n", MAX_DIA);
        return;
    }

    int idx = qtdPorDia[dia];

    printf("Numero do servico: ");
    scanf("%d", &matriz[dia][idx].numero);

    printf("Valor do servico: ");
    scanf("%f", &matriz[dia][idx].valor);

    int cod;
    printf("Codigo do tipo de servico: ");
    scanf("%d", &cod);
    if (buscarTipo(cod) == -1)
    {
        printf("Codigo de tipo de servico invalido.\n");
        return;
    }
    matriz[dia][idx].codigoServico = cod;

    printf("Codigo do cliente: ");
    scanf("%d", &matriz[dia][idx].codigoCliente);

    qtdPorDia[dia]++;
    printf("Servico cadastrado com sucesso.\n");
}

void mostrarDia()
{
    int dia;
    printf("Dia a consultar (1 a %d): ", DIAS);
    scanf("%d", &dia);
    if (dia < 1 || dia > DIAS)
    {
        printf("Dia invalido.\n");
        return;
    }
    dia--;

    if (qtdPorDia[dia] == 0)
    {
        printf("Nenhum servico cadastrado para o dia %d.\n", dia + 1);
        return;
    }

    printf("\nDIA %02d\n", dia + 1);
    printf("%-15s %-15s %-18s %-18s\n",
        "Nro servico", "Valor", "Cod. servico", "Cod. cliente");
    for (int i = 0; i < qtdPorDia[dia]; i++)
    {
        printf("%-15d R$ %-12.2f %-18d %-18d\n",
            matriz[dia][i].numero,
            matriz[dia][i].valor,
            matriz[dia][i].codigoServico,
            matriz[dia][i].codigoCliente);
    }
}

void mostrarIntervalo()
{
    float vmin, vmax;
    printf("Valor minimo: ");
    scanf("%f", &vmin);
    printf("Valor maximo: ");
    scanf("%f", &vmax);

    int achou = 0;
    printf("\nServicos com valor entre R$ %.2f e R$ %.2f:\n", vmin, vmax);
    printf("%-6s %-15s %-15s %-18s %-18s\n",
        "Dia", "Nro servico", "Valor", "Cod. servico", "Cod. cliente");

    for (int i = 0; i < DIAS; i++)
    {
        for (int j = 0; j < qtdPorDia[i]; j++)
        {
            if (matriz[i][j].valor >= vmin && matriz[i][j].valor <= vmax)
            {
                printf("%-6d %-15d R$ %-12.2f %-18d %-18d\n",
                    i + 1,
                    matriz[i][j].numero,
                    matriz[i][j].valor,
                    matriz[i][j].codigoServico,
                    matriz[i][j].codigoCliente);
                achou = 1;
            }
        }
    }

    if (!achou)
        printf("Nenhum servico encontrado nesse intervalo.\n");
}

void relatorioGeral()
{
    int algum = 0;
    for (int i = 0; i < DIAS; i++)
    {
        if (qtdPorDia[i] == 0)
            continue;
        algum = 1;
        printf("\nDIA %02d\n", i + 1);
        printf("%-15s %-15s %-18s %-20s %-18s\n",
            "Nro servico", "Valor", "Cod. servico", "Descricao", "Cod. cliente");
        for (int j = 0; j < qtdPorDia[i]; j++)
        {
            int idx = buscarTipo(matriz[i][j].codigoServico);
            char *desc = (idx >= 0) ? tipos[idx].descricao : "Desconhecido";
            printf("%-15d R$ %-12.2f %-18d %-20s %-18d\n",
                matriz[i][j].numero,
                matriz[i][j].valor,
                matriz[i][j].codigoServico,
                desc,
                matriz[i][j].codigoCliente);
        }
    }
    if (!algum)
        printf("Nenhum servico cadastrado.\n");
}