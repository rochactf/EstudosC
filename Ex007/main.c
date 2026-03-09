#include <stdio.h>
#include <stdlib.h>

float adicionalIdade(float salB, int idade);
float adicionalTempoServico(float salB, int anosCasa);
float adicionalDependentes(float salB, int numDep);
float calcularINSS(float salB);
float calcularIR(float salB);

int main()
{
    float salB, adIdade, adTservico, adDepend;
    float descINSS, descIR, salBruto, salL;
    int idade, anosCasa, numDep;

    printf("Digite o salario base do funcionario: ");
    scanf("%f", &salB);

    printf("Digite a idade do funcionario: ");
    scanf("%d", &idade);

    printf("Digite o numero de dependentes: ");
    scanf("%d", &numDep);

    printf("Digite o tempo de servico do funcionario (anos): ");
    scanf("%d", &anosCasa);

    adIdade = adicionalIdade(salB, idade);
    adTservico = adicionalTempoServico(salB, anosCasa);
    adDepend = adicionalDependentes(salB, numDep);

    salBruto = salB + adIdade + adTservico + adDepend;

    descINSS = calcularINSS(salB);
    descIR = calcularIR(salB);

    salL = salBruto - (descINSS + descIR);

    printf("\nSalario base: R$ %.2f\n", salB);
    printf("Adicional por idade: R$ %.2f\n", adIdade);
    printf("Adicional por tempo de servico: R$ %.2f\n", adTservico);
    printf("Adicional por dependentes: R$ %.2f\n", adDepend);
    printf("Salario bruto: R$ %.2f\n", salBruto);
    printf("Desconto INSS: R$ %.2f\n", descINSS);
    printf("Desconto IR: R$ %.2f\n", descIR);
    printf("Salario liquido: R$ %.2f\n", salL);

    return 0;
}

float adicionalIdade(float salB, int idade)
{
    if (idade > 25)
        /*code*/
        return (idade - 25) * 0.01 * salB;
    else
        return 0;
}

float adicionalTempoServico(float salB, int anosCasa)
{
    return anosCasa * 0.03 * salB;
}

float adicionalDependentes(float salB, int numDep)
{
    return numDep * 0.05 * salB;
}

float calcularINSS(float salB)
{
    return salB * 0.08;
}

float calcularIR(float salB)
{
    return salB * 0.27;
}