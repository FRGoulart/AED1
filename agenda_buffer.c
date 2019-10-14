#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Agenda{
    char telefone[11];
    char nome[50];
}pessoa;

typedef struct variaveis{ 
    int op,i,npessoas,flag;
    int sizebuf;
    char nome[50];
    char telefone[11];
}var;

void *pbuffer;
pessoa *p ;
var *pvar;

void insere (){
    pvar->npessoas ++;
    pvar->sizebuf = pbuffer + sizeof(var) + ((pvar->npessoas)*sizeof(pessoa));
    pbuffer = realloc (pbuffer,pvar->sizebuf);
    pvar= pbuffer;
    p = pbuffer + (pvar->npessoas)*sizeof(pessoa);
    printf ("Digite Dados Novo Contato:\n");
    printf ("Digite Nome:");
    fflush (stdin);
    fgets (p->nome,50,stdin);
    printf ("Digite Telefone:");
    fflush (stdin);
    fgets (p->telefone,11,stdin);
    };
void lista (){
    pessoa *aux=NULL;
    aux = p;
    aux = aux -( (pvar->npessoas)-1);
    if (pvar->npessoas == 0){
        printf ("Agenda Vazia!\n");
    }else{
        for (pvar->i=0;(pvar->i)<(pvar->npessoas);pvar->i++){
            printf (" Nome: %s Telefone: %s\n",aux->nome,aux->telefone);
            aux=aux + 1;
        }
    }
free (aux);
};
void procura (){
    pessoa *aux=NULL;
    aux = p - ((pvar->npessoas)-1);
    pvar->flag = 0;
    if (pvar->npessoas == 0){
        printf ("Agenda Vazia!\n");
    }else {
         printf ("Digite nome a ser pesquisado: ");
         fflush (stdin);
         fgets(pvar->nome,50,stdin);
        for (pvar->i=0;(pvar->npessoas)>(pvar->i);(pvar->i)++){
             if(strcmp(pvar->nome,aux->nome)==0){
                 printf (" Nome: %s Telefone: %s",aux->nome,aux->telefone);
                 pvar->flag++;
                
            }
             aux++;
       }
        if (pvar->flag == 0){
                printf ("Pessoa nao encontrada, tente novamente\n");
        };
    }
    free(aux);
};
void remover (){
     
    if (pvar->npessoas == 0){
        printf ("Agenda Vazia!\n");
    }else{
          pessoa *aux,*troca;
         troca = p;
        aux= p -((pvar->npessoas)-1);
        printf ("Digite nome a ser removido: ");
        fflush (stdin);
        fgets(pvar->nome,50,stdin);
        pvar->flag =0;
        for (pvar->i=0; pvar->i < pvar->npessoas; pvar->i++){
        	if (strcmp (aux->nome,pvar->nome) == 0){
        	    *aux = *troca ;
                pvar->flag = 1;
                pvar->npessoas--;
                pbuffer = realloc (pbuffer,((pvar->sizebuf) - sizeof(pessoa)));
                pvar = pbuffer;
                p = pbuffer + (pvar->npessoas)*sizeof(pessoa);
                }
            aux = aux + 1;
	    }
        free (aux);
        free (troca);
        if ( pvar->flag == 0){
        printf ("Pessoa Não Encontrada\n");
        }
    } 
 }


int main () {
    pbuffer = malloc(sizeof (var));   // Aloca o buffer com tamanho necessario para variaveis de controle, que ficam na struct
    if (pbuffer == NULL){           // verifica se conseguiu alocar
        exit(1);
    };
    pvar = pbuffer;                 // faz o ponteiros das variaveis apontar para o inicio do buffer
    pvar->op = 0;                   // inicia variaveis
    pvar->npessoas = 0;
    while (pvar->op != 5){          // Fica rodando até o usuário decidir sair da agenda
       pvar->op = 0;
        printf ("Menu Agenda");
        printf ("\n 1- Inserir\n 2- Listar \n 3- Procurar \n 4- Remover \n 5- Sair\n");
        fflush (stdin);
        scanf ("%d",&pvar->op);
        switch (pvar->op)
        {

            case 1:
                insere ();
                break;
            case 2:
                lista ();
                break;
            case 3:
                procura ();
                break;
            case 4:
                remover ();
                break;
            case 5:
                free(pbuffer);
                exit (1);
                break;
            default:
                printf ("Opcao Invalida, tente novamente\n");
                break;
       }
    }
   
}
