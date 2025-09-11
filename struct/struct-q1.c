#include <stdio.h>
#include <string.h>


typedef struct livro {
    char titulo[100];
    char autor[100];
    int ano;
} LivroType;

void imprimirLivro(LivroType *l) {
    printf("\n=== Informações do Livro ===\n");
    printf("Título: %s\n", l->titulo);
    printf("Autor: %s\n", l->autor);
    printf("Ano de Publicação: %d\n", l->ano);
}

void main() {
    LivroType livro;

    printf("Digite o título do livro: ");
    fgets(livro.titulo, sizeof(livro.titulo), stdin);
    //A função fgets serve para receber uma string com espaços e tem a seguinte sintaxe:
    //fgets(Variável, Tamanho_da_string, Leitor)
    //Estamos passando respectivamente: o titulo como variável para armazenar; o tamanho do titulo com sizeof; e o stdin (input do teclado)

    printf("Digite o nome do autor: ");
    fgets(livro.autor, sizeof(livro.autor), stdin);

    printf("Digite o ano de publicação: ");
    scanf("%d", &livro.ano);

    imprimirLivro(&livro);

}

