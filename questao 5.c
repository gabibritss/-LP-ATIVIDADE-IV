#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define limit 200

void limpacache (){
    fflush(stdin);
}


struct Funcionario {
    char nome[200];
    char cargo[200];
    float salario;
};

float calcularMedia(struct Funcionario funcionarios[], int numfunci, char cargo[]) {
    float somasala;
    int i ;

    for (i = 0; i < numfunci; i++) {
        if (strcmp(funcionarios[i].cargo, cargo) == 0) {
            somasala += funcionarios[i].salario;
            i++;
        }
    }

    if (i == 0) {
        return 0;
    }

    return somasala / i;
}

int main() {
    struct Funcionario funcionarios[limit];
    int numfunci;
    char cargop[200];
    int i;

    printf("\nInforme a quantidade de funcionarios: ");
    scanf("%d", &numfunci);

    for (i = 0; i < numfunci; i++) {
        limpacache();
        printf("\nDigite o nome do funcionario %dº: ", i + 1);
        gets(funcionarios[i].nome);
        fflush(stdin);
        printf("\n Digite o cargo do funcionario %dº: ", i + 1);
        scanf("%s", funcionarios[i].cargo);
        printf("\n Digite o salario do funcionario %dº: ", i + 1);
        scanf("%f", &funcionarios[i].salario);
         limpacache();
    }

    printf("\n Digite o cargo para calcular a media salarial: ");
    gets(cargop);

    float mediaSalarial = calcularMedia(funcionarios, numfunci, cargop);

    printf("\n A media salarial do %s é : %.2f",  cargop, mediaSalarial);

    return 0;
}   
