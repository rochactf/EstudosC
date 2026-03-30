#include <stdio.h>
#include <string.h>

#define MAX_USUARIOS 3
#define TAM 50

typedef struct
{
    char usuario[TAM];
    char senha[TAM];
    
} Conta;

int buscarUsuario(Conta contas[], int n, char *usuario, char *senha);

int main()
{
    Conta contas[MAX_USUARIOS] = {
        {"admin",   "admin123"},
        {"joao",    "senha456"},
        {"maria",   "maria789"}
    };

    char usuario[TAM];
    char senha[TAM];

    printf("=== SISTEMA DE LOGIN ===\n\n");

    printf("Usuario: ");
    scanf("%49s", usuario);

    printf("Senha: ");
    scanf("%49s", senha);

    int idx = buscarUsuario(contas, MAX_USUARIOS, usuario, senha);

    if (idx >= 0)
        printf("\nBem-vindo(a), %s!\n", contas[idx].usuario);
    else
        printf("\nUsuario ou senha invalidos.\n");

    return 0;
}

int buscarUsuario(Conta contas[], int n, char *usuario, char *senha)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(contas[i].usuario, usuario) == 0 &&
            strcmp(contas[i].senha, senha) == 0)
            return i;
    }
    return -1;
}