#include <stdio.h>

#define TOTAL_FOTOS 6

void main() {
    int fotos[TOTAL_FOTOS] = {1, 2, 3, 4, 5, 6};
    int *pFotos;

    printf("=== Fotos em sequ�ncia ===\n");
    pFotos = fotos;

    for (int i = 0; i < TOTAL_FOTOS; i++) {
        printf("Foto %d\n", *(pFotos + i));  // Acessa os valores usando ponteiro
    }

    printf("\n=== Fotos em ordem inversa ===\n");
    pFotos = fotos + (TOTAL_FOTOS - 1); // Aponta para o �ltimo elemento

    for (int j = TOTAL_FOTOS; j > 0; j--) {
        printf("Foto %d\n", *pFotos);
        pFotos--; // Decrementa o ponteiro para a posi��o anterior na mem�ria
    }

}
