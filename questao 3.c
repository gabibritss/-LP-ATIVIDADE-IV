#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Produto
{
    char nome[200];
    float preco;
    int estoque;
};

float compra(struct Produto *produto, float saldo)
{
    int compra;
    float resultado; 
   
    printf("Quantos produtos você deseja comprar ? ");
    scanf("%d", &compra);

    if (compra > 0 && compra <= produto->estoque)
    {
    resultado= produto->estoque - compra; 
    return resultado;
    } 
    else
    {
        printf("\nQuantidade inválida.");
    }
}

int main()
{
    float saldo =0; // Inicialize a variável saldo
    int opcao;

    setlocale(LC_ALL, "portuguese");

    struct Produto resultado;

    printf("\nDigite o nome do produto:");
    gets(resultado.nome); 

    printf("\nDigite o preço do produto:");
    scanf("%f", &resultado.preco);

    printf("\nQuantidade de produto:");
    scanf("%d", &resultado.estoque);

    printf("Nome do produto:%s\n", resultado.nome);
    printf("Preço do produto: %.2f\n", resultado.preco);
    printf("Quantidade de produto: %d\n", resultado.estoque);

    do
    {
        printf("Escolha uma das opções abaixo:\n");
        printf("(1°) Realizar compra\n");
        printf("(2°) Consultar estoque\n");
        printf("(3°) Sair do programa\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            saldo = compra(&resultado, saldo);
            printf("Compra realizada!\n");
            break;

        case 2:

           printf("Quantidade em estoque: %d\n", resultado.estoque);
           printf("Saldo atual: %.2f\n", saldo);
            break;

        case 3:
            printf("Saindo do programa...\n");
            return 0;
            break;
        }


    } while (opcao != 3);

    return 0;
}
