#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cabecalho (){
    	printf("=======================");
    	printf("\n\t SENAI");
     	printf("=======================");
}

void limpacache(){
	 fflush(stdin);
}

void limpatela(){
	system("cls||clear");
}

float calcularMedia(float numero[])
{
    int i;
    float soma = 0, media;

    for (i = 0; i < 2; i++)
    {
        soma += numero[i];
    }
    return media = soma / 2;
}


char *resultado(float nota)
{
    char resultado[200];

    if (nota >= 7)
    {
        strcpy(resultado, "APROVADO");
    }
    else
    {
        strcpy(resultado, "REPROVADO");
    }

    return resultado;
}

struct dados
{
    char nasci[200];
    char nome[200];
    float nota[2];
    float media;
};
int main(){

    int i, j;
    struct dados aluno[5];

    for (i = 0; i < 5; i++)
    {
        printf("\nNome do %dº aluno: ", i + 1);
        gets(aluno[i].nome);
        printf("Data de nascimento: ");
        gets(aluno[i].nasci);

        for (j = 0; j < 2; j++)
        {
            
            
                printf("Digite a %d° nota: ", j + 1);
                scanf("%f", &aluno[i].nota[j]);
             limpacache();   
        }
       
        aluno[i].media = calcularMedia(aluno[i].nota);
         
    }

    limpatela();
    cabecalho();
	for (i = 0; i < 5; i++)
    {
        printf("\nNome do %dº aluno : %s", i + 1, aluno[i].nome);
        printf("\nData de nascimento: %s", aluno[i].nasci);
        for (j = 0; j < 2; j++)
        {
            printf("\n%d° nota: %.2f\n", j + 1, aluno[i].nota[j]);
        }
        printf("\nMedia: %.1f\n", aluno[i].media);
        printf("\n-------%s--------", resultado(aluno[i].media));

    }

    return 0;
}
