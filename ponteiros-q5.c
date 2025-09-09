#include <stdio.h>

// Função que troca os valores de duas variáveis usando ponteiros
void troca(int *a, int *b) {
    int temp = *a;  // Armazena o valor de 'a' temporariamente
    *a = *b;        // Atribui o valor de 'b' em 'a'
    *b = temp;      // Atribui o valor de 'a' (armazenado temporariamente) em 'b'
}

void main() {
    int jogador1, jogador2;

    printf("Digite o valor da carta do Jogador 1: ");
    scanf("%d", &jogador1);

    printf("Digite o valor da carta do Jogador 2: ");
    scanf("%d", &jogador2);

    printf("\n=== Antes da troca ===\n");
    printf("Jogador 1: %d\n", jogador1);
    printf("Jogador 2: %d\n", jogador2);

    troca(&jogador1, &jogador2);

    printf("\n=== Depois da troca ===\n");
    printf("Jogador 1: %d\n", jogador1);
    printf("Jogador 2: %d\n", jogador2);

}
