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

int main () {
   int op=0;
    pessoa *topo = NULL;
    while (op != 5){
        printf ("Menu Agenda");
        printf ("\n 1- Inserir\n 2- Listar \n 3- Remover \n 4- Procurar \n 5- Sair\n");
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
                // remove (*topo);
                break;
            case 4:
            // procura (*topo);
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
