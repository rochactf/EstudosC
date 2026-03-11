#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int id;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

void enqueue(Fila* f, int id) {
    No* novo = (No*)malloc(sizeof(No));
    novo->id = id;
    novo->prox = NULL;

    if (f->fim == NULL) {
        f->inicio = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int dequeue(Fila* f) {
    if (f->inicio == NULL) return -1;

    No* temp = f->inicio;
    int val = temp->id;

    f->inicio = temp->prox;
    if (f->inicio == NULL)
        f->fim = NULL;

    free(temp);
    return val;
}

int filaVazia(Fila* f) {
    return f->inicio == NULL;
}


void removerPessoa(Fila* f, int alvo, int tamanho) {
    if (tamanho == 0) return;

    int x = dequeue(f);

    if (x != alvo)
        enqueue(f, x);

    removerPessoa(f, alvo, tamanho - 1);
}

void imprimirFila(Fila* f) {
    while (!filaVazia(f)) {
        printf("%d ", dequeue(f));
    }
}

int main() {
    int N, M, x;

    Fila fila;
    fila.inicio = fila.fim = NULL;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(&fila, x);
    }

    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        scanf("%d", &x);
        removerPessoa(&fila, x, N - i);
    }

    imprimirFila(&fila);

    return 0;
}