#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_PILHA 256
//=======ESTRUTURA=======
typedef struct stack {
    int top;
    char itens[TAMANHO_PILHA];
} StackType;

//=======FUN��ES=======
void init(StackType *pilha) {
    pilha->top = -1;
}

int empty(StackType *p) {
    return p->top == -1;
}

int full(StackType *p) {
    return p->top == TAMANHO_PILHA - 1;
}

void push(StackType *p, char caractere) {
    if (full(p)) {
        printf("[Aviso] Stack overflow: a pilha est� cheia (capacidade = %d).\n", TAMANHO_PILHA);
        exit(1);
    }
    p->top++;
    p->itens[p->top] = caractere;
}

char pop(StackType *p) {
    if (empty(p)) {
        printf("[Aviso] Stack underflow: a pilha est� vazia, nada para remover.\n");
        exit(1);
    }
    char removido;
    removido = p->itens[p->top];
    p->top--;
    return removido;
}

char stacktop(StackType *p) {
    if (empty(p)) {
        printf("[Aviso] Stack underflow: a pilha est� vazia, n�o h� topo.\n");
        exit(1);
    }
    return p->itens[p->top];
}

//=======PROGRAMA MAIN=======
int main() {
    char palavra[TAMANHO_PILHA];
    StackType pilha;
    init(&pilha);

    int tamanho = 0;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    for(int i = 0; palavra[i] != '\0'; i++) tamanho++;

    int eh_impar = tamanho % 2; //Quando um palindormo tem tamanho impar, a letra do meio n�o importa. Vamos usar essa vari�vel mais � frente


    for(int i = 0; i < tamanho; i++){
        if(i <= tamanho/2 - 1){
            push(&pilha, palavra[i]); //at� a metade da palavra (tamanho / 2 - 1), vamos empilhar
        } else {
            if(eh_impar && i == tamanho / 2){
                continue; //se a palavra tiver tamanho impar, a letra no meio � ignorada. portanto, n�o vamos empilhar nem desempilhar
            }
            char letra = pop(&pilha);
            if(palavra[i] != letra){
               printf("Nao eh palindromo");  //se a letra seguinte for diferente da letra desempilhada, n�o � palindromo
               return 0;
            }
        }
    }

    if(empty(&pilha)){
        printf("Eh palindromo"); //Se no final, n�o tiver nenhum item na pilha, � pal�ndromo
    }

    return 0;
}

