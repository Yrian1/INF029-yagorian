#include"Library-ATL08.h"
#include<stdio.h>

int validnome(char* nome){
	if(nome[20]!='\0'){
		puts("Voce inseriu um nome com mais de 20 caracteres por favor insira novamente");
		return 0;
	}
 	return 1;
}

int validcpf(char* cpf){
	int i=0;
	if(cpf[10]=='\0'){
		puts("Voce inseriu um cpf invalido por favor insira novamente");
		return 0;
	}
	while(i<11){
		if(cpf[i]<48 || cpf[i]>57){
			puts("Voce inseriu um cpf invalido por favor insira novamente");
			return 0;
			}
		i++;
	}
	return 1;
}

int validgen(char gen){
	if(gen>92)
		gen-=32;
	if(gen==70 || gen==77 || gen==79){
		return 1;
		}
	puts("Voce inseriu um genero invalido, por favor insira novamente");
	return 0;
}
int validnas(struct Datnas nasdate){
	if(nasdate.dia < 1 || nasdate.dia > 31){
	puts("Voce inseriu uma data de nascimento invalida, por favor tente novamente");
		return 0;
	}
	if(nasdate.mes < 1 || nasdate.mes > 12){
		puts("Voce inseriu uma data de nascimento invalida, por favor tente novamente");
		return 0;
	}	
	if(nasdate.ano < 1900 || nasdate.ano > 2021){
		puts("Voce inseriu uma data de nascimento invalida, por favor tente novamente");
		return 0;
	}
	return 1;
		
}
