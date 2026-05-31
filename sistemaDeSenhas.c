#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    printf("\n");
}

//  função para chamar a prox senha

void chamarProxSenha(){
    if(inicio==NULL){
        printf("A fila esta vazia\n ");
        return;
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
    bool encontrado = false ;

    while (atual != NULL ){
        // RETORNA A SENHA CASO A MESMA FOR ENCONTRADA E FOR IGUAL E FOR MENOR QUE A SENHA FINAL CRIADA
        if(atual -> senha == senha || (senha > atual -> senha  && senha < fim -> senha)){
            printf("A senha: %d ainda sera chamada, aguarde.... \n\n\n", senha);
            encontrado = true;
            return;
        }

        
        atual = atual -> prox;
        
    }
    // REOTNA A MENSAGEM CASO O USUARIO DIGITAR UMA SENHA MUITO MAIOR DO QUE A FINAL JA GERADA
    if((!encontrado && senha > fim -> senha ) || senha < 0){
    printf("A sua senha: %d, NAO FOI ENCONTRADA!\n", senha);
    return;
    }
    
    // POR ELIMINAÇÃO, RETORNA A SENHA QUE JA FOI PASSADA, OU SEJA, O PONTEIRO ATUAL JA ANDOU,
    // MAS COMO A SENHA SÃO SUMEROS CRESCENTES, O NUMERO MENOR DO QUE O ATUAL SIGINICA QUE JA FOI CHAMADO

    printf("A sua senha: %d ja foi chamada, PRESTE MAIS ATENCAO!\n", senha);
  
}

// gerar 10 senhas automaticamente:

int gerar10em10senhas(int inicio){

    int fim = inicio + 10;

    for(int i=inicio; i < fim; i++){
        gerarSenha(i);
    }

    return fim;
}



// ------------ Fim das fumções --------------------------





int main() {

    int opcaoSelecionada, senha, cont =1;

    do {
        
        printf("\n\n\n-=-=-=-=-= SYS SENHAS =-=-=-=-=- \n");
        printf("1 - gerar Senhas \t");
        printf("2 - Chamar proxima senha \t");
        printf("3 - Pesquisar senha \t");
        printf("4 - Exibir fila de senhas \n");
        printf("5 - gerar senha de 10 em 10 \n");
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
        break;
    
    case 2 :
        chamarProxSenha();
        break;
    
    case 3 :
        printf("Digite a senha que deseja buscar: ");
        scanf("%d", &senha);
        pesquisarSenha(senha);
        break;
    
    case 4 :
        exibirFila();
        break;
    
    case 5 :
        cont = gerar10em10senhas(cont);
        break;
    case 0 :
        
        break;
    
    default:
        break;
    }


    } while (opcaoSelecionada != 0);


    return 0;
}