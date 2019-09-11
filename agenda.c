#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Agenda{
    char telefone[11];
    char nome[50];
    struct Agenda *prox;
}pessoa;

void insere (pessoa **topo){
    char nome[50];
    char telefone[11];
    pessoa *nova;
    nova = (pessoa*)malloc(sizeof(pessoa));
    printf ("Digite Nome:\n");
    fflush (stdin);
    fgets (nome,50,stdin);
    printf ("Digite Telefone:\n");
    fflush (stdin);
    fgets (telefone,11,stdin);
    strcpy (nova->nome, nome);
    strcpy (nova->telefone, telefone);
    if (*topo ==NULL){
        nova->prox=NULL;
        *topo = nova;
    }else{
        nova->prox = *topo;
        *topo = nova;
    };
};
void lista (pessoa *topo){
    pessoa *aux;
    aux = topo;
    if (aux == NULL){
        printf ("Lista Vazia");
    }else {
        do {
            printf (" Nome: %s Telefone: %s\n",aux->nome,aux->telefone);
            aux = aux->prox;
        }while (aux != NULL);
    }


};
void procura (pessoa *topo){
    pessoa *aux;
    char nome[50];
    int flag=0;
    aux = topo;
    printf ("Digite nome a ser pesquisado: ");
    fflush (stdin);
    fgets(nome,50,stdin); 
    if (aux == NULL){
        printf ("Agenda Vazia!\n");
    }else {
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
    char nome[50];
    printf ("Digite nome a ser removido: ");
    fflush (stdin);
    fgets(nome,50,stdin); 
    if (*topo == NULL){
        printf ("Lista Vazia!\n");
    }else{
        for (aux = *topo; aux != NULL; aux = aux->prox){
        	if (strcmp (aux->nome, nome) == 0){
        	    aux = *topo;
        	    (*topo) = aux->prox;
                aux->prox = (*topo)->prox;
                *topo = aux;
                
	         };
        };
    };
};

int main () {
   int op=0;
    pessoa *topo = NULL;
    while (op != 5){
        printf ("Menu Agenda");
        printf ("\n 1- Inserir\n 2- Listar \n 3- Procurar \n 4- Remover \n 5- Sair\n");
        fflush (stdin);
        scanf ("%d",&op);
        switch (op)
        {
       
            case 1:
                insere (&topo);
                break;
            case 2:
                lista (topo);
                break;
            case 3:
                procura (topo);
                break;
            case 4:
               remover (&topo);
                break;
            case 5:
                break;
            default:
                break;
    }
    };
    free(topo);
return 0;
};
