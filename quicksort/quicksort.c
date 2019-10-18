#include <stdio.h>
#include <stdlib.h>

void quicksort(int *vet, int left, int rigth){
    int aux,pivo,i,j;   
    i = left;
    j = rigth;
    pivo = vet[((left + rigth)/2)];
    while (i <= j){
        while (vet[i] < pivo && i < rigth){
            i++;
        }
        while (vet[j] > pivo && j > left){
            j--;
        }
        if (i <=j){
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    }
    if (j > left) {
        quicksort(vet,left,j);
    }
    if (i < rigth) {
        quicksort(vet,i,rigth);
    }
}

int main (){
    int vet[10] = {10,3,8,2,6,5,4,9,7,1};
    printf ("Algoritmo Ordenacao QuickSort\n");
    quicksort(vet,0,9);
    for (int i=0; i<10;i++){
        printf ("%d",vet[i]);
    }
    printf ("\n");
    system ("pause");
}