#include <stdio.h>
#include <stdlib.h>

struct contaBancaria {
    int Conta;
    char nome[50];
    float saldo;
    char tipoConta[20];
};


void depositar(struct contaBancaria *conta, float valor) {
    if (valor > 0) {
        conta->saldo += valor;
        printf("\nDepósito de R$%.2f realizado com sucesso.", valor);
    } else {
        printf("\nDepósito não foi realizado, valor inválido.");
    }
}


void sacar(struct contaBancaria *conta, float valor) {
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de R$%.2f realizado com sucesso.\n", valor);
    } else {
        printf("\nValor inválido ou saldo insuficiente. O saque não foi realizado.");
    }
}


void imprimirSaldo(struct contaBancaria conta) {
    printf("Saldo atual da conta: R$%.2f\n", conta.saldo);
}

int main() {
    
    struct contaBancaria minhaConta = {12345, "Gabis", 10.000, "Corrente"};

    int opcao;
    float valor;

    do {
    
        printf("\n--------Menu--------\n");
        printf("\n1- Depositar dinheiro.");
        printf("\n2- Sacar dinheiro.");
        printf("\n3- Imprimir saldo.");
        printf("\n4- Sair do programa.");

        
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                
                printf("\nDigite o valor a ser depositado: ");
                scanf("%f", &valor);
                depositar(&minhaConta, valor);
                break;

            case 2:
                
                printf("\nDigite o valor a ser sacado: ");
                scanf("%f", &valor);
                sacar(&minhaConta, valor);
                break;

            case 3:
                
                imprimirSaldo(minhaConta);
                break;

            case 4:
                
                printf("\nSaindo do programa.");
                break;

            default:
                
                printf("Opção inválida. Tente novamente....\n");
        }

    } while (opcao != 4);

    return 0;
}
