#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionsort (int *vet, int n) {
    int  i,j,data;
    for (i=1; i<n;i++){
        data = vet[i];
         j = i-1;
        while (j >=0 && vet[j] > data){
                vet[j+1] = vet[j];
                j--;
            }
        vet [j+1] = data;
        }
    }
int main () {


int vet[10] = {10,9,8,7,6,5,4,3,2,1};
int i,j;
    printf ("Testando implementação algoritmo InsertionSort\n");
    insertionsort (vet,10);

    for (i=0; i <10; i++){
        printf ("%d",vet[i]);
    }
     printf ("\n");
    system ("pause");
}