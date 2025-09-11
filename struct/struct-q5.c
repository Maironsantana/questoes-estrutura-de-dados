#include <stdio.h>
#include <string.h>

#define TOTAL_ANIMAIS 5

typedef struct animal {
    char nome[50];
    char especie[30];
    int idade;
} AnimalType;

int main() {
    AnimalType animais[TOTAL_ANIMAIS];

    printf("=== Cadastro de Animais ===\n");
    for (int i = 0; i < TOTAL_ANIMAIS; i++) {
        printf("\nAnimal %d:\n", i + 1);

        printf("Nome: ");
        scanf("%s", &animais[i].nome);

        printf("Especie: ");
        scanf("%s", &animais[i].especie);

        printf("Idade: ");
        scanf("%d", &animais[i].idade);
    }


    printf("\n=== Animais da espécie 'cachorro' ou 'gato' ===\n");
    int encontrados = 0;

    for (int i = 0; i < TOTAL_ANIMAIS; i++) {
        if (strcmp(animais[i].especie, "cachorro") == 0 || strcmp(animais[i].especie, "gato") == 0) {
            printf("\nNome: %s\n", animais[i].nome);
            printf("Espécie: %s\n", animais[i].especie);
            printf("Idade: %d anos\n", animais[i].idade);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("\nNenhum cachorro ou gato foi atendido hoje.\n");
    }

    return 0;
}
