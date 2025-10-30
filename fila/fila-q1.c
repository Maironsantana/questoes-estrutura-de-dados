#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM 10

typedef struct fila{
    int inicio, fim, tam;
    int itens[MAX_TAM];
} FilaType;

void iniciarFila(FilaType *fila){
    fila->inicio = 0;
    fila->fim = -1;
    fila->tam = 0;
}

int filaVazia(FilaType *fila){
    if(fila->tam == 0){
        return 1;
    } else {
        return 0;
    }
}

int filaCheia(FilaType *fila){
    if(fila->tam == MAX_TAM){
        return 1;
    } else {
        return 0;
    }
}

void inserir(FilaType *fila, int valor){
    if(filaCheia(fila)){
        printf("overflow");
        exit(1);
    }

    if(fila->fim == MAX_TAM-1){
        fila->fim = 0;
    } else {
        fila->fim++;
    }
    fila->tam++;
    fila->itens[fila->fim] = valor;
}

int remover(FilaType *fila){
    if(filaVazia(fila)){
        printf("undeflow");
        exit(1);
    }

    int valor = fila->itens[fila->inicio];

    if(fila->inicio == MAX_TAM - 1){
        fila->inicio = 0;
    } else {
        fila->inicio++;
    }

    fila->tam--;

    return valor;
}

void imprimePrimeiroUltimo(FilaType *fila){
    if(filaVazia(fila)){
        printf("A fila esta vazia\n");
    } else {
        printf("Primeiro da fila: %d\n", fila->itens[fila->inicio]);
        printf("Ultimo da fila: %d\n", fila->itens[fila->fim]);
    }
}

void imprimeQuantidade(FilaType *fila){
    printf("Quantidade de elementos: %d\n",fila->tam);
}

void imprimeEspacosLivres(FilaType *fila){
    printf("Espacos livres na fila: %d", MAX_TAM - fila->tam);
}

void imprimeItensFila(FilaType *fila){
    if(filaVazia(fila)){
        printf("Fila vazia.");
        return;
    }
    FilaType aux;
    iniciarFila(&aux);

    int valor;

    printf("Itens da fila: ");
    while(!filaVazia(fila)){
        valor = remover(fila);
        printf("%d ", valor);
        inserir(&aux, valor);
    }

    while(!filaVazia(&aux)){
        valor = remover(&aux);
        inserir(fila, valor);
    }
}

void imprimeVetor(int vetor[]){
    for(int i = 0; i<MAX_TAM; i++){
        printf("posicao: %d\n", i);
        printf("valor: %d\n", vetor[i]);
    }
}

void printMenu(){
    printf("\n\n=================\n\n");
    printf("ESCOLHA A OPERACAO\n");
    printf("1)INSERIR NA FILA\n");
    printf("2)REMOVER DA FILA E IMPRIMIR\n");
    printf("3)IMPRIMIR PRIMEIRO E ULTIMO DA FILA\n");
    printf("4)IMPRIMIR QUANTIDADE DE ITENS NA FILA\n");
    printf("5)IMPRIMIR ESPACOS LIVRES NA FILA\n");
    printf("6)IMPRIMIR ITENS DA FILA\n");
    printf("0)SAIR\n");
}

void main(){
    FilaType fila;

    iniciarFila(&fila);

    int opcao;

    do{
        printMenu();
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                int valor;
                printf("Insira um numero inteiro: ");
                scanf("%d", &valor);

                inserir(&fila, valor);
                break;
            case 2:
                int valor_removido;
                valor_removido = remover(&fila);

                printf("Removido: %d\n", valor_removido);
                break;
            case 3:
                imprimePrimeiroUltimo(&fila);
                break;
            case 4:
                imprimeQuantidade(&fila);
                break;
            case 5:
                imprimeEspacosLivres(&fila);
                break;
            case 6:
                imprimeItensFila(&fila);
                break;
        }

    } while(opcao != 0);

    imprimeVetor(fila.itens);
    printf("inicio: %d\n", fila.inicio);
    printf("fim: %d\n", fila.fim);
    printf("tam: %d\n", fila.tam);
/*
    inserir(&fila, 'A');
    inserir(&fila, 'B');
    inserir(&fila, 'C');
    remover(&fila);
    remover(&fila);
    remover(&fila);
    remover(&fila);

    printf("inicio: %d\n", fila.inicio);
    printf("fim: %d\n", fila.fim);
    printf("tamanho: %d\n", fila.tam);
    printf("===============\n");


    imprimeVetor(fila.itens);
    */
}
