#include <stdlib.h>
#include <stdio.h>

typedef struct lista {
    int info;
    struct lista *prox;
} ListaType;

/* função de inicialização: retorna uma lista vazia */
ListaType *lista_inicializa(){
    return NULL;
}

/* inserção no início: retorna a lista atualizada */
ListaType *lista_insere(ListaType *l, int i){
    ListaType *novo = malloc(sizeof(ListaType));
    novo->info = i;
    novo->prox = l;
    return novo;
}

/* função retira: retira elemento da lista */
ListaType *lista_retira(ListaType *l, int v) {
    ListaType *ant = NULL; /* ponteiro para elemento anterior */
    ListaType *p = l; /* ponteiro para percorrer a lista*/

    /* procura elemento na lista, guardando anterior */
    while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }

    /* verifica se achou elemento */
    if (p == NULL)
        return l; /* não achou: retorna lista original */

    /* retira elemento */
    if (ant == NULL) {
        /* retira elemento do inicio */
        l = p->prox;
    } else {
        /* retira elemento do meio da lista */
        ant->prox = p->prox;
    }

    /* libera a memória usada pelo ponteiro auxiliar */
    free(p);
    return l;
}

/* função imprime: imprime valores dos elementos */
void lista_imprime(ListaType *l){
    ListaType *p; /* variável auxiliar para percorrer a lista */
    for (p = l; p != NULL; p = p->prox)
    printf("info = %d\n", p->info);
}
/* função vazia: retorna 1 se vazia ou 0 se não vazia */
int lista_vazia(ListaType *l){
    if (l == NULL)
    return 1;
    else
    return 0;
}

void libera_lista(ListaType *l){
    ListaType *p = l;

    while (p != NULL) {
        ListaType* t = p->prox; /* guarda referência para o próximo elemento */
        free(p); /* libera a memória apontada por p */
        p = t; /* faz p apontar para o próximo */
    }
}

void main(){
    ListaType *l;
    l = lista_inicializa();
    l = lista_insere(l, 23); /* insere na lista o elemento 23 */
    l = lista_insere(l, 45); /* insere na lista o elemento 45 */
    l = lista_insere(l, 56); /* insere na lista o elemento 56 */
    l = lista_insere(l, 78); /* insere na lista o elemento 78 */
    lista_imprime(l); /* imprimirá: 78 56 45 23 */
    l = lista_retira(l, 78);
    lista_imprime(l); /* imprimirá: 56 45 23 */
    l = lista_retira(l, 45);
    lista_imprime(l); /* imprimirá: 56 23 */
    libera_lista(l);
}

