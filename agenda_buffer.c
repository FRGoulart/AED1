#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Agenda{
    char telefone[11];
    char nome[50];
}pessoa;

typedef struct variaveis{ 
    int op,i,npessoas;
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
    printf ("Digite Nome:\n");
    fflush (stdin);
    fgets (p->nome,50,stdin);
    printf ("Digite Telefone:\n");
    fflush (stdin);
    fgets (p->telefone,11,stdin);
    };
void lista (){
    pessoa *aux;
    aux = p;
    printf ("Npessoas: %d",pvar->npessoas);
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
/*void procura (pessoa *topo){
    pessoa *aux;
    char nome[50];
    int flag=0;
    aux = topo;

    if (aux == NULL){
        printf ("Agenda Vazia!\n");
    }else {
         printf ("Digite nome a ser pesquisado: ");
         fflush (stdin);
         fgets(nome,50,stdin);
        do{
             if(strcmp(aux->nome,nome)==0){
                 printf (" Nome: %s Telefone: %s",aux->nome,aux->telefone);
                 flag++;
             }aux = aux->prox;
        }while (aux != NULL);
        if (aux == NULL & flag == 0){
                printf ("Pessoa nao encontrada, tente novamente\n");
        };
    };
    free (aux);
};
void remover (pessoa **topo){
     pessoa *aux;
     int flag=0;
    char nome[50];

    if (*topo == NULL){
        printf ("Lista Vazia!\n");
    }else{
        printf ("Digite nome a ser removido: ");
        fflush (stdin);
        fgets(nome,50,stdin);
        for (aux = *topo; aux != NULL; aux = aux->prox){
        	if (strcmp (aux->nome, nome) == 0){
        	    aux = *topo;
                if (aux->prox == NULL){
                    *topo = NULL;
                    flag = 1;
                }else{
        	    (*topo) = aux->prox;
                aux->prox = (*topo)->prox;
                *topo = aux;
                flag = 1;
                };
	         };
        };
        if ( aux == NULL & flag == 0){
            printf ("Pessoa Não Encontrada\n");
        };
    };
    free (aux);
 };*/


int main () {
    pbuffer = malloc(sizeof (var));
    if (pbuffer == NULL){
        exit(1);
    };
    pvar = pbuffer;
    pvar->op = 0;
    pvar->npessoas = 0;
    while (pvar->op != 5){
       
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
               // procura (topo);
                break;
            case 4:
              // remover (&topo);
                break;
            case 5:
                break;
            default:
                printf ("Opcao Invalida, tente novamente\n");
                break;
       };
    };
    free(pbuffer);
return 0;
};
