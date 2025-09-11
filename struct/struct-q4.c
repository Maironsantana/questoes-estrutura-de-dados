#include <stdio.h>
#include <string.h>

typedef struct pessoa{
    char nome[100];
    int anoNascimento;
} PessoaType;

int calcularIdade(PessoaType *p, int anoAtual) {
    return anoAtual - p->anoNascimento;
}

void main() {
    PessoaType pessoa;
    int anoAtual;

    printf("=== Cadastro de Pessoa ===\n");

    printf("Nome: ");
    fgets(pessoa.nome, sizeof(pessoa.nome), stdin);

    printf("Ano de nascimento: ");
    scanf("%d", &pessoa.anoNascimento);

    printf("Ano atual: ");
    scanf("%d", &anoAtual);

    int idade = calcularIdade(&pessoa, anoAtual);

    printf("\n=== Resultado ===\n");
    printf("%s tem %d anos de idade.\n", pessoa.nome, idade);
}
