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

// ====== a) i = 2º a partir do topo; remove os 2 superiores ======
void pegaSegundoRemovendo(StackType *p, int *i) {
    // topo = x1, abaixo = x2
    int x1 = pop(p);        // remove topo
    int x2 = pop(p);        // remove segundo
    *i = x2;                // segundo a partir do topo
}

// ====== b) i = 2º a partir do topo; pilha inalterada ======
void pegaSegundoPreservando(StackType *p, int *i) {
    StackType aux; init(&aux);
    int x1 = pop(p);            // topo
    int x2 = pop(p);            // segundo
    *i = x2;
    // restaura (segundo por baixo do topo)
    push(&aux, x2);
    push(&aux, x1);
    while (!empty(&aux)) push(p, pop(&aux));
}

// ====== c) i = n-ésimo a partir do topo; remove os n superiores ======
void pegaNEsimoRemovendo(StackType *p, int n, int *i) {
    int val = 0;
    for (int j = 1; j <= n; j++) {
        val = pop(p);       // ao final, val = n-ésimo removido (e os n foram removidos)
    }
    *i = val;
}

// ====== d) i = n-ésimo a partir do topo; pilha inalterada ======
void pegaNEsimoPreservando(StackType *p, int n, int *i) {
    StackType aux; init(&aux);
    int val = 0;
    for (int j = 1; j <= n; j++) {
        int x = pop(p);
        if (j == n) val = x;    // achou o n-ésimo a partir do topo
        push(&aux, x);          // guarda para restaurar
    }
    while (!empty(&aux)) push(p, pop(&aux)); // restaura exatamente como estava
    *i = val;
}

// ====== e) i = último (fundo) da pilha; deixar pilha vazia ======
void pegaFundoEsvaziando(StackType *p, int *i) {
    int ultimo = 0;
    while (!empty(p)) ultimo = pop(p);
    *i = ultimo; // pilha vazia ao final
}

// ====== f) i = último (fundo) da pilha; pilha inalterada ======
void pegaFundoPreservando(StackType *p, int *i) {
    StackType aux; init(&aux);
    int fundo = 0;
    // move tudo p->aux (inverte), topo de aux será o fundo original
    while (!empty(p)) push(&aux, pop(p));
    if (!empty(&aux)) fundo = stacktop(&aux); // olhar o fundo original
    // restaura à pilha original
    while (!empty(&aux)) push(p, pop(&aux));
    *i = fundo;
}

// ====== g) i = 3º a partir do final; deixar a pilha com 4 elementos ======
void pegaTerceiroDoFundoDeixandoQuatro(StackType *p, int *i) {
    // Estratégia:
    // 1) Passa tudo p->aux contando; topo de aux vira o fundo original.
    // 2) Ao voltar aux->p, apenas os últimos 4 voltam (para deixar 4 na pilha).
    //    Durante a varredura de baixo p/ cima (aux topo = fundo original):
    //    quando índice==3 (terceiro do fundo), salva em i.
    StackType aux; init(&aux);
    int count = 0;
    while (!empty(p)) { push(&aux, pop(p)); count++; }

    int idx = 0; // 1 = fundo, 2 = segundo do fundo, 3 = terceiro do fundo, ...
    while (!empty(&aux)) {
        int x = pop(&aux);
        idx++;
        if (idx == 3) *i = x;            // 3º a partir do fundo
        // Reconstroi apenas os 4 últimos elementos (do topo original)
        if (idx > count - 4) push(p, x); // mantém a pilha com 4 ao final
    }
}

//=======PROGRAMA MAIN=======
int main() {
    StackType P; init(&P);
    // empilha 10 valores (1 .. 10), 10 será o topo
    for (int v = 1; v <= 10; v++) push(&P, v);

    int i;

    // a)
    pegaSegundoRemovendo(&P, &i);
    printf("a) segundo do topo (removendo): i=%d | tamanho apos: %d\n", i, P.top+1);

    // reconstroi para seguir os testes (empilha novamente 9 e 10)
    push(&P, 9); push(&P, 10);

    // b)
    pegaSegundoPreservando(&P, &i);
    printf("b) segundo do topo (preservando): i=%d | tamanho apos: %d\n", i, P.top+1);

    // c) n-esimo removendo (ex.: n=4) -> pega o 4º do topo e remove 4
    pegaNEsimoRemovendo(&P, 4, &i);
    printf("c) 4o do topo (removendo): i=%d | tamanho apos: %d\n", i, P.top+1);

    // reconstroi 4 itens no topo para seguir (7,8,9,10)
    push(&P, 7); push(&P, 8); push(&P, 9); push(&P, 10);

    // d) n-esimo preservando (ex.: n=5)
    pegaNEsimoPreservando(&P, 5, &i);
    printf("d) 5o do topo (preservando): i=%d | tamanho apos: %d\n", i, P.top+1);

    // e) fundo esvaziando (deixa a pilha vazia)
    pegaFundoEsvaziando(&P, &i);
    printf("e) fundo (esvaziando): i=%d | tamanho apos: %d\n", i, P.top+1);

    // reempilha 10 valores de novo para f, g
    for (int v = 1; v <= 10; v++) push(&P, v);

    // f) fundo preservando
    pegaFundoPreservando(&P, &i);
    printf("f) fundo (preservando): i=%d | tamanho apos: %d\n", i, P.top+1);

    // g) 3º a partir do final, deixando 4 elementos
    pegaTerceiroDoFundoDeixandoQuatro(&P, &i);
    printf("g) 3o do fundo (deixando 4): i=%d | tamanho apos: %d\n", i, P.top+1);

    return 0;
}
