#include <stdio.h>
#include <string.h>


typedef struct livro {
    char titulo[100];
    char autor[100];
    int ano;
} LivroType;

void imprimirLivro(LivroType *l) {
    printf("\n=== Informa��es do Livro ===\n");
    printf("T�tulo: %s\n", l->titulo);
    printf("Autor: %s\n", l->autor);
    printf("Ano de Publica��o: %d\n", l->ano);
}

void main() {
    LivroType livro;

    printf("Digite o t�tulo do livro: ");
    fgets(livro.titulo, sizeof(livro.titulo), stdin);
    //A fun��o fgets serve para receber uma string com espa�os e tem a seguinte sintaxe:
    //fgets(Vari�vel, Tamanho_da_string, Leitor)
    //Estamos passando respectivamente: o titulo como vari�vel para armazenar; o tamanho do titulo com sizeof; e o stdin (input do teclado)

    printf("Digite o nome do autor: ");
    fgets(livro.autor, sizeof(livro.autor), stdin);

    printf("Digite o ano de publica��o: ");
    scanf("%d", &livro.ano);

    imprimirLivro(&livro);

}

