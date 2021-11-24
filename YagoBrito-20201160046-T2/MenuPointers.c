#include<stdio.h>
#include<stdlib.h>
#include"Lib_Pointers.h"

void Print_Hash_Line(){
	for(int i=0; i<=25; i++){
		printf("#");
	}
	printf("\n");
}
void Main_Menu(){
	Print_Hash_Line();	
	puts("Escolha uma opcao");
	puts("Inserir um numero em uma estrutura auxiliar(1)");
	puts("Listar numeros ordenados de uma estrutura auxilliar(2)");
	puts("Listar o tamanho das estrutura auxiliares e seus tamanho(3)");
	puts("Aumentar o tamanho de uma estrutura auxiliar(4)");
	puts("sair(0)");
	Print_Hash_Line();	
}
void Menu_Ins_Num(int **mvet){
	int num, rtrn, tm, pos, opt=-1;
	puts("Insira o numero a inserir numa estrutura auxiliar");
	scanf("%d", &num);
	puts("Insira a posicao na estrutura principal que pretende inserir"); 
	scanf("%d", &pos);
	do{
		if(mvet[pos-1]==NULL){
			printf("Estrutura auxiliar ainda nao foi criada gostaria de criar-la.\n\tSIM:(1)\tNAO:(0)");
			scanf("%d", &opt);
		}
		else
			break;
		switch (opt){
			case 1:
				puts("insira o tamanho da estrutura que deseja criar");
				scanf("%d", &tm);
				rtrn=Mk_Aux_Vet(&mvet[pos-1], pos, tm);
				if(rtrn==SUCESSO){
					puts("Sucesso em criar vetor auxiliar");
				}
				else if(rtrn==POSICAO_INVALIDA){
					puts("Posicao invalida");
					}
				else if(rtrn==SEM_ESPACO_DE_MEMORIA){
					puts("Sem espaco de memoria");
					}
				opt=-1;
				break;
			case 0:
				puts("Operacao cancelada");
				return;
				break;
			default:
				puts("Opcao invalida tente novamente");
				//opt=-1;
				break;
		}
	}while(opt!=-1);

	rtrn=Ins_Num(mvet[pos-1], num);
	if(rtrn==SUCESSO)
		puts("Numero inserido com sucesso");
	else
		printf("Nao foi possivel inserir o numero na estrutura por algum motivo");
}

void Menu_List_Strc(int **mvet){

	int opt, pos;

	do{
		puts("Insira a posicao da estrutura que deseja listar(1...10)");
		scanf("%d", &pos);
		if(mvet[pos-1]==NULL){
			printf("Nao existe estrutura auxiliar criada nessa posicao, deseja escolher outra?\n\tSIM(1)\tNAO(0)\n");
			scanf("%d",&opt);
		}
		else
			break;	
	}while(opt!=0);
	List_Strc(mvet[pos-1]);
}
void Menu_List_All(int **mvet){
	List_All(mvet);

}
void Menu_Rlc_Strc(int **mvet){
	int pos, rtrn;	
	puts("Insira a posicao da estrutura auxiliar que quer aumentar");
	scanf("%d", &pos);
	if(pos<1 || pos>10){
		puts("posicao invalida. Abortando...");
		return;
	}
	else if(mvet[pos-1]==NULL){
		puts("Essa estrutura ainda nao existe. Abortando...");
		return;
	}else{
		rtrn=Rlc_Strc(&mvet[pos-1]);
	}
	if(rtrn==SUCESSO){
		puts("Sucesso");
	}
	else
		puts("Nao foi possivel aumentar a estrutura");
}
