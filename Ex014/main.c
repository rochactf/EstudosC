#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int chave;
    int id;
    int nivel;
    struct No *esq, *dir;
} No;

No *cria_no(int nova_chave, int id)
{
    No *novo = malloc(sizeof(No));
    novo->chave = nova_chave;
    novo->id    = id;
    novo->esq   = novo->dir = NULL;
    novo->nivel = 0;
    return novo;
}

No *remove_id(No *raiz, int id, int *encontrado)
{
    if (raiz == NULL) return NULL;

    if (id == raiz->id) {
        *encontrado = 1;
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            return NULL;
        } else if (raiz->esq == NULL) {
            No *tmp = raiz->dir;
            free(raiz);
            return tmp;
        } else if (raiz->dir == NULL) {
            No *tmp = raiz->esq;
            free(raiz);
            return tmp;
        } else {
            No *pai_suc = raiz;
            No *suc     = raiz->dir;
            while (suc->esq != NULL) {
                pai_suc = suc;
                suc     = suc->esq;
            }
            raiz->chave = suc->chave;
            raiz->id    = suc->id;
            if (pai_suc == raiz)
                pai_suc->dir = suc->dir;
            else
                pai_suc->esq = suc->dir;
            free(suc);
            return raiz;
        }
    }

    raiz->esq = remove_id(raiz->esq, id, encontrado);
    if (!*encontrado)
        raiz->dir = remove_id(raiz->dir, id, encontrado);
    return raiz;
}

No *insere_no(No *raiz, int nova_chave, int id)
{
    No *pai_aux = NULL;
    No *aux     = raiz;
    No *nova    = cria_no(nova_chave, id);

    if (raiz == NULL)
        return nova;

    while (aux != NULL) {
        pai_aux = aux;
        if (nova_chave < aux->chave)
            aux = aux->esq;
        else
            aux = aux->dir;
    }
    nova->nivel = pai_aux->nivel + 1;
    if (nova_chave < pai_aux->chave)
        pai_aux->esq = nova;
    else
        pai_aux->dir = nova;
    return raiz;
}

int busca_pontuacao(No *raiz, int id)
{
    if (raiz == NULL) return -1;
    if (raiz->id == id) return raiz->chave;
    int esq = busca_pontuacao(raiz->esq, id);
    if (esq != -1) return esq;
    return busca_pontuacao(raiz->dir, id);
}

int conta_acima_de(No *raiz, int p)
{
    if (raiz == NULL) return 0;
    if (raiz->chave > p)
        return 1 + conta_acima_de(raiz->esq, p) + conta_acima_de(raiz->dir, p);
    else
        return conta_acima_de(raiz->esq, p) + conta_acima_de(raiz->dir, p);
}

int conta_mesmo_nivel_menor(No *raiz, int chave, int nivel_ref)
{
    if (raiz == NULL) return 0;
    int cnt = 0;
    if (raiz->chave == chave && raiz->nivel < nivel_ref) cnt = 1;
    return cnt
        + conta_mesmo_nivel_menor(raiz->esq, chave, nivel_ref)
        + conta_mesmo_nivel_menor(raiz->dir, chave, nivel_ref);
}

int nivel_do_id(No *raiz, int id)
{
    if (raiz == NULL) return -1;
    if (raiz->id == id) return raiz->nivel;
    int e = nivel_do_id(raiz->esq, id);
    if (e != -1) return e;
    return nivel_do_id(raiz->dir, id);
}

void position(No *raiz, int id)
{
    int p = busca_pontuacao(raiz, id);
    if (p == -1) { printf("NOT_FOUND\n"); return; }
    int acima        = conta_acima_de(raiz, p);
    int nv           = nivel_do_id(raiz, id);
    int empate_antes = conta_mesmo_nivel_menor(raiz, p, nv);
    printf("%d\n", acima + empate_antes + 1);
}

typedef struct { int chave; int id; int nivel; } Item;

int g_cnt;
Item g_items[2000];

