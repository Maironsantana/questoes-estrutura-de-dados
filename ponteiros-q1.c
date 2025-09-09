#include <stdio.h>

void main() {
    int cofre;          // Vari�vel para armazenar o n�mero do cofre
    int *pCofre;        // Ponteiro para inteiro

    printf("Digite o numero do cofre: ");
    scanf("%d", &cofre);

    // Fazendo o ponteiro apontar para a vari�vel cofre
    pCofre = &cofre;

    // Exibindo as informa��es solicitadas
    printf("\n=== Informacoes do Cofre ===\n");
    printf("Numero do cofre: %d\n", cofre);
    printf("Endereco de memoria do cofre: %p\n", &cofre);
    printf("Endereco de memoria armazenado no ponteiro: %p\n", pCofre);
    printf("Numero do cofre acessado pelo ponteiro: %d\n", *pCofre);
    printf("Endereco de memoria da variavel ponteiro: %p\n", &pCofre);
}

