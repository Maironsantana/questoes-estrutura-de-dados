#include <stdio.h>
#include <string.h>

void substituir_a(char *str) {
    while (*str != '\0') {   // Enquanto n�o chegar ao final da string
        if (*str == 'a' || *str == 'A') {
            *str = '@';      // Substitui o caractere
        }
        str++;  // Avan�a para o pr�ximo caractere
    }
}

void main() {
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", &palavra);

    // Fun��o que substitui os 'a' por '@'
    substituir_a(palavra); //Lembrando que vetor � ponteiro, ent�o passamos diretamente a vari�vel

    printf("Resultado apos substituicao: %s\n", palavra);

}
