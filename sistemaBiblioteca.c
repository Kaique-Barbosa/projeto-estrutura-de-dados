#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro {
    char nome[100];
    char autor[100];
    int anoLancamento;
    struct Livro *prox;
} Livro;

Livro *inicio = NULL;

// ------------ inicio das fumções --------------------------

//cadastrar livro
void cadastrarLivro(char nome[], char autor[], int anoLancamento) {
    Livro *novo = malloc(sizeof(Livro));

    strcpy(novo ->  nome,  nome);
    strcpy(novo ->  autor,  autor);
    novo -> anoLancamento = anoLancamento;
    novo ->  prox = NULL;



    if (inicio == NULL) {
        inicio = novo;
    } else {
        Livro *atual = inicio;

        while (atual ->  prox != NULL) {
            atual = atual ->  prox;
        }

        atual ->  prox = novo;
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
        printf("\n-Nome: %s\n", atual -> nome);
        printf("--Autor: %s\n", atual -> autor);
        printf("--Ano de lancamento: %d\n", atual -> anoLancamento);
         printf("-------------------------- \n");

        atual = atual -> prox;
    }
}

// Buscar livro
void buscarLivro(char nome[]) {
    Livro *atual = inicio;

    while (atual != NULL) {
        if (strcmp(atual ->  nome, nome) == 0) {
            printf("\nLivro encontrado!\n");
            printf("Nome: %s\n", atual -> nome);
            printf("Autor: %s\n", atual -> autor);
            printf("Ano de lancamento: %d\n", atual -> anoLancamento);
            return;
        }

        atual = atual -> prox;
    }

    printf("Livro nao encontrado.\n");
}



// Remover livro
void removerLivro(char nome[]) {
    Livro *atual = inicio;
    Livro *anterior = NULL;

    while (atual != NULL) {

        if (strcmp(atual->nome, nome) == 0) {

            if (anterior == NULL) { // verifica se é o primero nó
                inicio = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            free(atual);
            printf("Livro removido.\n");
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }

    printf("Livro nao encontrado.\n");
}

// ------------ Fim das fumções --------------------------




int main() {
    int opcao;
    
    char nome[100];
    char autor[100];
    int anoLancamento;

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
                nome[strcspn(nome, "\n")] = '\0'; //  qual posição aparece o primeiro "\n.""

                printf("Autor: ");
                fgets(autor, 100, stdin);
                autor[strcspn(autor, "\n")] = '\0';

                printf("Ano de lancamento: ");
                scanf("%d", &anoLancamento);
                getchar();

                cadastrarLivro(nome, autor, anoLancamento);
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