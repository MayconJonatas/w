#include <stdio.h>
#include <string.h>

typedef struct {
    char titulo[50];
    char autor[50];
    int numPaginas;
} Livro;

typedef struct {
    Livro livros[10];
    int quantidade;
} Biblioteca;

void lerLivro(Livro *livro) {
    printf("Digite o titulo do livro: ");
    fgets(livro->titulo, 50, stdin);

    printf("Digite o autor do livro: ");
    fgets(livro->autor, 50, stdin);

    printf("Digite o número de páginas do livro: ");
    scanf("%d", &livro->numPaginas);

    getchar();
}

void imprimirLivro(Livro livro) {
    printf("Titulo: %s", livro.titulo);
    printf("Autor: %s", livro.autor);
    printf("Numero de paginas: %d\n", livro.numPaginas);
}

void imprimirBiblioteca(Biblioteca biblioteca) {
    printf("Livros na biblioteca:\n");
    for (int i = 0; i < biblioteca.quantidade; i++) {
        imprimirLivro(biblioteca.livros[i]);
    }
}

void imprimirMaiorNumPaginas(Biblioteca biblioteca) {
    int indiceMaiorNumPaginas = 0;
    for (int i = 1; i < biblioteca.quantidade; i++) {
        if (biblioteca.livros[i].numPaginas > biblioteca.livros[indiceMaiorNumPaginas].numPaginas) {
            indiceMaiorNumPaginas = i;
        }
    }

    printf("Livro com o maior numero de paginas na biblioteca:\n");
    imprimirLivro(biblioteca.livros[indiceMaiorNumPaginas]);
}

int main() {
    Biblioteca biblioteca;
    biblioteca.quantidade = 0;

    int opcao;

    do {
        printf("Escolha uma opcao:\n");
        printf("1 - Adicionar livro\n");
        printf("2 - Imprimir todos os livros\n");
        printf("3 - Imprimir livro com maior numero de paginas\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                if(biblioteca.quantidade < 10) {
                    Livro novoLivro;
                    lerLivro(&novoLivro);
                    biblioteca.livros[biblioteca.quantidade++] = novoLivro;
                    printf("Livro adicionado com sucesso!\n");
                } else {
                    printf("Biblioteca esta cheia. Nao e possivel adicionar mais livros.\n");
                }
                break;
            case 2:
                imprimirBiblioteca(biblioteca);
                break;
            case 3:
                if(biblioteca.quantidade > 0) {
                    imprimirMaiorNumPaginas(biblioteca);
                } else {
                    printf("A biblioteca esta vazia.\n");
                }
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
