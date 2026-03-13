#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
} Autor;

typedef struct {
    int id;
    char titulo[50];
    char categoria[20];
    int num_autores;
    Autor autores[3];
    int exemplares;
    float nota;
    int num_avaliacoes;
} Livro;

Livro livros[200];
int totalLivros = 0;

void cadastrarLivro() {
    Livro l;

    scanf("%d %s %s", &l.id, l.titulo, l.categoria);
    scanf("%d", &l.num_autores);

    for (int i = 0; i < l.num_autores; i++) {
        scanf("%s", l.autores[i].nome);
    }

    scanf("%d", &l.exemplares);

    l.nota = 0.0;
    l.num_avaliacoes = 0;

    livros[totalLivros++] = l;
}

int buscarLivro(int id) {
    for (int i = 0; i < totalLivros; i++) {
        if (livros[i].id == id) {
            return i;
        }
    }
    return -1;
}

void avaliarLivro(int id, int nota) {

    int pos = buscarLivro(id);

    if (pos == -1) {
        printf("LIVRO_NAO_ENCONTRADO\n");
        return;
    }

    Livro *l = &livros[pos];

    float soma = l->nota * l->num_avaliacoes;
    soma += nota;

    l->num_avaliacoes++;
    l->nota = soma / l->num_avaliacoes;

    printf("AVALIADO %d %.2f\n", id, l->nota);
}

void imprimirAutores(Livro l) {

    for (int i = 0; i < l.num_autores; i++) {

        printf("%s", l.autores[i].nome);

        if (i < l.num_autores - 1)
            printf(", ");
    }
}

void relatorio(char categoria[]) {

    int melhor = -1;

    for (int i = 0; i < totalLivros; i++) {

        if (strcmp(livros[i].categoria, categoria) == 0 &&
            livros[i].num_avaliacoes > 0) {

            if (melhor == -1 ||
                livros[i].nota > livros[melhor].nota ||
                (livros[i].nota == livros[melhor].nota &&
                 livros[i].id < livros[melhor].id)) {

                melhor = i;
            }
        }
    }

    if (melhor == -1) {
        printf("SEM_AVALIACOES\n");
        return;
    }

    Livro l = livros[melhor];

    printf("%s (", l.titulo);
    imprimirAutores(l);
    printf(") - %.2f/5 (%d avaliacao(oes))\n", l.nota, l.num_avaliacoes);
}

void autoresNotaZero() {

    int encontrou = 0;

    for (int i = 0; i < totalLivros; i++) {

        if (livros[i].num_avaliacoes > 0 && livros[i].nota <= 0.00001) {

            for (int j = 0; j < livros[i].num_autores; j++) {
                printf("%s\n", livros[i].autores[j].nome);
                encontrou = 1;
            }
        }
    }

    if (!encontrou) {
        printf("NENHUM\n");
    }
}

int main() {

    int N, Q;

    scanf("%d %d", &N, &Q);

    for (int i = 0; i < N; i++) {
        cadastrarLivro();
    }

    for (int i = 0; i < Q; i++) {

        char operacao[30];
        scanf("%s", operacao);

        if (strcmp(operacao, "AVALIAR") == 0) {

            int id, nota;
            scanf("%d %d", &id, &nota);

            avaliarLivro(id, nota);
        }

        else if (strcmp(operacao, "RELATORIO") == 0) {

            char categoria[20];
            scanf("%s", categoria);

            relatorio(categoria);
        }

        else if (strcmp(operacao, "AUTORES_NOTA_ZERO") == 0) {

            autoresNotaZero();
        }
    }

    return 0;
}