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

int size(StackType *p) {
    return p->top + 1;
}

int freeSpaces(StackType *p) {
    return TAMANHO_PILHA - size(p);
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

void printStack(StackType *p) {
    StackType aux;
    init(&aux);

    printf("=== Conteúdo da pilha ===\n");

    // Desempilha todos os elementos, imprime e guarda na auxiliar
    while (!empty(p)) {
        int valor = pop(p);
        printf("%d\n", valor);
        push(&aux, valor);
    }

    // Restaura os elementos para a pilha original
    while (!empty(&aux)) {
        int valor = pop(&aux);
        push(p, valor);
    }
}

void printMenu(void) {
    printf("\n=== MENU ===\n");
    printf("1) Inserir um número na pilha (push)\n");
    printf("2) Remover um item da pilha e imprimir (pop)\n");
    printf("3) Imprimir o topo da pilha (stacktop)\n");
    printf("4) Imprimir a quantidade de itens na pilha\n");
    printf("5) Imprimir quantos espaços livres ainda existem\n");
    printf("6) Imprimir todos os itens da pilha\n");
    printf("0) Sair\n");
    printf("Escolha: ");
}

//=======PROGRAMA MAIN=======
int main(void) {
    StackType pilha;
    init(&pilha);

    int opcao;
    do {
        printMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int valor;
                printf("Digite um inteiro para inserir: ");
                scanf("%d", &valor);
                push(&pilha, valor);
                printf("OK: %d inserido.\n", valor);
                break;
            }

            case 2: {
                int numero = pop(&pilha);
                printf("Item removido: %d\n", numero);

                break;
            }

            case 3: {
                int topo = stacktop(&pilha);
                printf("Topo da pilha: %d\n", topo);
                break;
            }

            case 4:
                printf("Quantidade de itens na pilha: %d\n", size(&pilha));
                break;

            case 5:
                printf("Espaços livres na pilha: %d\n", freeSpaces(&pilha));
                break;

            case 6:
                printStack(&pilha);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
