#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_PILHA 10
//=======ESTRUTURA=======
typedef struct stack {
    int top;
    int itens[TAMANHO_PILHA];
} StackType;

//=======FUNÇÕES=======
void init(StackType *pilha) {
    pilha->top = -1;
}

int empty(StackType *p) {
    return p->top == -1;
}

int full(StackType *p) {
    return p->top == TAMANHO_PILHA - 1;
}

void push(StackType *p, int valor) {
    if (full(p)) {
        printf("[Aviso] Stack overflow: a pilha está cheia (capacidade = %d).\n", TAMANHO_PILHA);
        exit(1);
    }
    p->top++;
    p->itens[p->top] = valor;
}

int pop(StackType *p) {
    if (empty(p)) {
        printf("[Aviso] Stack underflow: a pilha está vazia, nada para remover.\n");
        exit(1);
    }
    int removido;
    removido = p->itens[p->top];
    p->top--;
    return removido;
}

int stacktop(StackType *p) {
    if (empty(p)) {
        printf("[Aviso] Stack underflow: a pilha está vazia, não há topo.\n");
        exit(1);
    }
    return p->itens[p->top];
}

//=======PROGRAMA MAIN=======
int main() {
    int n;
    StackType pilha;
    init(&pilha);

    printf("Digite um numero inteiro nao negativo: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Entrada invalida.\n");
        return 0;
    }

    // Caso especial: 0 em binário é "0"
    if (n == 0) {
        push(&pilha, 0);
    } else {
        int x = n;
        while (x > 0) {
            push(&pilha, x % 2);
            x /= 2;
        }
    }

    // Desempilha para imprimir na ordem correta
    printf("Binario: ");
    while (!empty(&pilha)) {
        printf("%d", pop(&pilha));
    }
    printf("\n");

    return 0;
}