void coleta_range(No *raiz, int mn, int mx)
{
    if (raiz == NULL) return;
    if (raiz->chave >= mn && raiz->chave <= mx) {
        g_items[g_cnt].chave = raiz->chave;
        g_items[g_cnt].id    = raiz->id;
        g_items[g_cnt].nivel = raiz->nivel;
        g_cnt++;
    }
    coleta_range(raiz->esq, mn, mx);
    coleta_range(raiz->dir, mn, mx);
}

int cmp_range(const void *a, const void *b)
{
    Item *ia = (Item *)a, *ib = (Item *)b;
    if (ib->chave != ia->chave) return ib->chave - ia->chave;
    return ib->nivel - ia->nivel;
}

void range(No *raiz, int mn, int mx)
{
    g_cnt = 0;
    coleta_range(raiz, mn, mx);
    if (g_cnt == 0) { printf("EMPTY\n"); return; }
    qsort(g_items, g_cnt, sizeof(Item), cmp_range);
    for (int i = 0; i < g_cnt; i++) {
        if (i > 0) printf(" ");
        printf("%d", g_items[i].id);
    }
    printf("\n");
}

void top(No *raiz)
{
    if (raiz == NULL) { printf("EMPTY\n"); return; }
    No *tmp = raiz;
    while (tmp->dir != NULL) tmp = tmp->dir;
    int max_chave = tmp->chave;
    g_cnt = 0;
    coleta_range(raiz, max_chave, max_chave);
    qsort(g_items, g_cnt, sizeof(Item), cmp_range);
    printf("%d\n", g_items[0].id);
}

void bottom(No *raiz)
{
    if (raiz == NULL) { printf("EMPTY\n"); return; }
    No *tmp = raiz;
    while (tmp->esq != NULL) tmp = tmp->esq;
    int min_chave = tmp->chave;
    g_cnt = 0;
    coleta_range(raiz, min_chave, min_chave);
    qsort(g_items, g_cnt, sizeof(Item), cmp_range);
    printf("%d\n", g_items[0].id);
}

int count_above(No *raiz, int val)
{
    if (raiz == NULL) return 0;
    int cnt = (raiz->chave > val) ? 1 : 0;
    return cnt + count_above(raiz->esq, val) + count_above(raiz->dir, val);
}

int count_below(No *raiz, int val)
{
    if (raiz == NULL) return 0;
    int cnt = (raiz->chave < val) ? 1 : 0;
    return cnt + count_below(raiz->esq, val) + count_below(raiz->dir, val);
}

void libera(No *raiz)
{
    if (raiz == NULL) return;
    libera(raiz->esq);
    libera(raiz->dir);
    free(raiz);
}

int main(void)
{
    int n;
    scanf("%d", &n);

    No *raiz = NULL;
    char op[20];

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "REGISTER") == 0) {
            int id, pts;
            scanf("%d %d", &id, &pts);
            raiz = insere_no(raiz, pts, id);

        } else if (strcmp(op, "UPDATE") == 0) {
            int id, nova_pts;
            scanf("%d %d", &id, &nova_pts);
            int encontrado = 0;
            raiz = remove_id(raiz, id, &encontrado);
            if (encontrado)
                raiz = insere_no(raiz, nova_pts, id);

        } else if (strcmp(op, "POSITION") == 0) {
            int id;
            scanf("%d", &id);
            position(raiz, id);

        } else if (strcmp(op, "RANGE") == 0) {
            int mn, mx;
            scanf("%d %d", &mn, &mx);
            range(raiz, mn, mx);

        } else if (strcmp(op, "TOP") == 0) {
            top(raiz);

        } else if (strcmp(op, "BOTTOM") == 0) {
            bottom(raiz);

        } else if (strcmp(op, "COUNT_ABOVE") == 0) {
            int val;
            scanf("%d", &val);
            printf("%d\n", count_above(raiz, val));

        } else if (strcmp(op, "COUNT_BELOW") == 0) {
            int val;
            scanf("%d", &val);
            printf("%d\n", count_below(raiz, val));
        }
    }

    libera(raiz);
    return 0;
}