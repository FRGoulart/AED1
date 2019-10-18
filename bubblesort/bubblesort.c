#include <stdlib.h>
#include <stdio.h>
void bubblesort(int *vet, int n){
    int i,j,aux;
    for (i=0; i<n-1; i++){
        for (j=0; j<n-i-1;j++){
           if(vet[j] > vet[j+1]){
               aux = vet[j];
               vet[j] = vet[j+1];
               vet[j+1] = aux;
           }
        }
    }
}

int main (){
    int vet[10] = {1,9,8,7,6,5,4,3,2,10};
    int i,j;
    printf ("Testando implementação algoritmo bubblesort\n");
    bubblesort (vet,10);

    for (i=0; i <10; i++){
        printf ("%d",vet[i]);
    }
     printf ("\n");
    system ("pause");
}
