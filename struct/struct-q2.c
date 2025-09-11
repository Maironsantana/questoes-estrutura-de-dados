#include <stdio.h>
#include <string.h>

typedef struct endereco {
    char rua[100];
    int numero;
    char cidade[50];
} EnderecoType;

typedef struct {
    char nome[100];
    char cargo[50];
    float salario;
    EnderecoType endereco;
} FuncionarioType;

void main() {
    FuncionarioType f;

    printf("=== Cadastro de Funcionario ===\n");

    printf("Nome: ");
    fgets(f.nome, sizeof(f.nome), stdin);

    printf("Cargo: ");
    fgets(f.cargo, sizeof(f.cargo), stdin);

    printf("Salario: ");
    scanf("%f", &f.salario);
    getchar(); // limpa o \n deixado pelo scanf

    printf("Rua: ");
    fgets(f.endereco.rua, sizeof(f.endereco.rua), stdin);

    printf("Numero: ");
    scanf("%d", &f.endereco.numero);
    getchar(); // limpa o \n deixado pelo scanf

    printf("Cidade: ");
    fgets(f.endereco.cidade, sizeof(f.endereco.cidade), stdin);

    printf("\n=== Dados do Funcionario ===\n");
    printf("Nome: %s\n", f.nome);
    printf("Cargo: %s\n", f.cargo);
    printf("Salario: R$ %.2f\n", f.salario);
    printf("Endereco: %s, %d - %s\n", f.endereco.rua, f.endereco.numero, f.endereco.cidade);
}
