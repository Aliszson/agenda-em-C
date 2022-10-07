#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAM_NOME 100
#define TAM_VET 100


    typedef struct agenda
 {
     char nome_contato [ TAM_NOME ];
     char endereco [300];
     int numero_endereco;
     char telefone [ 12 ];
     char email [ 200 ];
     char rede_social[100];
     enum tipo_endereco{Alameda = 1, Avenida, Travessa, Rua, Praca}tiEnd;
     enum tipo_redeSocial{Insta = 1, Facebook, LinkedIN, Twitter} tiRedeSocial;
     enum tipo_telefone{Fixo = 1, Comercial, Pessoal} tiTelefone;

 } contato ;


void adicionarContatos( contato usuario[], int *i);
void listarContatos( contato usuario[], int *i);
void alterarContatos(contato usuario[], int i);
void excluirContatos(contato usuario[], int* nContatos);
void gravarArquivo(contato usuario[], int nContatos);

int main( ){
 
    setlocale(LC_ALL,"");


        contato usuario[100];

        int opcao;
        int total = lerArquivo(usuario);


 // laço para o Usuï¿½rio decidir o que o codigo ira executar
do{
    
        printf("------------------------------------------\n");
        printf("- 1. Listar Contatos:                    -\n");
        printf("- 2. Adicionar Contato:                  -\n");
        printf("- 3. Alterar Contato:                    -\n");
        printf("- 4. Excluir Contato:                    -\n");
        printf("- 5. Consultar Contato:                  -\n");
        printf("- 6. Salvar:                             -\n");
        printf("- 0. Sair:                               -\n");
        printf("------------------------------------------\n");

        scanf("%i", &opcao);

    switch (opcao)
    {

    case 1:
        listarContatos(usuario, &total);
        break;

    case 2:
         adicionarContatos(usuario, &total);
        break;

    case 3:
        alterarContatos(usuario, total);
        break;

    case 4:
        excluirContatos(usuario, &total);
        break;
    case 5:
        consultarContatos(usuario, total);
        break;
    
    case 6:
        gravarArquivo(usuario, total);
        break;

    case 0:
        printf("------------------------------------------\n");
        printf("-SAINDO ,_,                              -\n");
        printf("------------------------------------------\n");
        break;

    default:
        printf("------------------------------------------\n");
        printf("- Essa Opção não Existe.                 -\n");
        printf("------------------------------------------\n");
        break;

    }


}while(opcao != 0);

    return 0;

}


void ordenarContatos( contato usuario[], int nContatos)
{
    int comp;
    contato secundaria;

    for (int i = 0; i < nContatos; i++)
    {
        for (int j = i+1; j < nContatos; j++)
        {
            comp = strcmp(usuario[i].nome_contato, usuario[j].nome_contato);
            if (comp>0){
                secundaria = usuario[i];
                usuario[i] = usuario[j];
                usuario[j] = secundaria;
            }
    }
    
}

}

void adicionarContatos( contato usuario[], int *i)
{
    setlocale(LC_ALL,"");
    printf(" ... ADICIONANDO CONTATO.\n");

    
    printf(" - NOME DO CONTATO: \n");
    fflush(stdin);
    scanf("%[^\n]s", &usuario[*i].nome_contato);

    printf("- TIPO DO ENDEREÇO:");
    printf("- 1. ALAMEDA:");
    printf("- 2. AVENIDA:");
    printf("- 3. TRAVESSA:");
    printf("- 4. RUA:");
    printf("- 5. PRAÇA:");
    scanf("%d",&usuario[*i].tiEnd);

    printf(" - ENDEREÇO: \n");
    fflush(stdin);
    scanf("%[^\n]s", &usuario[*i].endereco);

    printf(" - NUMERO: \n");
    fflush(stdin);
    scanf("%[^\n]s", &usuario[*i].telefone);

    printf(" - E-MAIL: \n");
    fflush(stdin);
    scanf("%[^\n]s", &usuario[*i].email);

    printf(" - REDE SOCIAL: \n");
    fflush(stdin);
    scanf("%[^\n]s", &usuario[*i].rede_social);


    (*i)++;

    ordenarContatos(usuario, *i);


}


void listarContatos(contato usuario[], int *numeros_contatos)
{

    
    for (int j = 0; j < *numeros_contatos; j++){

        printf("CONTATO %i |", j);
        printf("NOME: %s |", usuario[j].nome_contato);
        printf("TELEFONE: %s |", usuario[j].telefone);
        printf("EMAIL: %s |", usuario[j].email);
        printf("ENDEREÇO: %s |", usuario[j].endereco);
        printf("REDE SOCIAL: %s |", usuario[j].rede_social);
        printf("\n");

    }

}


