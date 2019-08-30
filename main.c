#include <stdlib.h>
#include <stdio.h>
struct agenda
{
    char nome[50];
    char telefone[50];
    char idade[2];
};
typedef struct agenda Pessoa;


void preenche_dados (Pessoa *p) {

    printf("Digite o nome:\n");
     fflush(stdin);
     fgets (p->nome,50,stdin);
     printf("\n TESTE NOME: %c",p->nome);
    printf("Digite o telefone:\n");
     fflush(stdin);
     fgets (p->telefone,50,stdin);
    printf("Digite o idade:\n");
     fflush(stdin);
     fgets (p->idade,2,stdin);
};
void pesquisa (Pessoa *pp, int tamanho){
     int opcao =0;
     char nome[50],idade[2],telefone[50];
     int i;
     printf ("Deseja Pesquisar por:\n1- Nome\n2- Idade\n3- Telefone\n");
      fflush(stdin);
      scanf ("%d", &opcao);
      switch (opcao) {

          case 1:{
             printf ("Digite o Nome:\n");
             fflush(stdin);
             fgets (nome,2,stdin);

            if (tamanho <= 0 ){
                printf ("A agenda está vazia!");
            }else{
                printf ("Nome: %c", pp->nome);
                for (i =0; i< tamanho; i++ ){

                    if (pp[i].nome == nome ){
                      printf ("Nome: &c", pp[i].nome);
                      printf ("Telefone: &c", pp[i].telefone);
                      printf ("Idade: &c", pp[i].idade);
                    };

                 };
            };
            break;
            };

          case 2:{
            printf ("Digite a Idade:\n");
             fflush(stdin);
             fgets (idade,50,stdin);
            if (tamanho <= 0 ){
                printf ("A agenda está vazia!");
            }else{
                for (i =0; i< tamanho; i++ ){
                    if (pp[i].idade == idade ){
                      printf ("Nome: &c", pp[i].nome);
                      printf ("Telefone: &c", pp[i].telefone);
                      printf ("Idade: &c", pp[i].idade);
                    };

                 };
            };
            break;
            };
          case 3:{
             printf ("Digite o Telefone:\n");
             fflush(stdin);
             fgets (telefone,50,stdin);
            if (tamanho <= 0 ){
                printf ("A agenda está vazia!");
            }else{
                for (i =0; i< tamanho; i++ ){
                    if (pp[i].telefone == telefone ){
                      printf ("Nome: &c", pp[i].nome);
                      printf ("Telefone: &c", pp[i].telefone);
                      printf ("Idade: &c", pp[i].idade);
                    };

                 };
            };
            break;
            };
      };
};


int main () {
    int resposta=0;
    int tamanho=0;
    Pessoa pessoa;
    Pessoa *pp = &pessoa;
    //p = malloc (sizeof(Pessoa*));
   //if (p == NULL){
   //     printf ("Erro na alocação");
   //     exit (0);
  //  };
    // MENU
   while (resposta != 4){

    printf ("1- Adicionar Pessoa \n2- Remover Pessoa\n3- Pesquisar Pessoa\n4- Fechar Agenda\n");
    fflush(stdin);
    scanf ("%d" ,&resposta);
        switch (resposta){
            case 1:{
                preenche_dados(pp);
                tamanho ++;
                break;
                };
            case 2 :{
               break;
               };
            case 3:{
                pesquisa (pp,tamanho) ;
                break;
                };
            case 4:{
                printf ("Agenda Fechada\n");
                exit(0);
                free (pp);
                break;
                };
        };
         resposta=0;
    };

};
