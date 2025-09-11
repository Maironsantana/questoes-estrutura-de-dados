#include <stdio.h>
#include <string.h>

#define TOTAL_PRODUTOS 10

typedef struct produto{
    char nome[50];
    float preco;
    int quantidade;
} ProdutoType;

void imprimirProduto(ProdutoType produtos[], char *nomeBusca) {
    int encontrado = 0;

    for (int i = 0; i < TOTAL_PRODUTOS; i++) {
        if (strcmp(produtos[i].nome, nomeBusca) == 0) {
            printf("\n=== Produto Encontrado ===\n");
            printf("Nome: %s\n", produtos[i].nome);
            printf("Preço: R$ %.2f\n", produtos[i].preco);
            printf("Quantidade: %d unidades\n", produtos[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nProduto \"%s\" não encontrado.\n", nomeBusca);
    }
}

void produtoMenorQuantidade(ProdutoType produtos[]) {
    int indiceMenor = 0;

    for (int i = 1; i < TOTAL_PRODUTOS; i++) {
        if (produtos[i].quantidade < produtos[indiceMenor].quantidade) {
            indiceMenor = i;
        }
    }

    printf("\n=== Produto com menor quantidade ===\n");
    printf("Nome: %s\n", produtos[indiceMenor].nome);
    printf("Quantidade: %d unidades\n", produtos[indiceMenor].quantidade);
}

float valorTotalEstoque(ProdutoType produtos[]) {
    float totalEstoque = 0;

    for (int i = 0; i < TOTAL_PRODUTOS; i++) {
        totalEstoque += produtos[i].preco * produtos[i].quantidade;
    }

    return totalEstoque;
}

void main() {

    ProdutoType produtos[TOTAL_PRODUTOS] = {
        {"Arroz", 25.50, 30},
        {"Feijao", 8.90, 20},
        {"Macarrao", 5.50, 15},
        {"Acucar", 4.20, 50},
        {"Sal", 3.00, 10},
        {"Leite", 6.80, 25},
        {"Cafe", 15.00, 8},
        {"Oleo", 7.50, 12},
        {"Biscoito", 2.50, 40},
        {"Detergente", 2.80, 5}
    }; // Dados dos produtos já armazenados na memória

    char nomeBusca[50];

    printf("Digite o nome do produto para buscar: ");
    scanf("%s", &nomeBusca);

    imprimirProduto(produtos, nomeBusca);

    produtoMenorQuantidade(produtos);

    printf("\n=== Valor total do estoque ===\n");
    printf("R$ %.2f\n", valorTotalEstoque(produtos));

}
