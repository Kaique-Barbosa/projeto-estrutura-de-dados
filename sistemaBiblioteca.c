#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro {
    char nome[100];
    struct Livro *prox;
} Livro;

Livro *inicio = NULL;

// ------------ inicio das fumções --------------------------

//cadastrar livro
void cadastrarLivro(char nome[]) {
    Livro *novo = malloc(sizeof(Livro));

    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if (inicio == NULL) {
        inicio = novo;
    } else {
        Livro *atual = inicio;

        while (atual->prox != NULL) {
            atual = atual->prox;
        }

        atual->prox = novo;
    }

    printf("Livro cadastrado com sucesso!\n");
}

// Listar livros
void listarLivros() {
    Livro *atual = inicio;

    if (atual == NULL) {
        printf("Nenhum livro encontrado no cadastro.\n");
        return;
    }

    printf("\n-=-=-=-=-= LIVROS CADASTRADOS =-=-=-=-=-\n");

    while (atual != NULL) {
        printf("- %s\n", atual->nome);
        atual = atual->prox;
    }
}

// Buscar livro
void buscarLivro(char nome[]) {
    Livro *atual = inicio;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            printf("Livro encontrado: %s\n", atual->nome);
            return;
        }

        atual = atual->prox;
    }

    printf("Livro nao encontrado.\n");
}

// ------------ Fim das fumções --------------------------




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
         system("cls");

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

               // buscarLivro(nome);
                break;

            case 3:
                listarLivros();
                break;

            case 4:
                printf("Nome do livro: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = '\0';

               // removerLivro(nome);
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