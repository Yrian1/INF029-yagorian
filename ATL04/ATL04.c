#include<stdio.h>
#define TAM 3
//atividade numero 4 da lista
//Aluno: Yago Rian | Prof: Roberto Novais | 2021
void Ler3numeros(int* vet);
int main(void){
	int vet[TAM];
	int i;
	Ler3numeros(vet);
	for (i = 0; i < TAM; i++)	
	printf("numero %d\n", vet[i]);
}

void Ler3numeros(int* vet){
	int i;
	puts("insira 3 numeros");
	for (i = 0; i < TAM; i++)
		scanf("%d", &vet[i]);
}

