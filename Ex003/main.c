#include <stdlib.h>
#include <stdio.h>

float peso1(float v1);
float peso2(float v1);
 

int main()
{
    float v1, ferias, academia;


    printf("Digite o peso inicial: ");
    scanf("%f", &v1);

    ferias = peso1(v1);
    academia = peso2(ferias);
    
    printf("O peso apos as ferias e de: %.2f\n", ferias);
    printf("O peso apos a academia e de: %.2f\n", academia);

    return 0;
}



float peso1(float v1)
{
    return v1 + (v1 * 0.15);
}

float peso2(float v1)
{
    return v1 - (v1 * 0.20);
}
