#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[51];
    int matricula;
    float notas[3];
    float media;
} Estudante;

float calcularMedia(Estudante e);
void lerEstudante(Estudante *e);
void lerEstudantes(Estudante *v, int n);
void mostrarEstudante(int pos, Estudante e);
void mostrarEstudantes(Estudante *v, int n);

int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    Estudante *v = malloc(n * sizeof(Estudante));

    lerEstudantes(v, n);
    mostrarEstudantes(v, n);

    free(v);
    return 0;
}

float calcularMedia(Estudante e)
{
    return (e.notas[0] + e.notas[1] + e.notas[2]) / 3.0f;
}

void lerEstudante(Estudante *e)
{
    char linha[100];
    do
    {
        fgets(linha, sizeof(linha), stdin);
    } while (linha[0] == '\n' || linha[0] == '\r');

    int len = strlen(linha);
    if (linha[len - 1] == '\n')
        linha[len - 1] = '\0';

    char *p = strrchr(linha, ' ');
    sscanf(p + 1, "%f", &e->notas[2]);
    *p = '\0';

    p = strrchr(linha, ' ');
    sscanf(p + 1, "%f", &e->notas[1]);
    *p = '\0';

    p = strrchr(linha, ' ');
    sscanf(p + 1, "%f", &e->notas[0]);
    *p = '\0';

    p = strrchr(linha, ' ');
    sscanf(p + 1, "%d", &e->matricula);
    *p = '\0';

    strcpy(e->nome, linha);
    e->media = calcularMedia(*e);
}

void lerEstudantes(Estudante *v, int n)
{
    for (int i = 0; i < n; i++)
        lerEstudante(&v[i]);
}

void mostrarEstudante(int pos, Estudante e)
{
    printf("%d. %s (%d): %.2f\n", pos, e.nome, e.matricula, e.media);
}

void mostrarEstudantes(Estudante *v, int n)
{
    for (int i = 0; i < n; i++)
        mostrarEstudante(i + 1, v[i]);
}