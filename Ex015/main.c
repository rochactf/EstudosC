#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIM 50

void receberNome(char *nome);
int validarNome(char *nome);
void mostrarRepetidos(int matriz[][DIM], int linhas, int colunas);

int main()
{
    int matriz[DIM][DIM];
    char nome[100];
    int linhas, colunas, opcao;

    receberNome(nome);

    do
    {
        linhas = 0;
        while (linhas < 1 || linhas > DIM)
        {
            printf("Quantas linhas deseja manipular (1 a %d): ", DIM);
            scanf("%d", &linhas);
            while (getchar() != '\n');
            if (linhas < 1 || linhas > DIM)
                printf("Valor invalido. Digite entre 1 e %d.\n", DIM);
        }

        colunas = 0;
        while (colunas < 1 || colunas > DIM)
        {
            printf("Quantas colunas deseja manipular (1 a %d): ", DIM);
            scanf("%d", &colunas);
            while (getchar() != '\n');
            if (colunas < 1 || colunas > DIM)
                printf("Valor invalido. Digite entre 1 e %d.\n", DIM);
        }

        for (int i = 0; i < DIM; i++)
            for (int j = 0; j < DIM; j++)
                matriz[i][j] = 0;

        srand(time(NULL));
        for (int i = 0; i < linhas; i++)
            for (int j = 0; j < colunas; j++)
                matriz[i][j] = rand() % 15 + 1;

        printf("\nAluno(a): %s\n", nome);
        printf("Matriz %dx%d gerada:\n\n", linhas, colunas);

        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
                printf("%4d", matriz[i][j]);
            printf("\n");
        }

        printf("\n");
        mostrarRepetidos(matriz, linhas, colunas);

        printf("\nDeseja gerar novamente? (1 - Sim / 0 - Nao): ");
        scanf("%d", &opcao);
        while (getchar() != '\n');
        printf("\n");
    } while (opcao == 1);

    printf("Encerrando programa.\n");
    return 0;
}

void receberNome(char *nome)
{
    int valido = 0;
    while (!valido)
    {
        printf("Digite o nome do aluno(a): ");
        fgets(nome, 100, stdin);
        int len = strlen(nome);
        if (nome[len - 1] == '\n')
            nome[len - 1] = '\0';
        valido = validarNome(nome);
        if (!valido)
            printf("Nome invalido. O nome nao pode ser vazio.\n");
    }
}

int validarNome(char *nome)
{
    int i = 0;
    while (nome[i] != '\0')
    {
        if (nome[i] != ' ')
            return 1;
        i++;
    }
    return 0;
}

void mostrarRepetidos(int matriz[][DIM], int linhas, int colunas)
{
    int temRepetido = 0;

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            int val = matriz[i][j];
            int jaContado = 0;

            for (int pi = 0; pi < linhas && !jaContado; pi++)
            {
                for (int pj = 0; pj < colunas && !jaContado; pj++)
                {
                    if ((pi < i || (pi == i && pj < j)) && matriz[pi][pj] == val)
                        jaContado = 1;
                }
            }

            if (!jaContado)
            {
                int count = 0;
                for (int ci = 0; ci < linhas; ci++)
                    for (int cj = 0; cj < colunas; cj++)
                        if (matriz[ci][cj] == val)
                            count++;

                if (count > 1)
                {
                    printf("O numero %d aparece %d vezes.\n", val, count);
                    temRepetido = 1;
                }
            }
        }
    }

    if (!temRepetido)
        printf("Nao ha nenhum numero repetido na matriz.\n");
}