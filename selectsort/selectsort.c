#include <stdlib.h>
#include <stdio.h>

void selectsort (int *vet, int n){
    //{10,9,8,7,6,5,4,3,2,1};
    int i,j,menor,aux;
    for (i=0; i<n-1; i++){
        menor=i;
        for (j=i+1; j<n;j++){
            if (vet[menor] >vet[j]){
                menor=j;
            }
        }
        if (i!=menor){
        aux=vet[i];
        vet[i]=vet[menor];
        vet[menor] =aux;
        }
        
    }
}
int main (){
    int vet[10] = {10,9,8,7,6,5,4,3,2,1};
    printf ("Algoritmo De Organização Select Sort\n");
    selectsort(vet,10);
    for (int i =0; i< 10; i++){
        printf ("%d",vet[i]);
    }
    printf ("\n");
    system ("pause");
}