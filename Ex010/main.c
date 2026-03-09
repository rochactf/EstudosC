#include <stdio.h>
#include <stdlib.h>

float lerNota(int prova);
float calcularMedia(float a, float b, float c, float d);
float calcularMedia2(float media, float prova);

int main()
{
    int sex;
    char nome[50];
    float p1, p2, p3, p4, p5, p6;
    float med1, med2, med3;

    printf("Digite o nome do aluno(a): ");
    scanf("%s", nome);

    printf("Digite o sexo do aluno(a) - 1 para masculino e 2 para feminino: ");
    scanf("%d", &sex);

    if (sex != 1 && sex != 2)
    {
        printf("Sexo invalido! Reiniciando\n");
        return 0;
    }

    p1 = lerNota(1);
    p2 = lerNota(2);
    p3 = lerNota(3);
    p4 = lerNota(4);

    med1 = calcularMedia(p1, p2, p3, p4);

    if (med1 < 4)
    {
        printf("ALUNO REPROVADO!\n");
    }
    else if (med1 >= 6)
    {
        printf("ALUNO APROVADO!\n");
    }
    else
    {
        p5 = lerNota(5);
        med2 = calcularMedia2(med1, p5);

        if (med2 < 4)
        {
            printf("REPROVADO NA P5!\n");
        }
        else if (med2 >= 6)
        {
            printf("APROVADO NA P5!\n");
        }
        else
        {
            p6 = lerNota(6);
            med3 = calcularMedia2(med2, p6);

            if (med3 < 6)
            {
                printf("REPROVADO NA SEG EPOCA!\n");
            }
            else
            {
                printf("APROVADO NA SEG EPOCA!\n");
            }
        }
    }

    return 0;
}

float lerNota(int prova)
{
    float nota;

    printf("Digite a nota da P%d: ", prova);
    scanf("%f", &nota);

    if (nota < 0 || nota > 10)
    {
        printf("Nota invalida!\n");
        exit(0);
    }

    return nota;
}

float calcularMedia(float a, float b, float c, float d)
{
    return (a + b + c + d) / 4;
}

float calcularMedia2(float media, float prova)
{
    return (media + prova) / 2;
}