void alterarContatos(contato usuario[], int i)
{

    int usuario_para_alterar = 0, quant_usuarios_do_arq = 0;
    contato usuario_alterar;
    char confimar_acao, dados[200], pt;

    do
    {
        printf("Qual Contato deseja Alterar? \n");
        scanf("%i", &usuario_para_alterar);

        if ( usuario_para_alterar >= quant_usuarios_do_arq )
        {
            printf ( "Usuario inexistente. Informe valor entre 0 e %i:", i );
        }
        
    } while (usuario_para_alterar > 0 && usuario_para_alterar > quant_usuarios_do_arq);
    

        printf("NOME: \n");
        fflush(stdin);
        scanf("%[^\n]s", usuario_alterar.nome_contato);
        printf("TELEFONE: \n");
        fflush(stdin);
        scanf("%i", &usuario_alterar.telefone);
        printf("EMAIL: \n");
        fflush(stdin);
        scanf("%[^\n]s", usuario_alterar.email);
        printf("ENDEREÇO: \n");
        fflush(stdin);
        scanf("%[^\n]s", usuario_alterar.endereco);
        printf("REDE SOCIAL: \n");
        fflush(stdin);
        scanf("%[^\n]s", usuario_alterar.rede_social);

    //laço para confimar se o usuario quer mesmo trocar as informações, se sim, ele troca e se não, mantêm as informaïçoes antigas.


    printf("Deseja Confirmar ?? (S/N)");
    
    
    fflush(stdin);
    scanf("%c", &confimar_acao);
    confimar_acao = tolower(confimar_acao);
    
        if(confimar_acao == 's'){
            printf("DEU BOOM, MEU REI \n");

        // (troca de informações
         strcpy ( usuario[usuario_para_alterar].nome_contato, usuario_alterar.nome_contato );
         strcpy ( usuario[usuario_para_alterar].telefone, usuario_alterar.telefone );
         strcpy ( usuario[usuario_para_alterar].email, usuario_alterar.email );
         strcpy ( usuario[usuario_para_alterar].endereco, usuario_alterar.endereco) ;
         strcpy ( usuario[usuario_para_alterar].rede_social, usuario_alterar.rede_social );


        
        }else if(confimar_acao == 'n'){
            printf("NUMERO NÃO ALTERADO, MENO OLHA ISSO AI \n");
        
        }
        //printf("%c",confimar_acao);

    ordenarContatos(usuario,i);

}



void consultarContatos(contato usuario[], int nContatos)
{

    char nomedousuario[100];
    char *comp;

    printf("DIGITE O NOME PARA CONSULTA: \n");
    fflush(stdin);
    scanf("%[^\n]s", &nomedousuario);

    for (int j = 0; j < nContatos; j++){
        comp = strstr(usuario[j].nome_contato, nomedousuario);
        if (comp != NULL){
            printf("POSIÇÃO: %i\n", j);
            printf("NOME: %s\n", usuario[j].nome_contato);
        }
    }
}

void excluirContatos(contato usuario[], int *nContatos)
{
     setlocale(LC_ALL,"");

        char confimar;
        int numero_excluir;

    printf("DIGITE QUAL NUMERO DESEJA EXCLUIR. \n");
    for (int l = 0; l < *nContatos; l++){
        printf("(%i) - %s\n", l,  usuario[l].nome_contato);
    }
    
     scanf("%i", &numero_excluir);
     fflush(stdin);
     printf("CONFIRMAR??( S/N ) \n");
     scanf("%c", &confimar);
     confimar = tolower(confimar);


     if( confimar == 's')
     {
        for (int c = numero_excluir; c < *nContatos; c++)
        {
            usuario[c] = usuario[c+1];  
        }

        printf("CONTATO %i APAGADO DA SUA VIDA :3 \n", numero_excluir);
        ordenarContatos(usuario, *nContatos);
        (*nContatos)--;
     } else {
         printf("DESISTIU FOI?? HMM >-<");
     }


}

void gravarArquivo(contato usuario[], int nContatos){

           // Criação do Arquivo e abertura do arquivo
       
        FILE *ptrArquivo = NULL;

     
        ptrArquivo = fopen ("agendinha-da-depressaum.txt", "w");

            if(ptrArquivo == NULL){
                printf("ALGO DEU ERRADO PATRÃO..\n");
                exit(0);
            }

        for(int l = 0; l < nContatos; l++)
            {
                fprintf(ptrArquivo, "%s;%d;%s;%s;%s;%s;\n", 
                usuario[l].nome_contato,
                usuario[l].tiEnd,
                usuario[l].endereco,
                usuario[l].telefone,
                usuario[l].email,
                usuario[l].rede_social );
            }
        
        fclose(ptrArquivo);
        ptrArquivo = NULL;
}



int lerArquivo(contato usuario[]){

        // Leitura do arquivo já criado

        char *token;
        char linhazinha[200];

        int i = 0;
        FILE *ptrArquivo = NULL;
        ptrArquivo = fopen ("agendinha-da-depressaum.txt", "r");
        if(ptrArquivo == NULL){
            printf("ALGO DEU ERRADO PATRÃO..");
            return 0;
        }


    while( (fgets(linhazinha, sizeof(linhazinha), ptrArquivo) ) != NULL){

        token = strtok(linhazinha, ";");

        strcpy(usuario[i].nome_contato, token);

        token = strtok(NULL, ";");

        strcpy(usuario[i].endereco, token);

        token = strtok(NULL, ";");

        strcpy(usuario[i].telefone, token);

        token = strtok(NULL, ";");

        strcpy(usuario[i].email, token);        

        token = strtok(NULL, ";");

        strcpy(usuario[i].rede_social, token);      

        i++;
    }

        fclose(ptrArquivo);
        ptrArquivo = NULL;

        return i;
}
//Autor TeusVieira&AliohS
