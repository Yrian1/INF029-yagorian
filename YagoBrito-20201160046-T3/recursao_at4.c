#include<stdio.h>
#include<stdlib.h>
//alterar aqui tamanho do vetor
#define TAM 5
//somar valores de um vetor recursivamente
int sumvet(int vet[],int size, int n){
	if(n>size) return 0;
	return vet[n]+sumvet(vet, size, n+1);
}
int main(void){
	int vet[TAM], rslt;
	//alterar valores do vetor
	for(int i=0; i<TAM; i++)
		vet[i]=5;
	rslt=sumvet(vet, sizeof(vet)/sizeof(int), 0);

	printf("%d\n", rslt);
}
