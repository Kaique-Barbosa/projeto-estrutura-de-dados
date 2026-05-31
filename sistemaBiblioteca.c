#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main() {
    int opcao;
    char nome[100];

    do {
        printf("\n\n-=-=-=-=-=BIBLIOTECA =-=-=-=-=-\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Buscar livro\n");
        printf("3 - Listar livros\n");
        printf("4 - Remover livro\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        getchar(); // limpa o \n do buffer

        switch (opcao) {

            case 1:
                printf("Nome do livro: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = '\0'; //  qual posição aparece o primeiro \n.

                cadastrarLivro(nome);
                break;

            case 2:
                printf("Nome do livro: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                buscarLivro(nome);
                break;

            case 3:
                listarLivros();
                break;

            case 4:
                printf("Nome do livro: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                removerLivro(nome);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}