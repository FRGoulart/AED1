#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionsort (int *vet, int n) {
    int temp=0, i,j;
    for (i=0; i<n;i++){
        for (j=1; j<n; j++){
            if (vet[i] > vet[i+1]){
                temp = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = temp;
            }
        }
    }
}
int main () {


int vet[10] = {1,3,2,4,5,6,8,9,7,10};
int i,j;
    printf ("Testando implementação algoritmo InsertionSort\n");
    insertionsort (vet,10);

    for (i=0; i <10; i++){
        printf ("%d",vet[i]);
    }
     printf ("\n");
    system ("pause");
}