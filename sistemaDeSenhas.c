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


// ------------ Fim das fumções --------------------------





int main() {

    int opcaoSelecionada, senha, cont =1;

    do {
        printf("-=-=-=-=-= SIS SENHAS =-=-=-=-=-");
        printf("1 - gerar Senhas \t");
        printf("2 - Chamar proxima senha \t");
        printf("3 - Pesquisar senha \t");
        printf("4 - Exibir fila de senhas \n");
        printf("0 - Sair do programa \n");
        printf("Opcao: ");
        scanf("%d ", &opcaoSelecionada);

    // SWITCH PARA GERENCIAR AS ENTRADAS ↓↓↓↓4↓↓↓↓↓↓↓↓↓↓ --------------------------------------

    switch (opcaoSelecionada)
    {
    case 1 :
        
    
        break;
    
    case 2 :
        
        break;
    
    case 3 :
        
        break;
    
    case 4 :
        
        break;
    
    case 0 :
        
        break;
    
    default:
        break;
    }








    } while (opcaoSelecionada != 0);


    return 0;
}