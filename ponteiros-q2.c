#include <stdio.h>

#define QTD_ENCOMENDAS 10

int main() {
    int rastreios[QTD_ENCOMENDAS] = {
        12345, 67890, 13579, 24680, 11223,
        44556, 77889, 99001, 22334, 55667
    };

    int posicao;
    int *pPosicao;

    printf("Digite a posicao da encomenda (0 a %d): ", QTD_ENCOMENDAS - 1);
    scanf("%d", &posicao);

    if (posicao < 0 || posicao >= QTD_ENCOMENDAS) {
        printf("\nErro: Posicao invalida! Tente um valor entre 0 e %d.\n", QTD_ENCOMENDAS - 1);
        return 1; // Sai do programa com código de erro
    }

    // Faz o ponteiro apontar para a posição escolhida
    pPosicao = &rastreios[posicao];

    printf("\n=== Informacoes da Encomenda ===\n");
    printf("Numero de rastreio: %d\n", *pPosicao);
    printf("Endereco de memoria: %p\n", pPosicao);

    return 0;
}
