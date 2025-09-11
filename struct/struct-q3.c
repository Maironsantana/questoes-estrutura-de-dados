#include <stdio.h>
#include <string.h>

#define TOTAL_PILOTOS 3

typedef struct piloto {
    char nome[50];
    char carro[50];
    float tempo;
} PilotoType;

void main() {
    PilotoType pilotos[TOTAL_PILOTOS];
    int indiceVencedor = 0;

    printf("=== Cadastro dos Pilotos ===\n");
    for (int i = 0; i < TOTAL_PILOTOS; i++) {
        printf("\nPiloto %d:\n", i + 1);

        printf("Nome: ");
        fgets(pilotos[i].nome, sizeof(pilotos[i].nome), stdin);

        printf("Carro: ");
        fgets(pilotos[i].carro, sizeof(pilotos[i].carro), stdin);

        printf("Tempo da volta (em segundos): ");
        scanf("%f", &pilotos[i].tempo);
        getchar(); // limpa \n do buffer
    }

    for (int i = 1; i < TOTAL_PILOTOS; i++) {
        if (pilotos[i].tempo < pilotos[indiceVencedor].tempo) {
            indiceVencedor = i;
        }
    }

    // Exibir vencedor
    printf("\n=== Vencedor da corrida ===\n");
    printf("Nome: %s\n", pilotos[indiceVencedor].nome);
    printf("Carro: %s\n", pilotos[indiceVencedor].carro);
    printf("Tempo: %.2f segundos\n", pilotos[indiceVencedor].tempo);

}
