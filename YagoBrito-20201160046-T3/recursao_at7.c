#include<stdio.h>
#define TAM 100

void invet(int vet[], int n){
	int aux;
	if(n>TAM/2) return;
	aux=vet[TAM-n-1];
	vet[TAM-n-1]=vet[n%TAM];
	vet[n%TAM]=aux;
	//printf("%d, ", n%TAM);
	invet(vet, n+1);
}
int main(void){
	int vet[TAM];
	for(int i=0; i<TAM; i++)
		vet[i]=i+2;
	invet(vet, 0);
	for(int i=0; i<TAM; i++)
		printf("%d, ", vet[i]);
}
