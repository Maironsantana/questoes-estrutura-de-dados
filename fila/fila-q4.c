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
    printf("A)ATENDER PROX. AVIÃO (REMOVER DA FILA)\n");
    printf("P)INSERIR NA FILA DE POUSO\n");
    printf("D)INSERIR NA FILA DE DECOLAGEM\n");
    printf("I)IMPRIMIR AVIÕES DA FILA\n");
    printf("Q)SAIR\n");
}

void main(){
    FilaType pouso;
    FilaType decolagem;

    iniciarFila(&pouso);
    iniciarFila(&decolagem);

    char opcao;

    do{
        printMenu();
        scanf(" %c",&opcao);

        switch(opcao){
            case 'P':
                // INSERIR NA FILA DE POUSO
                int IdP;
                printf("Insira o ID do avião: ");
                scanf("%d", &IdP);

                inserir(&pouso, IdP);
                break;
            case 'D':
                // INSERIR NA FILA DE DECOLAGEM
                int IdD;
                printf("Insira o ID do avião: ");
                scanf("%d", &IdD);

                inserir(&decolagem, IdD);
                break;
            case 'A':
                //remover da fila
                int valor_removido;
                if(!filaVazia(&pouso)){
                    valor_removido=remover(&pouso);
                    printf("O aviao %d pousou\n", valor_removido);
                } else {
                    valor_removido=remover(&decolagem);
                    printf("O aviao %d decolou\n", valor_removido);
                }

                break;
            case 'I':
                printf("\nFila de Pouso: ");
                imprimeItensFila(&pouso);
                printf("\nFila de Decolagem: ");
                imprimeItensFila(&decolagem);
                break;
        }

    } while(opcao != 'Q');
}

