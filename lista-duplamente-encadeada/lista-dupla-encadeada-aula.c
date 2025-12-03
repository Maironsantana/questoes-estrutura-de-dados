#include <stdlib.h>
#include <stdio.h>

typedef struct lista_dupla{
    int info;
    struct lista_dupla *ant;
    struct lista_dupla *prox;
} ListaDType;

ListaDType *inicia_lista(){
    return NULL;
}

/*inserção no inicio*/
ListaDType *lista_insere(ListaDType *lista, int valor){
    ListaDType *novo = malloc(sizeof(ListaDType));

    novo->info = valor;
    novo->prox = lista;
    novo->ant = NULL;

    /*Verifica se a lista possui algum item*/
    if(lista!=NULL)
        lista->ant=novo;

    return novo;
}

/*função busca: busca um elemento na lista *lista */
ListaDType *busca(ListaDType *lista, int valor){
    ListaDType *p;

    /*usa o ponteiro *p para percorrer os nós da lista*/
    for(p=lista; p!=NULL; p=p->prox){
        if(p->info == valor)
            return p;
    }

    return NULL;    /*não achou*/
}

void imprime_lista(ListaDType *lista){
    ListaDType *p;

    for(p=lista; p!=NULL; p=p->prox){
        printf("%d ", p->info);
    }
    printf("\n");
}

/*função lista_remove: remove um elemento da lista*/
ListaDType *lista_remove(ListaDType *lista, int valor){
    ListaDType *p = busca(lista, valor);

    if(p==NULL)
        return lista; /*não achou o elemento*/

    if(lista == p)
        lista = p->prox; /*o elemento estava no início da lista*/
    else
        p->ant->prox = p->prox;/*o elemento estava no meio ou fim da lista*/

    if(p->prox != NULL)
        /* se houver elementos após o item removido:
           ajustar o encadeamento do elemento seguinte*/
        p->prox->ant = p->ant;

    free(p);
    return lista;
}


void main(){
    ListaDType *lista;
    lista = inicia_lista();

    lista = NULL;

    lista = lista_insere(lista, 10);
    lista = lista_insere(lista, 20);
    lista = lista_insere(lista, 30);
    lista = lista_insere(lista, 40);
    imprime_lista(lista);

    lista = lista_remove(lista, 20);
    lista = lista_remove(lista, 25);
    imprime_lista(lista);
}
