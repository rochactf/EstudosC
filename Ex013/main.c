#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[51];
    int matricula;
    float notas[3];
    float media;
} Estudante;

void lerEstudante(Estudante *e){
    scanf(" %[^\n]", e->nome);
    scanf("%d", &e->matricula);
    scanf("%f %f %f", &e->notas[0], &e->notas[1], &e->notas[2]);
}

void lerVarios(Estudante v[], int n){
    for(int i=0;i<n;i++){
        lerEstudante(&v[i]);
    }
}

float calcularMedia(Estudante *e){
    e->media = (e->notas[0] + e->notas[1] + e->notas[2]) / 3.0;
    return e->media;
}

void calcularMedias(Estudante v[], int n){
    for(int i=0;i<n;i++){
        calcularMedia(&v[i]);
    }
}

void ordenar(Estudante v[], int n){
    Estudante temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(v[j].media > v[i].media){
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

void mostrarEstudante(Estudante e, int pos){
    printf("%d. %s (%d): %.2f\n", pos, e.nome, e.matricula, e.media);
}

void mostrarTodos(Estudante v[], int n){
    for(int i=0;i<n;i++){
        mostrarEstudante(v[i], i+1);
    }
}

int main(){

    int N;
    scanf("%d",&N);

    Estudante alunos[1000];

    lerVarios(alunos, N);
    calcularMedias(alunos, N);
    ordenar(alunos, N);
    mostrarTodos(alunos, N);

    return 0;
}