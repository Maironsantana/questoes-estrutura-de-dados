#include <stdio.h>

void main() {
    // Sensores simulando valores lidos
    int sensor1 = 35;
    int sensor2 = 42;
    int sensor3 = 27;

    // Vetor de ponteiros apontando para os sensores
    int *sensores[3];
    sensores[0] = &sensor1;
    sensores[1] = &sensor2;
    sensores[2] = &sensor3;

    // Ponteiro para ponteiro: aponta para o vetor de ponteiros
    int **controle = sensores;

    printf("=== Central de Controle ===\n");
    for (int i = 0; i < 3; i++) {
        printf("Sensor %d -> Endereco: %p | Valor: %d\n",
               i + 1,
               *(controle + i),     // Endereço do sensor
               **(controle + i));   // Valor do sensor
    }

}
