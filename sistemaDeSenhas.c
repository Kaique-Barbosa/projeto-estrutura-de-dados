#include <stdio.h>
#include <stdlib.h>

// Aluno: Kaique Almeida Barbosa
// -----------------------------
// problematica:  Sistema de atendimento de senhas


// CRiando a STRUCT

typedef struct No {
    int senha;
    struct No *prox;
} No;

// criando ponteiros do tipo No para delimitar o inicio e fim 

No *inicio = NULL;
No *fim = NULL;

// ------------ inicio das fumções --------------------------

// Função para gerar as senhas:
void gerarSenha(int senha){
    // definição do ponteiro Novo do tipo No
    No *novo = malloc(sizeof(No));

    novo -> senha = senha;
    novo -> prox = NULL;

    if(fim == NULL){
        // fim = novo; 
        // inicio = fim;
        // Declarando como atribuição encadeada mas siginifica o mesmo acima ↑↑
        inicio = fim = novo;
    } else{
        fim -> prox = novo;
        fim = novo;
    }

    printf("A senha %d foi adicionada na fila \n", senha);
    printf("\n \n");
}

//  função para chamar a prox senha

void chamarProxSenha(){
    if(inicio==NULL){
        printf("A fila está vazia\n ");
    }
 
    No *senhaChamada = inicio;

    printf("Chamando a senha: %d\n", senhaChamada -> senha);

    inicio = inicio -> prox;

    if(inicio == NULL){
        fim =NULL;
    }

    free(senhaChamada);
}



// Função para Exibir FIla

void exibirFila(){
    No * atual = inicio;

    if(atual == NULL){
        printf("A fila  Está Vazia!\n");
    }

    printf("Fila: ");
    while (atual != NULL){
        printf("Senha: %d\t", atual -> senha);
        atual = atual -> prox;
    }
    
}


// função para pesquisar senha

void pesquisarSenha(int senha){
    No *atual = inicio;

    while (atual != NULL ){
        
        
        printf("");
    }
}

// ------------ Fim das fumções --------------------------





int main() {

    int opcaoSelecionada, senha, cont =1;

    do {
        
        printf("-=-=-=-=-= SYS SENHAS =-=-=-=-=- \n");
        printf("1 - gerar Senhas \t");
        printf("2 - Chamar proxima senha \t");
        printf("3 - Pesquisar senha \t");
        printf("4 - Exibir fila de senhas \n");
        printf("0 - Sair do programa \n");
        printf("Opcao: ");
        scanf("%d", &opcaoSelecionada);
        system("cls");

    // SWITCH PARA GERENCIAR AS ENTRADAS ↓↓↓↓4↓↓↓↓↓↓↓↓↓↓ --------------------------------------

    switch (opcaoSelecionada)
    {
    case 1 :
        gerarSenha(cont);
        cont++;
        // incrementar sistema de geração aleatorio posteriormente 
        break;
    
    case 2 :
        chamarProxSenha();
        break;
    
    case 3 :
        
        break;
    
    case 4 :
        exibirFila();
        break;
    
    case 0 :
        
        break;
    
    default:
        break;
    }








    } while (opcaoSelecionada != 0);


    return 0;
}