#include<stdlib.h>
#include"Lib_Pointers.h"

int Mk_Aux_Vet(int **adress,int  pos,int tm){

	if(pos<=0 || pos>10)
		return POSICAO_INVALIDA;
	if(*adress!=NULL)
		return JA_TEM_ESTRUTURA_AUXILIAR;

	if((*adress=calloc(tm+1, sizeof(int)))==NULL)
			return SEM_ESPACO_DE_MEMORIA;
	*adress[0]=tm;

	//printf("%lu\n", sizeof(adress));
	return SUCESSO;
}

void inivet(int ***mvet){
	if((*mvet=calloc(TAM, sizeof(int *)))==NULL)
		puts("nao foi possivel");
	else
		puts("Sucesso");
		//printf("%p\n", mvet);
	

}

int Ins_Num(int *arr, int num){

	for(int i = 1; i<=arr[0]; i++){
		if(arr[i]==0){
			arr[i]=num;
			return SUCESSO;
		}
	}
	return 69; 

}
int List_Strc(int *aVet){
	int *bVet, i, j, aux=0;
	bVet=malloc((aVet[0]+1)*sizeof(int));
	for(i = 0; i<=aVet[0]; i++){
		bVet[i]=aVet[i];
	}
	for(i = 1; i<bVet[0]; i++){
		for(j=i+1; j<=bVet[0]; j++){
			if(bVet[i]>bVet[j]){
				aux=bVet[i];
				bVet[i]=bVet[j];
				bVet[j]=aux;
			}
		}
	}
	for(i=1; i<=bVet[0]; i++)
		printf("%d: %d\n", i, bVet[i]);
	return SUCESSO;
}
void List_All(int **mVet){
	int i, j;
		Print_Hash_Line();
	for(i=0; i<TAM; i++){
		if(mVet[i]==NULL){
			printf("Estrutura: %d vazia\n", i+1);
			Print_Hash_Line();
			continue;
		}
		printf("Estrutura: %d, tamanho: %d\n", i, mVet[i][0]);
		for(j=1; j<=mVet[i][0]; j++){
			printf("Posicao %d numero: %d\n", j, mVet[i][j]);
		}
		Print_Hash_Line();
	}
}
int Rlc_Strc(int **aVet){
	int nt, total=*aVet[0];
	puts("Insira quantas posicoes voce quer adicionar a estrutura");
	scanf("%d", &nt);
	total+=nt;

	if((*aVet=realloc(*aVet, sizeof(int)*total))==NULL){
		return SEM_ESPACO_DE_MEMORIA;
	}
	else{
		*aVet[0]=total;
		return SUCESSO;
	}
}
	
