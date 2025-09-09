#include <stdio.h>
#include <string.h>

void substituir_a(char *str) {
    while (*str != '\0') {   // Enquanto não chegar ao final da string
        if (*str == 'a' || *str == 'A') {
            *str = '@';      // Substitui o caractere
        }
        str++;  // Avança para o próximo caractere
    }
}

void main() {
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", &palavra);

    // Função que substitui os 'a' por '@'
    substituir_a(palavra); //Lembrando que vetor é ponteiro, então passamos diretamente a variável

    printf("Resultado apos substituicao: %s\n", palavra);

}
